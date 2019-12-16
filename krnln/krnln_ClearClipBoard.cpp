#include "stdafx.h"

//系统处理 - 清除剪辑板
/*
    调用格式： 〈无返回值〉 清除剪辑板 （） - 系统核心支持库->系统处理
    英文名称：ClearClipBoard
    清除当前 Windows 系统剪辑板中的所有数据。本命令为初级命令。
*/
LIBAPI(void, krnln_ClearClipBoard)
{
	if(OpenClipboard(NULL))
	{
		EmptyClipboard();
		CloseClipboard();
	}
}
