#include "stdafx.h"
#include <stdio.h>
#include <math.h>

//格式化时间文本
void DateTimeFormat(LPSTR strValue,DATE dtDt,BOOL bOnlyDatePart)
{
	DATE dd,dt;
	INT nYear, nMonth, nDay, nHour, nMinute, nSecond;
	dt = modf(dtDt,&dd);


	GetTimePart(dt,nHour,nMinute,nSecond);
	GetDatePart(dd,nYear,nMonth,nDay);


	char strFormat [128];
	strcpy(strFormat,"%d年%d月%d日");


	//格式化时间部分
	char strFormatTime [128];
	
	if(nSecond)
		strcpy(strFormatTime,"%d时%d分%d秒");
	else if(nMinute && nSecond ==0)
		strcpy(strFormatTime,"%d时%d分");
	else if(nHour && nMinute==0 && nSecond ==0)
		strcpy(strFormatTime,"%d时");
	else
		strFormatTime[0]=0;

	if(bOnlyDatePart==FALSE)
		strcat(strFormat,strFormatTime);

	sprintf(strValue,strFormat,nYear, nMonth, nDay, nHour, nMinute, nSecond);

}