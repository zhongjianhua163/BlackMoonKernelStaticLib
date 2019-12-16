// Mem.cpp: implementation of the CFreqMem class.
//
//////////////////////////////////////////////////////////////////////

#include <StdAfx.h>
#include <TCHAR.H>
#include "mem.h"

static HANDLE s_hHeap = NULL;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

static BOOL s_blAllowUseBuf = FALSE;
	// 如果本变量被设置为假，则缓冲区功能被禁止，但在 CVarManger 中被自动启用。

BOOL CFreqMem::IsAllowUseBuf ()
{
	return s_blAllowUseBuf;
}

void CFreqMem::AllowUseBuf (BOOL blAllow)
{
	s_blAllowUseBuf = blAllow;
}

//////////////////////////////////////////////////////////////////////

MEM_BUF _m_membuf;	// !!! 不允许直接引用此变量。

CFreqMem::CFreqMem ()
{
	m_pMemBuf = &_m_membuf;
	m_pData = NULL;
	m_nAllocedSize = m_nSize = 0;
}

// IMPLEMENT_SERIAL (CFreqMem, CObject, 1)

LPBYTE CFreqMem::Alloc (INT nSize)
{
//	ASSERT (nSize > 0);

	if (m_pData != NULL)
	{
//		ASSERT (m_nAllocedSize > 0);
		return Realloc (nSize);
	}

	if (nSize == 0)  return NULL;

	if (s_blAllowUseBuf == TRUE && nSize <= PAGE_SIZE &&
			m_pMemBuf->m_nPageUsedCount < PAGE_COUNT)
	{
		INT n = FindByte (m_pMemBuf->m_btaryUsed, PAGE_COUNT, 0);
//		ASSERT (n != -1);

		m_pMemBuf->m_btaryUsed [n] = 1;
		m_pMemBuf->m_nPageUsedCount++;

		m_nAllocedSize = PAGE_SIZE;
		m_pData = m_pMemBuf->m_buf + n * PAGE_SIZE;
		m_nSize = nSize;
		return m_pData;
	}

	if (s_hHeap == NULL)
		s_hHeap = ::GetProcessHeap ();

	m_pData = (LPBYTE)::HeapAlloc (s_hHeap, 0, nSize + FM_GROW_SIZE);
	if (m_pData == NULL)
	{
		m_nAllocedSize = 0;
		m_nSize = 0;
	}
	else
	{
		m_nAllocedSize = nSize + FM_GROW_SIZE;
		m_nSize = nSize;
	}
	return m_pData;
}

LPBYTE CFreqMem::Realloc (INT nSize)
{
//	ASSERT (nSize >= 0);
	if (nSize == 0)
	{
		Free ();
		return NULL;
	}
	if (m_pData == NULL)
	{
//		ASSERT (m_nAllocedSize == 0);
		return Alloc (nSize);
	}

	BOOL blIsAllocBuf = m_pData >= m_pMemBuf->m_buf &&
			m_pData < m_pMemBuf->m_buf + PAGE_BUF_SIZE;

	if (m_nAllocedSize >= nSize && (blIsAllocBuf == TRUE ||
			m_nAllocedSize - nSize <= FM_MAX_FREE_BUF_SIZE + FM_GROW_SIZE))
	{
		m_nSize = nSize;
		return m_pData;
	}

	if (s_hHeap == NULL)
		s_hHeap = ::GetProcessHeap ();

	LPBYTE pNew;
	if (blIsAllocBuf == TRUE)
	{
		pNew = (LPBYTE)::HeapAlloc (s_hHeap, 0, nSize + FM_GROW_SIZE);
		if (pNew != NULL)
		{
			CopyMemory (pNew, m_pData, min (nSize, m_nSize));
			_Free (m_pData);
			m_pData = pNew;
			m_nAllocedSize = nSize + FM_GROW_SIZE;
			m_nSize = nSize;
			return m_pData;
		}
		else
			return NULL;
	}

	pNew = (LPBYTE)::HeapReAlloc (s_hHeap, 0, m_pData, nSize + FM_GROW_SIZE);
	if (pNew != NULL)
	{
		m_pData = pNew;
		m_nAllocedSize = nSize + FM_GROW_SIZE;
		m_nSize = nSize;
		return m_pData;
	}
	else
		return NULL;
}

void CFreqMem::Free ()
{
	_Free (m_pData);

	m_pData = NULL;
	m_nAllocedSize = m_nSize = 0;
}

