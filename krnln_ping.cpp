#include "stdafx.h"
#pragma comment(lib,"WS2_32.LIB")
#pragma comment(lib,"icmp.lib")

//网络通信 - 通信测试
/*
    调用格式： 〈整数型〉 通信测试 （文本型 被测试主机地址，［整数型 最长等待时间］） - 系统核心支持库->网络通信
    英文名称：ping
    测试与指定主机是否能够正常通讯。返回被测试主机的通讯响应时间。如果无法通讯或者测试失败，返回 -1。本命令为初级命令。
    参数<1>的名称为“被测试主机地址”，类型为“文本型（text）”。可以为主机名、IP地址等。
    参数<2>的名称为“最长等待时间”，类型为“整数型（int）”，可以被省略。指定最长等待被测试主机响应的时间，单位为毫秒。超过此时间即认为无法与被测试主机通讯。如果省略本参数，则默认为 10 * 1000 毫秒，即 10 秒。
*/
#pragma pack (push, old_value)   // 保存VC++编译器结构对齐字节数。
#pragma pack (1)    // 设置为以一字节对齐。

typedef struct tagIPINFO 
{ 
u_char Ttl; // TTL 
u_char Tos; // 服务类型 
u_char IPFlags; // IP标志 
u_char OptSize; // 可选数据大小 
u_char *Options; // 可选数据buffer 
} IPINFO, *PIPINFO; 

typedef struct tagICMPECHO 
{ 
u_long Source; // 源地址 
u_long Status; // IP状态 
u_long RTTime; // RTT 
u_short DataSize; // 回复数据大小 
u_short Reserved; // 保留 
void *pData; // 回复数据buffer 
IPINFO ipInfo; // 回复IP选项 
char Data [250];
} ICMPECHO, *PICMPECHO; 

#pragma pack (pop, old_value)    // 恢复VC++编译器结构对齐字节数。

extern "C"
{
HANDLE _cdecl IcmpCreateFile(void);//用来打开个ICMP Echo请求能使用的句柄； 
BOOL _cdecl IcmpCloseHandle(HANDLE IcmpHandle);//关闭刚才打开的句柄 
DWORD _cdecl IcmpSendEcho(HANDLE,DWORD,LPVOID,WORD,PIPINFO,LPVOID,DWORD,DWORD);//发送Echo请求并等
}

DWORD BMGetIPbyname(char *HostName)
{
	hostent* heDestHost;
	DWORD retIP = inet_addr(HostName);
	if(retIP==0xFFFFFFFF)
	{
		heDestHost=gethostbyname (HostName);
		if(heDestHost)
			retIP=*(DWORD *)*heDestHost->h_addr_list;
	}

	return retIP;
}

LIBAPI(int, krnln_ping)
{
	PMDATA_INF pArgInf = &ArgInf;
	WSAData wsaData;
	INT nRet = -1;
	if(WSAStartup(MAKEWORD(2,2),&wsaData)==0)
	{
		DWORD dwAddress = BMGetIPbyname(pArgInf[0].m_pText);
		if(dwAddress != 0xFFFFFFFF)
		{
			DWORD dwPingTimeOut = 10000;
			if(pArgInf[1].m_dtDataType != _SDT_NULL)
				dwPingTimeOut = pArgInf[1].m_int;

			FARPROC (__stdcall *IcmpCreateFilefun)(void);
			*(FARPROC *)&IcmpCreateFilefun = (FARPROC)IcmpCreateFile;

			HANDLE hICmp = IcmpCreateFilefun();
			if(hICmp)
			{
				ICMPECHO icmp;
				FARPROC (__stdcall *IcmpSendEchofun)(HANDLE,DWORD,LPVOID,WORD,PIPINFO,LPVOID,DWORD,DWORD);
				*(FARPROC *)&IcmpSendEchofun = (FARPROC)IcmpSendEcho;

				if(IcmpSendEchofun (hICmp,
					dwAddress,
					"BlackMoonPing",
					13,
					0,
					&icmp,
					sizeof(icmp),
					dwPingTimeOut))
				{
					nRet = icmp.RTTime;
				}
				FARPROC (__stdcall *IcmpCloseHandlefun)(HANDLE);
				*(FARPROC *)&IcmpCloseHandlefun = (FARPROC)IcmpCloseHandle;
				IcmpCloseHandlefun(hICmp);
			}

		}

		WSACleanup ();
	}
	return nRet;
}
