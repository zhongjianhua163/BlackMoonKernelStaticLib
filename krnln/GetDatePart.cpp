#include "stdafx.h"
#include <math.h>
#include <stdio.h>
#include <oleauto.h>
#pragma comment(lib, "OleAut32.lib")

//取日期部分,参数1为只有日期部分的DATE数据
//1899年12月30日0时00分00秒 为0基准,单位为天数的小数值

void GetDatePart(DATE dt,INT& nYear,INT& nMonth,INT& nDay)
{
	SYSTEMTIME st = {0};
	VariantTimeToSystemTime(dt, &st);
	nYear = (INT)st.wYear;
	nMonth = (INT)st.wMonth;
	nDay = (INT)st.wDay;
	/*
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
		*/
}

//将两个小数整合到一起，a为整数部分,b为小数部分,符号以a为准
//请确保a只有整数，b只有小数
double makedb(double a, double b)
{
	if (((*(INT64*)&a)&0x8000000000000000) == ((*(INT64*)&b)&0x8000000000000000))
	{//符号相同直接加
		return a+b;
	}
	//符号不同则相减
	return a-b;
}

DATE toMyDate(DATE dt)
{
	if (dt > -1.0e-7) return dt; //大于等于0

	DATE dtZS;
	DATE dtXS = modf(dt, &dtZS);
	return dtZS + fabs(dtXS);
}

DATE toEDate(DATE dt)
{
	if (dt > -1.0e-7) return dt; //大于等于0

	DATE dtZS;
	DATE dtXS = modf(dt, &dtZS);
	if (fabs(dtXS) < 1.0e-7) { //小数部分为0
		return dtZS;//直接返回整数部分
	}
	dtZS -= 2.0;
	return dtZS - dtXS;
}