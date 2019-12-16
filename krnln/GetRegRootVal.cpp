#include "stdafx.h"
// 1、#根类； 2、#现行设置； 3、#现行用户； 4、#本地机器； 5、#所有用户。
HKEY GetRegRootVal(INT nVal)
{
	HKEY hkey = NULL;
	switch(nVal)
	{
	case 1:
		hkey = HKEY_CLASSES_ROOT;
		break;
	case 2:
		hkey = HKEY_CURRENT_CONFIG;
		break;
	case 3:
		hkey = HKEY_CURRENT_USER;
		break;
	case 4:
		hkey = HKEY_LOCAL_MACHINE;
		break;
	case 5:
		hkey = HKEY_USERS;
		break;
	}
	return hkey;
}