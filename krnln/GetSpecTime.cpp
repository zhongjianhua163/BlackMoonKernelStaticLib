#include "stdafx.h"
#include <math.h>

#include <oleauto.h>
#pragma comment(lib, "OleAut32.lib")

//取指定时间 参数时间值都是正确的
//1899年12月30日0时00分00秒 为0基准,单位为天数的小数值
double GetSpecDateTime(INT nYear, INT nMonth, INT nDay, INT nHour,INT nMinute,INT nSecond)
{
	double dDate = 0;
	SYSTEMTIME st = {0};
	st.wYear = (WORD)nYear;
	st.wMonth = (WORD)nMonth;
	st.wDay = (WORD)nDay;
	st.wHour = (WORD)nHour;
	st.wMinute = (WORD)nMinute;
	st.wSecond = (WORD)nSecond;
	SystemTimeToVariantTime(&st, &dDate);
	return dDate;
	/*
	double nSecCount = nHour * 3600;//总秒数
	nSecCount+=(nMinute*60);
	nSecCount+=nSecond;
	double dTime = nSecCount/86400;
	double dDate = 0;
	INT nStep;

	
	if(nYear==1899)
	{
		if(nMonth==12)
		{
			if(nDay >= 30)
			{
				dDate = nDay - 30;
				return (dDate + dTime); 
			}

		}

		nStep = -1;
	}
	else if (nYear > 1899)
	{
		nStep = 1;

	}else
		nStep = -1;

	

	INT nStatrYear;
	INT nYearDay;
	INT nCountDay = 0;
	if(nStep==1)
		nStatrYear = 1900;//到1900年1月1日为基准
	else
		nStatrYear = 1899;

		

	while(1)
	{

		if(nStatrYear==nYear)
		{
			DWORD nMonDay [12] = {31,28,31,30,31,30,31,31,30,31,30,31};
			if((nYear % 400==0) || (nYear % 100 != 0) && (nYear %4 ==0))//闰年
				nMonDay [1] = 29; //二月
			if(nStep==1)
			{
				for(INT i=0;i <12;i++)
				{
					if(i == nMonth - 1)
					{
						nCountDay += nDay;
						break;
					}
					nCountDay += nMonDay[i];
				}
			}else{

				for(INT i = 11;i >=0;i--)
				{
					if(i == nMonth - 1)
					{
						nCountDay += (nMonDay[i]-nDay);

						break;
					}
					nCountDay += nMonDay[i];
				}

			}
			break;

		}
		nYearDay = 365;
		if((nStatrYear % 400==0) || (nStatrYear % 100 !=0) && (nStatrYear %4 ==0))//闰年
			nYearDay ++;
		nCountDay += nYearDay;
		nStatrYear+=nStep;

	}

	if(nStep==1)
	{
		dDate = nCountDay + 1;
		return (dDate + dTime); 
	}


	dDate = -(nCountDay - 1 + dTime);
	return dDate; 
	
	*/
}
