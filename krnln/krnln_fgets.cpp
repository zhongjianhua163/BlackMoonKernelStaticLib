#include "stdafx.h"
#include <conio.h>
//����̨���� - ��׼����
/*
	���ø�ʽ�� ���ı��͡� ��׼���� �����߼��� �Ƿ���ԣݣ� - ϵͳ����֧�ֿ�->����̨����
	Ӣ�����ƣ�fgets
	�ڱ�׼�����豸����������������2048���ַ���һ���ı��������û�����������ݡ�ע�Ȿ����ֻ���ڿ���̨������ʹ�á�������Ϊ�������
	����<1>������Ϊ���Ƿ���ԡ�������Ϊ���߼��ͣ�bool���������Ա�ʡ�ԡ���������������ʱ�Ƿ���ʾ�������ַ���Ϊ�ٲ���ʾ��Ϊ����ʾ�������ʡ�ԣ�Ĭ��ֵΪ�棬�����ԡ�����ͨ��������������Ϊ�������������������Ϣ��
*/
LIBAPI(char*, krnln_fgets)
{
	char Buff[4096]; //��Ȼ˵����Ϊ2048����ʵ��Ϊ4096
	if (ArgInf.m_dtDataType == _SDT_NULL || ArgInf.m_bool)
	{
		HANDLE hCon = GetStdHandle(STD_INPUT_HANDLE);
		if (hCon == NULL)
			return NULL;

		DWORD dwSize;
		LPSTR pText = NULL;
		if (ReadConsole(hCon, Buff, sizeof(Buff), &dwSize, NULL))
		//if(ReadFile(hCon,Buff,sizeof(Buff),&dwSize,NULL))
		{
			DWORD i;
			for (i = 0; i < dwSize; i++)
			{
				if (Buff[i] == 0)
					break;
				else if (Buff[i] == '\r')
				{
					Buff[i] = 0;
					break;
				}
				else if (Buff[i] == '\n')
				{
					Buff[i] = 0;
					break;
				}
			}
			if (i == 0 && dwSize > 1)
			{
				Buff[0] = '\n';
				Buff[1] = 0;
			}
			pText = CloneTextData(Buff, dwSize);
		}
		return pText;
	}
	else {
		INT nIdx = 0;
		do
		{
#if _MSC_VER > 1200
			INT nChr = _getch();
#else
			INT nChr = getch();
#endif
			if (nChr == 13)
			{
				Buff[nIdx] = 0;
				break;
			}
			Buff[nIdx] = (char)nChr;
			++nIdx;
		} while (nIdx < sizeof(Buff));
		return CloneTextData(Buff, nIdx);
	}
}
