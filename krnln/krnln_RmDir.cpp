#include "stdafx.h"
#include "Myfunctions.h"

BOOL BlackMoonDeleteDir(LPSTR strDirName)
{
	
	char szName [MAX_PATH];
	char szFile [MAX_PATH];
	strcpy(szName,strDirName);
	INT nLen = mystrlen(szName);
	if(szName[nLen-1] != '\\')
		strcat(szName,"\\");

	strcpy(szFile,szName);//以\为结尾的当前操作目录
	strcat(szName,"*");//通配符目录

	WIN32_FIND_DATA FindFileData;
	HANDLE hFile = FindFirstFile(szName,&FindFileData);
	if(hFile==NULL || hFile == INVALID_HANDLE_VALUE) 
		return FALSE;
	BOOL bOK = TRUE;
	do{
		if(strcmp(FindFileData.cFileName,".")!=0 &&
			strcmp(FindFileData.cFileName,"..")!=0)
		{

			strcpy(szName,szFile);
			strcat(szName,FindFileData.cFileName);//产生操作目标文件或目录名
			if ((FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY)//为目录
			{
				bOK = BlackMoonDeleteDir(szName);//递归循环
				if(bOK)
					bOK = RemoveDirectory(szName);//删除空目录
				
			}else
				bOK = DeleteFile(szName);//删除文件
		}
		if(bOK == FALSE)
			break;
	}while(FindNextFile(hFile,&FindFileData));

	FindClose(hFile); //关闭句柄 
	return bOK;

}

//磁盘操作 - 删除目录
/*
    调用格式： 〈逻辑型〉 删除目录 （文本型 欲删除的目录名称） - 系统核心支持库->磁盘操作
    英文名称：RmDir
    删除一个存在的目录及其中的所有子目录和下属文件，请务必谨慎使用本命令。成功返回真，失败返回假。本命令为初级命令。
    参数<1>的名称为“欲删除的目录名称”，类型为“文本型（text）”。该目录应实际存在，如果目录中存在文件或子目录，将被一并删除，因此使用本命令请千万慎重。
*/
LIBAPI(BOOL, krnln_RmDir)
{
	if(ArgInf.m_pText == NULL)
		return FALSE;
	int nLen = mystrlen(ArgInf.m_pText);
	if(nLen==0)//防止删除当前目录的根目录"\*"
		return FALSE;
	if(nLen ==1 && ArgInf.m_pText[0]=='\\')//防止删除当前目录的根目录"\*"
		return FALSE;
	BOOL bOK = BlackMoonDeleteDir(ArgInf.m_pText);
	if(bOK)
		bOK = RemoveDirectory(ArgInf.m_pText);//删除空目录
	return bOK;
}
