#include "stdafx.h"

void* GetAryElementInf(void* pAryData ,DWORD& AryElementCount)
{
    LPINT pnData;
    INT nArys;
    UINT nElementCount;
    
    pnData = (LPINT)pAryData;
    
    nArys=*pnData; //取得维数。
    pnData +=1;

     // 计算成员数目。
    nElementCount = 1;
    while (nArys > 0)
	{
        nElementCount *= pnData[0];
        pnData ++;
        nArys--;
    }

    AryElementCount = nElementCount;
    return pnData;
}