#include "stdafx.h"

//系统处理 - 取默认底色
/*
    调用格式： 〈整数型〉 取默认底色 （） - 系统核心支持库->系统处理
    英文名称：GetBackColor
    取回Windows系统的默认窗口背景颜色。本命令为初级命令。
*/
LIBAPI(int, krnln_GetBackColor)
{
	return GetSysColor(0xF);
}
