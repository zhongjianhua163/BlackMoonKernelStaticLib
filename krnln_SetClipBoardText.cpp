#include "stdafx.h"
#include "Myfunctions.h"

//系统处理 - 置剪辑板文本
/*
    调用格式： 〈逻辑型〉 置剪辑板文本 （文本型 准备置入剪辑板的文本） - 系统核心支持库->系统处理
    英文名称：SetClipBoardText
    将指定文本存放到当前 Windows 系统剪辑板中去，剪辑板中的原有内容被覆盖。成功返回真，失败返回假。本命令为初级命令。
    参数<1>的名称为“准备置入剪辑板的文本”，类型为“文本型（text）”。

*/
LIBAPI(BOOL, krnln_SetClipBoardText)
{
	BOOL bRet = FALSE;
	if(ArgInf.m_pText && OpenClipboard(NULL))
	{
		EmptyClipboard();
		INT nLen = mystrlen(ArgInf.m_pText)+1;
		HGLOBAL hClip = GlobalAlloc(0x42,nLen);
		if(hClip)
		{
			LPSTR pStr = (LPSTR)GlobalLock(hClip);
			strcpy(pStr,ArgInf.m_pText);
			GlobalUnlock(hClip);
			SetClipboardData(CF_TEXT,hClip);
			bRet = TRUE;
		}
		CloseClipboard();
	}
	return bRet;

}
