#include "stdafx.h"

#pragma comment(lib,"gdi32.lib") 
#pragma comment(lib,"winspool.lib") 
#pragma comment(lib,"comdlg32.lib") 
#pragma comment(lib,"advapi32.lib")  
#pragma comment(lib,"shell32.lib")  
#pragma comment(lib,"ole32.lib")  
#pragma comment(lib,"oleaut32.lib")  
#pragma comment(lib,"uuid.lib")  
#pragma comment(lib,"odbc32.lib")  
#pragma comment(lib,"odbccp32.lib")  
char strBlackMoonFileName_Path[MAX_PATH];
char strBlackMoonFileName_Name[MAX_PATH];
EXTERN_C INT WINAPI BlackMoonFuncForeLibNotifySys (INT nMsg, DWORD dwParam1, DWORD dwParam2)
{
		
	switch(nMsg)
	{
	case  NRS_MALLOC:
			// 分配指定空间的内存，所有与易程序交互的内存都必须使用本通知分配。
			//   dwParam1为欲需求内存字节数。
			//   dwParam2如为0，则如果分配失败就自动报告运行时错并退出程序。
			// 如不为0，则如果分配失败就返回NULL。
			//   返回所分配内存的首地址。
		return (INT)E_MAlloc (dwParam1);
	case  NRS_MFREE:
			// 释放已分配的指定内存。
			// dwParam1为欲释放内存的首地址。
		E_MFree ((void*)dwParam1);
		break;
	case  NRS_MREALLOC:
			// 重新分配内存。
			//   dwParam1为欲重新分配内存尺寸的首地址。
			//   dwParam2为欲重新分配的内存字节数。
			// 返回所重新分配内存的首地址，失败自动报告运行时错并退出程序。
		return (INT)E_MRealloc ((void*)dwParam1,dwParam2);
		
	case  NRS_FREE_ARY:
			// 释放指定数组数据。
			// dwParam1为该数据的DATA_TYPE，只能为系统数据类型。
			// dwParam2为指向该数组数据的指针。
		switch(dwParam1)
		{
		case SDT_TEXT:
		case SDT_BIN:
			FreeAryElement ((void*)dwParam2);
			break;
		case SDT_INT:
		case SDT_BYTE:
		case SDT_SHORT:
		case SDT_FLOAT:
		case SDT_INT64:
		case SDT_DOUBLE:
		case SDT_SUB_PTR:
		case SDT_BOOL:
		case SDT_DATE_TIME:
			E_MFree ((void*)dwParam2);
			break;
		default:
			break;
			
		}
		break;
		
	case 	NRS_RUNTIME_ERR:
			// 通知系统已经产生运行时错误。
			// dwParam1为char*指针，说明错误文本。
		{
			char ErrorString [1024];
  			wsprintf(ErrorString, "BlackMoon RunTime Error:\r\n\r\n%s", dwParam1);
  			MessageBox(0, ErrorString, "ERROR", MB_ICONERROR);
			E_End (0);
		}
		break;
	case 	NRS_EXIT_PROGRAM:
			// 通知系统退出用户程序。
			// dwParam1为退出代码，该代码将被返回到操作系统。
			E_End (dwParam1);
			break;
	case  NRS_GET_PRG_TYPE:
			// 返回当前用户程序的类型，为PT_DEBUG_RUN_VER（调试版）或PT_RELEASE_RUN_VER（发布版）。
		return PT_RELEASE_RUN_VER;
	case 	NRS_DO_EVENTS:
			// 通知系统发送所有待处理事件。
		{
			MSG Msg;
			while(PeekMessage(&Msg,NULL,NULL,NULL,PM_NOREMOVE))
			{
				if(Msg.message == WM_QUIT)
					break;
				GetMessage (&Msg, NULL, 0, 0);
				TranslateMessage (&Msg);
				DispatchMessage (&Msg);
			}
		}
		break;
	case  NRS_GET_CMD_LINE_STR:
			// 取当前命令行文本
			// 返回命令行文本指针，有可能为空串。
		{
			LPSTR p = GetCommandLine ();
			// 跳过调用程序名。
			char ch = ' ';
			if (*p++ == '\"')
				ch = '\"';
			while (*p++ != ch);
			if (ch != ' ' && *p == ' ')  p++;    // 跳过第一个空格。
			return (INT)p;
		}
	case  NRS_GET_EXE_PATH_STR:
			// 取当前执行文件所处目录名称
			// 返回当前执行文件所处目录文本指针。
		if(::GetModuleFileName(NULL,strBlackMoonFileName_Path,MAX_PATH))
		{
			char* pFind = strrchr(strBlackMoonFileName_Path,'\\');
		//	pFind++;
			*pFind=0;
			return (INT)&strBlackMoonFileName_Path;
			
		}
		break;
			
	case  NRS_GET_EXE_NAME:
			// 取当前执行文件名称
			// 返回当前执行文件名称文本指针。
		if(::GetModuleFileName(NULL,strBlackMoonFileName_Path,MAX_PATH))
		{
			char* pFind = strrchr(strBlackMoonFileName_Path,'\\');
			//pFind++;
			*pFind=0;
			pFind++;
			return (INT)pFind;
		}
		break;
	case  NRS_CONVERT_NUM_TO_INT:
		{
			// 转换其它数值格式到整数。
			// dwParam1为 PMDATA_INF 指针，其 m_dtDataType 必须为数值型。
			// 返回转换后的整数值。
			PMDATA_INF pArgInf = (PMDATA_INF)dwParam1;
			INT nNewVal = pArgInf->m_int;
			switch(pArgInf->m_dtDataType)
			{
			case SDT_INT:
			case SDT_BYTE:
			case SDT_SHORT:
				break;
			case SDT_FLOAT:
				nNewVal = pArgInf->m_float;
				break;
			case SDT_INT64:
				nNewVal = pArgInf->m_int64;
				break;
			case SDT_DOUBLE:
				nNewVal = pArgInf->m_double;
				break;
			default:
				break;
				
			}
			return nNewVal;
		}
		break;
	case  NAS_GET_PATH:
			/* 返回当前开发或运行环境的某一类目录或文件名，目录名以“\”结束。
			dwParam1: 指定所需要的目录，可以为以下值：
			A、开发及运行环境下均有效的目录:
            1: 开发或运行环境系统所处的目录；
			B、开发环境下有效的目录(仅开发环境中有效):
            1001: 系统例程和支持库例程所在目录名
            1002: 系统工具所在目录
            1003: 系统帮助信息所在目录
            1004: 保存所有登记到系统中易模块的目录
            1005: 支持库所在的目录
            1006: 安装工具所在目录
			C、运行环境下有效的目录(仅运行环境中有效):
            2001: 用户EXE文件所处目录；
            2002: 用户EXE文件名；
			dwParam2: 接收缓冲区地址，尺寸必须为MAX_PATH。
			*/
		if(::GetModuleFileName(NULL,strBlackMoonFileName_Path,MAX_PATH))
		{
			char* pFind = strrchr(strBlackMoonFileName_Path,'\\');
			pFind++;
			*pFind=0;
			pFind++;
			strcpy(strBlackMoonFileName_Name,pFind);
		}else{
			strBlackMoonFileName_Path[0]=0;
			strBlackMoonFileName_Name[0]=0;
		}

		switch(dwParam1)
		{
        case 1:
			strcpy((char*)dwParam2, strBlackMoonFileName_Path);
			return (INT)strBlackMoonFileName_Path;
			break;
        case 2001:
			strcpy((char*)dwParam2, strBlackMoonFileName_Path);
			return (INT)strBlackMoonFileName_Path;
			break;
        case 2002:
			strcpy((char*)dwParam2, strBlackMoonFileName_Name);
			return (INT)strBlackMoonFileName_Name;
			break;
        default:
			return NULL;    
		}
	case  NAS_GET_LANG_ID :
			// 返回当前系统或运行环境所支持的语言ID，具体ID值请见lang.h
		return 1;
	case  NAS_GET_VER:
			// 返回当前系统或运行环境的版本号，LOWORD为主版本号，HIWORD为次版本号。
		return 0x00000004;
	case  NRS_GET_WINFORM_COUNT:
			// 返回当前程序的窗体数目。
		return 0;
	case  NRS_GET_WINFORM_HWND:
			// 返回指定窗体的窗口句柄，如果该窗体尚未被载入，返回NULL。
			// dwParam1为窗体索引。
		return NULL;
	case NAS_GET_APP_ICON:
			// 通知系统创建并返回程序的图标。
			// dwParam1为PAPP_ICON指针。
	case  NAS_GET_LIB_DATA_TYPE_INFO:
			// 返回指定库定义数据类型的PLIB_DATA_TYPE_INFO定义信息指针。
			// dwParam1为欲检查的数据类型。
			// 如果该数据类型无效或者不为库定义数据类型，则返回NULL，否则返回PLIB_DATA_TYPE_INFO指针。
	case  NAS_GET_HBITMAP:
			// dwParam1为图片数据指针，dwParam2为图片数据尺寸。
			// 如果成功返回非NULL的HBITMAP句柄（注意使用完毕后释放），否则返回NULL。

	case  NAS_CREATE_CWND_OBJECT_FROM_HWND:
			// 通过指定HWND句柄创建一个CWND对象，返回其指针，记住此指针必须通过调用NRS_DELETE_CWND_OBJECT来释放
			// dwParam1为HWND句柄
			// 成功返回CWnd*指针，失败返回NULL
	case  NAS_DELETE_CWND_OBJECT:
			// 删除通过NRS_CREATE_CWND_OBJECT_FROM_HWND创建的CWND对象
			// dwParam1为欲删除的CWnd对象指针
	case  NAS_DETACH_CWND_OBJECT:
			// 取消通过NRS_CREATE_CWND_OBJECT_FROM_HWND创建的CWND对象与其中HWND的绑定
			// dwParam1为CWnd对象指针
			// 成功返回HWND,失败返回0
	case  NAS_GET_HWND_OF_CWND_OBJECT:
			// 获取通过NRS_CREATE_CWND_OBJECT_FROM_HWND创建的CWND对象中的HWND
			// dwParam1为CWnd对象指针
			// 成功返回HWND,失败返回0
	case  NAS_ATTACH_CWND_OBJECT:
			// 将指定HWND与通过NRS_CREATE_CWND_OBJECT_FROM_HWND创建的CWND对象绑定起来
			// dwParam1为HWND
			// dwParam2为CWnd对象指针
			// 成功返回1,失败返回0
	case 	NAS_IS_EWIN:
			// 如果指定窗口为易语言窗口或易语言组件，返回真，否则返回假。
			// dwParam1为欲测试的HWND.
	// NRS_ 宏为仅能被易运行环境处理的通知。
	case  NRS_UNIT_DESTROIED:
			// 通知系统指定的组件已经被销毁。
			// dwParam1为dwFormID
			// dwParam2为dwUnitID
	case  NRS_GET_UNIT_PTR:
			// 取组件对象指针
			// dwParam1为WinForm的ID
			// dwParam2为WinUnit的ID
			// 成功返回有效的组件对象CWnd*指针，失败返回0。
	case  NRS_GET_AND_CHECK_UNIT_PTR:
			// 取组件对象指针
			// dwParam1为WinForm的ID
			// dwParam2为WinUnit的ID
			// 成功返回有效的组件对象CWnd*指针，失败报告运行时错误并退出程序。
	case  NRS_EVENT_NOTIFY:
			// 以第一类方式通知系统产生了事件。
			// dwParam1为PEVENT_NOTIFY指针。
			//   如果返回 0 ，表示此事件已被系统抛弃，否则表示系统已经成功传递此事件到用户
			// 事件处理子程序。
	case  NRS_GET_UNIT_DATA_TYPE:
			// dwParam1为WinForm的ID
			// dwParam2为WinUnit的ID
			// 成功返回有效的 DATA_TYPE ，失败返回 0 。

	case  NRS_EVENT_NOTIFY2:
			// 以第二类方式通知系统产生了事件。
			// dwParam1为PEVENT_NOTIFY2指针。
			//   如果返回 0 ，表示此事件已被系统抛弃，否则表示系统已经成功传递此事件到用户
			// 事件处理子程序。

	case  NRS_GET_BITMAP_DATA:
			// 返回指定HBITMAP的图片数据，成功返回包含BMP图片数据的HGLOBAL句柄，失败返回NULL。
			// dwParam1为欲获取其图片数据的HBITMAP。
	case  NRS_FREE_COMOBJECT:
			// 通知系统释放指定的DTP_COM_OBJECT类型COM对象。
			// dwParam1为该COM对象的地址指针。
	case  NRS_CHK_TAB_VISIBLE:
	default:    
		{
		char ErrorString [255];
  		wsprintf(ErrorString, "不支持系统功能函数%d. 请将此信息反馈给作者", nMsg);
  		MessageBox(0, ErrorString, "blackmoon", MB_ICONERROR);				
		break;
		}
	}
	return NULL;

}

