#include "stdafx.h"
#pragma comment(lib,"gdi32.lib") 
//系统处理 - 取颜色数
/*
    调用格式： 〈整数型〉 取颜色数 （） - 系统核心支持库->系统处理
    英文名称：GetColorCount
    返回当前显示方式所提供的最大颜色显示数目。本命令为初级命令。
*/
LIBAPI(int, krnln_GetColorCount)
{
	HDC hdc = ::GetDC(NULL);
	INT nRet = GetDeviceCaps(hdc,COLORRES);
	::ReleaseDC (NULL,hdc);
	return (1 << nRet);
}
