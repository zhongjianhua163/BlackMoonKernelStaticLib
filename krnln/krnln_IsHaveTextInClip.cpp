#include "stdafx.h"

//系统处理 - 剪辑板中可有文本
/*
    调用格式： 〈逻辑型〉 剪辑板中可有文本 （） - 系统核心支持库->系统处理
    英文名称：IsHaveTextInClip
    如果当前 Windows 系统剪辑板中有文本数据，则返回真，否则返回假。本命令为初级命令。
*/
LIBAPI(BOOL, krnln_IsHaveTextInClip)
{
	BOOL bRet = FALSE;
	if(OpenClipboard(NULL))
	{
		HANDLE hClip =  GetClipboardData(CF_TEXT);
		if(hClip)
			bRet = TRUE;
		CloseClipboard();
	}
	return bRet;
}
