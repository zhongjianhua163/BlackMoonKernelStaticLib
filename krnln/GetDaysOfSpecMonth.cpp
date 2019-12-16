#include "stdafx.h"

INT GetDaysOfSpecMonth(INT nYear,INT nMonth)
{
	DWORD nMonDay [12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if((nYear % 400==0) || (nYear % 100 != 0) && (nYear %4 ==0))//ÈòÄê
		nMonDay [1] = 29; //¶şÔÂ
	return nMonDay [nMonth-1];
}