#include "stdafx.h"
#include <stdio.h>
#include "LTrimZeroChr.h"
#include "Myfunctions.h"
char* SDataToStr (PMDATA_INF pArgInf)
{
	char* pSrc = NULL;
	char str [MAX_PATH];
	if((pArgInf->m_dtDataType & DT_IS_ARY) == 0)//非数组
	{
		
		
		switch(pArgInf->m_dtDataType)
		{
		case SDT_BYTE:
		case SDT_SHORT:
		case SDT_INT:
		case SDT_SUB_PTR:
			sprintf(str,"%d",pArgInf->m_int);
			pSrc = str;
			break;
		case SDT_INT64:
			sprintf(str,"%I64d",pArgInf->m_int64);
			pSrc = str;
			break;
		case SDT_FLOAT:
			sprintf(str,"%f",pArgInf->m_float);
			LTrimZeroChr(str);
			pSrc = str;
			break;
		case SDT_DOUBLE:
			sprintf(str,"%lf",pArgInf->m_double);
			LTrimZeroChr(str);
			pSrc = str;
			break;
		case SDT_BOOL:
			if(pArgInf->m_bool)
				strcpy(str,"真");
			else
				strcpy(str,"假");
			pSrc = str;
			break;

		case SDT_DATE_TIME:
			DateTimeFormat(str,pArgInf->m_double);
			pSrc = str;
			break;
		}
		if(pSrc)
		{
			INT nLen = mystrlen(str);
			pSrc = (LPSTR)malloc(nLen+1);
			strcpy(pSrc,str);
		}
	}
	return pSrc;
}