#include "stdafx.h"
#include "Myfunctions.h"
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
BYTE BMInputBoxDialogTemplateData[] = {
0xC0,0x08,0xC8,0x80,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0xFC,0x00,
0x5C,0x00,0x00,0x00,0x00,0x00,0xF7,0x8B,0x93,0x8F,0x65,0x51,0x1A,0xFF,0x00,0x00,
0x09,0x00,0x8B,0x5B,0x53,0x4F,0x00,0x00,0x00,0x10,0x02,0x50,0x00,0x00,0x00,0x00,
0x07,0x00,0x07,0x00,0xEE,0x00,0x23,0x00,0xFF,0xFF,0xFF,0xFF,0x82,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x50,0x00,0x00,0x00,0x00,0x0C,0x00,0x0B,0x00,
0xE5,0x00,0x1B,0x00,0x68,0x04,0xFF,0xFF,0x82,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x80,0x00,0x81,0x50,0x00,0x00,0x00,0x00,0x07,0x00,0x2D,0x00,0xEE,0x00,0x0C,0x00,
0xE9,0x03,0xFF,0xFF,0x81,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xA0,0x00,0x81,0x50,
0x00,0x00,0x00,0x00,0x07,0x00,0x2D,0x00,0xEE,0x00,0x0C,0x00,0xEA,0x03,0xFF,0xFF,
0x81,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x01,0x50,0x00,0x00,0x00,0x00,
0x3F,0x00,0x42,0x00,0x37,0x00,0x13,0x00,0x01,0x00,0xFF,0xFF,0x80,0x00,0x6E,0x78,
0xA4,0x8B,0x93,0x8F,0x65,0x51,0x28,0x00,0x26,0x00,0x4F,0x00,0x29,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x50,0x00,0x00,0x00,0x00,0x86,0x00,0x42,0x00,
0x37,0x00,0x13,0x00,0x02,0x00,0xFF,0xFF,0x80,0x00,0xD6,0x53,0x88,0x6D,0x28,0x00,
0x26,0x00,0x43,0x00,0x29,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };

/*
���ø�ʽ�� ���߼��͡� ����� �����ı��� ��ʾ��Ϣ�ݣ����ı��� ���ڱ���ݣ����ı��� ��ʼ�ı��ݣ�ͨ���ͱ��� ����������ݵı������������� ���뷽ʽ�ݣ���ͨ���� �����ڣݣ� - ϵͳ����֧�ֿ�->ϵͳ����
Ӣ�����ƣ�InputBox
��һ�Ի�������ʾ��ʾ���ȴ��û��������Ĳ����°�ť������û���ȷ������󣨰��¡�ȷ�����롱��ť��س������˳��������棬���򷵻ؼ١�������Ϊ�������
����<1>������Ϊ����ʾ��Ϣ��������Ϊ���ı��ͣ�text���������Ա�ʡ�ԡ������ʾ��Ϣ�������У����ڸ���֮���ûس��� (�����ַ� (13)��)�����з� (�����ַ� (10)��) ��س����з������ (�������ַ� (13) + �ַ� (10)��) ���ָ��������ʾ��Ϣ̫�����������࣬�������ֽ����ᱻ��ʾ������
����<2>������Ϊ�����ڱ��⡱������Ϊ���ı��ͣ�text���������Ա�ʡ�ԡ�����ֵָ����ʾ�ڶԻ���������е��ı������ʡ�ԣ�Ĭ��Ϊ�ı��������룺����
����<3>������Ϊ����ʼ�ı���������Ϊ���ı��ͣ�text���������Ա�ʡ�ԡ�����ֵָ����ʼ���õ��Ի��������ı����е����ݡ�
����<4>������Ϊ������������ݵı�����������Ϊ��ͨ���ͣ�all�������ṩ��������ʱֻ���ṩ����������ֵ��ָ���ı�������Ϊ��ֵ���ı��ͣ������Բ�ͬ����������ȡ���������ݡ�
����<5>������Ϊ�����뷽ʽ��������Ϊ�������ͣ�int���������Ա�ʡ�ԡ�����ֵ����Ϊ���³���ֵ�� 1��#�����ı��� 2��#���������� 3��#����С���� 4��#�������롣���ʡ�Ա�������Ĭ��Ϊ��#�����ı�����
����<6>������Ϊ�������ڡ�������Ϊ��ͨ���ͣ�all���������Ա�ʡ�ԡ�ָ�������ĸ�����,������һ��"����"�������ݻ���һ�������ʹ��ھ��.�����ʡ��,Ĭ��Ϊ��.
*/
/////////////////////////////////////////////////////////////////////////////
typedef struct
{
	LPSTR lpText;
	LPSTR lpTitle;
	LPSTR lpIntiTxt;
	INT nType;
	BOOL bResult;
	HWND hEdit;
	LPSTR lpUserInput;
} BMInputBoxDATA;



