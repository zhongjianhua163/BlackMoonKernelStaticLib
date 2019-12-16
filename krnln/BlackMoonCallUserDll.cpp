#include "stdafx.h"
extern "C" PDESTROY BlackMoonFreeAllUserDll;

HMODULE BMUserDllList[100] = {0};
INT nBMUserDllCount = 0;

void BlackMoonFreeALLUserDllFunc(){
	for(INT i=0;i<100;i++){
		if(BMUserDllList[i]==NULL)
			break;
		::FreeLibrary (BMUserDllList[i]);

	}

}
extern "C" 
void* _stdcall BlackMoonCallUserDllFunc (char* pDll,char* pName,void** pFunc)
{
	char ErrorString [1024];
	HMODULE hMod = ::GetModuleHandle (pDll);
	int nNoErrorBox = 0;
	if(hMod==NULL){
		hMod = ::LoadLibrary (pDll);
		if(hMod==NULL){

  			wsprintf(ErrorString, "同目录下无法找到DLL文件:\"%s\".请与作者联系.", pDll);
			if (fnEError_callback)
				nNoErrorBox = fnEError_callback(0, ErrorString);

			if (!nNoErrorBox)
  				MessageBox(0, ErrorString, "DLL ERROR", MB_ICONERROR);
			E_End(0);
		}
		BMUserDllList[nBMUserDllCount] = hMod;
		
		if(nBMUserDllCount==0)
			BlackMoonFreeAllUserDll = (PDESTROY)BlackMoonFreeALLUserDllFunc;
		nBMUserDllCount++;
	}
	char* pFuncName = NULL;
	if(pName[0]=='#')
		pFuncName=(char*)atoi(pName+1);
	else{
		strcpy(ErrorString,pName);
		pFuncName = ErrorString;
		char* pStr = strchr(pFuncName,'@');
		if(pStr && pStr[1]=='@')
			pStr[0]=0;
		
	}

	FARPROC pf = ::GetProcAddress (hMod,pFuncName);
	if(pf==NULL){
  		wsprintf(ErrorString, "无法定位DLL文件:\"%s\"当中的\"%s\"函数.", pDll,pName);
		if (fnEError_callback)
			nNoErrorBox = fnEError_callback(0, ErrorString);

		if (!nNoErrorBox)
  			MessageBox(0, ErrorString, "DLL ERROR", MB_ICONERROR);
		E_End(0);
	}
	
	*pFunc = pf;
		
	return pf;
}