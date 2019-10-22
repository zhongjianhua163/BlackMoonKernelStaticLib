#include "stdafx.h"

#pragma comment(lib,"kernel32.lib") 
#pragma comment(lib,"user32.lib") 

HANDLE hBlackMoonInstanceHandle = NULL;
DWORD dwBlackMoonPESizeOfImage = 0;
DWORD dwBlackMoonPEAddrrStart;
DWORD dwBlackMoonPEAddrrEnd;

EError_CALLBACK fnEError_callback = NULL;
INT isErrorCallBack = 0;

void GetBlackMoonPESizeOfImage()
{
	PBYTE module;
	if(hBlackMoonInstanceHandle)
		module = (PBYTE)hBlackMoonInstanceHandle;
	else
		module = (PBYTE)::GetModuleHandle(NULL);
	dwBlackMoonPESizeOfImage = ((PIMAGE_NT_HEADERS)(module+((PIMAGE_DOS_HEADER)module)->e_lfanew))->OptionalHeader.SizeOfImage;
	dwBlackMoonPEAddrrStart = (DWORD)module;
	dwBlackMoonPEAddrrEnd = (DWORD)module+dwBlackMoonPESizeOfImage;

}
LPSTR sErrorListForE []= 
{
"数组成员引用下标超出定义范围",
"未得到所需要的数值型数据",
"引用数组成员时维数不为1且不等于该数组目前所具有的维数",
"数组成员引用下标必须大于等于1",
"数据或数组类型不匹配",
"调用DLL命令后发现堆栈错误，通常是DLL参数数目不正确",
"子语句参数未返回数据或者返回了非系统基本类型或数组型数据",
"被比较数据只能使用等于或不等于命令比较",
"“多项选择”命令的索引值参数小于零或超出了所提供参数表范围",
"“重定义数组”命令的数组维定义参数值必须大于零或单维时大于等于零",
"所提供参数的数据类型不符合要求"
};
//extern BOOL bIsEnterFromBMEntrypoint;
extern INT nBMProtectESP;
extern INT nBMProtectEBP;
extern "C" {



PDESTROY DestroyAddress = NULL;

PDESTROY HFileDestroyAddress = NULL;

PDESTROY DestroyMidiPlayer = NULL;

HANDLE hBlackMoonHeap = NULL;

PDESTROY BlackMoonFreeAllUserDll = NULL;

	void  _cdecl E_End (DWORD Param1){

		E_DestroyRes();
		//if(bIsEnterFromBMEntrypoint)
		if(nBMProtectESP==0){
			 ExitProcess(Param1);
			 return;
		}
		__asm {
			mov eax,Param1;
			mov ebp,nBMProtectEBP;
			mov esp,nBMProtectESP;
			sub esp,4;
			ret;
		}

	}

	void  _cdecl E_ReportError (DWORD Param1, DWORD MethodId, DWORD position){
		char ErrorString [255];
//		int nEbx;
		//__asm mov nEbx,ebx;
		LPSTR ptxt = NULL;
		if(0 <Param1 && Param1<12)
			ptxt = sErrorListForE[Param1-1];

		wsprintf(ErrorString, "program internal error number is %d. \r\n%s\r\n错误位置:%d,%d(仅5.8以上版本有效)", Param1,ptxt,MethodId,position);

		INT nNoErrorBox = 0;
  		if (fnEError_callback && !isErrorCallBack)
		{
			isErrorCallBack = 1;
			nNoErrorBox = fnEError_callback(Param1, ErrorString);
			isErrorCallBack = 0;
		}

		if (!nNoErrorBox)
  			MessageBox(0, ErrorString, "error", MB_ICONERROR);

		E_End(0);

	}

	void*  _cdecl E_MAlloc (DWORD Param1){

		if(hBlackMoonHeap==NULL)
			hBlackMoonHeap =::GetProcessHeap();
		void * pData = HeapAlloc(hBlackMoonHeap, HEAP_ZERO_MEMORY, Param1);//malloc(Param1);//
		
		if(!pData)
			//ZeroMemory(pData,Param1);
		//else
		{
			MessageBox(0, "内存不足", "error", MB_ICONERROR);
			E_End (0);
		}

		return pData;
	}

	void*  _cdecl E_MAlloc_Nzero (DWORD Param1){
		
		if(hBlackMoonHeap==NULL)
			hBlackMoonHeap =::GetProcessHeap();
		void * pData = HeapAlloc(hBlackMoonHeap, NULL, Param1);//malloc(Param1);//
		
		if(!pData)
		{
			MessageBox(0, "内存不足", "error", MB_ICONERROR);
			E_End (0);
		}
		
		return pData;
	}

	void*  _cdecl E_MRealloc (void * Param1,DWORD Param2){
		void * pData;
		if(hBlackMoonHeap==NULL)
			hBlackMoonHeap =::GetProcessHeap();
		
		if(Param1)
			pData = HeapReAlloc(hBlackMoonHeap, 0, Param1, Param2);//realloc(Param1, Param2);//
		else
			pData = HeapAlloc(hBlackMoonHeap, HEAP_ZERO_MEMORY, Param2);//malloc(Param2);//
	
		if(!pData)
		{
			MessageBox(0, "内存不足", "error", MB_ICONERROR);
			E_End (0);
		}

		return pData;

	}
	

	void  _cdecl E_MFree (void * Param1){




		if((DWORD)Param1 > 0xFFFF)
		{
			if(dwBlackMoonPESizeOfImage==0)
				GetBlackMoonPESizeOfImage();


			if(dwBlackMoonPEAddrrStart <= (DWORD)Param1 && (DWORD)Param1 <= dwBlackMoonPEAddrrEnd)
			{
				//MessageBox(NULL,"ErrorString","指针",MB_OK);
				return;
				
			}
		

			if(IsBadReadPtr(Param1,8))
			{
				//char ErrorString [255];
				//wsprintf(ErrorString, "%08X = ", Param1);
				//MessageBox(NULL,ErrorString,"无效指针",MB_OK);
				return;
			}

			HeapFree(hBlackMoonHeap, 0 , Param1);  //free(Param1);//


			

		}


	}

	void  _cdecl E_Destroy (PDESTROY Param1){
		//int nIdx;
		//__asm mov nIdx,eax;	
		//if(nIdx==3)	//还有2的
			DestroyAddress = Param1; 

	}

	void  _cdecl E_HelpFunc12 (DWORD Param1){
		int nIdx;
		__asm mov nIdx,eax;	
	//	if(nIdx==3)	//其它12号函数调用,比如2的

	}
	
	void*  _cdecl E_CloneConstArray (DWORD Param1,void** Param2){
		void *result;
		result = (void *)1;
		if(dwBlackMoonPESizeOfImage==0)
			GetBlackMoonPESizeOfImage();
		void* pAryData = *Param2;
		
		
		if(dwBlackMoonPEAddrrStart <= (DWORD)pAryData && (DWORD)pAryData <= dwBlackMoonPEAddrrEnd)
		{
			LPINT pnData;
			INT nArys,nDim;
			UINT nElementCount;
			
			pnData = (LPINT)pAryData;
			
			nArys=*pnData; //取得维数。
			nDim = nArys;
			pnData +=1;
			
			// 计算成员数目。
			nElementCount = 1;
			while (nArys > 0)
			{
				nElementCount *= pnData[0];
				pnData ++;
				nArys--;
			}
			
			DWORD dwSize = Param1 * nElementCount + (nDim+1)*sizeof(INT);
			result = E_MAlloc_Nzero(dwSize);
			memcpy(result,pAryData,dwSize);
			*Param2 = result;

			
		}

		return result;
	}

	void*  _cdecl E_NULLARRAY ()
	{
		LPBYTE p = (LPBYTE)E_MAlloc_Nzero (sizeof (INT) * 2);
		*(LPINT)p = 1;  // 数组维数。
		*(LPINT)(p + sizeof (INT)) = 0;
		return p;
	}

	void BlackMoonCalleLibFunctionHelper(INT nArgCount,MDATA_INF ArgInf,...)
	{
		PFN_EXECUTE_CMD pfn;
		__asm mov pfn, eax;
		MDATA_INF RetData={0};
		pfn(&RetData,nArgCount,&ArgInf);
		__asm{
			mov eax, RetData.m_unit.m_dwFormID;
			mov edx, RetData.m_unit.m_dwUnitID;
			mov ecx, RetData.m_dtDataType
		}		
	}
//	void main(){};
}
extern "C" INT BlackMoonCalleLibList;
extern "C" DWORD BlackMoonFuncForeLib;

