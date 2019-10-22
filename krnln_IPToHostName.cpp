#include "stdafx.h"
#include "Myfunctions.h"

#pragma comment(lib,"WS2_32.LIB")
//网络通信 - 转换为主机名
/*
    调用格式： 〈文本型〉 转换为主机名 （文本型 欲转换IP地址） - 系统核心支持库->网络通信
    英文名称：IPToHostName
    将指定的 IP 地址转换为其主机名。如果失败返回空文本。本命令为初级命令。
    参数<1>的名称为“欲转换IP地址”，类型为“文本型（text）”。
*/

LIBAPI(char*, krnln_IPToHostName)
{
	WSAData wsaData;
	LPSTR pText=NULL;
	if(WSAStartup(MAKEWORD(2,2),&wsaData)==0)
	{
		DWORD retIP = inet_addr(ArgInf.m_pText);
		if(retIP !=0xFFFFFFFF)
		{
			hostent* hostinfo=gethostbyaddr((char*)&retIP,sizeof(retIP),AF_INET);
			pText=CloneTextData(hostinfo->h_name,mystrlen(hostinfo->h_name));
		
		}
		WSACleanup ();
	}
	return pText;

}
