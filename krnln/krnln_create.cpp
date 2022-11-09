#include "stdafx.h"
#include"shlwapi.h"
#pragma comment(lib,"shlwapi.lib") 
#pragma pack(1)
#if (_MSC_VER <= 1600)
WINOLEAUTAPI VarDateFromUdateEx( UDATE* pudateIn,  LCID lcid,  ULONG dwFlags, DATE* pdateOut);
#endif
/*创建暴漏接口*/
struct ColumnInfo//字段信息
{
    const char* Name;
    int Type;
    int StrDataLenth ;
};
typedef ColumnInfo* lpColumInfo;
int  CreateEdb(const char* Filename, ColumnInfo* ColumnArry, int ColumnNum);
BOOL IsValidName(const char* text);
char* refilename(const char* Filename, const char* extensionname);

//struct EDTDATA//EDT创建数据
//{
//    const BYTE Typename[4] = { 87,69,68,84 };//标识符WEDB，BYTE[4]和整数都可以，尽量不要用文本型，因为是指针;
//    const BYTE delimiter1[4] = { 0,0,1,0 };//分隔符0010 65536 也可以两个short，看你怎么写了;
//    double  check = 0;//COleDateTime::GetTickCount()，每次打开会刷新，兼容原版EDB;;
//    const  BYTE delimiter2[4] = { 1,0,0,0 };//分隔符0000 0;//分隔符1000 1;
//    BYTE data[492] = {};
//};
struct EDTDATA//EDT创建数据
{
    EDTDATA() {
        
        BYTE TypenameInit[4] = { 87,69,68,84 };//标识符WEDB，BYTE[4]和整数都可以，尽量不要用文本型，因为是指针;
        memcpy(Typename, TypenameInit, 4);
        BYTE delimiter1Init[4]= { 0,0,1,0 };//分隔符0010 65536 也可以两个short，看你怎么写了;
        memcpy(delimiter1, delimiter1Init, 4);
        double  check=0;//COleDateTime::GetTickCount()，每次打开会刷新，兼容原版EDB;;
        BYTE delimiter2Init[4]= { 1,0,0,0 };//分隔符0000 0;//分隔符1000 1;
        memcpy(delimiter2, delimiter2Init, 4);
        memset(data, 0, 492);
    }
    BYTE Typename[4];//标识符WEDB，BYTE[4]和整数都可以，尽量不要用文本型，因为是指针;
    BYTE delimiter1[4];//分隔符0010 65536 也可以两个short，看你怎么写了;
    double  check;//COleDateTime::GetTickCount()，每次打开会刷新，兼容原版EDB;;
    BYTE delimiter2[4];//分隔符0000 0;//分隔符1000 1;
    BYTE data[492];
};
struct EDBDATA//EDB创建数据
{
    EDBDATA() {
        const BYTE TypenameInit[4] = { 87,69,68,66 };//标识符WEDB，BYTE[4]和整数都可以，尽量不要用文本型，因为是指针;
        memcpy(Typename, TypenameInit, 4);
        const BYTE delimiter1Init[4] = { 0,0,1,0 };//分隔符0010 65536 也可以两个short，看你怎么写了;
        memcpy(delimiter1, delimiter1Init, 4);
        check = 0;//COleDateTime::GetTickCount()，每次打开会刷新，兼容原版EDB;;
        const  BYTE delimiter2Init[8] = { 0,0,0,0,1,0,0,0 };//分隔符0000 0;//分隔符1000 1;
        memcpy(delimiter2, delimiter2Init, 4);
        TotalLength = 0;//有效字段StorageLength4+各类型长度*数组数量 长度4;;
        memset(blankBYTE, 0, 84);
        ValidColumnNum = 0;//第112位后储存的int是有效字段数量;
    }
    BYTE Typename[4] ;//标识符WEDB，BYTE[4]和整数都可以，尽量不要用文本型，因为是指针;
    BYTE delimiter1[4];//分隔符0010 65536 也可以两个short，看你怎么写了;
    double  check;//COleDateTime::GetTickCount()，每次打开会刷新，兼容原版EDB;;
    BYTE delimiter2[8];//分隔符0000 0;//分隔符1000 1;
    int  TotalLength ;//有效字段StorageLength4+各类型长度*数组数量 长度4;;
    BYTE  blankBYTE[84];//目前未知84个空白长度，应该是留给索引表的;
    int ValidColumnNum;//第112位后储存的int是有效字段数量;
};
struct COLIMNDATA//单次字段信息创建
{
    COLIMNDATA() {
        memset(this, 0, sizeof(COLIMNDATA));
        DataLenth = 20;
    }
    char ColumnName[16];//名称最大16,边界对齐
    BYTE delimiter[4];//分隔符
    int ColumnType;
    int DataLenth;//需求数据长度;
    int strlenth;//如为文本类型则需要长度;
    BYTE Table[40];
};

