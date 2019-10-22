#include "stdafx.h"

//系统处理 - 取鼠标水平位置
/*
    调用格式： 〈整数型〉 取鼠标水平位置 （） - 系统核心支持库->系统处理
    英文名称：GetCursorHorzPos
    返回鼠标指针的当前水平位置，单位为像素点，相对于屏幕左边。本命令为初级命令。
*/
LIBAPI(int, krnln_GetCursorHorzPos)
{
	POINT point;
	if(GetCursorPos(&point))
		return point.x;
	return 0;
}
