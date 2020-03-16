#include "stdafx.h"
#include <math.h>
//取时间部分,参数1为只有时间部分的DATE数据
void GetTimePart(DATE dt,INT& nHour,INT& nMinute,INT& nSecond)
{
	INT nSecCount = (INT)DATE( 86400 * fabs(dt)+0.5);//总秒数
	nHour = nSecCount / 3600;
	nSecCount %= 3600;
	nMinute = nSecCount / 60;
	nSecond = nSecCount % 60;
}