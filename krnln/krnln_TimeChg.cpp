#include "stdafx.h"
#include <math.h>

#include <oleauto.h>
#pragma comment(lib, "OleAut32.lib")

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

	SYSTEMTIME st = {0};
	VariantTimeToSystemTime(pArgInf[0].m_date, &st);

	switch(pArgInf[1].m_int)
	{
	case 1://#年份
		{
			st.wYear += pArgInf[2].m_int;
			if(st.wMonth == 2 && st.wDay == 29)
				st.wDay = GetDaysOfSpecMonth(st.wYear, 2);

			SystemTimeToVariantTime(&st, &pArgInf[0].m_date);
			break;
		}
	case 2://#季度
		{
			INT nMonth;
			nMonth = st.wMonth + (pArgInf[2].m_int * 3);
			if(nMonth>0)
			{
				st.wYear += (nMonth / 12);
				nMonth %= 12;
			}
			else
			{
				INT decYear = nMonth / 12;
				if(nMonth % 12 != 0)
					decYear--;
				st.wYear += decYear;
				nMonth = 12 + (nMonth % 12);
			}
			st.wMonth = nMonth;

			INT nMaxDay = GetDaysOfSpecMonth(st.wYear, nMonth);
			if(st.wDay > nMaxDay)
				st.wDay = nMaxDay;

			SystemTimeToVariantTime(&st, &pArgInf[0].m_date);
			break;
		}
	case 3://#月份
		{
			INT nMonth;

			nMonth = st.wMonth + pArgInf[2].m_int;
			if(nMonth > 0)
			{
				if(nMonth > 12)
					st.wYear += (nMonth / 12);
				nMonth %= 12;
				if(nMonth == 0)
					nMonth = 12;

			}
			else
			{
				INT decYear = nMonth / 12;
				if(nMonth % 12 !=0 || nMonth ==0)
					decYear--;
				st.wYear += decYear;
				nMonth = 12 + (nMonth % 12);
			}
			st.wMonth = nMonth;

			INT nMaxDay = GetDaysOfSpecMonth(st.wYear, nMonth);
			if(st.wDay > nMaxDay)
				st.wDay = nMaxDay;
			
			SystemTimeToVariantTime(&st, &pArgInf[0].m_date);
			break;
		}
	case 4://#周
		{
			DATE objDate;
			DATE dt = modf(pArgInf[0].m_date, &objDate);
			objDate += (7 * pArgInf[2].m_int);
			pArgInf[0].m_date = makedb(objDate, dt);
			break;
		}
	case 5://#日
		{
			DATE objDate;
			DATE dt = modf(pArgInf[0].m_date, &objDate);
			objDate += pArgInf[2].m_int;
			pArgInf[0].m_date = makedb(objDate, dt);
			break;
		}
	case 6://#小时
		{
			SystemTimeToVariantTime(&st, &pArgInf[0].m_date); //防止多次运算后，时间精度越来越低
			pArgInf[0].m_date = toMyDate(pArgInf[0].m_date);
			pArgInf[0].m_date += double(pArgInf[2].m_int) / 24.0;
			pArgInf[0].m_date = toEDate(pArgInf[0].m_date);
			break;
		}
	case 7://#分钟
		{
			SystemTimeToVariantTime(&st, &pArgInf[0].m_date); //防止多次运算后，时间精度越来越低
			pArgInf[0].m_date = toMyDate(pArgInf[0].m_date);
			pArgInf[0].m_date += double(pArgInf[2].m_int) / 1440.0;
			pArgInf[0].m_date = toEDate(pArgInf[0].m_date);
			break;
		}
	case 8://#秒。
		{
			SystemTimeToVariantTime(&st, &pArgInf[0].m_date); //防止多次运算后，时间精度越来越低
			pArgInf[0].m_date = toMyDate(pArgInf[0].m_date);
			pArgInf[0].m_date += double(pArgInf[2].m_int) / 86400.0;
			pArgInf[0].m_date = toEDate(pArgInf[0].m_date);
			break;
		}
	}
	__asm{
		mov eax, ArgInf.m_unit.m_dwFormID;
		mov edx, ArgInf.m_unit.m_dwUnitID;
	}

}