void CFreqMem::_Free (LPBYTE pData)
{
	if (pData == NULL)  return;

	if (pData < m_pMemBuf->m_buf || pData >= m_pMemBuf->m_buf + PAGE_BUF_SIZE)
	{
		if (s_hHeap == NULL)
			s_hHeap = ::GetProcessHeap ();
//		VERIFY (::HeapFree (s_hHeap, NULL, pData));
		::HeapFree (s_hHeap, NULL, pData);
	}
	else
	{
//		ASSERT ((pData - m_pMemBuf->m_buf) % PAGE_SIZE == 0 &&
//				m_pMemBuf->m_btaryUsed [(pData - m_pMemBuf->m_buf) / PAGE_SIZE] == 1 &&
//				m_pMemBuf->m_nPageUsedCount > 0);
		m_pMemBuf->m_btaryUsed [(pData - m_pMemBuf->m_buf) / PAGE_SIZE] = 0;
		m_pMemBuf->m_nPageUsedCount--;
	}
}

///////////////////////////////////////////

void CFreqMem::AddFloat	(FLOAT flt)
{
	if (m_nAllocedSize - m_nSize >= sizeof (FLOAT))
	{
		*(FLOAT*)(m_pData + m_nSize) = flt;
		m_nSize += sizeof (FLOAT);
	}
	else
		Append ((LPBYTE)&flt, sizeof (flt));
}

void CFreqMem::AddDouble (DOUBLE db)
{
	if (m_nAllocedSize - m_nSize >= sizeof (DOUBLE))
	{
		*(DOUBLE*)(m_pData + m_nSize) = db;
		m_nSize += sizeof (DOUBLE);
	}
	else
		Append ((LPBYTE)&db, sizeof (DOUBLE));
}

void CFreqMem::AddDWord (DWORD dw)
{
	if (m_nAllocedSize - m_nSize >= sizeof (DWORD))
	{
		*(DWORD*)(m_pData + m_nSize) = dw;
		m_nSize += sizeof (DWORD);
	}
	else
		Append ((LPBYTE)&dw, sizeof (DWORD));
}

void CFreqMem::AddInt64 (INT64 n64)
{
	if (m_nAllocedSize - m_nSize >= sizeof (INT64))
	{
		*(INT64*)(m_pData + m_nSize) = n64;
		m_nSize += sizeof (INT64);
	}
	else
		Append ((LPBYTE)&n64, sizeof (INT64));
}

void CFreqMem::AddInt (INT n)
{
	if (m_nAllocedSize - m_nSize >= sizeof (INT))
	{
		*(INT*)(m_pData + m_nSize) = n;
		m_nSize += sizeof (INT);
	}
	else
		Append ((LPBYTE)&n, sizeof (INT));
}

void CFreqMem::AddWord (WORD w)
{
	if (m_nAllocedSize - m_nSize >= sizeof (WORD))
	{
		*(WORD*)(m_pData + m_nSize) = w;
		m_nSize += sizeof (WORD);
	}
	else
		Append ((LPBYTE)&w, sizeof (WORD));
}

void CFreqMem::AddShort (SHORT sht)
{
	if (m_nAllocedSize - m_nSize >= sizeof (SHORT))
	{
		*(SHORT*)(m_pData + m_nSize) = sht;
		m_nSize += sizeof (SHORT);
	}
	else
		Append ((LPBYTE)&sht, sizeof (SHORT));
}

void CFreqMem::AddByte (BYTE bt)
{
	if (m_nAllocedSize > m_nSize)
		m_pData [m_nSize++] = bt;
	else
		Append ((LPBYTE)&bt, sizeof (BYTE));
}

void CFreqMem::AddBool (BOOL bl)
{
	if (m_nAllocedSize - m_nSize >= sizeof (BOOL))
	{
		*(BOOL*)(m_pData + m_nSize) = bl;
		m_nSize += sizeof (BOOL);
	}
	else
		Append ((LPBYTE)&bl, sizeof (BOOL));
}

void CFreqMem::AddStr (LPTSTR pstr)
{
	if (IsEmptyStr (pstr) == TRUE)
		AddByte (0);
	else
		Append ((LPBYTE)pstr, tcsallbytes (pstr));
}

void CFreqMem::AddText (LPTSTR pstr)
{
	if (IsEmptyStr (pstr) == FALSE)
		Append ((LPBYTE)pstr, tcsbytes (pstr));
}

///////////////////////////////////////////

