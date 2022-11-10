#include "stdafx.h"
#include"shlwapi.h"
#pragma comment(lib,"shlwapi.lib") 
#pragma pack(1)
#if (_MSC_VER <= 1600)
WINOLEAUTAPI VarDateFromUdateEx( UDATE* pudateIn,  LCID lcid,  ULONG dwFlags, DATE* pdateOut);
#endif
/*������©�ӿ�*/
struct ColumnInfo//�ֶ���Ϣ
{
    const char* Name;
    int Type;
    int StrDataLenth ;
};
typedef ColumnInfo* lpColumInfo;
int  CreateEdb(const char* Filename, ColumnInfo* ColumnArry, int ColumnNum);
BOOL IsValidName(const char* text);
char* refilename(const char* Filename, const char* extensionname);

//struct EDTDATA//EDT��������
//{
//    const BYTE Typename[4] = { 87,69,68,84 };//��ʶ��WEDB��BYTE[4]�����������ԣ�������Ҫ���ı��ͣ���Ϊ��ָ��;
//    const BYTE delimiter1[4] = { 0,0,1,0 };//�ָ���0010 65536 Ҳ��������short��������ôд��;
//    double  check = 0;//COleDateTime::GetTickCount()��ÿ�δ򿪻�ˢ�£�����ԭ��EDB;;
//    const  BYTE delimiter2[4] = { 1,0,0,0 };//�ָ���0000 0;//�ָ���1000 1;
//    BYTE data[492] = {};
//};
struct EDTDATA//EDT��������
{
    EDTDATA() {
        
        BYTE TypenameInit[4] = { 87,69,68,84 };//��ʶ��WEDB��BYTE[4]�����������ԣ�������Ҫ���ı��ͣ���Ϊ��ָ��;
        memcpy(Typename, TypenameInit, 4);
        BYTE delimiter1Init[4]= { 0,0,1,0 };//�ָ���0010 65536 Ҳ��������short��������ôд��;
        memcpy(delimiter1, delimiter1Init, 4);
        double  check=0;//COleDateTime::GetTickCount()��ÿ�δ򿪻�ˢ�£�����ԭ��EDB;;
        BYTE delimiter2Init[4]= { 1,0,0,0 };//�ָ���0000 0;//�ָ���1000 1;
        memcpy(delimiter2, delimiter2Init, 4);
        memset(data, 0, 492);
    }
    BYTE Typename[4];//��ʶ��WEDB��BYTE[4]�����������ԣ�������Ҫ���ı��ͣ���Ϊ��ָ��;
    BYTE delimiter1[4];//�ָ���0010 65536 Ҳ��������short��������ôд��;
    double  check;//COleDateTime::GetTickCount()��ÿ�δ򿪻�ˢ�£�����ԭ��EDB;;
    BYTE delimiter2[4];//�ָ���0000 0;//�ָ���1000 1;
    BYTE data[492];
};
struct EDBDATA//EDB��������
{
    EDBDATA() {
        const BYTE TypenameInit[4] = { 87,69,68,66 };//��ʶ��WEDB��BYTE[4]�����������ԣ�������Ҫ���ı��ͣ���Ϊ��ָ��;
        memcpy(Typename, TypenameInit, 4);
        const BYTE delimiter1Init[4] = { 0,0,1,0 };//�ָ���0010 65536 Ҳ��������short��������ôд��;
        memcpy(delimiter1, delimiter1Init, 4);
        check = 0;//COleDateTime::GetTickCount()��ÿ�δ򿪻�ˢ�£�����ԭ��EDB;;
        const  BYTE delimiter2Init[8] = { 0,0,0,0,1,0,0,0 };//�ָ���0000 0;//�ָ���1000 1;
        memcpy(delimiter2, delimiter2Init, 4);
        TotalLength = 0;//��Ч�ֶ�StorageLength4+�����ͳ���*�������� ����4;;
        memset(blankBYTE, 0, 84);
        ValidColumnNum = 0;//��112λ�󴢴��int����Ч�ֶ�����;
    }
    BYTE Typename[4] ;//��ʶ��WEDB��BYTE[4]�����������ԣ�������Ҫ���ı��ͣ���Ϊ��ָ��;
    BYTE delimiter1[4];//�ָ���0010 65536 Ҳ��������short��������ôд��;
    double  check;//COleDateTime::GetTickCount()��ÿ�δ򿪻�ˢ�£�����ԭ��EDB;;
    BYTE delimiter2[8];//�ָ���0000 0;//�ָ���1000 1;
    int  TotalLength ;//��Ч�ֶ�StorageLength4+�����ͳ���*�������� ����4;;
    BYTE  blankBYTE[84];//Ŀǰδ֪84���հ׳��ȣ�Ӧ���������������;
    int ValidColumnNum;//��112λ�󴢴��int����Ч�ֶ�����;
};
struct COLIMNDATA//�����ֶ���Ϣ����
{
    COLIMNDATA() {
        memset(this, 0, sizeof(COLIMNDATA));
        DataLenth = 20;
    }
    char ColumnName[16];//�������16,�߽����
    BYTE delimiter[4];//�ָ���
    int ColumnType;
    int DataLenth;//�������ݳ���;
    int strlenth;//��Ϊ�ı���������Ҫ����;
    BYTE Table[40];
};

