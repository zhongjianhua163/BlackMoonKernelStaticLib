#include "stdafx.h"
#include <math.h>
//时间操作 - 取时间部分
/*
    调用格式： 〈整数型〉 取时间部分 （日期时间型 欲取其部分的时间，整数型 欲取的时间部分） - 系统核心支持库->时间操作
    英文名称：TimePart
    返回一个包含已知时间指定部分的整数。本命令为初级命令。
    参数<1>的名称为“欲取其部分的时间”，类型为“日期时间型（date）”。
    参数<2>的名称为“欲取的时间部分”，类型为“整数型（int）”。参数值可以为以下常量：
	1、#年份； 2、#季度； 3、#月份； 4、#自年首周数； 5、#日； 6、#小时； 7、#分钟； 8、#秒； 9、#星期几； 10、#自年首天数。其中：自年首周数、自年首天数均从 1 开始。
*/
INT GetDaysFromYear(DATE date)
{
	DATE objDate;
	INT nYear, nMonth, nDay;
	DATE dt = modf(date,&objDate);
	GetDatePart(objDate,nYear, nMonth, nDay);
	INT nCountDay = nDay;
	for(INT i=1;i< nMonth;i++)
		nCountDay += GetDaysOfSpecMonth(nYear,i);
	return nCountDay;
}

LIBAPI(int, krnln_TimePart)
{
	PMDATA_INF pArgInf = &ArgInf;
	INT nRet = 0;
	switch(pArgInf[1].m_int)
	{
	case 1://#年份
		{
			DATE objDate;
			INT nYear, nMonth, nDay;
			DATE dt = modf(pArgInf[0].m_date,&objDate);
			GetDatePart(objDate,nYear, nMonth, nDay);
			nRet = nYear;
			break;
		}
	case 2://#季度
		{
			DATE objDate;
			INT nYear, nMonth, nDay;
			DATE dt = modf(pArgInf[0].m_date,&objDate);
			GetDatePart(objDate,nYear, nMonth, nDay);
			nRet = nMonth/3;
			if(nMonth % 3)nRet++;
			break;
		}
	case 3://#月份
		{
			DATE objDate;
			INT nYear, nMonth, nDay;
			DATE dt = modf(pArgInf[0].m_date,&objDate);
			GetDatePart(objDate,nYear, nMonth, nDay);
			nRet = nMonth;
			break;
		}
	case 4://#自年首周数
		{
			INT nCountDay = GetDaysFromYear(pArgInf[0].m_date);
			nRet = nCountDay/7;
			if(nCountDay % 7)nRet++;
			break;
		}
	case 5://#日
		{
			DATE objDate;
			INT nYear, nMonth, nDay;
			DATE dt = modf(pArgInf[0].m_date,&objDate);
			GetDatePart(objDate,nYear, nMonth, nDay);
			nRet = nDay;
			break;
		}
	case 6://#小时
		{

			DATE objDate;
			DATE dt = modf(pArgInf[0].m_date,&objDate);
			INT nHour, nMinute, nSecond;
			GetTimePart(dt,nHour, nMinute, nSecond);
			nRet = nHour;

			break;
		}
	case 7://#分钟
		{
			DATE objDate;
			DATE dt = modf(pArgInf[0].m_date,&objDate);
			INT nHour, nMinute, nSecond;
			GetTimePart(dt,nHour, nMinute, nSecond);
			nRet = nMinute;

			break;
		}
	case 8://#秒。
		{
			DATE objDate;
			DATE dt = modf(pArgInf[0].m_date,&objDate);
			INT nHour, nMinute, nSecond;
			GetTimePart(dt,nHour, nMinute, nSecond);
			nRet = nSecond;

			break;
		}
	case 9://#星期几
		{
			nRet = GetWeekDay(pArgInf[0].m_date);

			break;
		}
	case 10://#自年首天数
		{
			nRet = GetDaysFromYear(pArgInf[0].m_date);
			break;
		}
	}
	return nRet ;
}
