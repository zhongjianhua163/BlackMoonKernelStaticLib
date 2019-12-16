// MyMemFile.h: interface for the CMyMemFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYMEMFILE_H__0D0A64A2_866B_4027_AD22_AEFE48A79B01__INCLUDED_)
#define AFX_MYMEMFILE_H__0D0A64A2_866B_4027_AD22_AEFE48A79B01__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMyMemFile  
{

public:

// Constructors
	CMyMemFile(UINT nGrowBytes = 1024);
	CMyMemFile(BYTE* lpBuffer, UINT nBufferSize, UINT nGrowBytes = 0);

// Operations
	void Attach(BYTE* lpBuffer, UINT nBufferSize, UINT nGrowBytes = 0);
	BYTE* Detach();

// Advanced Overridables
protected:
	virtual BYTE* Alloc(DWORD nBytes);
	virtual BYTE* Realloc(BYTE* lpMem, DWORD nBytes);
//	virtual BYTE* Memcpy(BYTE* lpMemTarget, const BYTE* lpMemSource, UINT nBytes);
	virtual void Free(BYTE* lpMem);
	virtual void GrowFile(DWORD dwNewLen);

// Implementation
protected:
	UINT m_nGrowBytes;
	DWORD m_nPosition;
	DWORD m_nBufferSize;
	DWORD m_nFileSize;
	BYTE* m_lpBuffer;
	BOOL m_bAutoDelete;

public:
	DWORD GetFileSize();
	virtual ~CMyMemFile();

	virtual DWORD GetPosition() const;
	//BOOL GetStatus(CFileStatus& rStatus) const;
	enum SeekPosition { begin = 0x0, current = 0x1, end = 0x2 };
	virtual LONG Seek(LONG lOff, UINT nFrom);
	virtual void SetLength(DWORD dwNewLen);
	virtual UINT Read(void* lpBuf, UINT nCount);
	virtual void Write(const void* lpBuf, UINT nCount);
	virtual void Abort();
//	virtual void Flush();
	virtual void Close();
	enum BufferCommand { bufferRead, bufferWrite, bufferCommit, bufferCheck };
	virtual UINT GetBufferPtr(UINT nCommand, UINT nCount = 0,
		void** ppBufStart = NULL, void** ppBufMax = NULL);

	// Unsupported APIs
//	virtual CFile* Duplicate() const;
//	virtual void LockRange(DWORD dwPos, DWORD dwCount);
//	virtual void UnlockRange(DWORD dwPos, DWORD dwCount);

};

#endif // !defined(AFX_MYMEMFILE_H__0D0A64A2_866B_4027_AD22_AEFE48A79B01__INCLUDED_)
