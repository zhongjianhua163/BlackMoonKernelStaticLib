#include "stdafx.h"
#pragma comment(lib,"winmm.lib") 

//媒体播放 - 播放音乐
/*
    调用格式： 〈逻辑型〉 播放音乐 （通用型 欲播放的音乐，［逻辑型 是否循环播放］） - 系统核心支持库->媒体播放
    英文名称：PlayMusic
    可以播放 .WAV、.MID 声音文件或相应格式的字节集声音数据、声音资源。成功返回真，失败返回假。本命令为初级命令。
    参数<1>的名称为“欲播放的音乐”，类型为“通用型（all）”。参数值可以为 .WAV、.MID 声音文件名称或相应格式的字节集声音数据、声音资源。
    参数<2>的名称为“是否循环播放”，类型为“逻辑型（bool）”，可以被省略。为真表示指定音乐将被循环播放，否则仅只播放一次。如果本参数被省略，默认为仅播放一次。
*/
extern HANDLE hBlackMoonInstanceHandle;

LIBAPI(BOOL, krnln_PlayMusic)
{
	DWORD dwSound = SND_ASYNC|SND_NODEFAULT;
	LPCSTR pszMusicData;
	HMODULE hmod = NULL;
	if(ArgInf.m_dtDataType == SDT_TEXT)
	{
		dwSound |= SND_FILENAME;
		pszMusicData = ArgInf.m_pText;

	}else if(ArgInf.m_dtDataType == SDT_BIN)
	{
		dwSound |= SND_MEMORY;

		pszMusicData = ArgInf.m_pText + 2*sizeof(INT);

	}else if(ArgInf.m_dtDataType == SDT_INT || ArgInf.m_dtDataType == SDT_BYTE || ArgInf.m_dtDataType == SDT_SHORT)
	{
		dwSound |=SND_RESOURCE;
		pszMusicData = MAKEINTRESOURCE(ArgInf.m_int);
		if(hBlackMoonInstanceHandle)
			hmod = (HMODULE)hBlackMoonInstanceHandle;
		else
			hmod = ::GetModuleHandle(NULL);
			

	}else
		return FALSE;

	PMDATA_INF pArgInf = &ArgInf;
	if(pArgInf[1].m_dtDataType != _SDT_NULL && pArgInf[1].m_bool)
		dwSound |= SND_LOOP;

	return PlaySound(pszMusicData,hmod,dwSound);
}
