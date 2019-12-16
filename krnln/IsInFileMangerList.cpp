#include "stdafx.h"

extern PFILEELEMENT pFileList;

BOOL IsInFileMangerList(PFILEELEMENT pFile)
{
	PFILEELEMENT pObjFile = pFileList;

	while(pObjFile)
	{
		if(pObjFile == pFile)
			return TRUE;
		pObjFile = (PFILEELEMENT)pObjFile->pLast;
	}
	return FALSE;
}