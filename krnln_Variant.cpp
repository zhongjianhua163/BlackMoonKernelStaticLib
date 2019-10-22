#include "stdafx.h"
#pragma comment(lib,"ole32.lib")
#pragma comment(lib,"oleaut32.lib")

#define		DTC_COM_OBJECT  		48
#define     DTC_VARIANT             49
#define		DTP_COM_OBJECT      MAKELONG (DTC_COM_OBJECT, 1)
#define     DTP_VARIANT         MAKELONG (DTC_VARIANT, 1)

BOOL E_GetVariantElement(PMDATA_INF pArgInf,VARIANTARG * pvargDest)
{
	memcpy(pvargDest,pArgInf[0].m_pCompoundData,sizeof(VARIANTARG));
	if(V_ISARRAY(pvargDest))
	{
		SAFEARRAY* psa = NULL;
		if(V_ISBYREF(pvargDest))
			psa = *pvargDest->pparray;
		else
			psa = pvargDest->parray;

		LONG lLb,lUb;
		UINT nDim = SafeArrayGetDim(psa);
		INT nCount=1;
		for(UINT i=1;i<=nDim;i++)
		{
			SafeArrayGetLBound(psa,i,&lLb);
			SafeArrayGetUBound(psa,i,&lUb);
			nCount*=(lUb - lLb +1);
			
		}
		if(pArgInf[1].m_int > nCount)
			return FALSE;

	//long lLbound = psa->rgsabound[0].lLbound;
		
		long nIdx;//可能按定义开始索引值
		if(pArgInf[1].m_dtDataType == _SDT_NULL)
		{
			nIdx = 0;

		}else{
			nIdx = pArgInf[1].m_int-1;
			if(nIdx < 0)
				nIdx = 0;		
		}

		if((VT_VARIANT & pvargDest->vt)==VT_VARIANT){
		/*char ErrorString [255];
  		wsprintf(ErrorString, "pvargDest->vt%d.  %d", pvargDest->vt,SafeArrayGetDim(psa));
			HRESULT hr = SafeArrayGetElement(psa,&nIdx,pvargDest);

  		MessageBox(0, ErrorString, "pvargDest->vt", MB_ICONERROR);*/

			VARIANTARG *pBuf = NULL; 
			HRESULT hr = SafeArrayAccessData(psa,(void **)&pBuf);
			if(FAILED(hr))
				return FALSE;
			pBuf+=nIdx;
			*pvargDest = *pBuf;
			
			SafeArrayUnaccessData (psa);
		
//			if(FAILED(hr))
//				return FALSE;
			
			if((VT_VARIANT|VT_BYREF) == pvargDest->vt){
		/*				char ErrorString [255];
  		wsprintf(ErrorString, "pvargDest->vt%d.", pvargDest->vt);
  		MessageBox(0, ErrorString, "pvargDest->vt", MB_ICONERROR);	*/

				VARIANT* pvt=pvargDest->pvarVal;
				memcpy(pvargDest,pvt,sizeof(VARIANTARG));

			}




		}else{
			/*HRESULT hr = SafeArrayGetElement(psa,&nIdx,&pvargDest->intVal);

			if(FAILED(hr))
				return FALSE;*/
			LPBYTE pBuf = NULL; 
			HRESULT hr = SafeArrayAccessData(psa,(void **)&pBuf);
			if(FAILED(hr))
				return FALSE;
			DWORD dwSize = SafeArrayGetElemsize(psa);
			pBuf+=(nIdx*dwSize);
			memcpy(&pvargDest->intVal,pBuf,dwSize);
			//pvargDest->intVal = *pBuf;

			SafeArrayUnaccessData (psa);
			pvargDest->vt = (~VT_ARRAY & pvargDest->vt);
		}
	}
	return TRUE;

}
LPOLESTR E_ASCII2Unicode(LPSTR pAsciiText)
{
	if(pAsciiText==NULL)// || IsBadReadPtr(pBStrText,8)
		return NULL;

	DWORD dwMinSize;
    dwMinSize = MultiByteToWideChar (CP_ACP, 0, pAsciiText, -1, NULL, 0);
	
    if(dwMinSize==0)
		return NULL;
    LPOLESTR lpwszStr = new USHORT [dwMinSize];
    // Convert headers from ASCII to Unicode.
    MultiByteToWideChar (CP_ACP, 0, pAsciiText, -1, lpwszStr, dwMinSize);  
	return lpwszStr;
}

LPSTR E_Unicode2ASCII(LPOLESTR pBStrText)
{
	if(pBStrText==NULL)// || IsBadReadPtr(pBStrText,8)
		return NULL;
	//需要转换的字符数 
	DWORD dwLen=WideCharToMultiByte (CP_ACP, 0, pBStrText, -1, NULL,0, NULL, NULL) ; 
	//计算转换的字符数
    if(dwLen==0)
		return NULL;
	LPSTR pText =(char*)E_MAlloc (dwLen);
	WideCharToMultiByte (CP_ACP, 0, pBStrText, -1, pText,dwLen, NULL, NULL);
	return pText;
}

