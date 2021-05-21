#include "stdafx.h"
#include "Myfunctions.h"
#include <stdio.h>
#define MAX(x, y) (x) > (y) ? (x) : (y)

unsigned char lowtable[] =
{
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,
	0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,
	0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,
	0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F,
	0x40, 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
	'p' , 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',0x5B,0x5C,0x5D,0x5E,0x5F,
	0x60, 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
	'p' , 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',0x7B,0x7C,0x7D,0x7E,0x7F,
	0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F,
	0x90,0x91,0x92,0x93,0x94,0x95,0x96,0x97,0x98,0x99,0x9A,0x9B,0x9C,0x9D,0x9E,0x9F,
	0xA0,0xA1,0xA2,0xA3,0xA4,0xA5,0xA6,0xA7,0xA8,0xA9,0xAA,0xAB,0xAC,0xAD,0xAE,0xAF,
	0xB0,0xB1,0xB2,0xB3,0xB4,0xB5,0xB6,0xB7,0xB8,0xB9,0xBA,0xBB,0xBC,0xBD,0xBE,0xBF,
	0xC0,0xC1,0xC2,0xC3,0xC4,0xC5,0xC6,0xC7,0xC8,0xC9,0xCA,0xCB,0xCC,0xCD,0xCE,0xCF,
	0xD0,0xD1,0xD2,0xD3,0xD4,0xD5,0xD6,0xD7,0xD8,0xD9,0xDA,0xDB,0xDC,0xDD,0xDE,0xDF,
	0xE0,0xE1,0xE2,0xE3,0xE4,0xE5,0xE6,0xE7,0xE8,0xE9,0xEA,0xEB,0xEC,0xED,0xEE,0xEF,
	0xF0,0xF1,0xF2,0xF3,0xF4,0xF5,0xF6,0xF7,0xF8,0xF9,0xFA,0xFB,0xFC,0xFD,0xFE,0xFF
};

unsigned char uptable[] =
{
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,
	0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,
	0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,
	0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F,
	0x40, 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
	'P' , 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',0x5B,0x5C,0x5D,0x5E,0x5F,
	0x60, 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
	'P' , 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',0x7B,0x7C,0x7D,0x7E,0x7F,
	0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F,
	0x90,0x91,0x92,0x93,0x94,0x95,0x96,0x97,0x98,0x99,0x9A,0x9B,0x9C,0x9D,0x9E,0x9F,
	0xA0,0xA1,0xA2,0xA3,0xA4,0xA5,0xA6,0xA7,0xA8,0xA9,0xAA,0xAB,0xAC,0xAD,0xAE,0xAF,
	0xB0,0xB1,0xB2,0xB3,0xB4,0xB5,0xB6,0xB7,0xB8,0xB9,0xBA,0xBB,0xBC,0xBD,0xBE,0xBF,
	0xC0,0xC1,0xC2,0xC3,0xC4,0xC5,0xC6,0xC7,0xC8,0xC9,0xCA,0xCB,0xCC,0xCD,0xCE,0xCF,
	0xD0,0xD1,0xD2,0xD3,0xD4,0xD5,0xD6,0xD7,0xD8,0xD9,0xDA,0xDB,0xDC,0xDD,0xDE,0xDF,
	0xE0,0xE1,0xE2,0xE3,0xE4,0xE5,0xE6,0xE7,0xE8,0xE9,0xEA,0xEB,0xEC,0xED,0xEE,0xEF,
	0xF0,0xF1,0xF2,0xF3,0xF4,0xF5,0xF6,0xF7,0xF8,0xF9,0xFA,0xFB,0xFC,0xFD,0xFE,0xFF
};

int __fastcall isSSE2()
{
	static int bIsSSE2 = FALSE;
	static int bIsSSE2Check = FALSE;
	if (bIsSSE2Check)
		return bIsSSE2;
	int res = 0;
	__asm
	{
		mov eax, 01h;
		cpuid;
		mov res, edx;
	}
	bIsSSE2 =  res & (1 << 26);
	bIsSSE2Check = TRUE;
	return bIsSSE2;
}

int inline MyMemCmp(unsigned char* a, unsigned char* b, int len)
{
	for (int i=0; i<(len>>2); i++)
	{
		if (((int*)a)[0]!=((int*)b)[0])
			return 1;
		a+=4;b+=4;
	}
	if ((len&2) != 0)
	{
		if (((short*)a)[0]!=((short*)b)[0])
			return 1;
		a+=2;b+=2;
	}
	if ((len&1) != 0 && a[0]!=b[0])
		return 1;
	return 0;
}

