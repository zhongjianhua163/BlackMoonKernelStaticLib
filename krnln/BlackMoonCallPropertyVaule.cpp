#include "stdafx.h"
#include "Myfunctions.h"
EXTERN_C void  _cdecl BlackMoonGetClassPropertyVaule(
	INT nIDX,HUNIT hUnit, INT nPropertyIndex,INT nRevrev)
{
	PFN_GET_PROPERTY_DATA pfn;
	_asm mov pfn,eax;
	UNIT_PROPERTY_VALUE sProperty;
	sProperty.m_data.m_nDataSize=0;
	sProperty.m_data.m_pData = 0;
	pfn(hUnit,nPropertyIndex,&sProperty);

	if(nIDX && nPropertyIndex < 32)
	{

		BOOL bIsText = (nIDX >> nPropertyIndex) & 1;
		if(bIsText)
		{
			char* pStr=CloneTextData(sProperty.m_szText,mystrlen(sProperty.m_szText));
			sProperty.m_szText = pStr;
		}
	}

	_asm mov eax,sProperty.m_int;
	_asm mov edx,sProperty.m_data.m_nDataSize;
}

EXTERN_C void  _cdecl BlackMoonSetClassPropertyVaule(
	INT nIDX,HUNIT hUnit, INT nPropertyIndex,INT nRevrev,UNIT_PROPERTY_VALUE sProperty,...)
{

	PFN_NOTIFY_PROPERTY_CHANGED pfn;
	_asm mov pfn,eax;
	pfn(hUnit,nPropertyIndex,&sProperty);

}