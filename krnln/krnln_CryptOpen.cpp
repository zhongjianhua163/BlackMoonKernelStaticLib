#include "stdafx.h"
#include "md5t.h"
#include "Myfunctions.h"

// 调用格式： 〈整数型〉 打开加密文件 （文本型 欲打开的文件名称，［整数型 打开方式］，［整数型 共享方式］，［文本型 文件密码］，［整数型 明文区长度］） - 系统核心支持库->文件读写
// 英文名称：CryptOpen
// 打开一个以指定密码加密的文件，以对此文件进行快速安全访问，支持大尺寸文件。成功返回被打开文件的文件号，失败返回 0。本命令为初级命令。
// 参数<1>的名称为“欲打开的文件名称”，类型为“文本型（text）”。
// 参数<2>的名称为“打开方式”，类型为“整数型（int）”，可以被省略。参数值说明对文件的操作方式，如果省略本参数，默认为“#读写”。方式值可以为以下常量之一：
// 1、#读入：从指定文件读入数据，如果该文件不存在则失败；
// 2、#写出：写出数据到指定文件，如果该文件不存在则失败；
// 3、#读写：从文件中读入数据或者写出数据到文件，如果该文件不存在则失败；
// 4、#重写：写出数据到指定文件。如果该文件不存在则先创建一个新文件，如果已经存在就先清除其中的所有数据；
// 5、#改写：写出数据到指定文件。如果该文件不存在则创建一个新文件，如果已经存在就直接打开；
// 6、#改读：从文件中读入数据或者写出数据到文件。如果该文件不存在则创建一个新文件，如果已经存在就直接打开。
// 参数<3>的名称为“共享方式”，类型为“整数型（int）”，可以被省略。参数值指定限制其它进程操作此文件的方式。如果省略本参数，默认为“#无限制”。方式值可以为以下常量之一：
// 1、#无限制：允许其它进程任意读写此文件；
// 2、#禁止读：禁止其它进程读此文件；
// 3、#禁止写：禁止其它进程写此文件；
// 4、#禁止读写：禁止其它进程读写此文件。
// 参数<4>的名称为“文件密码”，类型为“文本型（text）”，可以被省略。如果即将打开的文件中不存在任何数据（即为空文件或将创建的新文件），本参数指定保护该文件时所将使用的密码，以后所有写入该文件中的数据都将使用此密码加密后写入。建议密码长度最少为6个字符以上，并且最好混合使用汉字、字母、数字、符号，以保证密码本身的安全性。如果即将打开的文件中已经存在数据，本参数提供访问此已有数据时所需要的正确密码，如果此数据没有加密，请提供空文本以表示不需要密码。注意系统不会去校验密码的正确性，如果提供错误的密码，读写已有文件数据将得到错误的结果，请千万注意。因此如果需要校验密码是否正确，请在加密后的文件中保存正确的密码文本或密码文本的数据摘要信息（见数据操作支持库一中的“取数据摘要”命令），然后在打开加密文件后读出该信息对密码进行验证。系统所使用的加密算法是国际标准的RC4算法，可以保证数据的安全性。如果本参数被省略，则默认为空文本，即无密码。
// 参数<5>的名称为“明文区长度”，类型为“整数型（int）”，可以被省略。本参数指定从文件首部开始不希望被加密部分的长度，系统在读写此区域内的数据时，不会使用密码对其进行加解密操作。此参数用作将加密文件分为明文区和密文区两部分，以方便某些应用程序同时保存一些明文数据。注意当打开已有加密数据的文件时，此参数值必须与新建此加密文件时所提供的参数值一致，否则会造成数据访问错误。如果本参数被省略，则默认值为0，即没有明文区。
// 
// 操作系统需求： Windows
LIBAPI(void*, krnln_CryptOpen) // 未完成 
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
		if (pArgInf[3].m_dtDataType == _SDT_NULL || !pArgInf[3].m_pText || !*(pArgInf[3].m_pText))
			pFile->nType = 1; // 普通无密码文件
		else
		{
			int nKeylen = mystrlen(pArgInf[3].m_pText);
			pFile->nType = 3; // 有密码文件

			GetBufMD5(pFile->strMD5, (unsigned char*)pArgInf[3].m_pText, nKeylen);
			swap_hex(pFile->strMD5, 32); //反转MD5

			memset(pFile->strTable,0,258);
			E_RC4_init(pFile->strTable, (unsigned char*)pArgInf[3].m_pText, nKeylen);

			//明文区长度
			if(pArgInf[4].m_dtDataType == _SDT_NULL)
				pFile->nCryptStart = 0;
			else
				pFile->nCryptStart = pArgInf[4].m_int;
		}

		pFile->FileHandle = hFile;
		AddFileMangerList(pFile);
		return pFile;
	}
	return NULL;
}

