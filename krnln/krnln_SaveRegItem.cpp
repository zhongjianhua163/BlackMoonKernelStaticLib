#include "stdafx.h"
#pragma comment(lib,"advapi32.lib") 
#include "Myfunctions.h"

//系统处理 - 写注册项
/*
    调用格式： 〈逻辑型〉 写注册项 （整数型 根目录，文本型 全路径注册项名，通用型 欲写入值） - 系统核心支持库->系统处理
    英文名称：SaveRegItem
    在 Windows 注册表中保存或建立指定的注册表项。如欲写入注册项默认值，请在项目名后加“\”号，如“test\”。成功返回真，否则返回假。与“写注册表项”命令不同的是本命令可以写任意位置处的注册表项。本命令为中级命令。
    参数<1>的名称为“根目录”，类型为“整数型（int）”。可以为以下常量值之一： 1、#根类； 2、#现行设置； 3、#现行用户； 4、#本地机器； 5、#所有用户。
    参数<2>的名称为“全路径注册项名”，类型为“文本型（text）”。
    参数<3>的名称为“欲写入值”，类型为“通用型（all）”。参数值指定欲写入到指定注册表项中的值，只能为数值、文本或者字节集，否则命令将失败。
*/
LIBAPI(BOOL, krnln_SaveRegItem)
{
	PMDATA_INF pArgInf = &ArgInf;
	DWORD dwLen=0;
	DWORD dwType;
	DWORD dwNewVal;
	LPBYTE pData=NULL;

	switch(pArgInf[2].m_dtDataType)
	{
	case SDT_TEXT:
		dwType = REG_SZ;
		dwLen = mystrlen(pArgInf[2].m_pText)+1;
		pData = (LPBYTE)pArgInf[2].m_pText;
		break;
	case SDT_BIN:
		dwType = REG_BINARY;
		if(pArgInf[2].m_pBin)
		{
			dwLen = pArgInf[2].m_pInt[1];
			pData = pArgInf[2].m_pBin+2*sizeof(INT);
		}
		break;
	case SDT_INT:
	case SDT_BYTE:
	case SDT_SHORT:
		dwType = REG_DWORD;
		dwLen = sizeof(INT);
		pData = (LPBYTE)&pArgInf[2].m_int;
		break;
	case SDT_FLOAT:
		{
			dwType = REG_DWORD;
			dwLen = sizeof(INT);
			dwNewVal = (DWORD)pArgInf[2].m_float;
			//pArgInf[2].m_dwSubCodeAdr = dwVal;
			pData = (LPBYTE)&dwNewVal;
			break;
		}
	case SDT_INT64:
		{
			dwType = REG_DWORD;
			dwLen = sizeof(INT);
			dwNewVal = (DWORD)pArgInf[2].m_int64;
			//pArgInf[2].m_dwSubCodeAdr = dwVal;
			pData = (LPBYTE)&dwNewVal;
			break;
		}
	case SDT_DOUBLE:
		{
			dwType = REG_DWORD;
			dwLen = sizeof(INT);
			dwNewVal = (DWORD)pArgInf[2].m_double;
			//pArgInf[2].m_dwSubCodeAdr = dwVal;
			pData = (LPBYTE)&dwNewVal;
			break;
		}
	default:
		return FALSE;

	}

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
		if(RegCreateKeyEx(hRootkey,pSubkey,0,NULL,0,KEY_WRITE,NULL,&hkey,NULL)==ERROR_SUCCESS)
		{
			if(RegSetValueEx(hkey,pKeyname,0,dwType,pData,dwLen)==ERROR_SUCCESS)
			{
				bRet = TRUE;
			}
		

			RegCloseKey(hkey);


		}
		delete [] pSubkey;
	}

	return bRet;
}
