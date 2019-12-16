#include "stdafx.h"
#include "OLECTL.H"
#include "Myfunctions.h"
#include <stdio.h>
#pragma comment(lib,"ole32.lib")
#pragma comment(lib,"oleaut32.lib")

#define		DTC_COM_OBJECT  		48
#define     DTC_VARIANT             49
#define		DTP_COM_OBJECT      MAKELONG (DTC_COM_OBJECT, 1)
#define     DTP_VARIANT         MAKELONG (DTC_VARIANT, 1)



LPOLESTR ASCII2Unicode(LPSTR pAsciiText)
{
	if(pAsciiText==NULL)
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
LPSTR Unicode2EASCII(LPOLESTR pBStrText)
{
	if(pBStrText==NULL)
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

HRESULT Dispatch_GetIDsOfNames(LPDISPATCH lpDispatch,LPSTR pszName,DISPID* rgDispid)
{
	LPOLESTR lpzCom = ASCII2Unicode(pszName);
	HRESULT hRet = 0;
	/*
	UINT nMax = 0;
	hRet = lpDispatch->GetTypeInfoCount(&nMax);
	if(hRet ==S_OK){

			
		ITypeInfo* pp = NULL;
		for(UINT i=0;i<nMax;i++){
			hRet = lpDispatch->GetTypeInfo(i,0,&pp);
			if(hRet ==S_OK){
				hRet = pp->GetIDsOfNames(&lpzCom,1,rgDispid);

				pp->Release();
				if(hRet ==S_OK){
					
					
					if(lpzCom)
						delete [] lpzCom;
					return hRet;
				}
			char ErrorString [1024];
  			wsprintf(ErrorString, "%x %d", hRet,*rgDispid);
				MessageBox(NULL,ErrorString,NULL,MB_OK);
				pp = NULL;

			}

		}
	}
*/
	

	//hRet = lpDispatch->GetIDsOfNames(IID_NULL,&lpzCom,1, LOCALE_USER_DEFAULT,rgDispid); //大鸟原本代码
	hRet = lpDispatch->GetIDsOfNames(IID_NULL,&lpzCom,1, GetUserDefaultLCID(),rgDispid);
	if(lpzCom)
		delete [] lpzCom;
	return hRet;

}

HRESULT Dispatch_InvokeHelper(LPDISPATCH lpDispatch,DISPID dwDispID, WORD wFlags,
	VARIANT* pvarResult, INT nArgCount, PMDATA_INF pArgInf)
{
	DISPPARAMS dispparams;
	memset(&dispparams, 0, sizeof dispparams);

	//检测参数是否有传址
	BOOL* pbIsRef;
	if (nArgCount > 0)
	{
		pbIsRef = new BOOL[nArgCount];
		memset(pbIsRef, 0, sizeof(BOOL) * nArgCount);
	}
	
	ITypeInfo* pTypeInfo;
	lpDispatch->GetTypeInfo(0,0,&pTypeInfo);
	
	TYPEATTR* pAttr; 
	INT bIsMethod = FALSE;
	pTypeInfo->GetTypeAttr(&pAttr);
	if(wFlags == DISPATCH_METHOD)
	{
		FUNCDESC* pFuncDesc = NULL; 
		
		for (INT i=0;i <pAttr->cFuncs;i++) 
		{
			HRESULT hr = pTypeInfo->GetFuncDesc(i, &pFuncDesc); 
			if(hr == S_OK && pFuncDesc->memid == dwDispID)
			{
				INT nMax = min(nArgCount,pFuncDesc->cParams);
				for(INT j=0;j<nMax;j++)
				{
					if(pFuncDesc->lprgelemdescParam[j].tdesc.vt==VT_PTR || 
						(pFuncDesc->lprgelemdescParam[j].tdesc.vt & VT_BYREF)==VT_BYREF)
						pbIsRef[j] = TRUE;
				}

				if (pFuncDesc->invkind == INVOKE_PROPERTYPUT && nArgCount == 0) // 写属性 参数不能为0
					wFlags = INVOKE_PROPERTYGET;
				else
					wFlags = pFuncDesc->invkind;

				bIsMethod = TRUE;
				pTypeInfo->ReleaseFuncDesc(pFuncDesc); 
				break; 
			}
			pTypeInfo->ReleaseFuncDesc(pFuncDesc); 
			pFuncDesc = NULL; 
		}
	}
	if (!bIsMethod)
	{
		VARDESC* pVarDesc = NULL; 
		
		for (INT i=0;i <pAttr->cVars;i++) 
		{
			HRESULT hr = pTypeInfo->GetVarDesc(i, &pVarDesc); 
			if(hr == S_OK && pVarDesc->memid == dwDispID)
			{
				if(pVarDesc->elemdescVar.tdesc.vt==VT_PTR || 
					(pVarDesc->elemdescVar.tdesc.vt & VT_BYREF)==VT_BYREF)
					pbIsRef[0] = TRUE;
				
				if (wFlags == DISPATCH_METHOD)
					wFlags = INVOKE_PROPERTYGET;

				pTypeInfo->ReleaseVarDesc(pVarDesc); 
				break; 
			}
			pTypeInfo->ReleaseVarDesc(pVarDesc); 
			pVarDesc = NULL; 
		}
	}
	pTypeInfo->ReleaseTypeAttr(pAttr); 
	pTypeInfo->Release ();

	// determine number of arguments
	dispparams.cArgs = nArgCount;
	DISPID dispidNamed = DISPID_PROPERTYPUT;
	if (wFlags & (DISPATCH_PROPERTYPUT|DISPATCH_PROPERTYPUTREF))
	{
		//ASSERT(dispparams.cArgs > 0);
		dispparams.cNamedArgs = 1;
		dispparams.rgdispidNamedArgs = &dispidNamed;
	}
	if (dispparams.cArgs != 0)
	{
		// allocate memory for all VARIANT parameters
		VARIANT* pArg = new VARIANT[dispparams.cArgs];
		ASSERT(pArg != NULL);   // should have thrown exception
		dispparams.rgvarg = pArg;
		memset(pArg, 0, sizeof(VARIANT) * dispparams.cArgs);

		// get ready to walk vararg list
		pArg += dispparams.cArgs - 1;   // params go in opposite order

		for(INT i=0;i<nArgCount;i++)
		{	
			if((pArgInf[i].m_dtDataType & DT_IS_ARY) == 0)//非数组
			{	
				
				switch(pArgInf[i].m_dtDataType)
				{
				case SDT_BYTE:
					pArg->vt = VT_UI1;
					pArg->intVal = pArgInf[i].m_int;
					break;
				case SDT_SHORT:
					pArg->vt = VT_I2;
					pArg->intVal = pArgInf[i].m_int;
					break;
				case SDT_INT:
					pArg->vt = VT_I4;
					pArg->intVal = pArgInf[i].m_int;
					break;
				case SDT_SUB_PTR:
					pArg->vt = VT_UI4;
					pArg->intVal = pArgInf[i].m_int;
					break;
				case SDT_INT64:
					pArg->vt = VT_I8;
					pArg->date = pArgInf[i].m_date;
					break;
				case SDT_FLOAT:
					pArg->vt = VT_R4;
					pArg->fltVal= pArgInf[i].m_float;
					break;
				case SDT_DOUBLE:
					pArg->vt = VT_R8;
					pArg->date = pArgInf[i].m_date;
					break;
				case SDT_BOOL:
					pArg->vt = VT_BOOL;
					pArg->boolVal = pArgInf[i].m_bool?-1:0;
					break;
				case SDT_DATE_TIME:
					pArg->vt = VT_DATE;
					pArg->date = pArgInf[i].m_date;
					break;
				case SDT_TEXT:
					{
						pArg->vt = VT_BSTR;
						LPOLESTR lpsz = ASCII2Unicode(pArgInf[i].m_pText);
						pArg->bstrVal = ::SysAllocString(lpsz);
						delete [] lpsz;
					}
					break;
				case SDT_BIN:
					{
						pArg->vt = VT_ARRAY | VT_UI1;
						INT nLength=*(LPINT)(pArgInf[i].m_pBin + sizeof (INT));
						BYTE* pbuf=pArgInf[i].m_pBin + sizeof (INT) * 2;

						SAFEARRAY* psa;
						SAFEARRAYBOUND rgsabound[1];
						rgsabound[0].lLbound = 0;
						rgsabound[0].cElements = nLength;
						psa = SafeArrayCreate(VT_UI1, 1, rgsabound);
						psa->pvData=pbuf;
						pArg->parray = psa;
					}
					break;
				case DTP_VARIANT:
					if(pbIsRef[i])
					{
						pArg->vt = VT_VARIANT | VT_BYREF;
						pArg->pvarVal = (VARIANT*)pArgInf[i].m_pCompoundData;
					}else{
						//memcpy(pArg,(VARIANT*)pArgInf[i].m_pCompoundData,sizeof(VARIANT));
						VariantCopy(pArg,(VARIANT*)pArgInf[i].m_pCompoundData);
					}
					break;
				case DTP_COM_OBJECT:
					
					if(pbIsRef[i])
					{
						if(wFlags==DISPATCH_PROPERTYPUT)//对象为传址时，转换为有传址标志
							 wFlags = DISPATCH_PROPERTYPUTREF;
						pArg->vt = VT_DISPATCH | VT_BYREF;
						PEYDISPATCH pDest = (PEYDISPATCH)pArgInf[i].m_ppCompoundData;
						pArg->ppdispVal = (LPDISPATCH*)pDest;
					}else{			
						pArg->vt = VT_DISPATCH;
						PEYDISPATCH pDest = (PEYDISPATCH)pArgInf[i].m_ppCompoundData;
						pArg->pdispVal = pDest->pDisp;
					}
					break;
				}
			}
			else
			{
				
				DWORD dtDataType = ~DT_IS_ARY & pArgInf[i].m_dtDataType;
				switch(dtDataType)
				{
				case SDT_BYTE:
					if(pbIsRef[i])
					{
						pArg->vt = VT_UI1|VT_BYREF;
						pArg->intVal = pArgInf[i].m_int;
					}
					else
					{
						pArg->vt = VT_UI1;
						pArg->bVal = *pArgInf[i].m_pByte;
					}
					break;
				case SDT_SHORT:
					if(pbIsRef[i])
					{
						pArg->vt = VT_I2|VT_BYREF;
						pArg->intVal = pArgInf[i].m_int;
					}
					else
					{
						pArg->vt = VT_I2;
						pArg->iVal = *pArgInf[i].m_pShort;
					}
					break;
				case SDT_INT:
					if(pbIsRef[i])
					{
						pArg->vt = VT_I4|VT_BYREF;
						pArg->intVal = pArgInf[i].m_int;
					}
					else
					{
						pArg->vt = VT_I4;
						pArg->intVal = *pArgInf[i].m_pInt;
					}
					break;
				case SDT_SUB_PTR:
					if(pbIsRef[i])
					{
						pArg->vt = VT_UI4|VT_BYREF;
						pArg->intVal = pArgInf[i].m_int;
					}
					else
					{
						pArg->vt = VT_UI4;
						pArg->uintVal = *pArgInf[i].m_pdwSubCodeAdr;
					}
	
					break;
				case SDT_INT64:
					if(pbIsRef[i])
					{
						pArg->vt = VT_I8|VT_BYREF;
						pArg->intVal = pArgInf[i].m_int;
					}
					else
					{
						pArg->vt = VT_I8;
						pArg->date = *pArgInf[i].m_pDate;
					}

					break;
				case SDT_FLOAT:
					if(pbIsRef[i])
					{
						pArg->vt = VT_R4|VT_BYREF;
						pArg->intVal = pArgInf[i].m_int;
					}
					else
					{
						pArg->vt = VT_R4;
						pArg->fltVal = *pArgInf[i].m_pFloat;
					}
					
					break;
				case SDT_DOUBLE:
					if(pbIsRef[i])
					{
						pArg->vt = VT_R8|VT_BYREF;
						pArg->intVal = pArgInf[i].m_int;
					}
					else
					{
						pArg->vt = VT_R8;
						pArg->date = *pArgInf[i].m_pDate;
					}
					break;
				case SDT_BOOL:
					if(pbIsRef[i])
					{
						pArg->vt = VT_BOOL|VT_BYREF;
						if(*pArgInf[i].m_pBool)
							*pArgInf[i].m_pBool = -1;
						pArg->intVal = pArgInf[i].m_int;
					}
					else
					{
						pArg->vt = VT_BOOL;
						pArg->boolVal = *pArgInf[i].m_pBool?-1:0;
					}

					break;
				case SDT_DATE_TIME:
					if(pbIsRef[i])
					{
						pArg->vt = VT_DATE|VT_BYREF;
						pArg->intVal = pArgInf[i].m_int;
					}
					else
					{
						pArg->vt = VT_DATE;
						pArg->date = *pArgInf[i].m_pDate;
					}
					break;
				case SDT_TEXT:
					{
						if(pbIsRef[i])
						{
							pArg->vt = VT_BSTR|VT_BYREF;
							if(*pArgInf[i].m_ppText)
							{
								LPOLESTR lpsz = ASCII2Unicode(*pArgInf[i].m_ppText);
								LPOLESTR* pp = &pArg->bstrVal;
								pp++;
								*pp = ::SysAllocString(lpsz);
								pArg->pbstrVal = pp;
								delete [] lpsz;
							}
						}
						else
						{
							pArg->vt = VT_BSTR;
							if(*pArgInf[i].m_ppText)
							{
								LPOLESTR lpsz = ASCII2Unicode(*pArgInf[i].m_ppText);
								pArg->bstrVal = ::SysAllocString(lpsz);
								delete [] lpsz;
							}

						}
					}
					break;
				case SDT_BIN:
					{
						pArg->vt = VT_ARRAY | VT_UI1;
						//pArg->vt = VT_ARRAY | VT_UI1| VT_BYREF;
						LPBYTE pBin = *pArgInf[i].m_ppBin;
						if(pBin)
						{
							INT nLength=*(LPINT)(pBin + sizeof (INT));
							BYTE* pbuf = pBin + sizeof (INT) * 2;
							
							SAFEARRAY* psa;
							SAFEARRAYBOUND rgsabound[1];
							rgsabound[0].lLbound = 0;
							rgsabound[0].cElements = nLength;
							psa = SafeArrayCreate(VT_UI1, 1, rgsabound);
							psa->pvData=pbuf;
							pArg->parray = psa;
							/*
							INT nLength=*(LPINT)(pBin + sizeof (INT));
							BYTE* pbuf=pBin + sizeof (INT) * 2;
							
							SAFEARRAY* psa;
							SAFEARRAYBOUND rgsabound[1];
							rgsabound[0].lLbound = 0;
							rgsabound[0].cElements = nLength;
							psa = SafeArrayCreate(VT_UI1, 1, rgsabound);
							psa->pvData=pbuf;
							
							SAFEARRAY** pp = &pArg->parray;
							pp++;
							*pp = psa;
							pArg->pparray = pp;*/
						}

					}
					break;
				case DTP_VARIANT:
					//if(pbIsRef[i])
				//	{
						pArg->vt = VT_VARIANT | VT_BYREF;
						pArg->pvarVal = (VARIANT*)*pArgInf[i].m_ppCompoundData;
				//	}else
				//		memcpy(pArg,(VARIANT*)*pArgInf[i].m_ppCompoundData,sizeof(VARIANT));
					break;
				case DTP_COM_OBJECT:
					if(pbIsRef[i])
					{
						if(wFlags==DISPATCH_PROPERTYPUT)
							 wFlags = DISPATCH_PROPERTYPUTREF;//对象为传址时，转换为有传址标志
						pArg->vt = VT_DISPATCH | VT_BYREF;
						PEYDISPATCH pDest = *(PEYDISPATCH*)pArgInf[i].m_ppCompoundData;
						pArg->ppdispVal = (LPDISPATCH*)pDest;
					}else{
						pArg->vt = VT_DISPATCH;
						PEYDISPATCH pDest = *(PEYDISPATCH*)pArgInf[i].m_ppCompoundData;
						pArg->pdispVal = pDest->pDisp;
					}
					break;
				}
			}

					--pArg; // get ready to fill next argument
		}
		delete [] pbIsRef;

	}

	UINT nArgErr = (UINT)-1;  // initialize to invalid arg

	// make the call
	HRESULT hRet = lpDispatch->Invoke(dwDispID, IID_NULL, 0, wFlags,
		&dispparams, pvarResult, NULL, &nArgErr);

	// cleanup any arguments that need cleanup
	if (dispparams.cArgs != 0)
	{
		VARIANT* pArg = dispparams.rgvarg + dispparams.cArgs - 1;
		for(INT i=0;i<nArgCount;i++)
		{
			switch (pArg->vt)
			{
			case VT_BSTR:
				if(pArgInf[i].m_dtDataType !=(DTP_VARIANT |DT_IS_ARY))
					VariantClear(pArg);
				break;
			case VT_BSTR|VT_BYREF:
				if(pArgInf[i].m_dtDataType==VAR_TEXT && pArg->pbstrVal)
				{
					if(*pArgInf[i].m_ppText)
						E_MFree(*pArgInf[i].m_ppText);
					*pArgInf[i].m_ppText = Unicode2EASCII(*pArg->pbstrVal);
				}
				VariantClear(pArg);
				break;
			case VT_ARRAY | VT_UI1:
				SafeArrayDestroy(pArg->parray);
				break;
				/*
			case VT_ARRAY | VT_UI1| VT_BYREF:
				if(pArg->pparray)
					SafeArrayDestroy(*pArg->pparray);
				break;*/
			}
			--pArg;
		}

	}
	delete[] dispparams.rgvarg;

	return hRet;
}

extern "C" 
{
	/*
	复制对象型
	
	*/
	void _cdecl krnln_DispCopy (INT nArgCount,MDATA_INF ArgInf,...)
	{
		PMDATA_INF pArgInf = &ArgInf;
		PEYDISPATCH pDest = (PEYDISPATCH)pArgInf[0].m_pCompoundData;
		if(pDest->pDisp)
			pDest->pDisp->Release();
		PEYDISPATCH pSrc = (PEYDISPATCH)pArgInf[1].m_pCompoundData;
		pDest->pDisp = pSrc->pDisp;
		if(pDest->pDisp)
			pDest->pDisp->AddRef();


	}

	/*
    调用格式： 〈逻辑型〉 对象．创建 （文本型 对象类型，［文本型 类型库文件名］） - 系统核心支持库->对象
    英文名称：CreateObject
    创建指定类型的 COM 对象，本对象中的原有内容将被释放。成功返回真，否则返回假。本命令为初级对象成员命令。
    参数<1>的名称为“对象类型”，类型为“文本型（text）”。本参数指定对象的类型文本，譬如“Word.Application”、“Excel.Application”、“{000209FF-0000-0000-C000-000000000046}”等均可。
    参数<2>的名称为“类型库文件名”，类型为“文本型（text）”，可以被省略。如果需要通过类型库才能访问指定对象，可在本参数中提供其类型库或类型库数据所在文件名。注意如果没有提供文件路径，且在当前目录下无法找到该文件，系统将自动进行搜索。如果省略本参数，默认为不需要类型库文件。

	
	*/
	BOOL _cdecl krnln_DispCreateObject (INT nArgCount,MDATA_INF ArgInf,...)
	{
		PMDATA_INF pArgInf = &ArgInf;
		PEYDISPATCH pDest = (PEYDISPATCH)pArgInf[0].m_pCompoundData;
		if(pDest->pDisp)
		{
			pDest->pDisp->Release();
			pDest->pDisp = NULL;
		}
		LPOLESTR lpzCom = ASCII2Unicode(pArgInf[1].m_pText);
		if(lpzCom==NULL){
			pDest->hRet = 0;
			return FALSE;
		}
		LPUNKNOWN lpUnknown = NULL;
		SCODE sc = S_OK;
		if(pArgInf[2].m_dtDataType != _SDT_NULL && pArgInf[2].m_pText)
		{
			LPOLESTR lpzFile = ASCII2Unicode(pArgInf[2].m_pText);
			ITypeLib * ptlib;
			if(LoadTypeLib(lpzFile,&ptlib) == S_OK)
			{
				ULONG lHash= LHashValOfNameSys(SYS_WIN32,GetUserDefaultLCID(),lpzCom);
				ITypeInfo* pTinfo = NULL;
				MEMBERID rgMid;
				USHORT cFd;
				if(ptlib->FindName(lpzCom,lHash,&pTinfo,&rgMid,&cFd)==S_OK){
					if(cFd == 1){
						if(pTinfo->CreateInstance(NULL,IID_IUnknown, (LPVOID*)&lpUnknown)==S_OK){
							if(strchr(pArgInf[2].m_pText,'\\')!=NULL){
								pDest->hRet = RegisterTypeLib(ptlib,lpzFile,NULL);
							}
						}
						pTinfo->Release();
					}
					
				}
				ptlib->Release();
			}

			delete [] lpzFile;
			if(lpUnknown){
				delete [] lpzCom;
				goto RunCom;
			}
			

		}
		CLSID clsid;

		pDest->hRet = CLSIDFromProgID(lpzCom,&clsid);
		if(FAILED(pDest->hRet))
			pDest->hRet = CLSIDFromString(lpzCom,&clsid);
		delete [] lpzCom;
		if(FAILED(pDest->hRet))
			return FALSE;
		// create an instance of the object
		
		sc = CoCreateInstance(clsid, NULL, CLSCTX_ALL | CLSCTX_REMOTE_SERVER,
			IID_IUnknown, (LPVOID*)&lpUnknown);
		if (sc == E_INVALIDARG)
		{
			// may not support CLSCTX_REMOTE_SERVER, so try without
			sc = CoCreateInstance(clsid, NULL, CLSCTX_ALL & ~CLSCTX_REMOTE_SERVER,
				IID_IUnknown, (LPVOID*)&lpUnknown);
		}

		if (FAILED(sc))
			goto Failed;

RunCom:		
		// make sure it is running
		sc = OleRun(lpUnknown);
		if (FAILED(sc)){
			lpUnknown->Release();
			goto Failed;
		}
		// query for IDispatch interface
	/*	sc = lpUnknown->QueryInterface(IID_IDispatch,(void**)&pDest->pDisp);
		if (pDest->pDisp == NULL)
			goto Failed;*/
		pDest->hRet = sc;
		pDest->pDisp = (IDispatch*)lpUnknown;
		return TRUE;
		
Failed:

		pDest->hRet = sc;
		return FALSE;

	}

	/*
    调用格式： 〈逻辑型〉 对象．获取 （文本型 对象类型） - 系统核心支持库->对象
    英文名称：GetObject
    获取当前操作系统中已经存在的指定类型 COM 对象，本对象中的原有内容将被释放。成功返回真，否则返回假。本命令为初级对象成员命令。
    参数<1>的名称为“对象类型”，类型为“文本型（text）”。本参数指定对象的类型文本，譬如“Word.Application”、“Excel.Application”、“{000209FF-0000-0000-C000-000000000046}”等均可。
	
	*/
	BOOL _cdecl krnln_DispGetObject (INT nArgCount,MDATA_INF ArgInf,...)
	{
		PMDATA_INF pArgInf = &ArgInf;
		PEYDISPATCH pDest = (PEYDISPATCH)pArgInf[0].m_pCompoundData;
		if(pDest->pDisp)
		{
			pDest->pDisp->Release();
			pDest->pDisp=NULL;
		}
		CLSID clsid;
		LPOLESTR lpzCom = ASCII2Unicode(pArgInf[1].m_pText);
		pDest->hRet = CLSIDFromProgID(lpzCom,&clsid);
		if(FAILED(pDest->hRet))
			pDest->hRet = CLSIDFromString(lpzCom,&clsid);
		delete [] lpzCom;
		if(FAILED(pDest->hRet))
			return FALSE;

		DWORD dwReserved;
		pDest->hRet = GetActiveObject(clsid,&dwReserved,(LPUNKNOWN*)&pDest->pDisp);
		if(FAILED(pDest->hRet))
			return FALSE;
		return TRUE;

	}

	/*
    调用格式： 〈无返回值〉 对象．清除 （） - 系统核心支持库->对象
    英文名称：Clear
    将本对象的内容释放并清空。如果不调用本方法，则对象在退出其作用区域时会自动被释放。例如：假设对象存在于子程序局部变量中，当子程序调用退出时，该对象会被自动释放。本命令为初级对象成员命令。
	
	*/
	void _cdecl krnln_DispClear (INT nArgCount,MDATA_INF ArgInf,...)
	{
		PEYDISPATCH pDest = (PEYDISPATCH)ArgInf.m_pCompoundData;
		if(pDest->pDisp)
		{
			pDest->pDisp->Release();
			pDest->pDisp = NULL;
		}
		pDest->hRet = NULL;
		
	}

	/*
    调用格式： 〈逻辑型〉 对象．是否为空 （） - 系统核心支持库->对象
    英文名称：IsEmpty
    如果本对象的内容为空，返回真，否则返回假。本命令为初级对象成员命令。	
	*/
	BOOL _cdecl krnln_DispIsEmpty (INT nArgCount,MDATA_INF ArgInf,...)
	{
		PEYDISPATCH pDest = (PEYDISPATCH)ArgInf.m_pCompoundData;
		if(pDest->pDisp)
			return FALSE;
		return TRUE;
		
	}

	/*
    调用格式： 〈逻辑型〉 对象．是否相等 （对象 欲检查的对象） - 系统核心支持库->对象
    英文名称：IsEqual
    如果本对象的内容与指定对象的内容相等，返回真，否则返回假。本命令为初级对象成员命令。
    参数<1>的名称为“欲检查的对象”，类型为“对象（ComObject）”。本参数指定欲检查其内容是否相等的对象。
	
	*/
	BOOL _cdecl krnln_DispIsEqual (INT nArgCount,MDATA_INF ArgInf,...)
	{
		PMDATA_INF pArgInf = &ArgInf;
		PEYDISPATCH pDest = (PEYDISPATCH)pArgInf[0].m_pCompoundData;
		PEYDISPATCH pSrc = (PEYDISPATCH)pArgInf[1].m_pCompoundData;

		if(pDest->pDisp == pSrc->pDisp)
			return TRUE;
		return FALSE;

	}

	/*
    调用格式： 〈文本型〉 对象．读文本属性 （文本型 属性名称，［通用型 参数数据］，... ） - 系统核心支持库->对象
    英文名称：GetTextProperty
    读取并返回本对象的指定文本类型属性值，如果失败将返回空文本，且紧跟其后执行“取错误”方法将返回非空文本。本命令为初级对象成员命令。命令参数表中最后一个参数可以被重复添加。
    参数<1>的名称为“属性名称”，类型为“文本型（text）”。
    参数<2>的名称为“参数数据”，类型为“通用型（all）”，可以被省略。本参数及本参数后的所有扩展参数提供读写属性所需要的所有数据。如果读写该属性不需要任何参数，请保持本参数为空。
	*/
	char* _cdecl krnln_DispGetTextProperty (INT nArgCount,MDATA_INF ArgInf,...)
	{
		PMDATA_INF pArgInf = &ArgInf;
		PEYDISPATCH pDest = (PEYDISPATCH)pArgInf[0].m_pCompoundData;
		if(pDest->pDisp == NULL)
		{
			pDest->hRet = E_POINTER;
			return NULL;
		}
		LPDISPATCH lpDispatch = NULL;
		pDest->hRet = pDest->pDisp->QueryInterface(IID_IDispatch,(void **)&lpDispatch);
		if(pDest->hRet != S_OK)
			return NULL;
		DISPID dwDispid;
		pDest->hRet = Dispatch_GetIDsOfNames(lpDispatch,pArgInf[1].m_pText,&dwDispid);
		if(pDest->hRet != S_OK)
			return NULL;
		INT nCount = nArgCount - 2;
// 		if(pArgInf[nArgCount-1].m_dtDataType == _SDT_NULL)
// 			nCount --;
		for (int i = nArgCount - 1; i >= 2 && pArgInf[i].m_dtDataType == _SDT_NULL; i--)
			nCount --;
		
		VARIANT vaResult;
		memset(&vaResult, 0, sizeof vaResult);
		pDest->hRet = Dispatch_InvokeHelper(lpDispatch,
			dwDispid,DISPATCH_PROPERTYGET,&vaResult,nCount,&pArgInf[2]);

		lpDispatch->Release();

		LPSTR pText = NULL;
		if(vaResult.vt != VT_BSTR)
		{
			VARIANTARG vargDest;
			memcpy(&vargDest,&vaResult,sizeof(VARIANTARG));
			memset(&vaResult,0,sizeof(VARIANTARG));
			HRESULT hr = VariantChangeType(&vaResult,&vargDest,0,VT_BSTR);
			if(!FAILED(hr))
				pText = Unicode2EASCII(vaResult.bstrVal);
		}
		else
			pText = Unicode2EASCII(vaResult.bstrVal);
	/*	else{有取回的类型是对象型的
			VARIANTARG vargDest;
			memcpy(&vargDest,&vaResult,sizeof(VARIANTARG));
			memset(&vaResult,0,sizeof(VARIANTARG));
			pDest->hRet = VariantChangeType(&vaResult,&vargDest,0,VT_BSTR);
			VariantClear(&vargDest);

			if(pDest->hRet == S_OK){
				pText = Unicode2EASCII(vaResult.bstrVal);

			char ErrorString [1024];
  			wsprintf(ErrorString, "%s %d", pText,dwDispid);
			MessageBox(NULL,ErrorString,pArgInf[1].m_pText,MB_OK);
			}
		}*/
		
		VariantClear(&vaResult);


		return pText;
		
	}
	/*
    调用格式： 〈双精度小数型〉 对象．读数值属性 （文本型 属性名称，［通用型 参数数据］，... ） - 系统核心支持库->对象
    英文名称：GetNumProperty
    读取并返回本对象的指定数值类型属性值，如果失败将返回数值0，且紧跟其后执行“取错误”方法将返回非空文本。本命令为初级对象成员命令。命令参数表中最后一个参数可以被重复添加。
    参数<1>的名称为“属性名称”，类型为“文本型（text）”。
    参数<2>的名称为“参数数据”，类型为“通用型（all）”，可以被省略。本参数及本参数后的所有扩展参数提供读写属性所需要的所有数据。如果读写该属性不需要任何参数，请保持本参数为空。
	*/
	void _cdecl krnln_DispGetNumProperty (INT nArgCount,MDATA_INF ArgInf,...)
	{
		PMDATA_INF pArgInf = &ArgInf;
		PEYDISPATCH pDest = (PEYDISPATCH)pArgInf[0].m_pCompoundData;
		if(pDest->pDisp == NULL)
		{
			pDest->hRet = E_POINTER;
			return ;
		}
		LPDISPATCH lpDispatch = NULL;
		pDest->hRet = pDest->pDisp->QueryInterface(IID_IDispatch,(void **)&lpDispatch);
		if(pDest->hRet != S_OK)
			return ;
		DISPID dwDispid;
		pDest->hRet = Dispatch_GetIDsOfNames(lpDispatch,pArgInf[1].m_pText,&dwDispid);
		if(pDest->hRet != S_OK)
			return ;
		INT nCount = nArgCount - 2;
// 		if(pArgInf[nArgCount-1].m_dtDataType == _SDT_NULL)
// 			nCount --;
		for (int i = nArgCount - 1; i >= 2 && pArgInf[i].m_dtDataType == _SDT_NULL; i--)
			nCount --;

		VARIANT vaResult;
		memset(&vaResult, 0, sizeof vaResult);
		pDest->hRet = Dispatch_InvokeHelper(lpDispatch,
			dwDispid,DISPATCH_PROPERTYGET,&vaResult,nCount,&pArgInf[2]);



		lpDispatch->Release();
		MDATA_INF RetVal;

		switch (vaResult.vt)
		{
		case VT_UI1:
			RetVal.m_double = vaResult.bVal;
			break;
		case VT_I2:
			RetVal.m_double = vaResult.iVal;
			break;
		case VT_I4:
			RetVal.m_double = vaResult.lVal;
			break;
		case VT_R4:
			RetVal.m_double = vaResult.fltVal;
			break;
		case VT_R8:
			RetVal.m_double = vaResult.dblVal;
			break;
		case VT_DATE:
			RetVal.m_double = vaResult.date;
			break;
		case VT_CY:
			VarR8FromCy(vaResult.cyVal,&RetVal.m_double);
			break;
		case VT_I1:
			RetVal.m_double = vaResult.cVal;
			break;
		case VT_UI2:
			RetVal.m_double = vaResult.uiVal;
			break;
		case VT_UI4:
			RetVal.m_double = vaResult.ulVal;
			break;
		case VT_BOOL:
			VarR8FromBool(vaResult.boolVal,&RetVal.m_double);
			break;
		default:
			RetVal.m_double = 0;
			break;	
		}
		
		VariantClear(&vaResult);

		__asm
		{
			mov eax,RetVal.m_unit.m_dwFormID;
			mov edx,RetVal.m_unit.m_dwUnitID;
		}
		
	}
	/*
    调用格式： 〈逻辑型〉 对象．读逻辑属性 （文本型 属性名称，［通用型 参数数据］，... ） - 系统核心支持库->对象
    英文名称：GetBoolProperty
    读取并返回本对象的指定逻辑型属性值，如果失败将返回假，且紧跟其后执行“取错误”方法将返回非空文本。本命令为初级对象成员命令。命令参数表中最后一个参数可以被重复添加。
    参数<1>的名称为“属性名称”，类型为“文本型（text）”。
    参数<2>的名称为“参数数据”，类型为“通用型（all）”，可以被省略。本参数及本参数后的所有扩展参数提供读写属性所需要的所有数据。如果读写该属性不需要任何参数，请保持本参数为空。
	*/
	BOOL _cdecl krnln_DispGetBoolProperty (INT nArgCount,MDATA_INF ArgInf,...)
	{
		PMDATA_INF pArgInf = &ArgInf;
		PEYDISPATCH pDest = (PEYDISPATCH)pArgInf[0].m_pCompoundData;
		if(pDest->pDisp == NULL)
		{
			pDest->hRet = E_POINTER;
			return NULL;
		}
		LPDISPATCH lpDispatch = NULL;
		pDest->hRet = pDest->pDisp->QueryInterface(IID_IDispatch,(void **)&lpDispatch);
		if(pDest->hRet != S_OK)
			return NULL;
		DISPID dwDispid;
		pDest->hRet = Dispatch_GetIDsOfNames(lpDispatch,pArgInf[1].m_pText,&dwDispid);
		if(pDest->hRet != S_OK)
			return NULL;
		INT nCount = nArgCount - 2;
// 		if(pArgInf[nArgCount-1].m_dtDataType == _SDT_NULL)
// 			nCount --;
		for (int i = nArgCount - 1; i >= 2 && pArgInf[i].m_dtDataType == _SDT_NULL; i--)
			nCount --;

		VARIANT vaResult;
		memset(&vaResult, 0, sizeof vaResult);
		pDest->hRet = Dispatch_InvokeHelper(lpDispatch,
			dwDispid,DISPATCH_PROPERTYGET,&vaResult,nCount,&pArgInf[2]);
		lpDispatch->Release();
		BOOL bRet = FALSE;
		if(vaResult.vt == VT_BOOL)
			bRet =(vaResult.boolVal != 0 ? 1:0);
		
		VariantClear(&vaResult);

		return bRet;
		
	}
	/*
    调用格式： 〈日期时间型〉 对象．读日期属性 （文本型 属性名称，［通用型 参数数据］，... ） - 系统核心支持库->对象
    英文名称：GetDateProperty
    读取并返回本对象的指定日期时间型属性值，如果失败将返回100年1月1日，且紧跟其后执行“取错误”方法将返回非空文本。本命令为初级对象成员命令。命令参数表中最后一个参数可以被重复添加。
    参数<1>的名称为“属性名称”，类型为“文本型（text）”。
    参数<2>的名称为“参数数据”，类型为“通用型（all）”，可以被省略。本参数及本参数后的所有扩展参数提供读写属性所需要的所有数据。如果读写该属性不需要任何参数，请保持本参数为空。
	*/
	void _cdecl krnln_DispGetDateProperty (INT nArgCount,MDATA_INF ArgInf,...)
	{
		PMDATA_INF pArgInf = &ArgInf;
		PEYDISPATCH pDest = (PEYDISPATCH)pArgInf[0].m_pCompoundData;
		if(pDest->pDisp == NULL)
		{
			pDest->hRet = E_POINTER;
			return ;
		}
		LPDISPATCH lpDispatch = NULL;
		pDest->hRet = pDest->pDisp->QueryInterface(IID_IDispatch,(void **)&lpDispatch);
		if(pDest->hRet != S_OK)
			return ;
		DISPID dwDispid;
		pDest->hRet = Dispatch_GetIDsOfNames(lpDispatch,pArgInf[1].m_pText,&dwDispid);
		if(pDest->hRet != S_OK)
			return ;
		INT nCount = nArgCount - 2;
// 		if(pArgInf[nArgCount-1].m_dtDataType == _SDT_NULL)
// 			nCount --;
		for (int i = nArgCount - 1; i >= 2 && pArgInf[i].m_dtDataType == _SDT_NULL; i--)
			nCount --;

		VARIANT vaResult;
		memset(&vaResult, 0, sizeof vaResult);
		pDest->hRet = Dispatch_InvokeHelper(lpDispatch,
			dwDispid,DISPATCH_PROPERTYGET,&vaResult,nCount,&pArgInf[2]);
		lpDispatch->Release();

		MDATA_INF RetVal;

		if(vaResult.vt == VT_DATE)
			RetVal.m_date = vaResult.date;
		else
			RetVal.m_date = 0;
		
		VariantClear(&vaResult);

		__asm
		{
			mov eax,RetVal.m_unit.m_dwFormID;
			mov edx,RetVal.m_unit.m_dwUnitID;
		}
		
	}
	/*
    调用格式： 〈对象〉 对象．读对象型属性 （文本型 属性名称，［通用型 参数数据］，... ） - 系统核心支持库->对象
    英文名称：GetObjectProperty
    读取并返回本对象的指定对象属性值，如果失败将返回内容为空的对象，且紧跟其后执行“取错误”方法将返回非空文本。本命令为初级对象成员命令。命令参数表中最后一个参数可以被重复添加。
    参数<1>的名称为“属性名称”，类型为“文本型（text）”。
    参数<2>的名称为“参数数据”，类型为“通用型（all）”，可以被省略。本参数及本参数后的所有扩展参数提供读写属性所需要的所有数据。如果读写该属性不需要任何参数，请保持本参数为空。
	*/
	void* _cdecl krnln_DispGetObjectProperty (INT nArgCount,MDATA_INF ArgInf,...)
	{
		PMDATA_INF pArgInf = &ArgInf;
		PEYDISPATCH pdispRet = (PEYDISPATCH)E_MAlloc(sizeof(EYDISPATCH));
		//memset(pdispRet,0,sizeof(EYDISPATCH));
		PEYDISPATCH pDest = (PEYDISPATCH)pArgInf[0].m_pCompoundData;
		if(pDest->pDisp == NULL)
		{
			pDest->hRet = E_POINTER;
			return pdispRet;
		}
		LPDISPATCH lpDispatch = NULL;
		pDest->hRet = pDest->pDisp->QueryInterface(IID_IDispatch,(void **)&lpDispatch);
		if(pDest->hRet != S_OK)
			return pdispRet;
		DISPID dwDispid;
		pDest->hRet = Dispatch_GetIDsOfNames(lpDispatch,pArgInf[1].m_pText,&dwDispid);
		if(pDest->hRet != S_OK)
			return pdispRet;
		INT nCount = nArgCount - 2;
// 		if(pArgInf[nArgCount-1].m_dtDataType == _SDT_NULL)
// 			nCount --;
		for (int i = nArgCount - 1; i >= 2 && pArgInf[i].m_dtDataType == _SDT_NULL; i--)
			nCount --;

		VARIANT vaResult;
		memset(&vaResult, 0, sizeof vaResult);
		pDest->hRet = Dispatch_InvokeHelper(lpDispatch,
			dwDispid,DISPATCH_PROPERTYGET,&vaResult,nCount,&pArgInf[2]);
		lpDispatch->Release();
		

		switch (vaResult.vt)
		{
		case VT_DISPATCH:
			pdispRet->pDisp = vaResult.pdispVal;
			if(pdispRet->pDisp)
				pdispRet->pDisp->AddRef();
			break;
		case VT_UNKNOWN:
			pdispRet->pDisp = (LPDISPATCH)vaResult.punkVal;
			if(pdispRet->pDisp)
				pdispRet->pDisp->AddRef();
			break;
		case VT_DISPATCH|VT_BYREF:
			pdispRet->pDisp = *vaResult.ppdispVal;
			if(pdispRet->pDisp)
				pdispRet->pDisp->AddRef();
			break;
		case VT_UNKNOWN|VT_BYREF:
			pdispRet->pDisp = *(LPDISPATCH*)vaResult.ppunkVal;
			if(pdispRet->pDisp)
				pdispRet->pDisp->AddRef();
			break;
		}
		VariantClear(&vaResult);

		return pdispRet;
		
	}

	/*
    调用格式： 〈变体型〉 对象．读属性 （文本型 属性名称，［通用型 参数数据］，... ） - 系统核心支持库->对象
    英文名称：GetProperty
    读取并返回本对象的指定属性值，本方法可以用作读取任意类型的属性。如果失败将返回类型值为空的变体型对象，且紧跟其后执行“取错误”方法将返回非空文本，否则将返回包含对应数据类型数据的变体型对象。本命令为初级对象成员命令。命令参数表中最后一个参数可以被重复添加。
    参数<1>的名称为“属性名称”，类型为“文本型（text）”。
    参数<2>的名称为“参数数据”，类型为“通用型（all）”，可以被省略。本参数及本参数后的所有扩展参数提供读写属性所需要的所有数据。如果读写该属性不需要任何参数，请保持本参数为空。
	*/
	void* _cdecl krnln_DispGetProperty (INT nArgCount,MDATA_INF ArgInf,...)
	{
		PMDATA_INF pArgInf = &ArgInf;
		VARIANT* pVarRet = (VARIANT*)E_MAlloc(sizeof(VARIANT));
		//memset(pVarRet,0,sizeof(VARIANT));
		PEYDISPATCH pDest = (PEYDISPATCH)pArgInf[0].m_pCompoundData;
		if(pDest->pDisp == NULL)
		{
			pDest->hRet = E_POINTER;
			return pVarRet;
		}
		LPDISPATCH lpDispatch = NULL;
		pDest->hRet = pDest->pDisp->QueryInterface(IID_IDispatch,(void **)&lpDispatch);
		if(pDest->hRet != S_OK)
			return pVarRet;
		DISPID dwDispid;
		pDest->hRet = Dispatch_GetIDsOfNames(lpDispatch,pArgInf[1].m_pText,&dwDispid);
		if(pDest->hRet != S_OK)
			return pVarRet;
		INT nCount = nArgCount - 2;
// 		if(pArgInf[nArgCount-1].m_dtDataType == _SDT_NULL)
// 			nCount --;
		for (int i = nArgCount - 1; i >= 2 && pArgInf[i].m_dtDataType == _SDT_NULL; i--)
			nCount --;
		/*char tt[2];
		itoa(nCount,tt,10);
		MessageBox(NULL,tt,"count",MB_OK);*/

		pDest->hRet = Dispatch_InvokeHelper(lpDispatch,
			dwDispid,DISPATCH_PROPERTYGET,pVarRet,nCount,&pArgInf[2]);
		lpDispatch->Release();
		
		return pVarRet;
		
	}

	/*
    调用格式： 〈逻辑型〉 对象．写属性 （文本型 属性名称，［通用型 参数数据］，... ） - 系统核心支持库->对象
    英文名称：SetProperty
    设置本对象指定属性的值，如果失败，返回假，并且紧跟其后执行“取错误”方法将返回非空文本。本命令为初级对象成员命令。命令参数表中最后一个参数可以被重复添加。
    参数<1>的名称为“属性名称”，类型为“文本型（text）”。
    参数<2>的名称为“参数数据”，类型为“通用型（all）”，可以被省略。本参数及本参数后的所有扩展参数提供读写属性所需要的所有数据。如果读写该属性不需要任何参数，请保持本参数为空。
	*/
	BOOL _cdecl krnln_DispSetProperty (INT nArgCount,MDATA_INF ArgInf,...)
	{
		PMDATA_INF pArgInf = &ArgInf;
		PEYDISPATCH pDest = (PEYDISPATCH)pArgInf[0].m_pCompoundData;
		if(pDest->pDisp == NULL)
		{
			pDest->hRet = E_POINTER;
			return NULL;
		}
		LPDISPATCH lpDispatch = NULL;
		pDest->hRet = pDest->pDisp->QueryInterface(IID_IDispatch,(void **)&lpDispatch);
		if(pDest->hRet != S_OK)
			return NULL;
		DISPID dwDispid;
		pDest->hRet = Dispatch_GetIDsOfNames(lpDispatch,pArgInf[1].m_pText,&dwDispid);
		if(pDest->hRet != S_OK)
			return NULL;

		INT nCount = nArgCount - 2;
// 		if(pArgInf[nArgCount-1].m_dtDataType == _SDT_NULL)
// 			nCount --;
		for (int i = nArgCount - 1; i >= 2 && pArgInf[i].m_dtDataType == _SDT_NULL; i--)
			nCount --;

		DWORD dwFlags = DISPATCH_PROPERTYPUT;
/*		if(nCount>0 && (pArgInf[2].m_dtDataType & ~DT_IS_ARY) == DTP_COM_OBJECT)
			dwFlags = DISPATCH_PROPERTYPUTREF;
		else
			dwFlags = DISPATCH_PROPERTYPUT;*/

		pDest->hRet = Dispatch_InvokeHelper(lpDispatch,
			dwDispid,(WORD)dwFlags,NULL,nCount,&pArgInf[2]);
		lpDispatch->Release();
		BOOL bRet;
		if(pDest->hRet == S_OK)
			bRet = TRUE;
		else
			bRet = FALSE;
		return bRet;
		
	}
	/*
    调用格式： 〈无返回值〉 对象．方法 （文本型 方法名称，［通用型 参数数据］，... ） - 系统核心支持库->对象
    英文名称：RunMethod
    执行本对象的指定方法并忽略其返回值，如果失败，紧跟其后执行“取错误”方法将返回非空文本。本命令为初级对象成员命令。命令参数表中最后一个参数可以被重复添加。
    参数<1>的名称为“方法名称”，类型为“文本型（text）”。本参数提供欲调用方法的名称。
    参数<2>的名称为“参数数据”，类型为“通用型（all）”，可以被省略。本参数及本参数后的所有扩展参数提供调用方法所需要的所有数据。如果该方法不需要任何参数，请保持本参数为空。
	*/
	void _cdecl krnln_DispRunMethod (INT nArgCount,MDATA_INF ArgInf,...)
	{
		PMDATA_INF pArgInf = &ArgInf;
		PEYDISPATCH pDest = (PEYDISPATCH)pArgInf[0].m_pCompoundData;
		if(pDest->pDisp == NULL)
		{
			pDest->hRet = E_POINTER;
			return ;
		}
		LPDISPATCH lpDispatch = NULL;
		pDest->hRet = pDest->pDisp->QueryInterface(IID_IDispatch,(void **)&lpDispatch);
		if(pDest->hRet != S_OK)
			return ;
		DISPID dwDispid;
		pDest->hRet = Dispatch_GetIDsOfNames(lpDispatch,pArgInf[1].m_pText,&dwDispid);
		if(pDest->hRet != S_OK)
			return ;
		INT nCount = nArgCount - 2;
// 		if(pArgInf[nArgCount-1].m_dtDataType == _SDT_NULL)
// 			nCount --;
		for (int i = nArgCount - 1; i >= 2 && pArgInf[i].m_dtDataType == _SDT_NULL; i--)
			nCount --;

		VARIANT vaResult;
		memset(&vaResult, 0, sizeof vaResult);
		pDest->hRet = Dispatch_InvokeHelper(lpDispatch,
			dwDispid,DISPATCH_METHOD,&vaResult,nCount,&pArgInf[2]);
		lpDispatch->Release();
		if(vaResult.vt != VT_EMPTY)
			VariantClear(&vaResult);
		
	}

	/*
    调用格式： 〈变体型〉 对象．通用方法 （文本型 方法名称，［通用型 参数数据］，... ） - 系统核心支持库->对象
    英文名称：RunVariantMethod
    执行本对象的指定方法并返回一个变体型对象值，该对象内记录该方法的返回数据。本命令可以用作执行返回任何数据类型数据的方法，如果该方法没有返回数据，所返回变体型对象的类型值将为空。如果失败，将返回一个类型值为空的变体型对象，且紧跟其后执行“取错误”方法将返回非空文本。本命令为初级对象成员命令。命令参数表中最后一个参数可以被重复添加。
    参数<1>的名称为“方法名称”，类型为“文本型（text）”。本参数提供欲调用方法的名称。
    参数<2>的名称为“参数数据”，类型为“通用型（all）”，可以被省略。本参数及本参数后的所有扩展参数提供调用方法所需要的所有数据。如果该方法不需要任何参数，请保持本参数为空。
	*/
	void* _cdecl krnln_DispRunVariantMethod (INT nArgCount,MDATA_INF ArgInf,...)
	{
		PMDATA_INF pArgInf = &ArgInf;
		VARIANT* pVarRet = (VARIANT*)E_MAlloc(sizeof(VARIANT));
		//memset(pVarRet,0,sizeof(VARIANT));
		PEYDISPATCH pDest = (PEYDISPATCH)pArgInf[0].m_pCompoundData;
		if(pDest->pDisp == NULL)
		{
			pDest->hRet = E_POINTER;
			return pVarRet;
		}
		LPDISPATCH lpDispatch = NULL;
		pDest->hRet = pDest->pDisp->QueryInterface(IID_IDispatch,(void **)&lpDispatch);
		if(pDest->hRet != S_OK)
			return pVarRet;
		DISPID dwDispid;
		pDest->hRet = Dispatch_GetIDsOfNames(lpDispatch,pArgInf[1].m_pText,&dwDispid);
		if(pDest->hRet != S_OK)
			return pVarRet;
		INT nCount = nArgCount - 2;
// 		if(pArgInf[nArgCount-1].m_dtDataType == _SDT_NULL)
// 			nCount --;
		for (int i = nArgCount - 1; i >= 2 && pArgInf[i].m_dtDataType == _SDT_NULL; i--)
			nCount --;

		pDest->hRet = Dispatch_InvokeHelper(lpDispatch,
			dwDispid,DISPATCH_METHOD,pVarRet,nCount,&pArgInf[2]);
		lpDispatch->Release();
		
		return pVarRet;
		
	}

	/*
    调用格式： 〈文本型〉 对象．文本方法 （文本型 方法名称，［通用型 参数数据］，... ） - 系统核心支持库->对象
    英文名称：RunTextMethod
    执行本对象返回文本类型数据的方法，如果失败将返回空文本，且紧跟其后执行“取错误”方法将返回非空文本。本命令为初级对象成员命令。命令参数表中最后一个参数可以被重复添加。
    参数<1>的名称为“方法名称”，类型为“文本型（text）”。本参数提供欲调用方法的名称。
    参数<2>的名称为“参数数据”，类型为“通用型（all）”，可以被省略。本参数及本参数后的所有扩展参数提供调用方法所需要的所有数据。如果该方法不需要任何参数，请保持本参数为空。
	*/
	char* _cdecl krnln_DispRunTextMethod (INT nArgCount,MDATA_INF ArgInf,...)
	{
		PMDATA_INF pArgInf = &ArgInf;
		PEYDISPATCH pDest = (PEYDISPATCH)pArgInf[0].m_pCompoundData;
		if(pDest->pDisp == NULL)
		{
			pDest->hRet = E_POINTER;
			return NULL;
		}
		LPDISPATCH lpDispatch = NULL;
		pDest->hRet = pDest->pDisp->QueryInterface(IID_IDispatch,(void **)&lpDispatch);
		if(pDest->hRet != S_OK)
			return NULL;
		DISPID dwDispid;
		pDest->hRet = Dispatch_GetIDsOfNames(lpDispatch,pArgInf[1].m_pText,&dwDispid);
		if(pDest->hRet != S_OK)
			return NULL;
		INT nCount = nArgCount - 2;
// 		if(pArgInf[nArgCount-1].m_dtDataType == _SDT_NULL)
// 			nCount --;
		for (int i = nArgCount - 1; i >= 2 && pArgInf[i].m_dtDataType == _SDT_NULL; i--)
			nCount --;

		VARIANT vaResult;
		memset(&vaResult, 0, sizeof vaResult);
		pDest->hRet = Dispatch_InvokeHelper(lpDispatch,
			dwDispid,DISPATCH_METHOD,&vaResult,nCount,&pArgInf[2]);
		lpDispatch->Release();

		LPSTR pText = NULL;
		if(vaResult.vt != VT_BSTR)
		{
			VARIANTARG vargDest;
			memcpy(&vargDest,&vaResult,sizeof(VARIANTARG));
			memset(&vaResult,0,sizeof(VARIANTARG));
			HRESULT hr = VariantChangeType(&vaResult,&vargDest,0,VT_BSTR);
 			if(!FAILED(hr))
 				pText = Unicode2EASCII(vaResult.bstrVal);
		}
		else
			pText = Unicode2EASCII(vaResult.bstrVal);

		VariantClear(&vaResult);

		return pText;
	}

	/*
    调用格式： 〈双精度小数型〉 对象．数值方法 （文本型 方法名称，［通用型 参数数据］，... ） - 系统核心支持库->对象
    英文名称：RunNumMethod
    执行本对象返回数值类型数据的方法，如果失败将返回数值0，且紧跟其后执行“取错误”方法将返回非空文本。本命令为初级对象成员命令。命令参数表中最后一个参数可以被重复添加。
    参数<1>的名称为“方法名称”，类型为“文本型（text）”。本参数提供欲调用方法的名称。
    参数<2>的名称为“参数数据”，类型为“通用型（all）”，可以被省略。本参数及本参数后的所有扩展参数提供调用方法所需要的所有数据。如果该方法不需要任何参数，请保持本参数为空。
	*/
	void _cdecl krnln_DispRunNumMethod (INT nArgCount,MDATA_INF ArgInf,...)
	{
		PMDATA_INF pArgInf = &ArgInf;
		PEYDISPATCH pDest = (PEYDISPATCH)pArgInf[0].m_pCompoundData;
		if(pDest->pDisp == NULL)
		{
			pDest->hRet = E_POINTER;
			return ;
		}

		LPDISPATCH lpDispatch = NULL;
		pDest->hRet = pDest->pDisp->QueryInterface(IID_IDispatch,(void **)&lpDispatch);
		if(pDest->hRet != S_OK)
			return ;
		DISPID dwDispid;
		pDest->hRet = Dispatch_GetIDsOfNames(lpDispatch,pArgInf[1].m_pText,&dwDispid);

		if(pDest->hRet != S_OK)
			return ;
		INT nCount = nArgCount - 2;
// 		if(pArgInf[nArgCount-1].m_dtDataType == _SDT_NULL)
// 			nCount --;
		for (int i = nArgCount - 1; i >= 2 && pArgInf[i].m_dtDataType == _SDT_NULL; i--)
			nCount --;

		VARIANT vaResult;
		memset(&vaResult, 0, sizeof vaResult);
		pDest->hRet = Dispatch_InvokeHelper(lpDispatch,
			dwDispid,DISPATCH_METHOD,&vaResult,nCount,&pArgInf[2]);
		lpDispatch->Release();
		MDATA_INF RetVal;
		
		switch (vaResult.vt)
		{
		case VT_UI1:
			RetVal.m_double = vaResult.bVal;
			break;
		case VT_I2:
			RetVal.m_double = vaResult.iVal;
			break;
		case VT_I4:
			RetVal.m_double = vaResult.lVal;
			break;
		case VT_R4:
			RetVal.m_double = vaResult.fltVal;
			break;
		case VT_R8:
			RetVal.m_double = vaResult.dblVal;
			break;
		case VT_DATE:
			RetVal.m_double = vaResult.date;
			break;
		case VT_CY:
			VarR8FromCy(vaResult.cyVal,&RetVal.m_double);
			break;
		case VT_I1:
			RetVal.m_double = vaResult.cVal;
			break;
		case VT_UI2:
			RetVal.m_double = vaResult.uiVal;
			break;
		case VT_UI4:
			RetVal.m_double = vaResult.ulVal;
			break;
		case VT_BOOL:
			VarR8FromBool(vaResult.boolVal,&RetVal.m_double);
			break;
		default:
			RetVal.m_double = 0;
			break;	
		}
		
		VariantClear(&vaResult);

		__asm
		{
			mov eax,RetVal.m_unit.m_dwFormID;
			mov edx,RetVal.m_unit.m_dwUnitID;
		}
		
	}
	/*
    调用格式： 〈逻辑型〉 对象．逻辑方法 （文本型 方法名称，［通用型 参数数据］，... ） - 系统核心支持库->对象
    英文名称：RunBoolMethod
    执行本对象返回逻辑型数据的方法，如果失败将返回假，且紧跟其后执行“取错误”方法将返回非空文本。本命令为初级对象成员命令。命令参数表中最后一个参数可以被重复添加。
    参数<1>的名称为“方法名称”，类型为“文本型（text）”。本参数提供欲调用方法的名称。
    参数<2>的名称为“参数数据”，类型为“通用型（all）”，可以被省略。本参数及本参数后的所有扩展参数提供调用方法所需要的所有数据。如果该方法不需要任何参数，请保持本参数为空。
	*/
	BOOL _cdecl krnln_DispRunBoolMethod (INT nArgCount,MDATA_INF ArgInf,...)
	{
		PMDATA_INF pArgInf = &ArgInf;
		PEYDISPATCH pDest = (PEYDISPATCH)pArgInf[0].m_pCompoundData;
		if(pDest->pDisp == NULL)
		{
			pDest->hRet = E_POINTER;
			return NULL;
		}
		LPDISPATCH lpDispatch = NULL;
		pDest->hRet = pDest->pDisp->QueryInterface(IID_IDispatch,(void **)&lpDispatch);
		if(pDest->hRet != S_OK)
			return NULL;
		DISPID dwDispid;
		pDest->hRet = Dispatch_GetIDsOfNames(lpDispatch,pArgInf[1].m_pText,&dwDispid);
		if(pDest->hRet != S_OK)
			return NULL;
		INT nCount = nArgCount - 2;
// 		if(pArgInf[nArgCount-1].m_dtDataType == _SDT_NULL)
// 			nCount --;
		for (int i = nArgCount - 1; i >= 2 && pArgInf[i].m_dtDataType == _SDT_NULL; i--)
			nCount --;

		VARIANT vaResult;
		memset(&vaResult, 0, sizeof vaResult);
		pDest->hRet = Dispatch_InvokeHelper(lpDispatch,
			dwDispid,DISPATCH_METHOD,&vaResult,nCount,&pArgInf[2]);
		lpDispatch->Release();
		BOOL bRet = FALSE;
		if(vaResult.vt == VT_BOOL)
			bRet =(vaResult.boolVal != 0 ? 1:0);
		
		VariantClear(&vaResult);

		return bRet;
		
	}
	/*
    调用格式： 〈日期时间型〉 对象．日期方法 （文本型 方法名称，［通用型 参数数据］，... ） - 系统核心支持库->对象
    英文名称：RunDateMethod
    执行本对象返回日期时间型数据的方法，如果失败将返回100年1月1日，且紧跟其后执行“取错误”方法将返回非空文本。本命令为初级对象成员命令。命令参数表中最后一个参数可以被重复添加。
    参数<1>的名称为“方法名称”，类型为“文本型（text）”。本参数提供欲调用方法的名称。
    参数<2>的名称为“参数数据”，类型为“通用型（all）”，可以被省略。本参数及本参数后的所有扩展参数提供调用方法所需要的所有数据。如果该方法不需要任何参数，请保持本参数为空。
	*/
	void _cdecl krnln_DispRunDateMethod (INT nArgCount,MDATA_INF ArgInf,...)
	{
		PMDATA_INF pArgInf = &ArgInf;
		PEYDISPATCH pDest = (PEYDISPATCH)pArgInf[0].m_pCompoundData;
		if(pDest->pDisp == NULL)
		{
			pDest->hRet = E_POINTER;
			return ;
		}
		LPDISPATCH lpDispatch = NULL;
		pDest->hRet = pDest->pDisp->QueryInterface(IID_IDispatch,(void **)&lpDispatch);
		if(pDest->hRet != S_OK)
			return ;
		DISPID dwDispid;
		pDest->hRet = Dispatch_GetIDsOfNames(lpDispatch,pArgInf[1].m_pText,&dwDispid);
		if(pDest->hRet != S_OK)
			return ;
		INT nCount = nArgCount - 2;
// 		if(pArgInf[nArgCount-1].m_dtDataType == _SDT_NULL)
// 			nCount --;
		for (int i = nArgCount - 1; i >= 2 && pArgInf[i].m_dtDataType == _SDT_NULL; i--)
			nCount --;

		VARIANT vaResult;
		memset(&vaResult, 0, sizeof vaResult);
		pDest->hRet = Dispatch_InvokeHelper(lpDispatch,
			dwDispid,DISPATCH_METHOD,&vaResult,nCount,&pArgInf[2]);
		lpDispatch->Release();

		MDATA_INF RetVal;

		if(vaResult.vt == VT_DATE)
			RetVal.m_date = vaResult.date;
		else
			RetVal.m_date = 0;
		
		VariantClear(&vaResult);

		__asm
		{
			mov eax,RetVal.m_unit.m_dwFormID;
			mov edx,RetVal.m_unit.m_dwUnitID;
		}
		
	}
	/*
    调用格式： 〈对象〉 对象．对象型方法 （文本型 方法名称，［通用型 参数数据］，... ） - 系统核心支持库->对象
    英文名称：RunObjectMethod
    执行本对象返回对象型数据的方法，如果失败将返回内容为空的对象，且紧跟其后执行“取错误”方法将返回非空文本。本命令为初级对象成员命令。命令参数表中最后一个参数可以被重复添加。
    参数<1>的名称为“方法名称”，类型为“文本型（text）”。本参数提供欲调用方法的名称。
    参数<2>的名称为“参数数据”，类型为“通用型（all）”，可以被省略。本参数及本参数后的所有扩展参数提供调用方法所需要的所有数据。如果该方法不需要任何参数，请保持本参数为空。
	*/
	void* _cdecl krnln_DispRunObjectMethod (INT nArgCount,MDATA_INF ArgInf,...)
	{
		PMDATA_INF pArgInf = &ArgInf;
		PEYDISPATCH pdispRet = (PEYDISPATCH)E_MAlloc(sizeof(EYDISPATCH));
		//memset(pdispRet,0,sizeof(EYDISPATCH));
		PEYDISPATCH pDest = (PEYDISPATCH)pArgInf[0].m_pCompoundData;
		if(pDest->pDisp == NULL)
		{
			pDest->hRet = E_POINTER;
			return pdispRet;
		}
		LPDISPATCH lpDispatch = NULL;
		pDest->hRet = pDest->pDisp->QueryInterface(IID_IDispatch,(void **)&lpDispatch);
		if(pDest->hRet != S_OK)
			return pdispRet;
		DISPID dwDispid;
		pDest->hRet = Dispatch_GetIDsOfNames(lpDispatch,pArgInf[1].m_pText,&dwDispid);
		if(pDest->hRet != S_OK)
			return pdispRet;
		INT nCount = nArgCount - 2;
// 		if(pArgInf[nArgCount-1].m_dtDataType == _SDT_NULL)
// 			nCount --;
		for (int i = nArgCount - 1; i >= 2 && pArgInf[i].m_dtDataType == _SDT_NULL; i--)
			nCount --;

		VARIANT vaResult;
		memset(&vaResult, 0, sizeof vaResult);
		pDest->hRet = Dispatch_InvokeHelper(lpDispatch,
			dwDispid,DISPATCH_METHOD,&vaResult,nCount,&pArgInf[2]);
		lpDispatch->Release();
		
		switch (vaResult.vt)
		{
		case VT_DISPATCH:
			pdispRet->pDisp = vaResult.pdispVal;
			if(pdispRet->pDisp)
				pdispRet->pDisp->AddRef();
			break;
		case VT_UNKNOWN:
			pdispRet->pDisp = (LPDISPATCH)vaResult.punkVal;
			if(pdispRet->pDisp)
				pdispRet->pDisp->AddRef();
			break;
		case VT_DISPATCH|VT_BYREF:
			pdispRet->pDisp = *vaResult.ppdispVal;
			if(pdispRet->pDisp)
				pdispRet->pDisp->AddRef();
			break;
		case VT_UNKNOWN|VT_BYREF:
			pdispRet->pDisp = *(LPDISPATCH*)vaResult.ppunkVal;
			if(pdispRet->pDisp)
				pdispRet->pDisp->AddRef();
			break;
		}
		VariantClear(&vaResult);

		return pdispRet;
		
	}

	/*
     调用格式： 〈逻辑型〉 对象．创建图片对象 （字节集 图片数据） - 系统核心支持库->对象
    英文名称：CreatePicDispObj
    为指定图片数据创建对应的 COM 图片对象，本对象中的原有内容将被释放。成功返回真，否则返回假。本命令为初级对象成员命令。
    参数<1>的名称为“图片数据”，类型为“字节集（bin）”。本参数提供欲用作创建图片对象的图片数据。
	*/
	BOOL _cdecl krnln_DispCreatePicDispObj (INT nArgCount,MDATA_INF ArgInf,...)
	{
		PMDATA_INF pArgInf = &ArgInf;
		PEYDISPATCH pDest = (PEYDISPATCH)pArgInf[0].m_pCompoundData;
		if(pDest->pDisp)
		{
			pDest->pDisp->Release();
			pDest->pDisp=NULL;
		}
		if(pArgInf[1].m_pBin==NULL)
		{
			pDest->hRet = E_POINTER;
			return FALSE;
		}
		INT nLength=*(LPINT)(pArgInf[1].m_pBin + sizeof (INT));
		if(nLength <= 0)
		{
			pDest->hRet = E_POINTER;
			return FALSE;
		}
		BYTE* pbuf=pArgInf[1].m_pBin + sizeof (INT) * 2;
		LPVOID pvData = NULL;
		//分配内存，准备读入图片文件的数据
		//GlobalAlloc从堆分配指定字节的内存区域
		HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, nLength);
		//GlobalLock函数锁住一个全局的内存对象同时返回一个指向对象首字节的指针 
		pvData = GlobalLock(hGlobal);
		memcpy(pvData,pbuf,nLength);
		GlobalUnlock(hGlobal);

		//到此，我们已经把文件的数据读到了内存当中
		LPSTREAM pstm = NULL;
		//从全局内存创建IStream接口指针
		pDest->hRet = CreateStreamOnHGlobal(hGlobal, TRUE, &pstm);
		if(FAILED(pDest->hRet))
		{
			GlobalFree(hGlobal); 
			return FALSE;
		}

		//根据图片文件创建IPicture接口指针
		pDest->hRet = ::OleLoadPicture(pstm, nLength, FALSE, IID_IPicture, (LPVOID *)&pDest->pDisp);
		pstm->Release();
		GlobalFree(hGlobal); 

		if(FAILED(pDest->hRet))
			return FALSE;
		return TRUE;
		
	}
	/*
    调用格式： 〈字节集〉 对象．取回图片 （） - 系统核心支持库->对象
    英文名称：GetPic
    如果本对象为 COM 图片对象，则取回其具体图片数据。成功返回图片数据字节集，失败返回空字节集。本命令为初级对象成员命令。
	*/
	void* _cdecl krnln_DispGetPic (INT nArgCount,MDATA_INF ArgInf,...)
	{
		PMDATA_INF pArgInf = &ArgInf;
		PEYDISPATCH pDest = (PEYDISPATCH)pArgInf[0].m_pCompoundData;
		if(pDest->pDisp == NULL)
		{
			pDest->hRet = E_POINTER;
			return NULL;
		}
		IPicture*   pPicture=NULL;   
		pDest->hRet = pDest->pDisp->QueryInterface(IID_IPicture,(void **)&pPicture);
		if(pDest->hRet != S_OK)
			return NULL;
		LPSTREAM   pStream;   
		CreateStreamOnHGlobal(NULL,TRUE,&pStream);   
		LONG   size;   
		pDest->hRet = pPicture->SaveAsFile(pStream,TRUE,&size);
		if(pDest->hRet != S_OK || size==0)
		{
			pPicture->Release ();
			return NULL;
		}
		LARGE_INTEGER   li;   
		li.HighPart   =0;   
		li.LowPart   =0;   
		ULARGE_INTEGER   ulnewpos;   
		pStream->Seek(   li,STREAM_SEEK_SET,&ulnewpos);  
		
		LPBYTE pd = (LPBYTE)E_MAlloc ((DWORD)(sizeof (INT) * 2 + size));
		*(LPINT)pd = 1;
		*(LPINT)(pd + sizeof (INT)) =	size;
		ULONG   uReadCount   =   1;   
		pDest->hRet =pStream->Read(pd + sizeof (INT) * 2,size,&uReadCount); 
		pStream->Release();   
		pPicture->Release ();
		return pd;
	}
	/*
    调用格式： 〈文本型〉 对象．取错误 （） - 系统核心支持库->对象
    英文名称：GetErrorText
    当读写对象属性、执行对象方法或取回字体时，紧跟该语句后执行本方法可以检查其是否执行成功。如果成功，本命令将返回空文本，如果失败，本命令将返回一个描述具体错误信息的非空文本。本命令为初级对象成员命令。	
	*/
	char* _cdecl krnln_DispGetErrorText (INT nArgCount,MDATA_INF ArgInf,...)
	{
		PEYDISPATCH pDest = (PEYDISPATCH)ArgInf.m_pCompoundData;
		if(pDest->hRet == NULL)
			return NULL;
		char strErr[MAX_PATH];
		LPSTR pText = NULL;
		DWORD dwLen = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM,NULL,pDest->hRet,NULL,strErr,MAX_PATH,NULL);
		if(dwLen)
			pText = CloneTextData(strErr,mystrlen(strErr));
		return pText;
		
	}
	/*
    调用格式： 〈逻辑型〉 对象．取接口 （通用型 对象或窗口组件，［文本型 接口标志符］） - 系统核心支持库->对象
    英文名称：QueryInterface
    获取指定对象或者OCX窗口组件中的指定接口，本对象中的原有内容将被释放。成功返回真，失败返回假。本命令为初级对象成员命令。
    参数<1>的名称为“对象或窗口组件”，类型为“通用型（all）”。本参数提供欲获取其接口对象的对象数据，其数据类型为以下之一：1、COM包装库封装出来的对象型数据类型； 2、核心支持库中的“对象”数据类型(即本数据类型)； 3、COM包装库封装出来的OCX窗口组件数据类型。
    参数<2>的名称为“接口标志符”，类型为“文本型（text）”，可以被省略。可以在本参数中指定欲获取接口的具体名称或其全球唯一标志符(GUID)，如“IDataSourceControl”、{B62EE548-2B65-43BE-9F39-E2B71742578A}等。如果本参数被省略，则默认取出对象的基本接口。	
	*/
	BOOL _cdecl krnln_DispQueryInterface (INT nArgCount,MDATA_INF ArgInf,...)
	{
		PMDATA_INF pArgInf = &ArgInf;
		PEYDISPATCH pDest = (PEYDISPATCH)pArgInf[0].m_pCompoundData;
		if(pDest->pDisp)
		{
			pDest->pDisp->Release();
			pDest->pDisp=NULL;
		}
		if(pArgInf[1].m_dtDataType != DTP_COM_OBJECT)
		{
			pDest->hRet = E_POINTER;
			return FALSE;
		}
		PEYDISPATCH pSrc = (PEYDISPATCH)pArgInf[1].m_pCompoundData;
		if(pSrc->pDisp==NULL)
		{
			pDest->hRet = E_POINTER;
			return FALSE;
		}

		CLSID clsid;
		if(pArgInf[2].m_dtDataType != _SDT_NULL)
		{
			LPOLESTR lpzCom = ASCII2Unicode(pArgInf[2].m_pText);
			pDest->hRet = CLSIDFromProgID(lpzCom,&clsid);
			if(FAILED(pDest->hRet))
				pDest->hRet = CLSIDFromString(lpzCom,&clsid);
			delete [] lpzCom;
			if(FAILED(pDest->hRet))
				return FALSE;
		}
		else
			clsid = IID_IDispatch;

		pDest->hRet = pSrc->pDisp->QueryInterface(clsid,(void**)&pDest->pDisp);
		if(FAILED(pDest->hRet))
			return FALSE;
		return TRUE;

	}
	/*
    调用格式： 〈逻辑型〉 对象．创建字体对象 （字体 字体数据） - 系统核心支持库->对象
    英文名称：CreateFontDispObj
    为指定字体数据创建对应的 COM 字体对象，本对象中的原有内容将被释放。成功返回真，否则返回假。本命令为初级对象成员命令。
    参数<1>的名称为“字体数据”，类型为“字体（font）”。本参数提供欲用作创建字体对象的字体数据。
	*/
	BOOL _cdecl krnln_DispCreateFontDispObj (INT nArgCount,MDATA_INF ArgInf,...)
	{
		PMDATA_INF pArgInf = &ArgInf;
		PEYDISPATCH pDest = (PEYDISPATCH)pArgInf[0].m_pCompoundData;
		if(pDest->pDisp)
		{
			pDest->pDisp->Release();
			pDest->pDisp=NULL;
		}
		if(pArgInf[1].m_pBin==NULL)
		{
			pDest->hRet = E_POINTER;
			return FALSE;
		}
		FONTDESC fd;
		fd.cbSizeofstruct = sizeof(FONTDESC);
		fd.lpstrName = ASCII2Unicode((LPSTR)pArgInf[1].m_pInt[6]);
		fd.sWeight = (short)pArgInf[1].m_pInt[1]?700:400;
		fd.sCharset = DEFAULT_CHARSET;
		fd.fItalic = pArgInf[1].m_pInt[2];
		fd.fUnderline = pArgInf[1].m_pInt[4];
		fd.fStrikethrough = pArgInf[1].m_pInt[3];

		fd.cySize.Lo = pArgInf[1].m_pInt[5]*10000;  
		fd.cySize.Hi = 0;
		
		pDest->hRet = OleCreateFontIndirect(&fd, IID_IFontDisp, (void**) &pDest->pDisp);
		delete [] fd.lpstrName;
		if(FAILED(pDest->hRet))
			return FALSE;
		return TRUE;
	}
	/*
    调用格式： 〈字体〉 对象．取回字体 （） - 系统核心支持库->对象
    英文名称：GetFont
    如果本对象为 COM 字体对象，则取回其具体字体数据。如果失败，紧跟其后执行“取错误”方法将返回非空文本。本命令为初级对象成员命令。
	*/
	void* _cdecl krnln_DispGetFont (INT nArgCount,MDATA_INF ArgInf,...)
	{
		LPINT pFont = (LPINT)E_MAlloc ((DWORD)(sizeof (INT) * 7));
		PMDATA_INF pArgInf = &ArgInf;
		PEYDISPATCH pDest = (PEYDISPATCH)pArgInf[0].m_pCompoundData;
		if(pDest->pDisp == NULL)
		{
			pDest->hRet = E_POINTER;
			return pFont;
		}
		IFont*pDisp = NULL;
		pDest->hRet = pDest->pDisp->QueryInterface(IID_IFont, (void**) &pDisp);
		if(FAILED(pDest->hRet))
			return pFont;
		pDisp->get_Bold(&pFont[1]);
		pDisp->get_Italic(&pFont[2]);
		pDisp->get_Strikethrough(&pFont[3]);
		pDisp->get_Underline(&pFont[4]);

		CY cySize;
		pDisp->get_Size(&cySize);
		pFont[5]=cySize.Lo/10000;
		BSTR strName=NULL;
		pDisp->get_Name(&strName);
		pDisp->Release();
		if(strName)
		{
			pFont[6]=(INT)Unicode2EASCII(strName);
			SysFreeString(strName);
		}
		

		return pFont;
	}
}
/*
HRESULT hr = S_OK; 
FUNCDESC* pFuncDesc = NULL; 
TYPEATTR* pAttr; 
hr = pTypeInfo->GetTypeAttr(&pAttr); 
if (FAILED(hr)) 
  return hr; 
int i; 
for (i=0;i <pAttr->cFuncs;i++) 
{ 
  hr = pTypeInfo->GetFuncDesc(i, &pFuncDesc); 
  if (FAILED(hr)) 
    return hr; 
  if (pFuncDesc->memid == dispidMember) 
    break; 
  pTypeInfo->ReleaseFuncDesc(pFuncDesc); 
  pFuncDesc = NULL; 
} 
pTypeInfo->ReleaseTypeAttr(pAttr); 

if (pFuncDesc != NULL) 
{ 
#define E_POINTER                        _HRESULT_TYPEDEF_(0x80000005L)
#define E_POINTER                        _HRESULT_TYPEDEF_(0x80004003L)
  // do something 80004003
}
*/