static size_t mystrlen_normal(const char *pStr)
{
	const char *char_ptr;
    const unsigned int *longword_ptr;
    register unsigned int longword, himagic, lomagic;
	const char *cp;
	
    for (char_ptr = pStr; ((unsigned int) char_ptr & (sizeof(unsigned int) - 1)) != 0;
	++char_ptr) {
        if (*char_ptr == '\0')
            return char_ptr - pStr;
    }
	
    longword_ptr = (unsigned int*) char_ptr;
    himagic = 0x80808080L;
    lomagic = 0x01010101L;
    while (1) {
        longword = *longword_ptr++;
        if (((longword - lomagic) & ~longword & himagic) != 0) {
            cp = (const char*) (longword_ptr - 1);
            if (cp[0] == 0)
                return cp - pStr;
            if (cp[1] == 0)
                return cp - pStr + 1;
            if (cp[2] == 0)
                return cp - pStr + 2;
            if (cp[3] == 0)
                return cp - pStr + 3;
        }
    }
}

static size_t mystrlen_SSE2(const char *pStr)
{
	size_t res = 0;
	__asm
	{
		mov eax, pStr;                        // get pointer to string
		test eax, eax;
		je END__;                            // return 0 if eax is NULL
		mov ecx, eax;                        // copy pointer
		// pxor xmm0,xmm0;                   // set to zero
		_EMIT 0x66;
		_EMIT 0x0F;
		_EMIT 0xEF;
		_EMIT 0xC0;
		and ecx, 0Fh;                        // lower 4 bits indicate misalignment
		and eax, 0FFFFFFF0h;                 // align pointer by 16
		// movdqa xmm1, [eax];               // read from nearest preceding boundary
		_EMIT 0x66; 
		_EMIT 0x0F; 
		_EMIT 0x6F; 
		_EMIT 0x08;
		// pcmpeqb xmm1,xmm0;                // compare 16 bytes with zero
		_EMIT 0x66;
		_EMIT 0x0F;
		_EMIT 0x74;
		_EMIT 0xC8;   
		// pmovmskb edx, xmm1;               // get one bit for each byte result
		_EMIT 0x66;
		_EMIT 0x0F;
		_EMIT 0xD7;
		_EMIT 0xD1;   
		shr edx, cl;                         // shift out false bits
		shl edx, cl;                         // shift back again
		bsf edx, edx;                        // find first 1 - bit
		jne A200;                            // found
		
		//; Main loop, search 16 bytes at a time
A100 :		
		add eax, 10h;                        // increment pointer by 16
		// movdqa   xmm1, [eax];             // read 16 bytes aligned
		_EMIT 0x66;
		_EMIT 0x0F;
		_EMIT 0x6F;
		_EMIT 0x08;
		// pcmpeqb  xmm1, xmm0;              // compare 16 bytes with zero
		_EMIT 0x66;
		_EMIT 0x0F;
		_EMIT 0x74;
		_EMIT 0xC8;   
		// pmovmskb edx, xmm1;               // get one bit for each byte result
		_EMIT 0x66;
		_EMIT 0x0F;
		_EMIT 0xD7;
		_EMIT 0xD1;   
		bsf edx, edx;                        // find first 1 - bit
		//; (moving the bsf out of the loop and using test here would be faster for long strings on old processors,
		//;  but we are assuming that most strings are short, and newer processors have higher priority)
		je A100;                            // loop if not found
		
A200 : //; Zero - byte found.Compute string length
		sub eax, pStr;                        // subtract start address
		add eax, edx;                        // add byte index
		mov res, eax;
END__:
	}
	return res;
}

size_t mystrlen_auto(const char *pStr)
{ // 此函数为自适配函数，只会被调用一次。
	if (isSSE2())
	{ // 支持SSE2指令集
		mystrlen = mystrlen_SSE2;
		return mystrlen_SSE2(pStr);
	}
	else
	{
		mystrlen = mystrlen_normal;
		return mystrlen_normal(pStr);
	}
	return 0;
}
MYSTRLEN mystrlen = mystrlen_auto;

