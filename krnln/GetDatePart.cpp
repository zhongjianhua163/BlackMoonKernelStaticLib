#include "stdafx.h"
#include <math.h>
#include <stdio.h>
//取日期部分,参数1为只有日期部分的DATE数据
//1899年12月30日0时00分00秒 为0基准,单位为天数的小数值

void GetDatePart(DATE dt,INT& nYear,INT& nMonth,INT& nDay)
{
	if(dt==0 || dt==1)
	{
		nYear = 1899;
		nMonth = 12;
		nDay = 30 + (INT)dt;
		return;
	}
	INT nCountDay;
	INT nStatrYear;
	INT nYearDay;
	INT nStep;
	if(dt>0)
	{
		nCountDay = (INT)(dt-1);//到1900年1月1日为基准
		nStatrYear = 1900;
		nStep=1;
	}
	else
	{
		nCountDay = (INT)fabs(dt-1);//到1899年12月31日为基准
		nStatrYear = 1899;
		nStep = -1;
	}

	while(1)
	{
		nYearDay = 365;
		if((nStatrYear % 400==0) || (nStatrYear % 100 !=0) && (nStatrYear %4 ==0))//闰年
			nYearDay ++;
		if(nCountDay <= nYearDay)//在这年的范围内
		{
			nYear = nStatrYear;
			if(nStep==-1)
			{
				nCountDay = nYearDay - nCountDay;
			}

			break;
		}
		nCountDay -=nYearDay;
		nStatrYear +=nStep;
	}
	DWORD nMonDay [12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if((nYear % 400==0) || (nYear % 100 != 0) && (nYear %4 ==0))//闰年
		nMonDay [1] = 29; //二月

	for(INT i=0;i <12;i++)
	{
		if(nCountDay <= (INT)(nMonDay[i]))
		{
			nMonth = i+1;
			nDay = nCountDay;
			break;
		}
		nCountDay-=nMonDay[i];

	}
		
}