BOOL EDataLetToVariant(VARIANTARG * pvargDest,PMDATA_INF pArgInf)
{
	VARIANTARG pArg;
	memset(&pArg,0,sizeof(VARIANTARG));
	switch(pArgInf->m_dtDataType)
	{
	case SDT_BYTE:
		pArg.vt = VT_UI1;
		pArg.intVal = pArgInf->m_int;
		break;
	case SDT_SHORT:
		pArg.vt = VT_I2;
		pArg.intVal = pArgInf->m_int;
		break;
	case SDT_INT:
		pArg.vt = VT_I4;
		pArg.intVal = pArgInf->m_int;
		break;
	case SDT_SUB_PTR:
		pArg.vt = VT_UI4;
		pArg.intVal = pArgInf->m_int;
		break;
	case SDT_INT64:
		pArg.vt = VT_I8;
		pArg.date = pArgInf->m_date;
		break;
	case SDT_FLOAT:
		pArg.vt = VT_R4;
		pArg.fltVal= pArgInf->m_float;
		break;
	case SDT_DOUBLE:
		pArg.vt = VT_R8;
		pArg.date = pArgInf->m_date;
		break;
	case SDT_BOOL:
		pArg.vt = VT_BOOL;
		pArg.boolVal = pArgInf->m_bool?-1:0;
		break;
	case SDT_DATE_TIME:
		pArg.vt = VT_DATE;
		pArg.date = pArgInf->m_date;
		break;
	case SDT_TEXT:
		{
			pArg.vt = VT_BSTR;
			LPOLESTR lpsz = E_ASCII2Unicode(pArgInf->m_pText);
			pArg.bstrVal = ::SysAllocString(lpsz);
			delete [] lpsz;
		}
		break;
	
	case DTP_VARIANT:
		if(FAILED(VariantCopy(&pArg,(VARIANTARG *)pArgInf->m_pCompoundData)))
			return FALSE;
		break;
	case DTP_COM_OBJECT:
		{
			pArg.vt = VT_UNKNOWN;//用VT_DISPATCH会出错
			PEYDISPATCH pDest = (PEYDISPATCH)pArgInf->m_pCompoundData;
			pArg.pdispVal = pDest->pDisp;
			if(pArg.pdispVal)
				pArg.pdispVal->AddRef();
		}
		break;
	default:
		return FALSE;
		break;
	}

	VariantClear(pvargDest);
	memcpy(pvargDest,&pArg,sizeof(VARIANTARG));

	return TRUE;

}

