#include "stdafx.h"
#include "Myfunctions.h"

#pragma comment(lib,"advapi32.lib") 
//系统处理 - 注册项是否存在
/*
    调用格式： 〈逻辑型〉 注册项是否存在 （整数型 根目录，文本型 全路径注册项名） - 系统核心支持库->系统处理
    英文名称：IsRegItemExist
    如果指定注册表项存在，返回真，否则返回假。如欲检查注册项是否有默认值，请在项目名后加“\”号，如“test\”。本命令为中级命令。
    参数<1>的名称为“根目录”，类型为“整数型（int）”。可以为以下常量值之一： 1、#根类； 2、#现行设置； 3、#现行用户； 4、#本地机器； 5、#所有用户。
    参数<2>的名称为“全路径注册项名”，类型为“文本型（text）”。
*/
LIBAPI(BOOL, krnln_IsRegItemExist)
{
	PMDATA_INF pArgInf = &ArgInf;
	HKEY hRootkey = GetRegRootVal(pArgInf[0].m_int);
	BOOL bRet = FALSE;
	INT nLen = mystrlen(pArgInf[1].m_pText);
	if(hRootkey && nLen)
	{
		HKEY hkey;
		LPSTR pSubkey = new char [nLen +1];
		strcpy(pSubkey,pArgInf[1].m_pText);
		LPSTR pKeyname = strrchr(pSubkey,'\\');
		if(pKeyname)
		{
			*pKeyname = 0;
			pKeyname++;
		}
		if(RegOpenKey(hRootkey,pSubkey,&hkey)==ERROR_SUCCESS)
		{
			DWORD nLen = MAX_PATH;
			DWORD dwType;
			char sRetVal[MAX_PATH];
			INT nRet = RegQueryValueEx(hkey,pKeyname,NULL,&dwType,(LPBYTE)sRetVal,&nLen);
			if(ERROR_SUCCESS == nRet || nRet == ERROR_MORE_DATA)
			{
				bRet = TRUE;
			}
			RegCloseKey(hkey);
		}
		delete [] pSubkey;
	}

	return bRet;
}