int __fastcall mymemchr(unsigned char *pSrc, int nLen, unsigned char Des)
{
	register unsigned int longword, dmagic, *longword_ptr;
	unsigned char *cp;
	unsigned char *char_ptr = pSrc;
    for (int i = 0; i < (nLen & 3);i++)
        if (*char_ptr++ == Des)
            return char_ptr - pSrc - 1;
	
	dmagic = Des | (Des<<8) | (Des<<16) | (Des<<24);
	for (longword_ptr = (unsigned int*)char_ptr; longword_ptr < (unsigned int*)(pSrc + nLen); longword_ptr++)
    {
        longword = *longword_ptr ^ dmagic;
        if (((longword - 0x01010101) & ~longword & 0x80808080) != 0)
		{
            cp = (unsigned char*)(longword_ptr);
            if (cp[0] == Des)
                return cp - pSrc;
            if (cp[1] == Des)
                return cp - pSrc + 1;
            if (cp[2] == Des)
                return cp - pSrc + 2;
            if (cp[3] == Des)
                return cp - pSrc + 3;
        }
    }
	return -1;
}

int __fastcall myinstring(unsigned char *src, int slen, unsigned char *des, int dlen)
{
//	register unsigned char* naddr;
//	int sl;int i;int j;
	int i;
	if (!src || !des || !slen || !dlen || dlen > slen)
		return -1;

	switch (dlen)
	{
	case 1:  // 短子串直接暴力搜索
		return mymemchr(src, slen, des[0]);
	case 2:
		for (i=0; i < slen - 1; i++)
			if (((short*)(src+i))[0] == ((short*)des)[0])
				return i;
		return -1;
	case 3:
		for (i=0; i < slen - 2; i++)
			if (((short*)(src+i))[0] == ((short*)des)[0])
				if (src[i+2] == des[2])
					return i;
		return -1;
	case 4:
		for (i=0; i < slen - 3; i++)
			if (((int*)(src+i))[0] == ((int*)des)[0])
				return i;
		return -1;
	case 5:
		for (i=0; i < slen - 4; i++)
			if (((int*)(src+i))[0] == ((int*)des)[0])
				if (src[i+4] == des[4])
					return i;
		return -1;
	case 6:
		for (i=0; i < slen - 5; i++)
			if (((int*)(src+i))[0] == ((int*)des)[0])
				if (((short*)(src+i+4))[0] == ((short*)(des+4))[0])
					return i;	
		return -1;
	default:// 长子串使用BM算法,
		return BoyerMoore(src, slen, des, dlen);
	}
	
	// Sunday算法,
// 	unsigned char next[256];
// 	if (dlen >= 256)
// 	{
// 		sl = 256;
// 		memset(next, 255, 256);
// 	}else{
// 		sl = dlen;
// 		memset(next, dlen, 256);
// 	}
// 	for (i = 0; i < sl; i++)
// 		next[des[i]] = sl - i;
// 	
// 	register unsigned char* endaddr = src + slen - dlen;
// 	for (naddr = src; naddr <= endaddr; naddr += next[naddr[dlen]])
// 		if (MyMemCmp(naddr, des, dlen)==0)
// 			return naddr-src;
// 		
// 		return -1;
}

char* TBR::toString()
{
	if (m_nCount <= 0 || m_nTLen <= 0 || !m_data)
	{
		return NULL;
	}
	char* pText = (char*)E_MAlloc_Nzero(m_nTLen + 1);
	char* pRetnTmp = pText;
	
	for (int i = 0; i < m_nCount; i++)
	{
		memcpy(pRetnTmp, m_data[i].addr, m_data[i].len);
		pRetnTmp += m_data[i].len;
	}
	pText[m_nTLen] = '\0';
	return pText;
}

TBR::TBR()
{
	m_nCount = 0;
	m_nTCount = 0;
	m_nTLen = 0;
	m_data = NULL;
}
TBR::~TBR()
{
	if (m_data)
	{
		free(m_data);
	}
}
void TBR::add(PVOID addr, size_t len)
{
	if (!m_data)
	{
		m_data = (PTBRECORD)malloc(512 * sizeof(TBRECORD));
		if (!m_data)
			return;
		m_nTCount = 512;
	}
	if (m_nCount >= m_nTCount)
	{
		int nNewCount = m_nTCount << 1;
		PVOID pNewData = realloc(m_data, nNewCount * sizeof(TBRECORD));
		if (!pNewData)
		{
			pNewData = malloc(sizeof(TBRECORD) * nNewCount);
			if (!pNewData)
				return;
			memcpy(pNewData, m_data, sizeof(TBRECORD) * m_nTCount);
			free(m_data);
		}
		m_data = (TBRECORD*)pNewData;
		m_nTCount = nNewCount;
	}
	if (len < 0)
	{
		len = 0;
	}
	m_data[m_nCount].addr = addr;
	m_data[m_nCount++].len = len;
	m_nTLen += len;
}