BOOL CFreqMem::EmptyAndRqSpace (INT nSize)
{
//	ASSERT (nSize >= 0);
	if (nSize <= 0)
		nSize = 0;

	if (Realloc (nSize) != NULL)
	{
		m_nSize = 0;
		return TRUE;
	}
	else
		return FALSE;
}

// !! 必须保证不改变两个 MEM 的首地址指针。
void CFreqMem::XchgMem (CFreqMem& mem)
{
	PMEM_BUF pMemBuf = m_pMemBuf;
	m_pMemBuf = mem.m_pMemBuf;
	mem.m_pMemBuf = pMemBuf;

	LPBYTE p = m_pData;
	m_pData = mem.m_pData;
	mem.m_pData = p;

	INT n = m_nAllocedSize;
	m_nAllocedSize = mem.m_nAllocedSize;
	mem.m_nAllocedSize = n;

	n = m_nSize;
	m_nSize = mem.m_nSize;
	mem.m_nSize = n;
}
/*
void CFreqMem::SaveEmpty (CArchive& ar)
{
	ASSERT (ar.IsStoring ());
	ar << (INT)0;
}

void CFreqMem::Serialize (CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_nSize;
		if (m_nSize > 0)
			ar.Write (m_pData, m_nSize);
	}
	else
	{
		Free ();

		INT nSize;
		ar >> nSize;
		if (nSize > 0)
		{
			if (Alloc (nSize) != NULL)
				ar.Read (m_pData, nSize);
			else
				AfxThrowArchiveException (CArchiveException::generic);
		}
	}
}

INT CFreqMem::ReadFile (CString& strFileName, INT nReadLength)
{
	TRY
	{
		CFile file;
		if (file.Open (strFileName, CFile::modeRead | CFile::shareDenyWrite) == TRUE)
		{
			if (nReadLength == -1)
				nReadLength = file.GetLength ();

			if (nReadLength > 0)
			{
				LPBYTE p = Alloc (nReadLength);
				if (p != NULL)
				{
					INT n = file.Read (p, nReadLength);
					if (n != nReadLength)
						Realloc (n);
					return n;
				}
			}
			else
			{
				Free ();
				return 0;
			}
		}
	}
	END_TRY

	Free ();
	return -1;
}

BOOL CFreqMem::WriteFile (CString& strFileName, INT nWriteLength)
{
	ASSERT (strFileName.IsEmpty () == FALSE);

	TRY
	{
		INT nSize = GetSize ();
		if (nWriteLength == -1)
			nWriteLength = nSize;
		else
			nWriteLength = min (nWriteLength, nSize);

		CFile file;
		if (file.Open (strFileName, CFile::modeCreate | CFile::modeWrite |
				CFile::shareExclusive) == TRUE)
		{
			if (nWriteLength > 0)
				file.Write (GetPtr (), nWriteLength);

			file.Close ();
			return TRUE;
		}
	}
	END_TRY

	return FALSE;
}
*/
////////////////////////////

// if pData == NULL, insert blank data.
BOOL CFreqMem::Insert (INT nOffset, LPBYTE pData, INT nSize)
{
//	ASSERT (nOffset >= 0 && nSize >= 0);
	if (nSize == 0)  return TRUE;
	if (nOffset == m_nSize)  return Append (pData, nSize);

	INT nOldSize = m_nSize;
	LPBYTE pMem = Realloc (max (nOffset, nOldSize) + nSize);
	if (pMem == NULL)  return FALSE;

	LPBYTE pInsert = pMem + nOffset;
	if (nOffset < nOldSize)
		MoveMem (pInsert + nSize, pInsert, nOldSize - nOffset);
	
	if (pData != NULL)
	{
//		ASSERT (AfxIsValidAddress (pData, nSize));
		MoveMem (pInsert, pData, nSize);
	}
	else
		ZeroMem (pInsert, nSize);

	return TRUE;
}

BOOL CFreqMem::AppendSpace (INT nSpaceCount)
{
//	ASSERT (nSpaceCount >= 0);

	if (Append (NULL, nSpaceCount) == TRUE)
	{
		if (nSpaceCount > 0)
			memset (GetPtr () + GetSize () - nSpaceCount, ' ', nSpaceCount);
		return TRUE;
	}

	return FALSE;
}