BOOL CALLBACK BMInputBoxDlgProc(HWND hwndDlg,  // handle to dialog box 
	UINT uMsg,     // message 
	WPARAM wParam, // first message parameter 
	LPARAM lParam  // second message parameter 
)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		BMInputBoxDATA* lpData = (BMInputBoxDATA*)lParam;
		::SetWindowText(hwndDlg, lpData->lpTitle);
		HWND hwndEDIT;
		if (lpData->nType == 4)//�����
		{
			hwndEDIT = GetDlgItem(hwndDlg, 1001);
			ShowWindow(hwndEDIT, SW_HIDE);
			lpData->hEdit = GetDlgItem(hwndDlg, 1002);

		}
		else {
			hwndEDIT = GetDlgItem(hwndDlg, 1002);
			ShowWindow(hwndEDIT, SW_HIDE);
			lpData->hEdit = GetDlgItem(hwndDlg, 1001);
		}
		if (lpData->lpIntiTxt)//��ʼ�ı�
			::SetWindowText(lpData->hEdit, lpData->lpIntiTxt);

		hwndEDIT = GetDlgItem(hwndDlg, 1128);
		ShowWindow(hwndEDIT, SW_HIDE);
		hwndEDIT = GetDlgItem(hwndDlg, 65535);

		if (lpData->lpText)//��ʾ�ı�
			::SetWindowText(hwndEDIT, lpData->lpText);
		else {

			ShowWindow(hwndEDIT, SW_HIDE);
			RECT rect;
			INT x, y;
			INT offect = 57;

			hwndEDIT = GetDlgItem(hwndDlg, 1);
			::GetWindowRect(hwndEDIT, &rect);
			::ScreenToClient(hwndDlg, (LPPOINT)&rect);
			x = rect.left;
			y = rect.top - offect;
			::SetWindowPos(hwndEDIT, NULL, x, y, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE);

			hwndEDIT = GetDlgItem(hwndDlg, 2);
			::GetWindowRect(hwndEDIT, &rect);
			::ScreenToClient(hwndDlg, (LPPOINT)&rect);
			x = rect.left;
			::SetWindowPos(hwndEDIT, NULL, x, y, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE);

			::GetWindowRect(lpData->hEdit, &rect);
			::ScreenToClient(hwndDlg, (LPPOINT)&rect);
			x = rect.left;
			::SetWindowPos(lpData->hEdit, NULL, x, 11, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE);

			::GetWindowRect(hwndDlg, &rect);
			x = rect.right - rect.left;
			y = rect.bottom - rect.top - offect;
			::SetWindowPos(hwndDlg, NULL, 0, 0, x, y, SWP_NOMOVE | SWP_NOACTIVATE);




		}

		::SetWindowLong(hwndDlg, GWL_USERDATA, (LONG)lpData);

	}

	break;
	case WM_COMMAND:
	{
		BMInputBoxDATA* lpData = (BMInputBoxDATA*)GetWindowLong(hwndDlg, GWL_USERDATA);
		INT nID = wParam & 0xffff;
		if (nID == IDCANCEL)
			DestroyWindow(hwndDlg);
		else if (nID == IDOK) {

			INT nLen = ::GetWindowTextLength(lpData->hEdit);
			if (nLen > 0)
			{
				lpData->lpUserInput = new char[nLen + 1];
				GetWindowText(lpData->hEdit, lpData->lpUserInput, nLen + 1);
			}
			lpData->bResult = TRUE;
			DestroyWindow(hwndDlg);
		}

	}

	break;
	case WM_CLOSE:
		DestroyWindow(hwndDlg);
		break;
	case WM_DESTROY:
		// Perform cleanup tasks. 
		PostQuitMessage(0);
		//PostMessage (hwndDlg,WM_QUIT,0,0);
		break;
	default:
		return FALSE;

	}
	return TRUE;
}

