#include "stdafx.h"

//系统处理 - 置等待鼠标
/*
    调用格式： 〈无返回值〉 置等待鼠标 （） - 系统核心支持库->系统处理
    英文名称：SetWaitCursor
    本命令设置现行鼠标的形状为沙漏形，用作在即将长时间执行程序前提示操作者。本命令为初级命令。
*/
extern HCURSOR hCurOld;

LIBAPI(void, krnln_SetWaitCursor)
{
	if(hCurOld==NULL)
	{
		HCURSOR hCur =  LoadCursor(NULL,IDC_WAIT);
		hCurOld = SetCursor(hCur);
	}
}
