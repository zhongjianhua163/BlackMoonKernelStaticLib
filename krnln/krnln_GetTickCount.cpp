#include "stdafx.h"

//系统处理 - 取启动时间
/*
    调用格式： 〈整数型〉 取启动时间 （） - 系统核心支持库->系统处理
    英文名称：GetTickCount
    返回自 Windows 系统启动后到现在为止所经历过的毫秒数。本命令为初级命令。
*/
LIBAPI(int, krnln_GetTickCount)
{
	return GetTickCount();
}
