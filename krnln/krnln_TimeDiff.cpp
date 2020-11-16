#include "stdafx.h"
#include <math.h>

//时间操作 - 取时间间隔
/*
    调用格式： 〈双精度小数型〉 取时间间隔 （日期时间型 时间1，日期时间型 时间2，整数型 取间隔部分） - 系统核心支持库->时间操作
    英文名称：TimeDiff
    返回一个数值，表示“时间1”减去“时间2”之后的间隔数目。注意：每个星期以星期天为第一天。本命令为初级命令。
    参数<1>的名称为“时间1”，类型为“日期时间型（date）”。
    参数<2>的名称为“时间2”，类型为“日期时间型（date）”。
    参数<3>的名称为“取间隔部分”，类型为“整数型（int）”。参数值指定取时间间隔的单位，可以为以下常量： 1、#年份； 2、#季度； 3、#月份； 4、#周； 5、#日； 6、#小时； 7、#分钟； 8、#秒。
*/

//距离起始日期多少周
//起始日期 1899年12月30日 数值为0, 为该周最后一天(星期六)
//-13到-7 是第-1周
//-6到0 是第0周
//1到7 是第1周
double GetWeekDayNum(DATE dt)
{
	INT nRet;
	if ((INT)dt > 0) {
		nRet = ((INT)dt + 6) / 7;
	}
	else {
		nRet = (INT)dt / 7;
	}
	return (double)nRet;
}

LIBAPI(void, krnln_TimeDiff)
{
	PMDATA_INF pArgInf = &ArgInf;
	
	switch(pArgInf[2].m_int)
	{
	case 1://#年份
		{
			INT nYear, nMonth, nDay;
			INT nYear1, nMonth1, nDay1;
			GetDatePart(pArgInf[0].m_date, nYear, nMonth, nDay);
			GetDatePart(pArgInf[1].m_date, nYear1, nMonth1, nDay1);
			pArgInf[0].m_date = nYear - nYear1;
			break;
		}
	case 2://#季度
		{
			INT nYear, nMonth, nDay;
			INT nYear1, nMonth1, nDay1;
			GetDatePart(pArgInf[0].m_date, nYear, nMonth, nDay);
			GetDatePart(pArgInf[1].m_date, nYear1, nMonth1, nDay1);
			pArgInf[0].m_date = (nYear - nYear1) * 4 + ((nMonth - 1) / 3) - ((nMonth1 - 1) / 3);
			break;
		}
	case 3://#月份
		{
			INT nYear, nMonth, nDay;
			INT nYear1, nMonth1, nDay1;
			GetDatePart(pArgInf[0].m_date, nYear, nMonth, nDay);
			GetDatePart(pArgInf[1].m_date, nYear1, nMonth1, nDay1);
			pArgInf[0].m_date = (nYear - nYear1) * 12 - nMonth1 + nMonth;
 			break;
		}
	case 4://#周
		{
			DATE objDate, objDate1;
			DATE dt = modf(pArgInf[0].m_date, &objDate);
			dt = modf(pArgInf[1].m_date, &objDate1);

			pArgInf[0].m_date = GetWeekDayNum(objDate) - GetWeekDayNum(objDate1);
			break;
		}
	case 5://#日
		{
			DATE objDate = toMyDate(pArgInf[0].m_date) - toMyDate(pArgInf[1].m_date);
			pArgInf[0].m_date = objDate;
			break;
		}
	case 6://#小时
		{
			DATE objDate = toMyDate(pArgInf[0].m_date) - toMyDate(pArgInf[1].m_date);
			modf(objDate * 24.0 + 0.000005787037037037037, &pArgInf[0].m_date);
			break;
		}
	case 7://#分钟
		{
			DATE objDate = toMyDate(pArgInf[0].m_date) - toMyDate(pArgInf[1].m_date);
			modf(objDate * 1440.0 + 0.000005787037037037037, &pArgInf[0].m_date);
			break;
		}
	case 8://#秒。
		{
			DATE objDate = toMyDate(pArgInf[0].m_date) - toMyDate(pArgInf[1].m_date);
			modf(objDate * 86400.0 + 0.000005787037037037037, &pArgInf[0].m_date);
			break;
		}
	default:
		pArgInf[0].m_double = 0;

	}
	__asm{
		mov eax, ArgInf.m_unit.m_dwFormID;
		mov edx, ArgInf.m_unit.m_dwUnitID;
	}

}
