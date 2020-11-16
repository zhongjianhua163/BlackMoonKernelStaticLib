#include "stdafx.h"
#include <math.h>
#include <oleauto.h>
#pragma comment(lib, "OleAut32.lib")

INT GetWeekDay(DATE date)
{
	SYSTEMTIME st = {0};
	VariantTimeToSystemTime(date, &st);
	return st.wDayOfWeek + 1;
	/*
	DATE dt,dd;
	dt = modf(date,&dd);
	INT nRet = (INT)fmod(dd,7);
	if(nRet <= 0)
		nRet += 7;
	return nRet;
	*/
}