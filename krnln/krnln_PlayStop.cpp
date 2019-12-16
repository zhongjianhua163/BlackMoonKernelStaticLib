#include "stdafx.h"
#pragma comment(lib,"winmm.lib") 
//媒体播放 - 停止播放
/*
    调用格式： 〈无返回值〉 停止播放 （） - 系统核心支持库->媒体播放
    英文名称：PlayStop
    停止正在播放的音乐。本命令为初级命令。
*/
LIBAPI(void, krnln_PlayStop)
{
	PlaySound(NULL,NULL,SND_PURGE);
}
