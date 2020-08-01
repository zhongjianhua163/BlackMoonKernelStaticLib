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
double GetWeekDayNum(DATE dt)
{
	double nRet;
	INT nSgn = dt > 0 ? 1:-1;
	//dt--;
	nRet = dt / 7;
	if(nRet !=0 && modf(nRet,&nRet) !=0)
		nRet +=nSgn;
	return nRet;
}

LIBAPI(void, krnln_TimeDiff)
{
	PMDATA_INF pArgInf = &ArgInf;
	
	switch(pArgInf[2].m_int)
	{
	case 1://#年份
		{
			DATE objDate;
			INT nYear, nMonth, nDay;
			INT nYear1, nMonth1, nDay1;
			DATE dt = modf(pArgInf[0].m_date,&objDate);
			GetDatePart(objDate,nYear, nMonth, nDay);
			dt = modf(pArgInf[1].m_date,&objDate);
			GetDatePart(objDate,nYear1, nMonth1, nDay1);
			pArgInf[0].m_date = nYear - nYear1;
			break;
		}
	case 2://#季度
		{
			DATE objDate;
			INT nYear, nMonth, nDay;
			INT nYear1, nMonth1, nDay1;
			DATE dt = modf(pArgInf[0].m_date,&objDate);
			GetDatePart(objDate,nYear, nMonth, nDay);
			dt = modf(pArgInf[1].m_date,&objDate);
			GetDatePart(objDate,nYear1, nMonth1, nDay1);

			objDate = (nYear*12+nMonth) - (nYear1*12+nMonth1);
			objDate = objDate / 3;
			dt = modf(objDate,&pArgInf[0].m_date);
			if(dt !=0)
				pArgInf[0].m_date ++;
			break;
		}
	case 3://#月份
		{
			DATE objDate;
			INT nYear, nMonth, nDay;
			INT nYear1, nMonth1, nDay1;
			DATE dt = modf(pArgInf[0].m_date,&objDate);
			GetDatePart(objDate,nYear, nMonth, nDay);
			dt = modf(pArgInf[1].m_date,&objDate);
			GetDatePart(objDate,nYear1, nMonth1, nDay1);

			pArgInf[0].m_date = (nYear*12+nMonth) - (nYear1*12+nMonth1);
			break;
		}
	case 4://#周
		{
			DATE objDate, objDate1;
			DATE dt = modf(toMyDate(pArgInf[0].m_date), &objDate);
			dt = modf(toMyDate(pArgInf[1].m_date), &objDate1);

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
			double nSecCount = 86400 * objDate;//总秒数
			objDate = nSecCount / 3600; //换算成小时
			//pArgInf[0].m_date = objDate;
			modf(objDate, &pArgInf[0].m_date);
			break;
		}
	case 7://#分钟
		{
			DATE objDate = toMyDate(pArgInf[0].m_date) - toMyDate(pArgInf[1].m_date);
			double nSecCount = 86400 * objDate;//总秒数
			objDate = nSecCount / 60; //换算成分钟
			//pArgInf[0].m_date =objDate;
			modf(objDate, &pArgInf[0].m_date);
			break;
		}
	case 8://#秒。
		{
			DATE objDate = toMyDate(pArgInf[0].m_date) - toMyDate(pArgInf[1].m_date);
			double nSecCount = 86400 * objDate;//总秒数
			//pArgInf[0].m_date = nSecCount;
			modf(nSecCount, &pArgInf[0].m_date);
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
