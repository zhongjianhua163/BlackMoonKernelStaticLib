#include "StdAfx.h"

// 使用指定数据建立易程序中使用的字节集数据。
LPBYTE CloneBinData (LPBYTE pData, INT nDataSize)
{
	if (nDataSize == 0)
		return NULL;
	
	LPBYTE pd = (LPBYTE)E_MAlloc_Nzero ((DWORD)(sizeof (INT) * 2 + nDataSize));
	*(LPINT)pd = 1;
	*(LPINT)(pd + sizeof (INT)) = nDataSize;
	memcpy (pd + sizeof (INT) * 2, pData, nDataSize);
	return pd;
}