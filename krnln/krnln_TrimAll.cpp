#include "stdafx.h"
#include "Myfunctions.h"
//文本操作 - 删全部空
/*
    调用格式： 〈文本型〉 删全部空 （文本型 欲删除空格的文本） - 系统核心支持库->文本操作
    英文名称：TrimAll
    返回一个文本，其中包含被删除了所有全角或半角空格的指定文本。本命令为初级命令。
    参数<1>的名称为“欲删除空格的文本”，类型为“文本型（text）”。
*/
LIBAPI(char*, krnln_TrimAll)
{// 被封七号 改
	PMDATA_INF pArgInf = &ArgInf;
	char* pSrc = pArgInf[0].m_pText;
	register char *str1 = pSrc;
	if (!*str1) return NULL;

	// 开始计算
	PTB pTb = initSubTb();
	if (!pTb)
		return NULL;

	char* pFirst = pSrc;
	while (1)
	{
		//首空
		while ( *str1 )
		{
			if (*str1 == ' ')
				str1++;
			else if (*((unsigned short*)str1) == 0xA1A1)
				str1+=2;
			else
				break;
		}
		if (!*str1) break;
		pFirst = str1;
		if (*str1 < 0) {
			str1+=2;
		} else {
			str1++;
		}
		//找尾
		while ( *str1 )
		{
			if (*str1 == ' ')
				break;
			else if (*((unsigned short*)str1) == 0xA1A1)
				break;
			if (*str1 < 0)
				str1+=2;
			else
				str1++;
		}
		if (str1 - pFirst > 0)
			recSub(&pTb, pFirst, str1 - pFirst);
	}

	char* pText = SubTbtoString(pTb);
	if (pTb)
		free(pTb);
	return pText;
}
