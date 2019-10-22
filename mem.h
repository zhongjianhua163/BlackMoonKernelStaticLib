// Mem.h: interface for the CFreqMem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MEM_H__AD73B7A1_418A_11D2_AAE7_000021612B48__INCLUDED_)
#define AFX_MEM_H__AD73B7A1_418A_11D2_AAE7_000021612B48__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

BOOL IsEmptyStr (LPTSTR szStr);
INT tcsallbytes (LPTSTR pstr, LPDWORD pdwStrIndex);
INT tcsallbytes (LPTSTR pstr);
INT tcsbytes (LPTSTR pstr);
INT FindWord (LPWORD pwTable, INT count, WORD wFind);
INT FindDWord (LPDWORD pdwTable, INT count, DWORD dwFind);
INT FindInt (LPINT pnTable, INT nCount, INT nFind);
INT FindByte (LPBYTE pTable, INT count, BYTE btFind);
void ZeroMem (LPBYTE pDest, DWORD dwLength);
void CopyMem (LPBYTE pDest, LPBYTE pSrc, DWORD dwLength);
void MoveMem (LPBYTE pDest, LPBYTE pSrc, DWORD dwLength);


#define	PAGE_SIZE			512		// 页尺寸
#define	PAGE_COUNT			96		// 页数目
#define	PAGE_BUF_SIZE		PAGE_COUNT * PAGE_SIZE

struct MEM_BUF
{
	INT m_nPageUsedCount;			// 页当前已经被使用的数目。
	BYTE m_btaryUsed [PAGE_COUNT];	// 记录每一页是否已被使用。
	BYTE m_buf [PAGE_BUF_SIZE];
};
typedef MEM_BUF* PMEM_BUF;

//////////////////////

#define	FM_MAX_FREE_BUF_SIZE	128
#define	FM_GROW_SIZE			128

class CFreqMem
{
protected:
	PMEM_BUF m_pMemBuf;

protected:
	LPBYTE m_pData;
	INT m_nAllocedSize;
	INT m_nSize;

public:
	CFreqMem ();
	virtual ~CFreqMem ()
	{
		Free ();
	}

public:
	static void BeginUseBuf ();
	static BOOL IsAllowUseBuf ();
	static void AllowUseBuf (BOOL blAllow);

	LPBYTE GetPtr () const
	{
		return m_nSize == 0 ? NULL : m_pData;
	}
	operator LPBYTE () const
	{
		return m_nSize == 0 ? NULL : m_pData;
	}
	INT GetSize () const
	{
		return m_nSize;
	}
	operator INT () const
	{
		return m_nSize;
	}
	INT FindInt (INT nFind)
	{
		LPINT pn = (LPINT)GetPtr ();
		if (pn == NULL)
			return -1;
		else
			return ::FindDWord ((LPDWORD)pn, GetSize () / sizeof (DWORD), (DWORD)nFind);
	}
	INT FindDWord (DWORD dwFind)
	{
		LPDWORD pdw = (LPDWORD)GetPtr ();
		if (pdw == NULL)
			return -1;
		else
			return ::FindDWord (pdw, GetSize () / sizeof (DWORD), dwFind);
	}
	INT FindWord (WORD wFind)
	{
		LPWORD pw = (LPWORD)GetPtr ();
		if (pw == NULL)
			return -1;
		else
			return ::FindWord (pw, GetSize () / sizeof (WORD), wFind);
	}
	BOOL IsEmpty ()
	{
		return m_nSize == 0;
	}

public:
	BOOL EmptyAndRqSpace (INT nSize);
//	void Serialize (CArchive& ar);
//	void SaveEmpty (CArchive& ar);

	void AddFloat		(FLOAT flt);
	void AddDouble		(DOUBLE db);
	void AddDWord		(DWORD dw);
	void AddInt64		(INT64 n64);
	void AddInt			(INT n);
	void AddWord		(WORD w);
	void AddShort		(SHORT sht);
	void AddByte		(BYTE bt);
	void AddBool		(BOOL bl);
	void AddStr			(LPTSTR pstr);
	void AddText        (LPTSTR pstr);

