#include "stdafx.h"
#include "Myfunctions.h"

void LTrimZeroChr(char* str)
{
	int nLen = mystrlen(str);
	char * pend = str + nLen;
	do
	{

		pend--;

		if(*pend =='.')
		{
			
			*pend = 0;
			break;
		} else if(*pend !='0')
		{
			pend++;
			*pend = 0;
			break;
		}

	}while(* pend =='0' && pend > str);

}