INT __fastcall mystristr(char* str1, char* str2)
{
	register char *cp = str1;
	register char *s1, *s2;
	register unsigned char* lt = lowtable;
	while (*cp)
	{
		s1 = cp;
		s2 = str2;
		while ( *s1 && *s2 && (*s1==*s2 || lt[(unsigned char)(*s1)]==lt[(unsigned char)(*s2)]) )
			s1++, s2++;
		if (!*s2)
			return cp - str1;
		
		if (*cp < 0)
		{
			cp++;
			if (!*cp)
				return -1;
		}
		cp++;
	}
	return -1;
}

INT __fastcall mystrstr(char* str1, char* str2)
{
	register char *cp = str1;
	register char *s1, *s2;
	while (*cp)
	{
		s1 = cp;
		s2 = str2;
		while ( *s1 && *s2 && !(*s1-*s2) )
			s1++, s2++;
		if (!*s2)
			return cp - str1;
		
		if (*cp < 0)
		{
			cp++;
			if (!*cp)
				return -1;
		}
		cp++;
	}
	return -1;
}

void PreBmBc(unsigned char *pattern, int m, int bmBc[])
{
    int i;
	
    for(i = 0; i < 256; i++)
        bmBc[i] = m;
	
    for(i = 0; i < m - 1; i++)
        bmBc[pattern[i]] = m - 1 - i;
}

void suffix(unsigned char *pattern, int m, int suff[]) {
	int f, g, i;
	
	suff[m - 1] = m;
	g = m - 1;
	for (i = m - 2; i >= 0; --i) {
		if (i > g && suff[i + m - 1 - f] < i - g)
			suff[i] = suff[i + m - 1 - f];
		else {
			if (i < g)
				g = i;
			f = i;
			while (g >= 0 && pattern[g] == pattern[g + m - 1 - f])
				--g;
			suff[i] = f - g;
		}
	}
}

void PreBmGs(unsigned char *pattern, int m, int bmGs[])
{
    int i, j;
    int suff[256];  
	
    // 计算后缀数组
    suffix(pattern, m, suff);
	
    // 先全部赋值为m，包含Case3
    for(i = 0; i < m; i++)
        bmGs[i] = m;
	
    // Case2
    j = 0;
    for(i = m - 1; i >= 0; i--)
        if(suff[i] == i + 1)
            for(; j < m - 1 - i; j++)
                if(bmGs[j] == m)
                    bmGs[j] = m - 1 - i;
				
	// Case1
	for(i = 0; i <= m - 2; i++)
		bmGs[m - 1 - suff[i]] = m - 1 - i;
}

int BoyerMoore(unsigned char *text, int n, unsigned char *pattern, int m)
{
    int i, j, bmBc[256], bmGs[256];
	
    // Preprocessing
    PreBmBc(pattern, m, bmBc);
    PreBmGs(pattern, m, bmGs);
	
    // Searching
    j = 0;
    while(j <= n - m)
    {
        for(i = m - 1; i >= 0 && pattern[i] == text[i + j]; i--);
        if(i < 0)
        {
			return j;
// 			j += bmGs[0];
// 			return;
        }
        else
            j += MAX(bmBc[text[i + j]] - m + 1 + i, bmGs[i]);
    }
	return -1;
}

void swap_hex(unsigned char* str, int len)
{
	for (int i=0; i<len/2; i+= sizeof(WORD))
	{
		WORD temp = *(WORD*)(str+len-i-sizeof(WORD));
		*(WORD*)(str + len - i - sizeof(WORD)) = *(WORD*)(str + i);
		*(WORD*)(str+i) = temp;
	}
}

void E_RC4_init(unsigned char* keytable, unsigned char* key, int keylen)
{
	int i = 0, j = 0;
	unsigned char k[256] = { 0 };
	unsigned char tmp = 0;
	for (i = 0; i < 256; i++) {
		keytable[i] = i;
		k[i] = key[i % keylen];
	}
	for (i = 0; i < 256; i++) {
		tmp = keytable[i];
		j = (j + tmp + k[i]) % 256;
		keytable[i] = keytable[j];//交换s[i]和s[j]
		keytable[j] = tmp;
	}
	keytable[256] = 0;
	keytable[257] = 0;
}

