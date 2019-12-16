#include "stdafx.h"
#include "Myfunctions.h"
//系统处理 - 取剪辑板文本
/*
    调用格式： 〈文本型〉 取剪辑板文本 （） - 系统核心支持库->系统处理
    英文名称：GetClipBoardText
    返回存放于当前 Windows 系统剪辑板中的文本。如果当前剪辑板中无文本数据，将返回空文本。本命令为初级命令。
*/
LIBAPI(char*, krnln_GetClipBoardText)
{

	char* pText = NULL;
	if(OpenClipboard(NULL))
	{
		HANDLE hClip =  GetClipboardData(CF_TEXT);
		if(hClip)
		{
			LPSTR pStr = (LPSTR)GlobalLock(hClip);
			pText = CloneTextData(pStr,mystrlen(pStr));
			GlobalUnlock(hClip);
		}
		CloseClipboard();
	}
	return pText;
}
