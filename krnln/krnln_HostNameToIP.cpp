#include "stdafx.h"
#include "Myfunctions.h"

#pragma comment(lib,"WS2_32.LIB")
//网络通信 - 转换为IP地址
/*
    调用格式： 〈文本型〉 转换为IP地址 （文本型 欲转换主机名） - 系统核心支持库->网络通信
    英文名称：HostNameToIP
    将指定的主机名转换为其 IP 地址。如果失败返回空文本。本命令为初级命令。
    参数<1>的名称为“欲转换主机名”，类型为“文本型（text）”。
*/

DWORD MYGetIPbyname(char *HostName)
{
	DWORD retIP;
	hostent* heDestHost = gethostbyname (HostName);

	if(heDestHost)
		retIP=*(DWORD *)*heDestHost->h_addr_list;
	else
		retIP=0xFFFFFFFF;
	return retIP;
}

LIBAPI(char*, krnln_HostNameToIP)
{
	WSAData wsaData;
	LPSTR pText=NULL;
	if(WSAStartup(MAKEWORD(2,2),&wsaData)==0)
	{
		DWORD retIP = MYGetIPbyname(ArgInf.m_pText);
		if(retIP !=0xFFFFFFFF)
		{
			sockaddr_in localaddr;
			localaddr.sin_addr.S_un.S_addr=retIP;
			LPSTR pIp = inet_ntoa(localaddr.sin_addr);
			pText=CloneTextData(pIp,mystrlen(pIp));

		}
		WSACleanup ();
	}
	return pText;
}
