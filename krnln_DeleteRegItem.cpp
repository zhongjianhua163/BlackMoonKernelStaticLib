#include "stdafx.h"
#include "Myfunctions.h"
#pragma comment(lib,"advapi32.lib") 
//系统处理 - 删除注册项
/*
    调用格式： 〈逻辑型〉 删除注册项 （整数型 根目录，文本型 全路径注册项名） - 系统核心支持库->系统处理
    英文名称：DeleteRegItem
    在 Windows 注册表中删除指定注册表项或注册表目录。如欲删除注册项默认值，请在项目名后加“\”号，如“test\”。成功返回真，否则返回假。注意在删除目录之前必须先删除该目录下所有的项目。本命令为中级命令。
    参数<1>的名称为“根目录”，类型为“整数型（int）”。可以为以下常量值之一： 1、#根类； 2、#现行设置； 3、#现行用户； 4、#本地机器； 5、#所有用户。
    参数<2>的名称为“全路径注册项名”，类型为“文本型（text）”。
*/
LIBAPI(BOOL, krnln_DeleteRegItem)
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
		if(RegOpenKeyEx(hRootkey,pSubkey,0,KEY_ALL_ACCESS,&hkey)==ERROR_SUCCESS)
		{
			bRet = (RegDeleteValue(hkey,pKeyname)==ERROR_SUCCESS);
			RegCloseKey(hkey);
		}
		if(bRet == FALSE)
		{
			bRet = (RegDeleteKey(hRootkey,pArgInf[1].m_pText)==ERROR_SUCCESS);
		}

		delete [] pSubkey;
	}

	return bRet;
}
