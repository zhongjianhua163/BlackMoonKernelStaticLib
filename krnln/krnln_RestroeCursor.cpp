#include "stdafx.h"

//系统处理 - 恢复鼠标
/*
    调用格式： 〈无返回值〉 恢复鼠标 （） - 系统核心支持库->系统处理
    英文名称：RestroeCursor
    本命令恢复现行鼠标的原有形状，用作与“置等待鼠标”命令配对使用。本命令为初级命令。
*/
HCURSOR hCurOld = NULL;

LIBAPI(void, krnln_RestroeCursor)
{

	if(hCurOld)
	{
		SetCursor(hCurOld);
		hCurOld = NULL;
	}
}
