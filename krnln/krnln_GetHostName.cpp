#include "stdafx.h"
#include "Myfunctions.h"

#pragma comment(lib,"WS2_32.LIB")
//网络通信 - 取主机名
/*
    调用格式： 〈文本型〉 取主机名 （） - 系统核心支持库->网络通信
    英文名称：GetHostName
    返回本机的主机名，用作在网络通讯中标志本机地址。本命令为初级命令。
*/
LIBAPI(void*, krnln_GetHostName)
{
	WSAData wsaData;
	LPSTR pText=NULL;
	if(WSAStartup(MAKEWORD(2,2),&wsaData)==0)
	{
		char hst[MAX_PATH];
		if(gethostname(hst,MAX_PATH)==0)
		{
			pText=CloneTextData(hst,mystrlen(hst));
		}
		WSACleanup ();
	}
	return pText;
}
