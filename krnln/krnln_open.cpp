#include "stdafx.h"

//文件读写 - 打开文件
/*
    调用格式： 〈整数型〉 打开文件 （文本型 欲打开的文件名称，［整数型 打开方式］，［整数型 共享方式］） - 系统核心支持库->文件读写
    英文名称：open
    打开一个普通文件，以对文件进行输入或输出。成功返回被打开文件的文件号，失败返回 0。本命令为初级命令。
    参数<1>的名称为“欲打开的文件名称”，类型为“文本型（text）”。
    参数<2>的名称为“打开方式”，类型为“整数型（int）”，可以被省略。参数值说明对文件的操作方式，如果省略本参数，默认为“#读写”。方式值可以为以下常量之一：
  1、#读入：从指定文件读入数据，如果该文件不存在则失败；
  2、#写出：写出数据到指定文件，如果该文件不存在则失败；
  3、#读写：从文件中读入数据或者写出数据到文件，如果该文件不存在则失败；
  4、#重写：写出数据到指定文件。如果该文件不存在则先创建一个新文件，如果已经存在就先清除其中的所有数据；
  5、#改写：写出数据到指定文件。如果该文件不存在则创建一个新文件，如果已经存在就直接打开；
  6、#改读：从文件中读入数据或者写出数据到文件。如果该文件不存在则创建一个新文件，如果已经存在就直接打开。
    参数<3>的名称为“共享方式”，类型为“整数型（int）”，可以被省略。参数值指定限制其它进程操作此文件的方式。如果省略本参数，默认为“#无限制”。方式值可以为以下常量之一：
  1、#无限制：允许其它进程任意读写此文件；
  2、#禁止读：禁止其它进程读此文件；
  3、#禁止写：禁止其它进程写此文件；
  4、#禁止读写：禁止其它进程读写此文件。
*/
LIBAPI(void*, krnln_open)
{
	PMDATA_INF pArgInf = &ArgInf;
	DWORD dwDesiredAccess,dwShareMode,dwCreationDisposition;

	if(pArgInf[1].m_dtDataType == _SDT_NULL)
	{//#读写
		dwDesiredAccess = GENERIC_READ | GENERIC_WRITE;
		dwCreationDisposition = OPEN_EXISTING;
	}
	else
	{
		switch (pArgInf[1].m_int)
		{
		case 1://#读入
			dwDesiredAccess = GENERIC_READ;
			dwCreationDisposition = OPEN_EXISTING;
			break;
		case 2://#写出
			dwDesiredAccess = GENERIC_WRITE;
			dwCreationDisposition = OPEN_EXISTING;
			break;
		case 4://#重写
			dwDesiredAccess = GENERIC_WRITE;
			dwCreationDisposition = CREATE_ALWAYS;
			break;
		case 5://#改写
			dwDesiredAccess = GENERIC_WRITE;
			dwCreationDisposition = OPEN_ALWAYS;
			break;
		case 6://#改读
			dwDesiredAccess = GENERIC_READ | GENERIC_WRITE;
			dwCreationDisposition = OPEN_ALWAYS;
			break;
		default://#读写
			dwDesiredAccess = GENERIC_READ | GENERIC_WRITE;
			dwCreationDisposition = OPEN_EXISTING;
			break;
		}
	}

	if(pArgInf[2].m_dtDataType == _SDT_NULL)
		dwShareMode = (FILE_SHARE_READ | FILE_SHARE_WRITE );
	else
	{
		if(pArgInf[2].m_int ==2)
			dwShareMode = FILE_SHARE_WRITE ;
		else if(pArgInf[2].m_int ==3)
			dwShareMode = FILE_SHARE_READ ;
		else if(pArgInf[2].m_int ==4)
			dwShareMode = 0;
		else
			dwShareMode = (FILE_SHARE_READ | FILE_SHARE_WRITE );
	}

	HANDLE hFile = CreateFile(ArgInf.m_pText,
		dwDesiredAccess,
		dwShareMode,
		NULL,
		dwCreationDisposition,
		FILE_ATTRIBUTE_ARCHIVE,
		0);
	

	if(hFile != INVALID_HANDLE_VALUE)
	{
		PFILEELEMENT pFile = new FILEELEMENT;
		pFile->nType = 1;
		pFile->FileHandle = hFile;
		AddFileMangerList(pFile);
		return pFile;
	}
	return NULL;
}