	INT GetDoubleCount ()	{	return m_nSize / sizeof (DOUBLE);	}
	INT GetDWordCount ()	{	return m_nSize / sizeof (DWORD);	}
	INT GetIntCount ()		{	return m_nSize / sizeof (INT);		}
	INT GetWordCount ()		{	return m_nSize / sizeof (WORD);		}
	INT GetShortCount ()	{	return m_nSize / sizeof (SHORT);	}
	DOUBLE*	GetDoublePtr ()	{	return m_nSize == 0 ? NULL : (DOUBLE*)m_pData;		}
	LPDWORD	GetDWordPtr ()	{	return m_nSize == 0 ? NULL : (LPDWORD)m_pData;		}
	LPINT	GetIntPtr ()	{	return m_nSize == 0 ? NULL : (LPINT)m_pData;		}
	LPWORD	GetWordPtr ()	{	return m_nSize == 0 ? NULL : (LPWORD)m_pData;		}
	SHORT*	GetShortPtr ()	{	return m_nSize == 0 ? NULL : (SHORT*)m_pData;		}

public:
	LPBYTE Alloc (INT nSize);
	LPBYTE Realloc (INT nSize);
	void Free ();

	void XchgMem (CFreqMem& mem);
	void Empty ()  { m_nSize = 0; }
	BOOL CopyFrom (CFreqMem& mem)
	{
		Empty ();
		return Append (mem, mem);
	}
	BOOL CopyFrom (LPBYTE pData, INT nSize)
	{
		Empty ();
		return Append (pData, nSize);
	}

	BOOL Insert (INT nOffset, LPBYTE pData, INT nSize);
	BOOL Append (LPBYTE pData, INT nSize);
	BOOL Replace (INT nOffset, INT nSize, LPBYTE pReplaceData, INT nReplaceSize);
	BOOL Remove (INT nOffset, INT nSize);
	BOOL AppendSpace (INT nSpaceCount);

//	INT ReadFile (CString& strFileName, INT nReadLength = -1);
//	BOOL WriteFile (CString& strFileName, INT nWriteLength = -1);

/////////////////

protected:
	void _Free (LPBYTE pData);
};

class CMyDWordArray : public CFreqMem
{
public:
	CMyDWordArray ()  { }

	INT GetSize ()
	{
		return GetDWordCount ();
	}
	INT GetUpperBound ()
	{
		return GetDWordCount () - 1;
	}
	BOOL SetSize (INT nNewSize);
	void RemoveAll ()
	{
		Free ();
	}
	LPDWORD GetData ()
	{
		return GetDWordPtr ();
	}

	DWORD GetAt (INT nIndex) const
	{
//		ASSERT (nIndex >= 0 && nIndex < (INT)(m_nSize / sizeof (DWORD)));
		return ((LPDWORD)m_pData) [nIndex];
	}
	DWORD& ElementAt (INT nIndex)
	{
//		ASSERT (nIndex >= 0 && nIndex < (INT)(m_nSize / sizeof (DWORD)));
		return ((LPDWORD)m_pData) [nIndex];
	}

	void SetAt (INT nIndex, DWORD dwElement)
	{
//		ASSERT (nIndex >= 0 && nIndex < GetDWordCount ());
		if (nIndex >= 0 && nIndex < GetDWordCount ())
			((LPDWORD)m_pData) [nIndex] = dwElement;
	}

	INT Append (const CMyDWordArray& src)
	{
		INT n = GetSize ();
		CFreqMem::Append (src, src);
		return n;
	}
	void Copy (CMyDWordArray& src)
	{
		CopyFrom (src);
	}

	DWORD operator[] (INT nIndex) const
	{
		return GetAt (nIndex);
	}
	DWORD& operator[] (INT nIndex)
	{
		return ElementAt (nIndex);
	}

	INT Add (DWORD dwElement)
	{
		AddDWord (dwElement);
		return GetUpperBound ();
	}
	void InsertAt (INT nIndex, DWORD dwElement)
	{
		Insert (nIndex * sizeof (DWORD), (LPBYTE)&dwElement, sizeof (DWORD));
	}
	void RemoveAt (INT nIndex, INT nCount = 1)
	{
		Remove (nIndex * sizeof (DWORD), sizeof (DWORD) * nCount);
	}
};


#endif // !defined(AFX_MEM_H__AD73B7A1_418A_11D2_AAE7_000021612B48__INCLUDED_)