BOOL EAryDataToVariant(VARIANTARG * pvargDest,PMDATA_INF pArgInf)
{
	INT nDataType = pArgInf->m_dtDataType;
	INT nVtype,nDataSize;

	DWORD dwSize=0;
	void* pData = GetAryElementInf(pArgInf->m_pAryData,dwSize);
	if(pData==NULL || dwSize==0)
		return FALSE;

	if(nDataType == SDT_BIN)
	{
		nVtype =  VT_UI1;
		nDataSize = sizeof (BYTE);

	}else{

		nDataType = ~DT_IS_ARY & nDataType;
		switch(nDataType)
		{
		case SDT_BYTE:
			nVtype = VT_UI1;
			nDataSize = sizeof (BYTE);
			break;
		case SDT_SHORT:
			nVtype = VT_I2;
			nDataSize = sizeof (SHORT);
			break;
		case SDT_INT:
			nVtype = VT_I4;
			nDataSize = sizeof (INT);
			break;
		case SDT_SUB_PTR:
			nVtype = VT_UI4;
			nDataSize = sizeof (DWORD);
			break;
		case SDT_INT64:
			nVtype = VT_I8;
			nDataSize = sizeof (INT64);
			break;
		case SDT_FLOAT:
			nVtype = VT_R4;
			nDataSize = sizeof (FLOAT);
			break;
		case SDT_DOUBLE:
			nVtype = VT_R8;
			nDataSize = sizeof (DOUBLE);
			break;
		case SDT_BOOL:
			nVtype = VT_BOOL;
			nDataSize = sizeof (BOOL);
			break;
		case SDT_DATE_TIME:
			nVtype = VT_DATE;
			nDataSize = sizeof (DATE);
			break;
		case SDT_TEXT:
			nVtype = VT_BSTR;
			nDataSize = sizeof (DWORD);
			break;
		default:
			return FALSE;
			break;
		}
	}

	SAFEARRAY* pArray=NULL;
	HRESULT hr=SafeArrayAllocDescriptor(1,&pArray);//创建SAFEARRAY结构的对象
	if(FAILED(hr))
		return FALSE;
	pArray->cbElements=nDataSize;
	pArray->rgsabound[0].cElements=dwSize;
	pArray->rgsabound[0].lLbound=0;
	SafeArrayAllocData(pArray);
	void * pDest =NULL;
	hr = SafeArrayAccessData(pArray,(void**)&pDest);
	if(FAILED(hr))
	{
		SafeArrayDestroy(pArray);
		return FALSE;
	}

	if(nVtype == VT_BSTR)
	{
		LPSTR* pArySrc = (LPSTR*)pData;
		LPOLESTR* pAryDest = (LPOLESTR*)pDest;
			
					
		for(INT i=0;i<(INT)dwSize;i++)
		{
			LPOLESTR lpsz = E_ASCII2Unicode(pArySrc[i]);
			pAryDest[i] = ::SysAllocString(lpsz);
			delete [] lpsz;
		}

	}else if(nVtype == VT_BOOL){
		LPINT pArySrc = (LPINT)pData;
		LPINT pAryDest = (LPINT)pDest;
		for(INT i=0;i<(INT)dwSize;i++)
		{
			if(pArySrc[i])
				pAryDest[i] = -1;
			else
				pAryDest[i] = 0;
		}

	}else{
		memcpy(pDest,pData,dwSize*nDataSize);
	}
	SafeArrayUnaccessData(pArray);
	VariantClear(pvargDest);
	pvargDest->vt = nVtype | VT_ARRAY;
	pvargDest->parray = pArray;
	return TRUE;

}
extern "C" 
{
	/*
	复制变体型
	
	*/
	void _cdecl krnln_VariantCopy (INT nArgCount,MDATA_INF ArgInf,...)
	{
		PMDATA_INF pArgInf = &ArgInf;
		VARIANTARG * pvargDest = (VARIANTARG *)pArgInf[0].m_pCompoundData;
		if(pvargDest==NULL)return;
		VariantClear(pvargDest);
		VARIANTARG * pvargSrc = (VARIANTARG *)pArgInf[1].m_pCompoundData;
		if(pvargSrc)
			VariantCopy(pvargDest,pvargSrc);
	}

	/*
    调用格式： 〈无返回值〉 对象．清除 （） - 系统核心支持库->变体型
    英文名称：Clear
    将本对象的内容释放并清空。如果不调用本方法，则对象在退出其作用区域时会自动被释放。例如：假设对象存在于子程序局部变量中，当子程序调用退出时，该对象会被自动释放。本命令为初级对象成员命令。
	
	*/
	void _cdecl krnln_VariantClear (INT nArgCount,MDATA_INF ArgInf,...)
	{
		VARIANTARG * pvargDest = (VARIANTARG *)ArgInf.m_pCompoundData;
		VariantClear(pvargDest);
		VariantInit(pvargDest);

	}

	/*
    调用格式： 〈变体类型〉 对象．取类型 （） - 系统核心支持库->变体型
    英文名称：GetType
    取回当前变体型对象的数据类型。本命令为初级对象成员命令。
    数据类型名称：变体类型    英文名称：VariantType
    本数据类型为枚举常量集合类型，共包含 15 个枚举常量值。
    操作系统需求： Windows
    提供变体型中所能够容纳数据类型的枚举值。
    枚举常量值<1>的中文名称为“未知”，英文名称为“Unknown”，值为-1。
    枚举常量值<2>的中文名称为“空”，英文名称为“Empty”，值为0。
    枚举常量值<3>的中文名称为“数值型”，英文名称为“Number”，值为1。
    枚举常量值<4>的中文名称为“文本型”，英文名称为“Text”，值为2。
    枚举常量值<5>的中文名称为“逻辑型”，英文名称为“Bool”，值为3。
    枚举常量值<6>的中文名称为“日期型”，英文名称为“Date”，值为4。
    枚举常量值<7>的中文名称为“对象型”，英文名称为“Object”，值为5。
    枚举常量值<8>的中文名称为“错误值型”，英文名称为“Error”，值为6。
    枚举常量值<9>的中文名称为“数值型数组”，英文名称为“NumberArray”，值为7。
    枚举常量值<10>的中文名称为“文本型数组”，英文名称为“TextArray”，值为8。
    枚举常量值<11>的中文名称为“逻辑型数组”，英文名称为“BoolArray”，值为9。
    枚举常量值<12>的中文名称为“日期型数组”，英文名称为“DateArray”，值为10。
    枚举常量值<13>的中文名称为“对象型数组”，英文名称为“ObjectArray”，值为11。
    枚举常量值<14>的中文名称为“错误值型数组”，英文名称为“ErrorArray”，值为12。
    枚举常量值<15>的中文名称为“变体型数组”，英文名称为“VariantArray”，值为13。	
	*/
	int _cdecl krnln_VariantGetType (INT nArgCount,MDATA_INF ArgInf,...)
	{
		VARIANTARG * pvargDest = (VARIANTARG *)ArgInf.m_pCompoundData;
		VARTYPE vt = pvargDest->vt;
		BOOL bIsArray = FALSE;
		if(vt & VT_ARRAY)
		{
			vt &=(~VT_ARRAY);//去除数组标志
			bIsArray = TRUE;
		}
		int nType = -1;
		switch(vt)
		{
		case VT_UI1:
		case VT_UI2:
		case VT_UI4:
		case VT_UI8:
		case VT_I1:
		case VT_I2:
		case VT_I4:
		case VT_I8:
		case VT_R4:
		case VT_R8:
		case VT_INT:
		case VT_UINT:
		case VT_CY:
		case VT_DECIMAL:
			nType = 1;
			break;
		case VT_BSTR:
			nType = 2;
			break;
		case VT_BOOL:
			nType = 3;
			break;
		case VT_DATE:
			nType = 4;
			break;
		case VT_DISPATCH://对象是否有传址标志?
			nType = 5;
			break;
		case VT_ERROR:
			nType = 6;
			break;
		case VT_EMPTY:
		case VT_NULL:
			nType = 0;
			break;			
		}
		if(bIsArray)
		{
			if(nType==-1 && vt==VT_VARIANT)
				nType = 13;
			else if(1 <= nType && nType <=6)
				nType +=6;
		}

		return nType;
	}

	/*
    调用格式： 〈整数型〉 对象．取数组成员数 （） - 系统核心支持库->变体型
    英文名称：GetElementCount
    如果本对象中存放的是数组数据，执行本方法将返回其成员数目，如果不是数组数据，执行本方法将返回 -1 。本命令为初级对象成员命令。

	
	*/
	int _cdecl krnln_VariantGetElementCount (INT nArgCount,MDATA_INF ArgInf,...)
	{
		VARIANTARG * pvargDest = (VARIANTARG *)ArgInf.m_pCompoundData;
		if(V_ISARRAY(pvargDest))
		{
			SAFEARRAY* psa = NULL;
			if(V_ISBYREF(pvargDest))
				psa = *pvargDest->pparray;
			else
				psa = pvargDest->parray;
			LONG lLb,lUb;
			UINT nDim = SafeArrayGetDim(psa);
			INT nCount=1;
			for(UINT i=1;i<=nDim;i++)
			{
				SafeArrayGetLBound(psa,i,&lLb);
				SafeArrayGetUBound(psa,i,&lUb);
				nCount*=(lUb - lLb +1);

			}
			return nCount;
		}
		return -1;
	}

	/*
    调用格式： 〈文本型〉 对象．取文本 （［整数型 成员索引］） - 系统核心支持库->变体型
    英文名称：GetText
    返回本对象中或本对象数组成员中的文本数据，如果当前数据的数据类型不为文本型，将自动进行转换，如果转换失败将返回空文本。本命令为初级对象成员命令。
    参数<1>的名称为“成员索引”，类型为“整数型（int）”，可以被省略。如果当前对象内为数组型数据，且欲对数组内的某个成员进行操作，则可以在此参数中指定其引用索引值，该索引值从 1 开始。除开上述情况外，请省略本参数。

	
	*/
	char* _cdecl krnln_VariantGetText (INT nArgCount,MDATA_INF ArgInf,...)
	{
		VARIANTARG vargSrc;
		if(E_GetVariantElement(&ArgInf,&vargSrc)==FALSE)
			return NULL;

		LPSTR pText = NULL;
		if(vargSrc.vt == VT_BOOL)
		{
			if(vargSrc.boolVal != 0)
				pText = CloneTextData("真",2);
			else
				pText = CloneTextData("假",2);
			return pText;
		}
		BOOL bIsFromChg = FALSE;
		if(vargSrc.vt != VT_BSTR)
		{
			VARIANTARG vargDest;
			memcpy(&vargDest,&vargSrc,sizeof(VARIANTARG));
			memset(&vargSrc,0,sizeof(VARIANTARG));
			HRESULT hr = VariantChangeType(&vargSrc,&vargDest,0,VT_BSTR);
			if(FAILED(hr))
				return NULL;
			bIsFromChg = TRUE;
		}
		pText = E_Unicode2ASCII(vargSrc.bstrVal);
		if(bIsFromChg)
			VariantClear(&vargSrc);
		return pText;
	}

	/*
    调用格式： 〈双精度小数型〉 对象．取数值 （［整数型 成员索引］） - 系统核心支持库->变体型
    英文名称：GetNum
    返回本对象中或本对象数组成员中的数值数据，如果当前数据的数据类型不为数值或错误值型，将自动进行转换，如果转换失败将返回 0 。本命令为初级对象成员命令。
    参数<1>的名称为“成员索引”，类型为“整数型（int）”，可以被省略。如果当前对象内为数组型数据，且欲对数组内的某个成员进行操作，则可以在此参数中指定其引用索引值，该索引值从 1 开始。除开上述情况外，请省略本参数。	
	*/
	void _cdecl krnln_VariantGetNum (INT nArgCount,MDATA_INF ArgInf,...)
	{
		VARIANTARG vargSrc;
		MDATA_INF RetVal;
		if(E_GetVariantElement(&ArgInf,&vargSrc))
		{
			if(vargSrc.vt != VT_R8)
			{
				VARIANTARG vargDest;
				memcpy(&vargDest,&vargSrc,sizeof(VARIANTARG));
				memset(&vargSrc,0,sizeof(VARIANTARG));
				VariantChangeType(&vargSrc,&vargDest,0,VT_R8);
			}
			RetVal.m_double = vargSrc.dblVal;
		}
		else
			RetVal.m_double = 0;
		__asm
		{
			mov eax,RetVal.m_unit.m_dwFormID;
			mov edx,RetVal.m_unit.m_dwUnitID;
		}
	}

	/*
    调用格式： 〈逻辑型〉 对象．取逻辑值 （［整数型 成员索引］） - 系统核心支持库->变体型
    英文名称：GetBool
    返回本对象中或本对象数组成员中的逻辑值数据，如果当前数据的数据类型不为逻辑型，将自动进行转换，如果转换失败将返回假。本命令为初级对象成员命令。
    参数<1>的名称为“成员索引”，类型为“整数型（int）”，可以被省略。如果当前对象内为数组型数据，且欲对数组内的某个成员进行操作，则可以在此参数中指定其引用索引值，该索引值从 1 开始。除开上述情况外，请省略本参数。
	*/
	BOOL _cdecl krnln_VariantGetBool (INT nArgCount,MDATA_INF ArgInf,...)
	{
		VARIANTARG vargSrc;
		BOOL bRet = FALSE;

		if(E_GetVariantElement(&ArgInf,&vargSrc))
		{
			if(vargSrc.vt != VT_BOOL)
			{
				VARIANTARG vargDest;
				memcpy(&vargDest,&vargSrc,sizeof(VARIANTARG));
				memset(&vargSrc,0,sizeof(VARIANTARG));
				HRESULT hr = VariantChangeType(&vargSrc,&vargDest,0,VT_BSTR);
				if(FAILED(hr))
					return bRet;
			}
			bRet = (vargSrc.boolVal !=0 ?1:0);
		}
		return bRet;

	}
	/*
    调用格式： 〈日期时间型〉 对象．取日期 （［整数型 成员索引］） - 系统核心支持库->变体型
    英文名称：GetDateTime
    返回本对象中或本对象数组成员中的日期时间值数据，如果当前数据的数据类型不为日期时间型，将自动进行转换，如果转换失败将返回100年1月1日。本命令为初级对象成员命令。
    参数<1>的名称为“成员索引”，类型为“整数型（int）”，可以被省略。如果当前对象内为数组型数据，且欲对数组内的某个成员进行操作，则可以在此参数中指定其引用索引值，该索引值从 1 开始。除开上述情况外，请省略本参数。
	*/
	void _cdecl krnln_VariantGetDateTime (INT nArgCount,MDATA_INF ArgInf,...)
	{
		VARIANTARG vargSrc;
		MDATA_INF RetVal;
		if(E_GetVariantElement(&ArgInf,&vargSrc))
		{
			if(vargSrc.vt != VT_DATE)
			{
				VARIANTARG vargDest;
				memcpy(&vargDest,&vargSrc,sizeof(VARIANTARG));
				memset(&vargSrc,0,sizeof(VARIANTARG));
				HRESULT hr = VariantChangeType(&vargSrc,&vargDest,0,VT_DATE);
				if(FAILED(hr))
					vargSrc.date = -657434;//100年1月1日;
			}
			RetVal.m_date = vargSrc.date;
		}
		else
			RetVal.m_date = -657434;//100年1月1日;
		__asm
		{
			mov eax,RetVal.m_unit.m_dwFormID;
			mov edx,RetVal.m_unit.m_dwUnitID;
		}
	}
	/*
    调用格式： 〈对象〉 对象．取对象 （［整数型 成员索引］） - 系统核心支持库->变体型
    英文名称：GetObject
    返回本对象中或本对象数组成员中的COM对象型数据，如果当前数据的数据类型不为COM对象型，将返回空COM对象。本命令为初级对象成员命令。
    参数<1>的名称为“成员索引”，类型为“整数型（int）”，可以被省略。如果当前对象内为数组型数据，且欲对数组内的某个成员进行操作，则可以在此参数中指定其引用索引值，该索引值从 1 开始。除开上述情况外，请省略本参数。
	*/
	void* _cdecl krnln_VariantGetObject (INT nArgCount,MDATA_INF ArgInf,...)
	{
		VARIANTARG vargSrc;
		PEYDISPATCH pdispRet = (PEYDISPATCH)E_MAlloc(sizeof(EYDISPATCH));

		if(E_GetVariantElement(&ArgInf,&vargSrc))
		{
			switch (vargSrc.vt)
			{
			case VT_DISPATCH:
				pdispRet->pDisp = vargSrc.pdispVal;
				if(pdispRet->pDisp)
					pdispRet->pDisp->AddRef();
				break;
			case VT_UNKNOWN:
				pdispRet->pDisp = (LPDISPATCH)vargSrc.punkVal;
				if(pdispRet->pDisp)
					pdispRet->pDisp->AddRef();
				break;
			case VT_DISPATCH|VT_BYREF:
				pdispRet->pDisp = *vargSrc.ppdispVal;
				if(pdispRet->pDisp)
					pdispRet->pDisp->AddRef();
				break;
			case VT_UNKNOWN|VT_BYREF:
				pdispRet->pDisp = *(LPDISPATCH*)vargSrc.ppunkVal;
				if(pdispRet->pDisp)
					pdispRet->pDisp->AddRef();
				break;
			}
		}
		return pdispRet;

	}

	/*
    调用格式： 〈变体型〉 对象．取变体型 （［整数型 成员索引］） - 系统核心支持库->变体型
    英文名称：GetVariant
    返回本对象中或本对象数组成员中的变体型数据类型数据，如果当前数据的数据类型不为变体型，将自动进行转换。本命令为初级对象成员命令。
    参数<1>的名称为“成员索引”，类型为“整数型（int）”，可以被省略。如果当前对象内为数组型数据，且欲对数组内的某个成员进行操作，则可以在此参数中指定其引用索引值，该索引值从 1 开始。除开上述情况外，请省略本参数。
	*/
	void* _cdecl krnln_VariantGetVariant (INT nArgCount,MDATA_INF ArgInf,...)
	{
		VARIANTARG vargSrc;
		VARIANT* pVarRet = (VARIANT*)E_MAlloc(sizeof(VARIANT));

		if(E_GetVariantElement(&ArgInf,&vargSrc))
			VariantCopy(pVarRet,&vargSrc);
		return pVarRet;

	}
	/*
    调用格式： 〈逻辑型〉 对象．赋值 （［通用型数组/非数组 欲写入数据］，［整数型 成员索引］） - 系统核心支持库->变体型
    英文名称：set
    设置本对象的内容，成功返回真，失败返回假。本命令为初级对象成员命令。
    参数<1>的名称为“欲写入数据”，类型为“通用型（all）”，可以被省略，提供参数数据时可以同时提供数组或非数组数据。参数值可以为文本、数值、逻辑值、日期时间值、COM对象型数据类型或者这些数据类型及“变体型”数据类型本身的数组形式。如果本参数被省略，则将对象清空。
    参数<2>的名称为“成员索引”，类型为“整数型（int）”，可以被省略。如果当前对象内为数组型数据，且欲对数组内的某个成员进行操作，则可以在此参数中指定其引用索引值，该索引值从 1 开始。除开上述情况外，请省略本参数。
	*/
	BOOL _cdecl krnln_Variantset (INT nArgCount,MDATA_INF ArgInf,...)
	{
		PMDATA_INF pArgInf = &ArgInf;
		VARIANTARG * pvargDest = (VARIANTARG *)pArgInf[0].m_pCompoundData;
		if(pArgInf[1].m_dtDataType == _SDT_NULL)
		{
			VariantClear(pvargDest);
			VariantInit(pvargDest);
			return TRUE;
		}


		BOOL bRet;

		if((pArgInf[1].m_dtDataType & DT_IS_ARY) == DT_IS_ARY || pArgInf[1].m_dtDataType == SDT_BIN)
			bRet = EAryDataToVariant(pvargDest,&pArgInf[1]);
		else
		{
			if(V_ISARRAY(pvargDest))
			{
				SAFEARRAY* psa = pvargDest->parray;
				LONG lLb,lUb;
				UINT nDim = SafeArrayGetDim(psa);
				INT nCount=1;
				for(UINT i=1;i<=nDim;i++)
				{
					SafeArrayGetLBound(psa,i,&lLb);
					SafeArrayGetUBound(psa,i,&lUb);
					nCount*=(lUb - lLb +1);
					
				}
				if(pArgInf[2].m_int > nCount)
					return FALSE;

				VARIANTARG vargSrc;
				VariantInit(&vargSrc);
				
				if(EDataLetToVariant(&vargSrc,&pArgInf[1])==FALSE)
					return FALSE;
				


				//long lLbound = //psa->rgsabound[0].lLbound;
				long nIdx;//可能按定义开始索引值
				if(pArgInf[2].m_dtDataType == _SDT_NULL)
				{
					nIdx = 0;//lLbound;
					
				}else{
					nIdx = pArgInf[2].m_int-1;//+lLbound;
					if(nIdx < 0)
						nIdx = 0;//lLbound;
				}
				INT nVarType = ~VT_ARRAY & pvargDest->vt;
		
				HRESULT hr;


				if((VT_VARIANT & nVarType)==VT_VARIANT){
					//hr = SafeArrayPutElement(psa,&nIdx,&vargSrc);
					VARIANTARG *pBuf = NULL; 
					HRESULT hr = SafeArrayAccessData(psa,(void **)&pBuf);
					if(!FAILED(hr)){
						pBuf+=nIdx;
						VariantClear(pBuf);
						*pBuf=vargSrc;
					
						SafeArrayUnaccessData (psa);
					}
				}else{
					if(nVarType != vargSrc.vt)
					{
						VARIANTARG vargDest;
						memcpy(&vargDest,&vargSrc,sizeof(VARIANTARG));
						memset(&vargSrc,0,sizeof(VARIANTARG));
						hr = VariantChangeType(&vargSrc,&vargDest,0,nVarType);
						if(FAILED(hr))
						{
							VariantClear(&vargDest);
							return FALSE;
						}
					}
					//hr = SafeArrayPutElement(psa,&nIdx,&vargSrc.intVal);
					LPBYTE pBuf = NULL;
					HRESULT hr = SafeArrayAccessData(psa,(void **)&pBuf);
					if(!FAILED(hr)){
						DWORD dwSize = SafeArrayGetElemsize(psa);
						pBuf+=(nIdx*dwSize);
						if(nVarType==VT_BSTR)
							::SysFreeString (*(BSTR*)pBuf);
						memcpy(pBuf,&vargSrc.intVal,dwSize);
					
						SafeArrayUnaccessData (psa);
					}
				}

				if(FAILED(hr))
				{
					VariantClear(&vargSrc);
					return FALSE;
				}
				
				return TRUE;
				
			}else
				bRet = EDataLetToVariant(pvargDest,&pArgInf[1]);
		}

		return bRet;
	}
	/*
    调用格式： 〈逻辑型〉 对象．创建数组 （整数型 成员类型，整数型 成员数目） - 系统核心支持库->变体型
    英文名称：CreateArray
    创建指定类型和指定成员数的空白数组，对象中的原有内容将被清空，成功返回真，失败返回假。本命令为初级对象成员命令。
    参数<1>的名称为“成员类型”，类型为“整数型（int）”。指定所创建数组成员的数据类型，为以下数值之一：
	1: 字节型； 2: 短整数型； 3: 整数型； 4: 小数型； 5: 双精度小数型； 6: 文本型； 7: 逻辑型； 8: 日期型； 9: 对象型； 10: 变体型。
    参数<2>的名称为“成员数目”，类型为“整数型（int）”。指定所创建数组成员的数目。
	*/
	BOOL _cdecl krnln_VariantCreateArray (INT nArgCount,MDATA_INF ArgInf,...)
	{
		PMDATA_INF pArgInf = &ArgInf;
		VARIANTARG * pvargDest = (VARIANTARG *)pArgInf[0].m_pCompoundData;
		VariantClear(pvargDest);
		VariantInit(pvargDest);

		INT nDataType = pArgInf[1].m_int;
		INT nDataSize,nVtype;
		switch(nDataType)
		{
		case 1://字节型
			nVtype = VT_UI1;
			nDataSize = sizeof (BYTE);
			break;
		case 2://短整数型
			nVtype = VT_I2;
			nDataSize = sizeof (SHORT);
			break;
		case 3://整数型
			nVtype = VT_I4;
			nDataSize = sizeof (INT);
			break;
		case 4://小数型
			nVtype = VT_R4;
			nDataSize = sizeof (FLOAT);
			break;
		case 5://双精度小数型
			nVtype = VT_R8;
			nDataSize = sizeof (DOUBLE);
			break;
		case 7://逻辑型
			nVtype = VT_BOOL;
			nDataSize = sizeof (BOOL);
			break;
		case 8://日期型
			nVtype = VT_DATE;
			nDataSize = sizeof (DATE);
			break;
		case 6://文本型
			nVtype = VT_BSTR;
			nDataSize = sizeof (DWORD);
			break;
		case 9://对象型
			nVtype = VT_DISPATCH;
			nDataSize = sizeof (DWORD);
			break;
		case 10://变体型
			nVtype = VT_VARIANT;
			nDataSize = sizeof (VARIANT);
			break;
		default:
			return FALSE;
			break;
		}

		

		SAFEARRAY* pArray=NULL;
		HRESULT hr=SafeArrayAllocDescriptor(1,&pArray);//创建SAFEARRAY结构的对象
		if(FAILED(hr))
			return FALSE;
		pArray->cbElements=nDataSize;
		pArray->rgsabound[0].cElements=pArgInf[2].m_int;
		pArray->rgsabound[0].lLbound=0;
		hr = SafeArrayAllocData(pArray);
		if(FAILED(hr))
		{
			SafeArrayDestroyDescriptor(pArray);
			return FALSE;
		}
		
		pvargDest->vt = nVtype | VT_ARRAY;
		pvargDest->parray = pArray;
		return TRUE;

	}
	/*
    调用格式： 〈逻辑型〉 对象．置类型 （变体类型 欲设置的类型） - 系统核心支持库->变体型
    英文名称：SetType
    清除当前变体型对象中的原有内容，并改变它的数据类型，成功返回真，失败返回假。本命令为初级对象成员命令。
    参数<1>的名称为“欲设置的类型”，类型为“变体类型（VariantType）”。参数值提供欲设置的变体类型。
    枚举常量值<2>的中文名称为“空”，英文名称为“Empty”，值为0。
    枚举常量值<3>的中文名称为“数值型”，英文名称为“Number”，值为1。
    枚举常量值<4>的中文名称为“文本型”，英文名称为“Text”，值为2。
    枚举常量值<5>的中文名称为“逻辑型”，英文名称为“Bool”，值为3。
    枚举常量值<6>的中文名称为“日期型”，英文名称为“Date”，值为4。
    枚举常量值<7>的中文名称为“对象型”，英文名称为“Object”，值为5。
    枚举常量值<8>的中文名称为“错误值型”，英文名称为“Error”，值为6。
    枚举常量值<9>的中文名称为“数值型数组”，英文名称为“NumberArray”，值为7。
    枚举常量值<10>的中文名称为“文本型数组”，英文名称为“TextArray”，值为8。
    枚举常量值<11>的中文名称为“逻辑型数组”，英文名称为“BoolArray”，值为9。
    枚举常量值<12>的中文名称为“日期型数组”，英文名称为“DateArray”，值为10。
    枚举常量值<13>的中文名称为“对象型数组”，英文名称为“ObjectArray”，值为11。
    枚举常量值<14>的中文名称为“错误值型数组”，英文名称为“ErrorArray”，值为12。
    枚举常量值<15>的中文名称为“变体型数组”，英文名称为“VariantArray”，值为13。	
	*/
	BOOL _cdecl krnln_VariantSetType (INT nArgCount,MDATA_INF ArgInf,...)
	{
		PMDATA_INF pArgInf = &ArgInf;
		VARIANTARG * pvargDest = (VARIANTARG *)pArgInf[0].m_pCompoundData;
	

		INT nVtype;
		switch(pArgInf[1].m_int)
		{
		case 0:
			nVtype = VT_EMPTY;
			break;
		case 1:
			nVtype = VT_R8;
			break;
		case 2:
			nVtype = VT_BSTR;
			break;
		case 3:
			nVtype = VT_BOOL;
			break;
		case 4:
			nVtype = VT_DATE;
			break;
		case 5:
			nVtype = VT_DISPATCH;
			break;
		case 6:
			nVtype = VT_ERROR;
			break;
		case 7:
			nVtype = VT_R8|VT_ARRAY;
			break;
		case 8:
			nVtype = VT_BSTR|VT_ARRAY;
			break;
		case 9:
			nVtype = VT_BOOL|VT_ARRAY;
			break;
		case 10:
			nVtype = VT_DATE|VT_ARRAY;
			break;
		case 11:
			nVtype = VT_DISPATCH|VT_ARRAY;
			break;
		case 12:
			nVtype = VT_ERROR|VT_ARRAY;
			break;
		case 13:
			nVtype = VT_VARIANT|VT_ARRAY;
			break;
		default:
			VariantClear(pvargDest);
			VariantInit(pvargDest);
			return FALSE;
			break;
		}
		if(nVtype == VT_EMPTY)
		{
			VariantClear(pvargDest);
			VariantInit(pvargDest);
		}
		else
		{
			VARIANTARG vargDest;
			memset(&vargDest,0,sizeof(VARIANTARG));
			HRESULT hr = VariantChangeType(&vargDest,pvargDest,0,nVtype);
			VariantClear(pvargDest);
			if(FAILED(hr))
			{
				VariantInit(pvargDest);
				return FALSE;
			}
			memcpy(pvargDest,&vargDest,sizeof(VARIANTARG));


		}
		return TRUE;
	
	}
	/*
    调用格式： 〈字节集〉 对象．取字节集 （［整数型 成员索引］） - 系统核心支持库->变体型
    英文名称：GetBin
    返回本对象中或本对象数组成员中的字节集数据，如果当前数据的数据类型不为字节集型，将自动进行转换，如果转换失败将返回空字节集。本命令为初级对象成员命令。
    参数<1>的名称为“成员索引”，类型为“整数型（int）”，可以被省略。如果当前对象内为数组型数据，且欲对数组内的某个成员进行操作，则可以在此参数中指定其引用索引值，该索引值从 1 开始。除开上述情况外，请省略本参数。
	*/
	void* _cdecl krnln_VariantGetBin (INT nArgCount,MDATA_INF ArgInf,...)
	{
		
		LPBYTE pData = NULL;
		VARIANTARG vargSrc;
		BOOL bIsFromChg = FALSE;
		PMDATA_INF pArgInf = &ArgInf;
		SAFEARRAY* psa;
		VARIANTARG * pvargDest = (VARIANTARG *)pArgInf[0].m_pCompoundData;
		if(pvargDest->vt != (VT_ARRAY | VT_UI1) && pvargDest->vt != (VT_ARRAY | VT_I1))
		{
			
			if(E_GetVariantElement(&ArgInf,&vargSrc)==FALSE)
				return pData;
			VARIANTARG vargDest;
			memcpy(&vargDest,&vargSrc,sizeof(VARIANTARG));
			memset(&vargSrc,0,sizeof(VARIANTARG));
			HRESULT hr = VariantChangeType(&vargSrc,&vargDest,0,VT_ARRAY | VT_UI1);
			if(FAILED(hr))
				return pData;
			psa = vargSrc.parray;
			bIsFromChg = TRUE;

		}else
			psa = pvargDest->parray;

		LONG lLb,lUb;
		UINT nDim = SafeArrayGetDim(psa);
		INT nCount=1;
		for(UINT i=1;i<=nDim;i++)
		{
			SafeArrayGetLBound(psa,i,&lLb);
			SafeArrayGetUBound(psa,i,&lUb);
			nCount*=(lUb - lLb +1);
			
		}
		BYTE *pBuf = NULL; 
		SafeArrayAccessData(psa,(void **)&pBuf);
		pData = CloneBinData (pBuf, nCount);
		SafeArrayUnaccessData (psa);
		if(bIsFromChg)
			VariantClear(&vargSrc);
		return pData;

	}
}