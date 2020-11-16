#include "stdafx.h"
#include <stdio.h>
#include <math.h>

#include <oleauto.h>
#pragma comment(lib, "OleAut32.lib")

//格式化时间文本
void DateTimeFormat(LPSTR strValue,DATE dtDt,BOOL bOnlyDatePart)
{
	SYSTEMTIME st = {0};
	VariantTimeToSystemTime(dtDt, &st);
	
	char strFormat [128];
	strcpy(strFormat,"%d年%d月%d日");


	//格式化时间部分
	char strFormatTime [128];
	
	if(st.wSecond)
		strcpy(strFormatTime,"%d时%d分%d秒");
	else if(st.wMinute && st.wSecond ==0)
		strcpy(strFormatTime,"%d时%d分");
	else if(st.wHour && st.wMinute==0 && st.wSecond ==0)
		strcpy(strFormatTime,"%d时");
	else
		strFormatTime[0]=0;

	if(bOnlyDatePart==FALSE)
		strcat(strFormat,strFormatTime);

	sprintf(strValue, strFormat, st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);

}