EXTERN_C INT WINAPI BlackMoonReplac_NotifySys (INT nMsg, DWORD dwParam1, DWORD dwParam2)
{
	return NR_OK;
}

INT WINAPI NotifySys (INT nMsg, DWORD dwParam1, DWORD dwParam2)
{

	return BlackMoonFuncForeLibNotifySys (nMsg,dwParam1,dwParam2);
}

// 使用指定文本数据建立易程序中使用的文本数据。
/*
char* CloneTextData (char* ps)
{
    if (ps == NULL || *ps == '\0')
        return NULL;

    INT nTextLen = strlen (ps);
    char* pd = (char*)NotifySys (NRS_MALLOC, (DWORD)(nTextLen + 1), 0);
    memcpy (pd, ps, nTextLen);
    pd [nTextLen] = '\0';
    return pd;
}*/
/*
// 使用指定文本数据建立易程序中使用的文本数据。
//   nTextLen用作指定文本部分的长度（不包含结束零），
// 如果为-1，则取ps的全部长度。
char* CloneTextData (char* ps, INT nTextLen)
{
    if (nTextLen <= 0)
        return NULL;

    char* pd = (char*)NotifySys (NRS_MALLOC, (DWORD)(nTextLen + 1), 0);
    memcpy (pd, ps, nTextLen);
    pd [nTextLen] = '\0';
    return pd;
}

// 使用指定数据建立易程序中使用的字节集数据。
LPBYTE CloneBinData (LPBYTE pData, INT nDataSize)
{
    if (nDataSize == 0)
        return NULL;

    LPBYTE pd = (LPBYTE)NotifySys (NRS_MALLOC, (DWORD)(sizeof (INT) * 2 + nDataSize), 0);
    *(LPINT)pd = 1;
    *(LPINT)(pd + sizeof (INT)) = nDataSize;
    memcpy (pd + sizeof (INT) * 2, pData, nDataSize);
    return pd;
}

// 报告运行时错误。
void GReportError (char* szErrText)
{
    NotifySys (NRS_RUNTIME_ERR, (DWORD)szErrText, 0);
}

void* MMalloc (INT nSize)
{
	return (void*)NotifySys (NRS_MALLOC, (DWORD)nSize, 0);
}

void MFree (void* p)
{
	NotifySys (NRS_MFREE, (DWORD)p, 0);
}
*/
// 返回数组的数据部分首地址及成员数目。
LPBYTE GetAryElementInf (void* pAryData, LPINT pnElementCount)
{
	LPINT pnData = (LPINT)pAryData;
	INT nArys = *pnData++;  // 取得维数。
	// 计算成员数目。
	INT nElementCount = 1;
	while (nArys > 0)
	{
		nElementCount *= *pnData++;
		nArys--;
	}

	if (pnElementCount != NULL)
		*pnElementCount = nElementCount;
	return (LPBYTE)pnData;
}
/*
#define DTT_IS_NULL_DATA_TYPE   0
#define DTT_IS_SYS_DATA_TYPE    1
#define DTT_IS_USER_DATA_TYPE   2
#define DTT_IS_LIB_DATA_TYPE    3
// 取回数据类型的类别。
INT GetDataTypeType (DATA_TYPE dtDataType)
{
	if (dtDataType == _SDT_NULL)
		return DTT_IS_NULL_DATA_TYPE;

	DWORD dw = dtDataType & 0xC0000000;
	return dw == DTM_SYS_DATA_TYPE_MASK ? DTT_IS_SYS_DATA_TYPE :
			dw == DTM_USER_DATA_TYPE_MASK ? DTT_IS_USER_DATA_TYPE :
			DTT_IS_LIB_DATA_TYPE;
}
*/

//以下由liigo添加


/*
//!!! 以下函数均假设数据类型之成员全部为INT类型(或同样占用4个字节)
//index: 0..*/


 void* _GetPointerByIndex(void *pBase, int index)
{
	return (void*) ((INT)pBase + index * sizeof(INT));
}

 INT _GetIntByIndex(void *pBase, INT index)
{
	return *((INT*)_GetPointerByIndex(pBase,index));
}

 void _SetIntByIndex(void *pBase, INT index, INT value)
{
	*((INT*)_GetPointerByIndex(pBase,index)) = value;
}


INT GetIntByIndex(PMDATA_INF pArgInf, INT index)
{
	return _GetIntByIndex(pArgInf->m_pCompoundData,index);
}

void SetIntByIndex(PMDATA_INF pArgInf, INT index, INT value)
{
	_SetIntByIndex(pArgInf->m_pCompoundData,index,value);
}

void* GetPointerByIndex(PMDATA_INF pArgInf, INT index)
{
	return _GetPointerByIndex(pArgInf->m_pCompoundData,index);
}

void SetLogfont_CompileLanVer(LPLOGFONT pLogfont)
{
	::GetObject (::GetStockObject (DEFAULT_GUI_FONT), sizeof (LOGFONT), pLogfont);

}