// if pData == NULL, append blank data.
BOOL CFreqMem::Append (LPBYTE pData, INT nSize)
{
//	ASSERT (nSize >= 0);
	if (nSize <= 0)  return TRUE;

	INT nOldSize = m_nSize;
	LPBYTE pMem = Realloc (nOldSize + nSize);
	if (pMem == NULL)  return FALSE;

	LPBYTE pAppend = pMem + nOldSize;
	if (pData != NULL)
		MoveMem (pAppend, pData, nSize);
	else
		ZeroMem (pAppend, nSize);

	return TRUE;
}

// if pReplaceData == NULL, replace blank data.
BOOL CFreqMem::Replace (INT nOffset, INT nSize, LPBYTE pReplaceData, INT nReplaceSize)
{
//	ASSERT (nOffset >= 0 && nSize >= 0 && nReplaceSize >= 0);

	INT nOldSize = m_nSize;
	if (nSize == 0 || nOffset >= nOldSize)
		return Insert (nOffset, pReplaceData, nReplaceSize);
	if (nReplaceSize == 0)  
		return Remove (nOffset, nSize);

	if (nSize > nOldSize - nOffset)  nSize = nOldSize - nOffset;

	LPBYTE pReplaceAt;
	INT nMoveSize = nOldSize - nOffset - nSize;
	if (nReplaceSize > nSize)
	{
		pReplaceAt = Realloc (nOldSize + nReplaceSize - nSize);
		if (pReplaceAt == NULL)  return FALSE;
		pReplaceAt += nOffset;

		if (nMoveSize > 0)
			MoveMem (pReplaceAt + nReplaceSize, pReplaceAt + nSize, nMoveSize);
	}
	else
	{
		pReplaceAt = m_pData;
//		ASSERT (pReplaceAt != NULL);
		pReplaceAt += nOffset;

		if (nReplaceSize < nSize)
		{
			if (nMoveSize > 0)
				MoveMem (pReplaceAt + nReplaceSize, pReplaceAt + nSize, nMoveSize);

			pReplaceAt = Realloc (nOldSize - (nSize - nReplaceSize));
		//	ASSERT (pReplaceAt != NULL);
			if (pReplaceAt == NULL)  return FALSE;  // data already be changed!
			pReplaceAt += nOffset;
		}
	}

	if (pReplaceData != NULL)
	{
//		ASSERT (AfxIsValidAddress (pReplaceData, nReplaceSize, FALSE));
		MoveMem (pReplaceAt, pReplaceData, nReplaceSize);
	}
	else
		ZeroMem (pReplaceAt, nReplaceSize);
	return TRUE;
}

// if nOffset == -1, delete data from tail.
BOOL CFreqMem::Remove (INT nOffset, INT nSize)
{
	if (nOffset == -1)
	{
		INT nNewSize = max (0, m_nSize - nSize);
		if (nNewSize == 0)
		{
			Free ();
			return TRUE;
		}
		else
			return Realloc (nNewSize) != NULL;
	}

	if (nSize == 0)  return TRUE;
	if (m_pData == NULL || nOffset >= m_nSize)  return FALSE;
	
	LPBYTE pRemoveAt = m_pData + nOffset;
	
	INT nRemoveSize;
	if (nSize < m_nSize - nOffset)
	{
		nRemoveSize = nSize;
		MoveMem (pRemoveAt, pRemoveAt + nRemoveSize, m_nSize - nOffset - nRemoveSize);
	}
	else
		nRemoveSize = m_nSize - nOffset;

	if (m_nSize == nRemoveSize)
	{
		Free ();
		return TRUE;
	}
	else
		return Realloc (m_nSize - nRemoveSize) != NULL;
}

//////////////////////////////////////////