LIBAPI(int, krnln_InputBox)
{
	BMInputBoxDATA data;
	HWND hParent = NULL;
	memset(&data, 0, sizeof(BMInputBoxDATA));
	PMDATA_INF pArgInf = &ArgInf;
	if (pArgInf[0].m_dtDataType != _SDT_NULL && mystrlen(pArgInf[0].m_pText) > 0)
		data.lpText = pArgInf[0].m_pText;
	if (pArgInf[1].m_dtDataType != _SDT_NULL)
		data.lpTitle = pArgInf[1].m_pText;
	if (pArgInf[2].m_dtDataType != _SDT_NULL)
		data.lpIntiTxt = pArgInf[2].m_pText;

	if (pArgInf[4].m_dtDataType == _SDT_NULL)
		data.nType = 1;
	else {
		data.nType = pArgInf[4].m_int;
		if (data.nType < 1 || data.nType>4)
			data.nType = 1;
	}

	if (6 <= nArgCount)
	{
		if (pArgInf[5].m_dtDataType != _SDT_NULL)
			hParent = (HWND)pArgInf[5].m_int;
	}

	LPBYTE lpDialogTemplate = BMInputBoxDialogTemplateData;
	HWND hDlg = CreateDialogIndirectParam(::GetModuleHandle(NULL), (LPCDLGTEMPLATE)lpDialogTemplate, hParent, (DLGPROC)BMInputBoxDlgProc, (LPARAM)&data);
	if (hDlg) {
		ShowWindow(hDlg, SW_SHOW);
		UpdateWindow(hDlg);
		MSG msg;
		while (GetMessage(&msg, NULL, 0, 0)) {
			//if(msg.message == WM_CLOSE)MessageBox(NULL,"exit",NULL,MB_OK);
			if (msg.hwnd == data.hEdit && msg.message == WM_CHAR) {
				if (msg.wParam == 13)
					::SendMessage(hDlg, WM_COMMAND, IDOK, 0);
				else if (data.nType == 2 || data.nType == 3) {
					if (!(msg.wParam == '-' || (msg.wParam >= '0' && msg.wParam <= '9') || (data.nType == 3 && msg.wParam == '.')))
						continue;
				}

			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	BOOL bResult = data.bResult;
	if (bResult) {
		INT nLen = 0;

		if (data.lpUserInput)
			nLen = mystrlen(data.lpUserInput);
		else
			data.lpUserInput = (LPSTR)"0";

		switch (pArgInf[3].m_dtDataType)
		{
		case SDT_TEXT:
			E_MFree(*pArgInf[3].m_ppText);
			*pArgInf[3].m_ppText = CloneTextData(data.lpUserInput, nLen);
			break;
		case SDT_BYTE:
			*pArgInf[3].m_pByte = (BYTE)atoi(data.lpUserInput);
			break;
		case SDT_SHORT:
			*pArgInf[3].m_pShort = (SHORT)atoi(data.lpUserInput);
			break;
		case SDT_INT:
			*pArgInf[3].m_pInt = atoi(data.lpUserInput);
			break;
		case SDT_INT64:
			*pArgInf[3].m_pInt64 = _atoi64(data.lpUserInput);
			break;
		case SDT_FLOAT:
			*pArgInf[3].m_pFloat = (FLOAT)atof(data.lpUserInput);
			break;
		case SDT_DOUBLE:
			*pArgInf[3].m_pDouble = atof(data.lpUserInput);
			break;
		default:
			bResult = FALSE;
		}

		if (nLen > 0)
			delete[] data.lpUserInput;
	}
	return bResult;

}
/*
int __cdecl krnln_fnInputBox(int a1, int a2, int a3)
{
  char *v3; // edi@2
  int v4; // eax@4
  signed int v5; // eax@12
  int v6; // edx@18
  unsigned int v7; // eax@19
  __int16 v8; // ax@24
  char v9; // al@25
  int v10; // eax@27
  double v11; // st7@31
  int v13; // edx@36
  char v14; // [sp+14h] [bp-F4h]@4
  char v15; // [sp+70h] [bp-98h]@7
  char v16; // [sp+74h] [bp-94h]@5
  char v17; // [sp+78h] [bp-90h]@9
  char *String; // [sp+7Ch] [bp-8Ch]@24
  int v19; // [sp+80h] [bp-88h]@11
  char v20; // [sp+84h] [bp-84h]@36
  char v21; // [sp+C4h] [bp-44h]@36

  if ( *(_DWORD *)(a3 + 8) )
	v3 = *(char **)a3;
  else
	v3 = 0;
  v4 = IsEmptyStr(v3);
  CInputDlg__CInputDlg(&v14, 0, v4 != 0 ? 1150 : 1037);
  if ( *(_DWORD *)(a3 + 8) )
	CString__operator_(&v16, v3);
  if ( *(_DWORD *)(a3 + 20) )
	CString__operator_(&v15, *(_DWORD *)(a3 + 12));
  if ( *(_DWORD *)(a3 + 32) )
	CString__operator_(&v17, *(_DWORD *)(a3 + 24));
  if ( !*(_DWORD *)(a3 + 56) )
  {
	v19 = 1;
	goto LABEL_18;
  }
  v5 = *(_DWORD *)(a3 + 48);
  if ( v5 > 4 )
	goto LABEL_39;
  if ( v5 < 1 )
  {
	v19 = 1;
	goto LABEL_18;
  }
  if ( v5 <= 4 )
	v19 = *(_DWORD *)(a3 + 48);
  else
LABEL_39:
	v19 = 4;
LABEL_18:
  if ( CDialog__DoModal(&v14) != 1 )
  {
	*(_DWORD *)a1 = 0;
	goto LABEL_36;
  }
  v7 = *(_DWORD *)(a3 + 44);
  if ( v7 > 0x80000301 )
  {
	if ( v7 == -2147482623 )
	{
	  *(_QWORD *)*(_DWORD *)(a3 + 36) = _atoi64(String);
	}
	else
	{
	  if ( v7 == -2147482367 )
	  {
		**(float **)(a3 + 36) = atof(String);
		v6 = a1;
		*(_DWORD *)a1 = 1;
		goto LABEL_36;
	  }
	  if ( v7 == -2147482111 )
	  {
		v11 = atof(String);
		v6 = a1;
		*(_QWORD *)*(_DWORD *)(a3 + 36) = *(_QWORD *)&v11;
		*(_DWORD *)a1 = 1;
		goto LABEL_36;
	  }
	}
	goto LABEL_34;
  }
  if ( v7 == -2147482879 )
  {
	v10 = atoi(String);
	v6 = a1;
	**(_DWORD **)(a3 + 36) = v10;
	*(_DWORD *)a1 = 1;
	goto LABEL_36;
  }
  if ( v7 == -2147483644 )
  {
	krnl_MFree(**(_DWORD **)(a3 + 36));
	**(_DWORD **)(a3 + 36) = CloneTextData(String);
	v6 = a1;
	*(_DWORD *)a1 = 1;
	goto LABEL_36;
  }
  if ( v7 == -2147483391 )
  {
	v9 = atoi(String);
	v6 = a1;
	**(_BYTE **)(a3 + 36) = v9;
	*(_DWORD *)a1 = 1;
	goto LABEL_36;
  }
  if ( v7 != -2147483135 )
  {
LABEL_34:
	v6 = a1;
	*(_DWORD *)a1 = 1;
	goto LABEL_36;
  }
  v8 = atoi(String);
  v6 = a1;
  **(_WORD **)(a3 + 36) = v8;
  *(_DWORD *)a1 = 1;
LABEL_36:
  CInputEdit___CInputEdit(&v21, v6);
  CInputEdit___CInputEdit(&v20, v13);
  CString___CString(&String);
  CString___CString(&v17);
  CString___CString(&v16);
  CString___CString(&v15);
  return CDialog___CDialog(&v14);
}

  */
  /*
  HGLOBAL hDialogTemplate = NULL;
  HINSTANCE hInst = LoadLibrary("I:\\Program Files\\e5\\lib\\krnln.fne");
  HRSRC hResource = ::FindResource(hInst, (LPCSTR)1037, RT_DIALOG);
  hDialogTemplate = LoadResource(hInst, hResource);
  if (hDialogTemplate != NULL){
	  INT nSize = ::SizeofResource (hInst,hResource);
	  lpDialogTemplate = new BYTE[nSize];
	  memcpy(lpDialogTemplate,LockResource(hDialogTemplate),nSize);

  HANDLE hFile = CreateFile("E:\\��ҵ֧�ֿ�\\��ֲ����������\\InputBox.dat",
	  GENERIC_WRITE,
	  0,
	  NULL,
	  CREATE_ALWAYS,
	  FILE_ATTRIBUTE_ARCHIVE,
	  0);

  BOOL bRet = FALSE;
  if(hFile != INVALID_HANDLE_VALUE)
  {

	  DWORD dwNumOfByteRead;
	  bRet = TRUE;


		  if(WriteFile(hFile,lpDialogTemplate,nSize,&dwNumOfByteRead,NULL))
		  {
			  MessageBox(NULL,"OK1",NULL,MB_OK);

		  }

	  CloseHandle(hFile);
  }

  }


  UnlockResource(hDialogTemplate);
  FreeResource(hDialogTemplate);
  FreeLibrary(hInst);
*/