double  GetCOLeDateTime()//‘为了向下兼容原版EDB,验校时间，为了绑定EDT
{

    SYSTEMTIME time;
    GetLocalTime(&time);
    double pdateOut;
    UDATE pudateIn;
    pudateIn.st.wDayOfWeek = time.wDayOfWeek;
    pudateIn.st.wYear = time.wYear;
    pudateIn.st.wHour = time.wHour;
    pudateIn.st.wMinute = time.wMinute;
    pudateIn.st.wDay = time.wDay;
    pudateIn.st.wMonth = time.wMonth;
    pudateIn.st.wSecond = time.wSecond;
    VarDateFromUdateEx(&pudateIn, 0x409u, 0x80000000, &pdateOut);
    return pdateOut;
}//
int  CreateEdb(const char* Filename, ColumnInfo* ColumnArry,  int ColumnNum) {

    BYTE* Data = NULL;
    // int DataLenth = 0;
    int Index;//判断字段重复计数
    int i;//全局计次
    int ValidColumnNum = 0;//有效字段数量
    int StorageLength;//存储长度;
    int  NowColumnType = 0;//当前字段类型
    bool HaveByteorRemark = false;//是否有字节型或备注;
    /*长度*/
    int  TotalLength = 4;//单次空记录所有字段数据所需求长度;
    int DataLenth = 4;//初始字段类型需求数据长度
    int strlenth = 0;//文本型数据长度
    int Nowstrlenth = 0;//本次文本型数据长度
    const char* NowColumnName = NULL;//当前字段名称;
    EDBDATA EdbData;//结构体;
    double checktime = 0;//文件验校;
    HANDLE hFile = NULL;
    HANDLE hDataFile = NULL;

    //BYTE ColumnNameByte[16] = {  };//长度最大且固定为16;
    //BYTE NowData[72];
    //lpReOpenBuff;//原版使用;






    if (!Filename) {
        return -3;
    }
    if (ColumnNum <= 0) {
        return -16;
    }
    for (i = 0; i < ColumnNum; i++) {
        //cout << ColumnArry[i].Name;
        if (!ColumnArry[i].Name)// 扫到空字段名即停，以后的字段不会再扫描{
        {
            ColumnNum = ValidColumnNum;
            if (ValidColumnNum <= 0) {
                return -16;
            }
        }
        else {
            if (!IsValidName(ColumnArry[i].Name) || strlen(ColumnArry[i].Name) > 16) {
                return -18;
            }
            NowColumnType = ColumnArry[i].Type;
            StorageLength = 4;
            if (NowColumnType > 12) { // 类型大于12
                return -17;
            }
            switch (NowColumnType)
            {
            case 1:
                StorageLength = 1;
                break;
            case 7:
                StorageLength = 1;
                break;
            case 2:
                StorageLength = 2;
                break;
            case 4:
                StorageLength = 8;
                break;
            case 6:
                StorageLength = 8;
                break;
            case 8:
                StorageLength = 8;
                break;
            case 10:
                StorageLength = 0;
                break;
            case 3:
                StorageLength = 2;
                break;
            case 5:
                StorageLength = 4;
                break;
            case 9:
                StorageLength = 4;
                break;
            case 11:
                StorageLength = 4;
                break;
            case 12:
                StorageLength = 4;
                break;
            default:
                return -17;//无效的字段类型
            }

            if (NowColumnType == 10) { // 如果类型为文本型
                StorageLength = ColumnArry[i].StrDataLenth;
                if (StorageLength < 1 || StorageLength>1024) {
                    return -19;
                }
            }
            if (HaveByteorRemark == false && (NowColumnType == 12 || NowColumnType == 11)) {
                HaveByteorRemark = true;
            }
            TotalLength = TotalLength + StorageLength; // 总长度，以后每拓展一个新空记录便为一个总长度;
            ValidColumnNum = ValidColumnNum + 1; // 全部完成以后有效字段自加1个，遇到无效字段截停;
        }
    }
    for (i = 0; i < ColumnNum; i++) {
        NowColumnName = ColumnArry[i].Name;
        if (ColumnNum > 0) {
            Index = 0;
            do {
                if (Index != i) {
                    if (NowColumnName == ColumnArry[Index].Name) {
                        return -20;
                    }
                }
                Index = Index + 1;
            } while (Index <= ColumnNum);
        }
    }
    ; // 此为古代版本，吴总应该是这么写的，易用起来没用问题，毕竟申请不了大于两G的内存;
    ; // hFile=OpenFile (refilename (Filename, ".edb"), lpReOpenBuff, 位或 (E常量_OF_SHARE_EXCLUSIVE, E常量_OF_CREATE, E常量_OF_WRITE));
    ; // 现代人请用→;
    ; // HANDLE hFile = CreateFileA(refilename(Filename, ".edb").c_str(), GENERIC_WRITE, 0, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, 0);;
    char* infilename = refilename(Filename, ".edb");
    hFile = CreateFileA(infilename, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, 0);//CREATE_ALWAYS是为了在"清空命令中使用文件覆盖快速完成清空"
    delete[]infilename;
    ; // 调试输出 (refilename (Filename, ".edb"));
    ; // (hFile == INVALID_HANDLE_VALUE);
    ; // (hFile == HFILE_ERROR);
    if (hFile == INVALID_HANDLE_VALUE) {
        CloseHandle(hFile);
        return -1;
    }
    ; // memset (取变量数据地址 (EdbData), 0, 160)  ; // EdbData={};

    EdbData.check = checktime;
    EdbData.ValidColumnNum = ValidColumnNum;
    EdbData.TotalLength = TotalLength;
    // 结构体，仅供参考，易里到此为止不再使用;
    checktime = GetCOLeDateTime(); // 验校时间，用于兼容和绑定EDT文件;
    // 以上两个是完全相同的，字节集会方便一点，C++里用结构体更方便;


    COLIMNDATA* AllColumnData = new COLIMNDATA[ColumnNum];

    for (i = 0; i < ColumnNum; i++) {
        //COLIMNDATA NowData;

        NowColumnType = ColumnArry[i].Type;
        memcpy(AllColumnData[i].ColumnName, ColumnArry[i].Name, strlen(ColumnArry[i].Name));
        AllColumnData[i].ColumnType = NowColumnType;
        if (NowColumnType == 10) { // 为文本则类型长度{
            strlenth = ColumnArry[i].StrDataLenth;
        }
        else {
            strlenth = 0;
        }
        if (NowColumnType == 10) {
            Nowstrlenth = ColumnArry[i].StrDataLenth;
        }
        else {
            if (13 > NowColumnType && NowColumnType > 0) {
                switch (NowColumnType)
                {
                case 1:
                    Nowstrlenth = 1;
                    break;
                case 7:
                    Nowstrlenth = 1;
                    break;
                case 2:
                    Nowstrlenth = 2;
                    break;
                case 4:
                    Nowstrlenth = 8;
                    break;
                case 6:
                    Nowstrlenth = 8;
                    break;
                case 8:
                    Nowstrlenth = 8;
                    break;
                case 10:
                    Nowstrlenth = 0;
                    break;
                case 3:
                    Nowstrlenth = 2;
                    break;
                case 5:
                    Nowstrlenth = 4;
                    break;
                case 9:
                    Nowstrlenth = 4;
                    break;
                case 11:
                    Nowstrlenth = 4;
                    break;
                case 12:
                    Nowstrlenth = 4;
                    break;
                default:
                    Nowstrlenth = -1;
                    break;
                }
            }
            else {
                Nowstrlenth = -1;
            }
        }
        AllColumnData[i].DataLenth = DataLenth;
        DataLenth = DataLenth + Nowstrlenth; // 此字段最大长度;
        AllColumnData[i].strlenth = strlenth; // 文本类型长度;
    }
    DataLenth = sizeof(EdbData) + sizeof(COLIMNDATA) * ColumnNum;
    Data = new BYTE[DataLenth];
    memcpy(Data, &EdbData, sizeof(EdbData));
    memcpy(Data + sizeof(EdbData), AllColumnData, sizeof(COLIMNDATA) * ColumnNum);
    WriteFile(hFile, Data, DataLenth, 0, 0);
    delete[]AllColumnData;
    delete[]Data;
    CloseHandle(hFile);
    if (HaveByteorRemark == true) { // 如果为字节集或备注型，则创建绑定EDT文件{
        char* inedtname = refilename(Filename, ".EDT");
        hDataFile = CreateFileA(inedtname, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, 0);
        delete[]inedtname;
        ; // hDataFile=OpenFile (refilename (Filename, ".edt"), lpReOpenBuff, 4113);
        if (hDataFile == INVALID_HANDLE_VALUE) {
            return -50;
        }
        EDTDATA EdTData;
        EdTData.check = checktime;
        if (WriteFile(hFile, &EdTData, sizeof(EDTDATA), 0, 0) == 0) {
            return -50;
        }
    }
    return 0;
}





