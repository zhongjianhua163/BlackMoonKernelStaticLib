#include "stdafx.h"
#include <math.h>

INT GetWeekDay(DATE date)
{
	DATE dt,dd;
	dt = modf(date,&dd);
	INT nRet = (INT)fmod(dd,7);
	if(nRet <= 0)
		nRet += 7;
	return nRet;
}