BOOL CMyDWordArray::SetSize (INT nNewSize)
{
	if (nNewSize == 0)
	{
		Free ();
	}
	else
	{
		nNewSize *= sizeof (DWORD);
		LPBYTE p = Alloc (nNewSize);
		if (p != NULL)
			ZeroMem (p, nNewSize);
		else
			return FALSE;
	}

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////

INT FindInt (LPINT pnTable, INT nCount, INT nFind)
{
	return FindDWord ((LPDWORD)pnTable, nCount, (DWORD)nFind);
}

BOOL IsEmptyStr (LPTSTR szStr)
{
	return szStr == NULL || *szStr == 0;
}

void MoveMem (LPBYTE pDest, LPBYTE pSrc, DWORD dwLength)
{
	if (dwLength == 0)
		return;
	else if (dwLength == 1)
		*pDest = *pSrc;
	else if (dwLength == sizeof (WORD))
		*(LPWORD)pDest = *(LPWORD)pSrc;
	else if (dwLength == sizeof (DWORD))
		*(LPDWORD)pDest = *(LPDWORD)pSrc;
	else
		::MoveMemory (pDest, pSrc, dwLength);
}

void CopyMem (LPBYTE pDest, LPBYTE pSrc, DWORD dwLength)
{
	if (dwLength == 0)
		return;
	else if (dwLength == 1)
		*pDest = *pSrc;
	else if (dwLength == sizeof (WORD))
		*(LPWORD)pDest = *(LPWORD)pSrc;
	else if (dwLength == sizeof (DWORD))
		*(LPDWORD)pDest = *(LPDWORD)pSrc;
	else
		::CopyMemory (pDest, pSrc, dwLength);
}

void ZeroMem (LPBYTE pDest, DWORD dwLength)
{
	if (dwLength == 0)
		return;
	else if (dwLength == 1)
		*pDest = 0;
	else if (dwLength == sizeof (WORD))
		*(LPWORD)pDest = 0;
	else if (dwLength == sizeof (DWORD))
		*(LPDWORD)pDest = 0;
	else
		::ZeroMemory (pDest, dwLength);
}

INT tcsallbytes (LPTSTR pstr)
{
	return (_tcslen (pstr) + 1) * sizeof (TCHAR);
/*
	if (*pstr == '\0')  return 1;

	DWORD dw;

	_asm
	{
		push	eax
		push	ebx
		push	esi

		mov		esi, dword ptr [pstr]
		mov		ebx, esi

		cld
	l0:
		lodsb
		or		al, al
		jne		l0

		sub		esi, ebx
		mov		dw, esi

		pop		esi
		pop		ebx
		pop		eax
	}

	return (INT)dw; */
}

INT tcsbytes (LPTSTR pstr)
{
	return _tcslen (pstr) * sizeof (TCHAR);
/*
	if (pstr == NULL || *pstr == '\0')  return 0;

	DWORD dw;

	_asm
	{
		push	eax
		push	ebx
		push	esi

		mov		esi, dword ptr [pstr]
		mov		ebx, esi

		cld
	l0:
		lodsb
		or		al, al
		jne		l0

		dec		esi
		sub		esi, ebx
		mov		dw, esi

		pop		esi
		pop		ebx
		pop		eax
	}

	return (INT)dw; */
}

// 返回的是字节偏移数。
INT FindByte (LPBYTE pTable, INT count, BYTE btFind)
{ 
	INT nRetOffset = -1;

	if (count > 0)
	{
//		ASSERT (pTable != NULL);
		if (*pTable == btFind)  return 0;

		__asm
		{
			push edi
			push eax
			push ecx

			mov al, btFind
			mov ecx, count
			push ecx
			mov edi, dword ptr [pTable]

	        cld
			repne scasb
			pop eax
			jnz quit

			inc ecx
			sub eax, ecx
			mov dword ptr [nRetOffset], eax
quit:
			pop ecx
			pop eax
			pop edi
		}
	}

	return nRetOffset;
}

// 返回的不是字节数，而是DWORD偏移数。
INT FindDWord (LPDWORD pdwTable, INT count, DWORD dwFind)
{ 
	INT nRetOffset = -1;

	if (count > 0)
	{
		if (*pdwTable == dwFind)  return 0;

	//	ASSERT (pdwTable != NULL);
		__asm
		{
			push edi
			push eax
			push ecx

			mov eax, dwFind
			mov ecx, count
			push ecx
			mov edi, dword ptr [pdwTable]

	        cld
			repne scasd
			pop eax
			jnz quit

			inc ecx
			sub eax, ecx
			mov dword ptr [nRetOffset], eax
quit:
			pop ecx
			pop eax
			pop edi
		}
	}

	return nRetOffset;
}

// 返回的不是字节数，而是WORD偏移数。
INT FindWord (LPWORD pwTable, INT count, WORD wFind)
{ 
	INT nRetOffset = -1;

	if (count > 0)
	{
	//	ASSERT (pwTable != NULL);
		__asm
		{
			push edi
			push eax
			push ecx

			mov ax, wFind
			mov ecx, count
			push ecx
			mov edi, dword ptr [pwTable]

	        cld
			repne scasw
			pop eax
			jnz quit

			inc ecx
			sub eax, ecx
			mov dword ptr [nRetOffset], eax
quit:
			pop ecx
			pop eax
			pop edi
		}
	}

	return nRetOffset;
}

