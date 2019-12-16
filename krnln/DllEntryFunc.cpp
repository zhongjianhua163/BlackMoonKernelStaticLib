#include "stdafx.h"


extern "C" PDESTROY ECodeStart();
PDESTROY DllEntryFunc(){
	DWORD dwReturn;//保护主要寄存器，不然返回时出错
	__asm{
        push esi
        push edi
        push ebx
        call ECodeStart
        pop ebx
        pop edi
        pop esi
		mov dwReturn,eax
 	}
	return (PDESTROY)dwReturn;

}


