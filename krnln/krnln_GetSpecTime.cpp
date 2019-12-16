#include "stdafx.h"

//时间操作 - 指定时间
/*
    调用格式： 〈日期时间型〉 指定时间 （整数型 年，［整数型 月］，［整数型 日］，［整数型 小时］，［整数型 分钟］，［整数型 秒］） - 系统核心支持库->时间操作
    英文名称：GetSpecTime
    返回包含指定年、月、日、小时、分、秒的时间。如果指定了无效时间，将自动使用最相近的有效时间代替。本命令为初级命令。
    参数<1>的名称为“年”，类型为“整数型（int）”。
    参数<2>的名称为“月”，类型为“整数型（int）”，可以被省略。如果本参数被省略，默认为 1 月。
    参数<3>的名称为“日”，类型为“整数型（int）”，可以被省略。如果本参数被省略，默认为 1 日。
    参数<4>的名称为“小时”，类型为“整数型（int）”，可以被省略。如果本参数被省略，默认为 0 时。
    参数<5>的名称为“分钟”，类型为“整数型（int）”，可以被省略。如果本参数被省略，默认为 0 分钟。
    参数<6>的名称为“秒”，类型为“整数型（int）”，可以被省略。如果本参数被省略，默认为 0 秒。
*/
LIBAPI(void, krnln_GetSpecTime) // 直接修改了eax和eax,所以不需要指定返回值类型
{
	PMDATA_INF pArgInf = &ArgInf;	
	INT nYear, nMonth, nDay;
	INT nHour, nMinute, nSecond;
	nYear = pArgInf[0].m_int;
	if(nYear < 100) nYear =100;

	if(pArgInf[1].m_dtDataType ==_SDT_NULL)
		nMonth = 1;
	else
	{
		nMonth = pArgInf[1].m_int;
		if(nMonth < 1)
			nMonth =1;
		else if (nMonth > 12)
			nMonth =12;
	}

	if(pArgInf[2].m_dtDataType ==_SDT_NULL)
		nDay = 1;
	else
	{
		nDay = pArgInf[2].m_int;
		if(nDay < 1)
			nDay = 1;
		else
		{
			INT nMaxDay = GetDaysOfSpecMonth(nYear,nMonth);
			if(nDay > nMaxDay)
				nDay = nMaxDay;
		}
	}

	nHour = pArgInf[3].m_int;
	if(nHour < 0)
		nHour = 0;
	else if (nHour > 23)
		nHour = 23;

	nMinute = pArgInf[4].m_int;
	if(nMinute < 0)
		nMinute = 0;
	else if (nMinute > 59)
		nMinute = 59;

	nSecond = pArgInf[5].m_int;
	if(nSecond < 0)
		nSecond = 0;
	else if (nSecond > 59)
		nSecond = 59;

	ArgInf.m_double = GetSpecDateTime(nYear, nMonth, nDay, nHour, nMinute, nSecond);
	__asm{
		mov eax, ArgInf.m_unit.m_dwFormID;
		mov edx, ArgInf.m_unit.m_dwUnitID;
	}
}
