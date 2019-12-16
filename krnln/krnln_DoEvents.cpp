#include "stdafx.h"

//其他 - 处理事件
/*
    调用格式： 〈无返回值〉 处理事件 （） - 系统核心支持库->其他
    英文名称：DoEvents
    暂时转让控制权，以便让 Windows 操作系统有机会处理其它的如用户键盘或鼠标输入等事件。直到操作系统处理并发送完程序队列中的所有事件后，命令才会返回。本命令为中级命令。
*/
LIBAPI(void, krnln_DoEvents)
{
	MSG Msg;
	while(PeekMessage(&Msg,NULL,NULL,NULL,PM_NOREMOVE))
	{
		if(Msg.message == WM_QUIT)
			break;
		GetMessage (&Msg, NULL, 0, 0);
		TranslateMessage (&Msg);
		DispatchMessage (&Msg);
	}
}
