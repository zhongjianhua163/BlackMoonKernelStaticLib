#include "stdafx.h"
#include "Myfunctions.h"

//�ı����� - ��ȫ��
/*
	���ø�ʽ�� ���ı��͡� ��ȫ�� ���ı��� ���任���ı��� - ϵͳ����֧�ֿ�->�ı�����
	Ӣ�����ƣ�QJCase
	���ı��еİ����ĸ���ո�����ֱ任Ϊȫ�ǣ����ر任��Ľ���ı���������Ϊ�������
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
char* towf(char* s) {
	char* rs = NULL;
	char* ret = NULL;
	if (s && mystrlen(s)) {
		size_t lenth = mystrlen(s) * 2;//��󲻻ᳬ��
		char* ws = new char[lenth + 1];
		rs = ws;
		memset(ws, 0, lenth + 1);
		for (size_t i = 0; i < mystrlen(s); i++)
		{
			if (s[i] == '~') {

				memcpy(ws, "��", 2);

				ws++;
			}
			else if (s[i] == ' ') {

				memcpy(ws, "��", 2);
				ws++;
			}

			else if (s[i] <= 0x20 || s[i] >= 0x7F) {

				if (s[i] & 0x80) { // �����ַ�
					if (!s[i + 1]) { // �������ض�
						*ws = '\0';
						return rs;
					}
					*ws = s[i];
					i++;
					ws++;
					*ws = s[i];
				}
				else { // �����ַ�
					*ws = s[i];
				}
			}
			else {

				*ws = (char)163; // ���������ַ��еĸ�λ
				ws++;
				*ws = s[i] | (char)0x80; // ��λ
			}
			ws++;

		}
		ret = (char*)E_MAlloc(mystrlen(rs) + 1);
		memset(ret, 0, mystrlen(rs) + 1);
		strcpy(ret, rs);
		delete[]rs;

	}
	return ret;
}
LIBAPI(char*, krnln_QJCase)
{
	size_t nLen = mystrlen(ArgInf.m_pText);
	if (nLen == 0) return NULL;
	return towf(ArgInf.m_pText);
}

