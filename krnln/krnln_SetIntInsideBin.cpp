#include "stdafx.h"

// 调用格式： 〈无返回值〉 置字节集内整数 （字节集 待处理的字节集，整数型 欲设置整数所处偏移，整数型 欲设置的整数值，［逻辑型 是否反转字节序］） - 系统核心支持库->字节集操作
// 英文名称：SetIntInsideBin
// 设置字节集中所指定位置处的整数值。本命令为初级命令。
// 参数<1>的名称为“待处理的字节集”，类型为“字节集（bin）”。提供待处理的字节集。
// 参数<2>的名称为“欲设置整数所处偏移”，类型为“整数型（int）”。提供所欲设置的整数值在字节集中的偏移位置。
// 参数<3>的名称为“欲设置的整数值”，类型为“整数型（int）”。提供所欲设置的具体整数值。
// 参数<4>的名称为“是否反转字节序”，类型为“逻辑型（bool）”，可以被省略。指定是否将所设置整数的字节序进行反转,譬如十六进制整数0x12345678,反转后将为0x78563412. 本功能在与类似Java这样的语言进行数据交互时很有用处. 如果参数被省略，默认值为假.
// 
// 操作系统需求： Windows、Linux
LIBAPI(void, krnln_SetIntInsideBin)
{
	PMDATA_INF pArgInf = &ArgInf;

	LPBYTE pSrc = pArgInf[0].m_pBin;
	if (!pSrc) return;

	int nLen = pArgInf[0].m_pInt[1];
	int off = pArgInf[1].m_int;
	if (nLen - off < 4) return;

	int nValue = pArgInf[2].m_int;
	if (pArgInf[3].m_dtDataType != _SDT_NULL && pArgInf[3].m_bool)
	{
		int nTmp = nValue;
		nValue = nTmp >> 24;
		nValue |= ((nTmp & 0x00FF0000) >> 8);
		nValue |= ((nTmp & 0x0000FF00) << 8);
		nValue |= ((nTmp & 0x000000FF) << 24);
	}
	*(LPINT)(pSrc + off + 2*sizeof(int)) = nValue;
}