double  GetCOLeDateTime()//��Ϊ�����¼���ԭ��EDB,��Уʱ�䣬Ϊ�˰�EDT
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
    int Index;//�ж��ֶ��ظ�����
    int i;//ȫ�ּƴ�
    int ValidColumnNum = 0;//��Ч�ֶ�����
    int StorageLength;//�洢����;
    int  NowColumnType = 0;//��ǰ�ֶ�����
    bool HaveByteorRemark = false;//�Ƿ����ֽ��ͻ�ע;
    /*����*/
    int  TotalLength = 4;//���οռ�¼�����ֶ����������󳤶�;
    int DataLenth = 4;//��ʼ�ֶ������������ݳ���
    int strlenth = 0;//�ı������ݳ���
    int Nowstrlenth = 0;//�����ı������ݳ���
    const char* NowColumnName = NULL;//��ǰ�ֶ�����;
    EDBDATA EdbData;//�ṹ��;
    double checktime = 0;//�ļ���У;
    HANDLE hFile = NULL;
    HANDLE hDataFile = NULL;

    //BYTE ColumnNameByte[16] = {  };//��������ҹ̶�Ϊ16;
    //BYTE NowData[72];
    //lpReOpenBuff;//ԭ��ʹ��;






    if (!Filename) {
        return -3;
    }
    if (ColumnNum <= 0) {
        return -16;
    }
    for (i = 0; i < ColumnNum; i++) {
        //cout << ColumnArry[i].Name;
        if (!ColumnArry[i].Name)// ɨ�����ֶ�����ͣ���Ժ���ֶβ�����ɨ��{
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
            if (NowColumnType > 12) { // ���ʹ���12
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
                return -17;//��Ч���ֶ�����
            }

            if (NowColumnType == 10) { // �������Ϊ�ı���
                StorageLength = ColumnArry[i].StrDataLenth;
                if (StorageLength < 1 || StorageLength>1024) {
                    return -19;
                }
            }
            if (HaveByteorRemark == false && (NowColumnType == 12 || NowColumnType == 11)) {
                HaveByteorRemark = true;
            }
            TotalLength = TotalLength + StorageLength; // �ܳ��ȣ��Ժ�ÿ��չһ���¿ռ�¼��Ϊһ���ܳ���;
            ValidColumnNum = ValidColumnNum + 1; // ȫ������Ժ���Ч�ֶ��Լ�1����������Ч�ֶν�ͣ;
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
    ; // ��Ϊ�Ŵ��汾������Ӧ������ôд�ģ���������û�����⣬�Ͼ����벻�˴�����G���ڴ�;
    ; // hFile=OpenFile (refilename (Filename, ".edb"), lpReOpenBuff, λ�� (E����_OF_SHARE_EXCLUSIVE, E����_OF_CREATE, E����_OF_WRITE));
    ; // �ִ������á�;
    ; // HANDLE hFile = CreateFileA(refilename(Filename, ".edb").c_str(), GENERIC_WRITE, 0, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, 0);;
    char* infilename = refilename(Filename, ".edb");
    hFile = CreateFileA(infilename, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, 0);//CREATE_ALWAYS��Ϊ����"���������ʹ���ļ����ǿ���������"
    delete[]infilename;
    ; // ������� (refilename (Filename, ".edb"));
    ; // (hFile == INVALID_HANDLE_VALUE);
    ; // (hFile == HFILE_ERROR);
    if (hFile == INVALID_HANDLE_VALUE) {
        CloseHandle(hFile);
        return -1;
    }
    ; // memset (ȡ�������ݵ�ַ (EdbData), 0, 160)  ; // EdbData={};

    EdbData.check = checktime;
    EdbData.ValidColumnNum = ValidColumnNum;
    EdbData.TotalLength = TotalLength;
    // �ṹ�壬�����ο������ﵽ��Ϊֹ����ʹ��;
    checktime = GetCOLeDateTime(); // ��Уʱ�䣬���ڼ��ݺͰ�EDT�ļ�;
    // ������������ȫ��ͬ�ģ��ֽڼ��᷽��һ�㣬C++���ýṹ�������;


    COLIMNDATA* AllColumnData = new COLIMNDATA[ColumnNum];

    for (i = 0; i < ColumnNum; i++) {
        //COLIMNDATA NowData;

        NowColumnType = ColumnArry[i].Type;
        memcpy(AllColumnData[i].ColumnName, ColumnArry[i].Name, strlen(ColumnArry[i].Name));
        AllColumnData[i].ColumnType = NowColumnType;
        if (NowColumnType == 10) { // Ϊ�ı������ͳ���{
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
        DataLenth = DataLenth + Nowstrlenth; // ���ֶ���󳤶�;
        AllColumnData[i].strlenth = strlenth; // �ı����ͳ���;
    }
    DataLenth = sizeof(EdbData) + sizeof(COLIMNDATA) * ColumnNum;
    Data = new BYTE[DataLenth];
    memcpy(Data, &EdbData, sizeof(EdbData));
    memcpy(Data + sizeof(EdbData), AllColumnData, sizeof(COLIMNDATA) * ColumnNum);
    WriteFile(hFile, Data, DataLenth, 0, 0);
    delete[]AllColumnData;
    delete[]Data;
    CloseHandle(hFile);
    if (HaveByteorRemark == true) { // ���Ϊ�ֽڼ���ע�ͣ��򴴽���EDT�ļ�{
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
//�Ƿ�Ϊȫ������
bool Isfullwidthnum(const char str, const char str2);
//�Ƿ�Ϊȫ����ĸ
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
    if (first & 0x80)//����ı�Ϊ����
    {
        char second = *(str + 1);
        if (((BYTE)first != 163 || (BYTE)second != 223) && !Isfullwidthnum(first, second) && !Isfullwidthletter(first, second) && ((BYTE)first < 0x81u || (BYTE)first > 0xA0u) && (BYTE)first < 0xAAu) {
            if (first == -87)//char[0]==-87������ŶΣ�char[1]==96��Ϊ���`������Ϊ������
            {
                if (second != 96) {
                    return -1;
                }
                return 1;
            }
            if (first == -92)//char[0]==-87�������ĶΣ�char[1]>96��Ϊ���`������Ϊ������
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
            if (first != -91 || (BYTE)second < 0xA1u || (BYTE)second > 0xF6u) {//�Ƿ��ַ�����{}
                return -1;
            }
        }
        return 1;
    };
    if (first == 95 || first >= 48 && first <= 57 || first >= 65 && first <= 90 || first >= 97 && first <= 122) {//��Сд�ַ�������
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

    if (nElementCount < 1) {//�������涨����Ϊ����
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