void E_RC4_updatetable(int len, unsigned char* keytable)
{
	int i;
	unsigned char tmp;
	unsigned char x = keytable[256];
	unsigned char y = keytable[257];
	for (i = 0; i < len; i++)
	{
		x = (x + 1);
		tmp = keytable[x];
		y = (y + tmp);
		keytable[x] = keytable[y];//交换s[x]和s[y]
		keytable[y] = tmp;
	}
	keytable[256] = x;
	keytable[257] = y;
}

void E_RC4(unsigned char* data, int datalen, unsigned char* keytable)
{
	int i;
	unsigned char tmp;
	unsigned char x = keytable[256];
	unsigned char y = keytable[257];
	for (i = 0; i < datalen; i++)
	{
		x = (x + 1);
		tmp = keytable[x];
		y = (y + tmp);
		keytable[x] = keytable[y];//交换s[x]和s[y]
		keytable[y] = tmp;
		data[i] ^= keytable[(unsigned char)(keytable[x] + tmp)];
	}
	keytable[256] = x;
	keytable[257] = y;
}

#define ERC4_TLEN 258
#define ERC4_CHUNK 4096
BOOL E_RC4_Calc(int pos, unsigned char *pData,int nDlen, unsigned char *pKeytable, int nCryptStart, unsigned char *pMD5)
{
	int nCTLen, nCTRemain;
	int nTableLen, nTableIndex;
	int nChunk, nOChunk;
	int nF,nB;
	unsigned char pTableTMP[ERC4_TLEN];
	unsigned char *pTableData, *pTableData2;
	unsigned char pNewPass[40]; // 4 + 32 + 4

	memcpy(pTableTMP, pKeytable, ERC4_TLEN);

	nCTLen = nCryptStart;
	nCTRemain = nCTLen - pos;
	if (nCTRemain > 0)
	{
		pData += nCTRemain;
		nDlen -= nCTRemain;
		if (nDlen <= 0)
			return FALSE;
		pos = nCTLen;
	}

	E_RC4_updatetable(4*(pos/ERC4_CHUNK), pTableTMP);
	nTableLen = 4*(nDlen/ERC4_CHUNK) + 8;
	if (nTableLen % 4 > 0)
		nTableLen = nTableLen + nTableLen % 4;

	pTableData = new unsigned char[nTableLen];
	memset(pTableData, 0, nTableLen);
	pTableData2 = pTableData;
	E_RC4(pTableData, nTableLen, pTableTMP);

	nTableIndex = pos/ERC4_CHUNK;
	nChunk = pos%ERC4_CHUNK;
	if (nChunk >= 0)
	{
		nF = *((int*)pTableData);
		nB = nTableIndex ^ nF;

		*((int*)pNewPass) = nF;
		memcpy(pNewPass + 4, pMD5, 32);
		*((int*)(pNewPass+36)) = nB;

		nTableIndex++;
		pTableData += 4;

		E_RC4_init(pTableTMP, pNewPass, 40);
		E_RC4_updatetable(nChunk + 36, pTableTMP);

		nOChunk = min(ERC4_CHUNK - nChunk, nDlen);
		E_RC4(pData, nOChunk, pTableTMP);

		nDlen -= nOChunk;
		pData += nOChunk;
	}

	while (nDlen > 0)
	{
		nF = *((int*)pTableData);
		nB = nTableIndex ^ nF;
		
		*((int*)pNewPass) = nF;
		memcpy(pNewPass + 4, pMD5, 32);
		*((int*)(pNewPass+36)) = nB;
		
		nTableIndex++;
		pTableData += 4;
		
		E_RC4_init(pTableTMP, pNewPass, 40);
		E_RC4_updatetable(nChunk + 36, pTableTMP);

		if (nDlen <= ERC4_CHUNK)
		{
			E_RC4(pData, nDlen, pTableTMP);
			pData += nDlen;
			nDlen = 0;
			break;
		}
		E_RC4(pData, ERC4_CHUNK, pTableTMP);
		nDlen -= ERC4_CHUNK;
		pData += ERC4_CHUNK;
	}

	delete []pTableData2;
	return TRUE;
}