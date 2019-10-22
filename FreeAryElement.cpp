#include "stdafx.h"



void FreeAryElement (void* pAryData)//对于文本和字节集数组有效
{
	DWORD AryElementCount = 0;
	LPINT* pArryPtr = (LPINT*)GetAryElementInf(pAryData ,AryElementCount);

	for(INT i=0;i < (INT)AryElementCount;i++)
	{
		void* pElementData = *pArryPtr;
		if(pElementData)
		{
			E_MFree(pElementData);
			*pArryPtr = NULL;
		}
		pArryPtr++;
	}

	E_MFree(pAryData);
}