void BlackMoonInitAllElib(){
	LPINT pfnNotifySys = &BlackMoonCalleLibList;
	while(*pfnNotifySys){
		PFN_NOTIFY_SYS g_fnNotifySys = (PFN_NOTIFY_SYS)*pfnNotifySys;
		g_fnNotifySys(NL_SYS_NOTIFY_FUNCTION,BlackMoonFuncForeLib,0);
		pfnNotifySys++;
	}
}

void BlackMoonFreeAllElib(){
	LPINT pfnNotifySys = &BlackMoonCalleLibList;
	while(*pfnNotifySys){
		PFN_NOTIFY_SYS g_fnNotifySys = (PFN_NOTIFY_SYS)*pfnNotifySys;
		g_fnNotifySys(NL_FREE_LIB_DATA,0,0);
		pfnNotifySys++;
	}
	if(BlackMoonFreeAllUserDll)
		BlackMoonFreeAllUserDll();
}


//其他 - 置错误提示管理
/*
    调用格式： 〈无返回值〉 置错误提示管理 （［子程序指针 用作进行错误提示的子程序］） - 系统核心支持库->其他
    英文名称：SetErrorManger
    本命令用来设置当运行时如果产生了导致程序崩溃的严重错误时用来对该错误进行详细提示的子程序地址，如果未进行此项设置，发生严重错误时运行时环境将自动提示该错误的详细信息并直接退出。本命令为高级命令。
    参数<1>的名称为“用作进行错误提示的子程序”，类型为“子程序指针（SubPtr）”，可以被省略。注意该子程序必须接收两个参数，第一个参数为整数型，用作接收错误代码，
	第二个参数为文本型，用作接收详细错误文本。同时该子程序必须返回一个逻辑值，返回真表示已经自行处理完毕，系统将不再显示该错误信息，返回假表示由系统来继续显示该错误信息。
	以上设置必须完全正确，否则结果不能预测，另外，还请注意以下几点： 
	1、该错误提示子程序不要再引发新的错误； 
	2、在进入该错误提示子程序后，系统将自动关闭事件消息通知处理机制，也就是说任何事件将无法得到响应； 
	3、无论如何，当该子程序调用退出后，系统将自动将整个应用程序关闭。  如果省略本参数，系统将恢复错误提示的默认处理方式。
*/
LIBAPI(void, krnln_SetErrorManger)
{
	if (ArgInf.m_dtDataType == SDT_SUB_PTR && ArgInf.m_pdwSubCodeAdr)
		fnEError_callback = (EError_CALLBACK)ArgInf.m_pdwSubCodeAdr;
	else
		fnEError_callback = NULL;
}