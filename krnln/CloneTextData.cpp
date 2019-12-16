#include "StdAfx.h"
#include "Myfunctions.h"

// 使用指定文本数据建立易程序中使用的文本数据。
//   nTextLen用作指定文本部分的长度（不包含结束零），
// 如果为-1，则取ps的全部长度。
char* CloneTextData (char* ps, INT nTextLen)
{
	if (nTextLen <= 0)
		return NULL;
	
	char* pd = (char*)E_MAlloc_Nzero ((DWORD)(nTextLen + 1));
	memcpy (pd, ps, nTextLen);
	pd [nTextLen] = '\0';
	return pd;
}
// 使用指定文本数据建立易程序中使用的文本数据。
char* CloneTextData (char* ps)
{
    if (ps == NULL || *ps == '\0')
        return NULL;

    INT nTextLen = mystrlen (ps);
    char* pd = (char*)E_MAlloc_Nzero ((DWORD)(nTextLen + 1));
    memcpy (pd, ps, nTextLen);
    pd [nTextLen] = '\0';
    return pd;
}