char* refilename(const char* Filename, const char* extensionname) {
    char* NewPath=new char[MAX_PATH];
    char* suffix;
    strcpy(NewPath, Filename);
    suffix = PathFindExtensionA(extensionname);
    if (strlen(suffix) > 1)
    {
        if (PathRenameExtensionA(NewPath, suffix)) {
            return NewPath;
        };
        return NewPath;
    }
    return NewPath;
}
//是否为全角数字
bool Isfullwidthnum(const char str, const char str2);
//是否为全角字母
bool Isfullwidthletter(const char str, const char str2);
bool Isfullwidthnum(const char str, const char str2) {
    char str_[2] = { str2, str };
    short num = *(short*)((char*)str_);
    return num >= (short)0xA3C1u && num <= (short)0xA3DAu || num >= (short)0xA3E1u && num <= (short)0xA3FAu;;
};
bool Isfullwidthletter(const char str, const char str2) {
    char str_[2] = { str2, str };
    short letter = *(short*)((char*)str_);
    return letter >= (short)0xA3C1u && letter <= (short)0xA3DAu || letter >= (short)0xA3E1u && letter <= (short)0xA3FAu;;
};
BOOL Isvalidchar(const char* str);
BOOL Isvalidchar(const char* str) {
    char first = *str;
    BOOL result;
    if (first & 0x80)//如果文本为汉字
    {
        char second = *(str + 1);
        if (((BYTE)first != 163 || (BYTE)second != 223) && !Isfullwidthnum(first, second) && !Isfullwidthletter(first, second) && ((BYTE)first < 0x81u || (BYTE)first > 0xA0u) && (BYTE)first < 0xAAu) {
            if (first == -87)//char[0]==-87进入符号段，char[1]==96则为“ー”其余为标点符号
            {
                if (second != 96) {
                    return -1;
                }
                return 1;
            }
            if (first == -92)//char[0]==-87进入日文段，char[1]>96则为“ー”其余为标点符号
            {
                if ((BYTE)second >= 0xA1u)
                {
                    if ((BYTE)second > 0xF3u) {
                        return -1;
                    }
                    return 1;
                }
                return -1;
            }
            if (first != -91 || (BYTE)second < 0xA1u || (BYTE)second > 0xF6u) {//非法字符区域{}
                return -1;
            }
        }
        return 1;
    };
    if (first == 95 || first >= 48 && first <= 57 || first >= 65 && first <= 90 || first >= 97 && first <= 122) {//大小写字符，数字
        result = 0;
    }
    else {
        result = -1;
    }
    return result;
}
BOOL IsValidName(const char* text) {


    if (!text) {
        return 0;
    }
    BYTE NowChar = 0;
    int textlenth = strlen(text);

    if (*text >= 48 && *text <= 57 || *text == 46) {
        return false;
    }
    if (*text & 0x80 && Isfullwidthnum(text[0], text[1])) {
        return false;
    }

    for (int i = 0; i < textlenth; i++) {
        NowChar = text[i];

        if (!IsDBCSLeadByteEx(CP_ACP, NowChar)) {
            continue;
        };
        i++;
        BOOL isvalidchar = Isvalidchar(text);
        if (isvalidchar == -1)
        {
            return false;
        }
    }
    return 1;
}


