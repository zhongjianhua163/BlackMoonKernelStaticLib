#include "stdafx.h"

//系统处理 - 取屏幕宽度
/*
    调用格式： 〈整数型〉 取屏幕宽度 （） - 系统核心支持库->系统处理
    英文名称：GetScreenWidth
    返回屏幕当前显示区域的宽度，单位为像素点。本命令为初级命令。
*/
LIBAPI(int, krnln_GetScreenWidth)
{
	return GetSystemMetrics(SM_CXSCREEN);
}
