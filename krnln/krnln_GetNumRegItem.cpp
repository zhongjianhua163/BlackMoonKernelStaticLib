#include "stdafx.h"
#include "Myfunctions.h"

#pragma comment(lib,"advapi32.lib") 
//系统处理 - 取数值注册项
/*
    调用格式： 〈整数型〉 取数值注册项 （整数型 根目录，文本型 全路径注册项名，［整数型 默认数值］） - 系统核心支持库->系统处理
    英文名称：GetNumRegItem
    在 Windows 注册表中返回指定的数值类型注册表项值。如欲读取注册项默认值，请在项目名后加“\”号，如“test\”。与“取数值注册表项”命令不同的是本命令可以取任意位置处的注册表项。本命令为中级命令。
    参数<1>的名称为“根目录”，类型为“整数型（int）”。可以为以下常量值之一： 1、#根类； 2、#现行设置； 3、#现行用户； 4、#本地机器； 5、#所有用户。
    参数<2>的名称为“全路径注册项名”，类型为“文本型（text）”。
    参数<3>的名称为“默认数值”，类型为“整数型（int）”，可以被省略。如果指定的注册表项不存在，将返回此默认数值。如果指定的注册表项不存在且本参数被省略，将返回数值 0。
*/
LIBAPI(int, krnln_GetNumRegItem)
{
	PMDATA_INF pArgInf = &ArgInf;
	HKEY hRootkey = GetRegRootVal(pArgInf[0].m_int);
	BOOL bOk = FALSE;
	INT nRetVal = 0;
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
		
			DWORD nLen = 4;
			DWORD dwType = REG_DWORD;

			if(ERROR_SUCCESS == RegQueryValueEx(hkey,pKeyname,NULL,&dwType,(LPBYTE)&nRetVal,&nLen))
			{
				if(dwType == REG_DWORD)
					bOk = TRUE;
			}

			RegCloseKey(hkey);

		}
		delete [] pSubkey;
	}

	if(bOk == FALSE && pArgInf[2].m_dtDataType != _SDT_NULL)
	{
		nRetVal = pArgInf[2].m_int;
	}
	return nRetVal;
}
