#include "stdafx.h"
#include "Myfunctions.h"

//文本操作 - 到全角
/*
	调用格式： 〈文本型〉 到全角 （文本型 欲变换的文本） - 系统核心支持库->文本操作
	英文名称：QJCase
	将文本中的半角字母、空格或数字变换为全角，返回变换后的结果文本。本命令为初级命令。
	参数<1>的名称为“欲变换的文本”，类型为“文本型（text）”。

' 数字范围163开头，176--185
' 大写字母，163开头，193--218
' 小写字母，163开头，225--250
' ///////////以上为全角的，下面是半角的
' 数字范围，48--57
' 大写字母，65--90
' 小写字母，97-122
到字节集 (“．－”)  ' 163,174,163,173
*/
char* towf(char* s) {
	char* rs = NULL;
	char* ret = NULL;
	if (s && mystrlen(s)) {
		size_t lenth = mystrlen(s) * 2;//最大不会超过
		char* ws = new char[lenth + 1];
		rs = ws;
		memset(ws, 0, lenth + 1);
		for (size_t i = 0; i < mystrlen(s); i++)
		{
			if (s[i] == '~') {

				memcpy(ws, "～", 2);

				ws++;
			}
			else if (s[i] == ' ') {

				memcpy(ws, "　", 2);
				ws++;
			}

			else if (s[i] <= 0x20 || s[i] >= 0x7F) {

				if (s[i] & 0x80) { // 中文字符
					if (!s[i + 1]) { // 结束符截断
						*ws = '\0';
						return rs;
					}
					*ws = s[i];
					i++;
					ws++;
					*ws = s[i];
				}
				else { // 常规字符
					*ws = s[i];
				}
			}
			else {

				*ws = (char)163; // 中文两个字符中的高位
				ws++;
				*ws = s[i] | (char)0x80; // 低位
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

