#include "stdafx.h"

//系统处理 - 取最后错误
/*
    调用格式： 〈整数型〉 取最后错误 （） - 系统核心支持库->系统处理
    英文名称：GetLastError
    调用操作系统的GetLastError函数,返回该API函数被调用后的返回值.本命令为初级命令。
	
	操作系统需求： Windows
*/
LIBAPI(INT, krnln_GetLastError)
{
	return GetLastError();
}