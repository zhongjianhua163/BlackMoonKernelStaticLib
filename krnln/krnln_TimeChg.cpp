#include "stdafx.h"
#include <math.h>
//时间操作 - 增减时间
/*void GetDatePart(DATE dt,INT& nYear,INT& nMonth,INT& nDay)
    调用格式： 〈日期时间型〉 增减时间 （日期时间型 时间，整数型 被增加部分，整数型 增加值） - 系统核心支持库->时间操作
    英文名称：TimeChg
    返回一个时间，这一时间被加上或减去了一段间隔。如果改变后的时间无效，将自动靠近最近的有效时间。本命令为初级命令。
    参数<1>的名称为“时间”，类型为“日期时间型（date）”。
    参数<2>的名称为“被增加部分”，类型为“整数型（int）”。参数值指定增加或减少时间的哪一部分，可以为以下常量：
	1、#年份； 2、#季度； 3、#月份； 4、#周； 5、#日； 6、#小时； 7、#分钟； 8、#秒。
    参数<3>的名称为“增加值”，类型为“整数型（int）”。相对于被增加部分的增加或减少数值。
*/
LIBAPI(void, krnln_TimeChg)
{
	PMDATA_INF pArgInf = &ArgInf;
	switch(pArgInf[1].m_int)
	{
	case 1://#年份
		{
			DATE objDate;
			INT nYear, nMonth, nDay;
			INT nHour, nMinute, nSecond;
			DATE dt = modf(pArgInf[0].m_date,&objDate);
			GetDatePart(objDate,nYear, nMonth, nDay);
			GetTimePart(dt,nHour, nMinute, nSecond);
			nYear+=pArgInf[2].m_int;
			if(nMonth==2 && nDay ==29)
				nDay = GetDaysOfSpecMonth(nYear,2);
			pArgInf[0].m_date =GetSpecDateTime(nYear,nMonth,nDay,nHour, nMinute, nSecond);
			break;
		}
	case 2://#季度
		{
			DATE objDate;
			INT nYear, nMonth, nDay;
			INT nHour, nMinute, nSecond;
			nHour = nMinute = nSecond =0;
			DATE dt = modf(pArgInf[0].m_date,&objDate);
			GetDatePart(objDate,nYear, nMonth, nDay);
			if(dt !=0)
				GetTimePart(dt,nHour, nMinute, nSecond);

			nMonth+=(pArgInf[2].m_int*3);
			if(nMonth>0)
			{
				nYear+=(nMonth/12);
				nMonth %= 12;
			}
			else
			{
				INT decYear = nMonth/12;
				if(nMonth % 12 !=0)
					decYear --;
				nYear+=decYear;
				nMonth = 12 + (nMonth % 12);
			}

			INT nMaxDay = GetDaysOfSpecMonth(nYear,nMonth);
			if(nDay > nMaxDay)
				nDay = nMaxDay;
			pArgInf[0].m_date =GetSpecDateTime(nYear,nMonth,nDay,nHour, nMinute, nSecond);
			break;
		}
	case 3://#月份
		{
			DATE objDate;
			INT nYear, nMonth, nDay;
			INT nHour, nMinute, nSecond;
			nHour = nMinute = nSecond =0;
			DATE dt = modf(pArgInf[0].m_date,&objDate);
			GetDatePart(objDate,nYear, nMonth, nDay);
			if(dt !=0)
				GetTimePart(dt,nHour, nMinute, nSecond);

			nMonth+=pArgInf[2].m_int;
			if(nMonth>0)
			{
				if(nMonth > 12)
					nYear+=(nMonth/12);
				nMonth %= 12;
				if(nMonth ==0)
					nMonth = 12;

			}
			else
			{
				INT decYear = nMonth/12;
				if(nMonth % 12 !=0 || nMonth ==0)
					decYear --;
				nYear+=decYear;
				nMonth = 12 + (nMonth % 12);
			}

			INT nMaxDay = GetDaysOfSpecMonth(nYear,nMonth);
			if(nDay > nMaxDay)
				nDay = nMaxDay;
			pArgInf[0].m_date =GetSpecDateTime(nYear,nMonth,nDay,nHour, nMinute, nSecond);
			break;
		}
	case 4://#周
		{
			DATE objDate;
			DATE dt = modf(toMyDate(pArgInf[0].m_date), &objDate);
			objDate+=(7*pArgInf[2].m_int);
			objDate+=dt;
			pArgInf[0].m_date = toEDate(objDate);
			break;
		}
	case 5://#日
		{
			DATE objDate;
			DATE dt = modf(toMyDate(pArgInf[0].m_date), &objDate);
			objDate+=pArgInf[2].m_int;
			objDate+=dt;
			pArgInf[0].m_date = toEDate(objDate);
			break;
		}
	case 6://#小时
		{

/*			DATE objDate;
			DATE dt = modf(pArgInf[0].m_date,&objDate);
			
			double nSecCount =86400 * fabs(dt);//总秒数
			nSecCount +=(pArgInf[2].m_int*3600);
			INT nDay =  INT(nSecCount / 86400);
			nSecCount = fmod (fabs(nSecCount),86400);
			objDate +=nDay;
			dt = nSecCount/86400;
			double nSgn = objDate < 0 ? -1:1;
			
			pArgInf[0].m_date =(fabs(objDate)+dt)* nSgn;
*/
			pArgInf[0].m_date = toMyDate(pArgInf[0].m_date);
			pArgInf[0].m_date +=double(pArgInf[2].m_int)/24;
			pArgInf[0].m_date = toEDate(pArgInf[0].m_date);
			break;
		}
	case 7://#分钟
		{
/*
			DATE objDate;
			DATE dt = modf(pArgInf[0].m_date,&objDate);

			double nSecCount =86400 * fabs(dt);//总秒数DATE( 86400 * fabs(dt)+0.5);
			nSecCount +=(pArgInf[2].m_int*60);
			INT nDay =  INT(nSecCount / 86400);
			nSecCount = fmod (fabs(nSecCount),86400);
			objDate +=nDay;
			dt = nSecCount/86400;
			double nSgn = objDate < 0 ? -1:1;
			
			pArgInf[0].m_date =(fabs(objDate)+dt)* nSgn;*/
			pArgInf[0].m_date = toMyDate(pArgInf[0].m_date);
			pArgInf[0].m_date +=double(pArgInf[2].m_int)/1440;
			pArgInf[0].m_date = toEDate(pArgInf[0].m_date);
			break;
		}
	case 8://#秒。
		{
/*
			DATE objDate;
			DATE dt = modf(pArgInf[0].m_date,&objDate);

			double nSecCount = 86400 * fabs(dt);//总秒数
			nSecCount +=pArgInf[2].m_int;
			INT nDay =  INT(nSecCount / 86400);
			nSecCount = fmod (fabs(nSecCount),86400);
			objDate +=nDay;
			dt = nSecCount/86400;
			double nSgn = objDate < 0 ? -1:1;
			
			pArgInf[0].m_date =(fabs(objDate)+dt)* nSgn;*/
			pArgInf[0].m_date = toMyDate(pArgInf[0].m_date);
			pArgInf[0].m_date +=double(pArgInf[2].m_int)/86400;
			pArgInf[0].m_date = toEDate(pArgInf[0].m_date);
			break;
		}
	}
	__asm{
		mov eax, ArgInf.m_unit.m_dwFormID;
		mov edx, ArgInf.m_unit.m_dwUnitID;
	}

}
