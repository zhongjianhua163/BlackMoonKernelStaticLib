#include "stdafx.h"

//系统处理 - 鸣叫
/*
    调用格式： 〈无返回值〉 鸣叫 （） - 系统核心支持库->系统处理
    英文名称：beep
    通过计算机媒体设备或者喇叭发出一个声音。本命令为初级命令。
*/
LIBAPI(void, krnln_beep)
{
	::MessageBeep(0xffffffff);
}
