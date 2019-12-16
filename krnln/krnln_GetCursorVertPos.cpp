#include "stdafx.h"

//系统处理 - 取鼠标垂直位置
/*
    调用格式： 〈整数型〉 取鼠标垂直位置 （） - 系统核心支持库->系统处理
    英文名称：GetCursorVertPos
    返回鼠标指针的当前垂直位置，单位为像素点，相对于屏幕顶边。本命令为初级命令。
*/
LIBAPI(int, krnln_GetCursorVertPos)
{
	POINT point;
	if(GetCursorPos(&point))
		return point.y;
	return 0;
}
