#include "stdafx.h"
#include "Myfunctions.h"


//�ı����� - �����
/*
	���ø�ʽ�� ���ı��͡� ����� ���ı��� ���任���ı��� - ϵͳ����֧�ֿ�->�ı�����
	Ӣ�����ƣ�BJCase
	���ı��е�ȫ����ĸ���ո�����ֱ任Ϊ��ǣ����ر任��Ľ���ı���������Ϊ�������
	����<1>������Ϊ�����任���ı���������Ϊ���ı��ͣ�text������

' ���ַ�Χ163��ͷ��176--185
' ��д��ĸ��163��ͷ��193--218
' Сд��ĸ��163��ͷ��225--250
' ///////////����Ϊȫ�ǵģ������ǰ�ǵ�
' ���ַ�Χ��48--57
' ��д��ĸ��65--90
' Сд��ĸ��97-122
���ֽڼ� (��������)  ' 163,174,163,173
*/
//string toh(const std::string& str) {
//	std::string result;
//	unsigned char fc;
//	unsigned char lc;
//	for (std::string::size_type i = 0; i < str.size(); i++) {
//		fc = str[i];
//		lc = str[i + 1];
//		if (fc == 163)
//		{
//			result += (unsigned char)str[i + 1] - 128;
//			i++;
//			continue;
//		}
//		else if (fc > 163)    //����
//		{
//			result += str.substr(i, 2);
//			i++;
//			continue;
//		}
//		else if (fc == 161 && lc == 161)    ///����ȫ�ǿո�
//		{
//			result += "";
//			i++;
//		}
//		else {
//			result += str.substr(i, 1);
//		}
//
//	}
//	return result;
//}
LIBAPI(char*, krnln_BJCase)
{
	PMDATA_INF pArgInf = &ArgInf;
	size_t nLen = mystrlen(ArgInf.m_pText);
	if (nLen == 0) return NULL;

	char* pszLast = ArgInf.m_pText + nLen;
	char* pszFirst = ArgInf.m_pText;
	char* pszSrc = (char*)malloc(nLen + 1);
	char* pszTmp = pszSrc;
	size_t sSublen;
	for (;;)
	{
		char* pPos = strstr(pszFirst, "��");
		if (!pPos) break;
		sSublen = pPos - pszFirst;
		if (sSublen > 0)
		{
			memcpy(pszTmp, pszFirst, sSublen);
		}
		pszTmp[sSublen] = '\\';
		pszTmp += sSublen + 1;
		pszFirst = pPos + 2;
	}
	sSublen = pszLast - pszFirst;
	if (sSublen > 0)
	{
		memcpy(pszTmp, pszFirst, sSublen);
		pszTmp += sSublen;
	}
	pszTmp[0] = '\0';

	nLen = mystrlen(pszSrc);
	INT nBufLen = nLen + 1;
	char* pBJText = (char*)E_MAlloc(nBufLen);
	LCMapString(2052, LCMAP_HALFWIDTH, pszSrc, nLen, pBJText, nBufLen);
	free(pszSrc);
	return pBJText;
}