LIBAPI(BOOL, krnln_create)
{
    PMDATA_INF pArgInf = &ArgInf;
    

    if (pArgInf[0].m_dtDataType != SDT_TEXT)
    {
        return FALSE;
    }
    
    const char* filename = pArgInf[0].m_pText;

   
    if ( nArgCount != 2)
    {
        return FALSE;
    }
    
    DWORD nElementCount;
    lpColumInfo* pAryDataBegin = (lpColumInfo*)GetAryElementInf(pArgInf[1].m_pAryData, nElementCount);

    if (nElementCount < 1) {//参数二规定必须为数组
        return FALSE;
    }
    ColumnInfo* InAryData = new ColumnInfo[nElementCount];
    if (!pAryDataBegin || !InAryData)
    {
        delete[]InAryData;
        return FALSE;
    }
    
    if (nElementCount > 0)
    {
        for (DWORD i = 0; i < nElementCount; i++) {
            InAryData[i].Name = pAryDataBegin[i]->Name;
            InAryData[i].StrDataLenth = pAryDataBegin[i]->StrDataLenth;
            InAryData[i].Type = pAryDataBegin[i]->Type;
            
        }

    }//memcppy
    BOOL ret = CreateEdb(filename, InAryData, nElementCount) == 0;
    delete[]InAryData;
    return ret;
}


