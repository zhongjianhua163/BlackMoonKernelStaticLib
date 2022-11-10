#include "stdafx.h"

struct  EDRIVERSTATUS {
    BYTE     bDriverError;
    BYTE     bIDEError;
    BYTE     bReserved[2];
    DWORD   dwReserved[2];
};

struct EIDEREGS {
    BYTE     bFeaturesReg;           // Used for specifying SMART "commands".
    BYTE     bSectorCountReg;        // IDE sector count register
    BYTE     bSectorNumberReg;       // IDE sector number register
    BYTE     bCylLowReg;             // IDE low order cylinder value
    BYTE     bCylHighReg;            // IDE high order cylinder value
    BYTE     bDriveHeadReg;          // IDE drive/head register
    BYTE     bCommandReg;            // Actual IDE command.
    BYTE     bReserved;                      // reserved for future use.  Must be zero.
};

struct SENDCMDOUTPARAMS__
{
    DWORD cBufferSize; // Size of bBuffer in bytes 
    EDRIVERSTATUS DriverStatus; // Driver status structure. 
    BYTE bBuffer[512]; // Buffer of arbitrary length 
};

struct ESENDCMDINPARAMS {
    DWORD   cBufferSize;            // Buffer size in bytes
    EIDEREGS irDriveRegs;            // Structure with drive register values.
    BYTE     bDriveNumber;           // Physical drive number to send
                                                            // command to (0,1,2,3).
    BYTE     bReserved[3];           // Reserved for future expansion.
    DWORD   dwReserved[4];          // For future use.
    BYTE     bBuffer[1];                     // Input buffer.
};

struct ESENDCMDOUTPARAMS {
    DWORD                   cBufferSize;            // Size of bBuffer in bytes
    EDRIVERSTATUS            DriverStatus;           // Driver status structure.
    BYTE                    bBuffer[1];             // Buffer of arbitrary length in which to store the data read from the                                                                                  // drive.
};

static inline BOOL  DoIDENTIFY(HANDLE hDevice, ESENDCMDINPARAMS* lpInBuffer, SENDCMDOUTPARAMS__* lpOutBuffer, char arg1, char arg2, LPDWORD lpBytesReturned)
{
    lpInBuffer->irDriveRegs.bSectorCountReg = 1;
    lpInBuffer->irDriveRegs.bSectorNumberReg = 1;
    lpInBuffer->irDriveRegs.bFeaturesReg = 0;
    lpInBuffer->bDriveNumber = arg2;
    lpInBuffer->irDriveRegs.bCylLowReg = 0;
    lpInBuffer->irDriveRegs.bCylHighReg = 0;
    lpInBuffer->irDriveRegs.bDriveHeadReg = 16 * (arg2 & 1 | 0xFA);
    lpInBuffer->irDriveRegs.bCommandReg = arg1;
    lpInBuffer->cBufferSize = 512;
    return DeviceIoControl(hDevice, 0x7C088u, lpInBuffer, 0x20u, lpOutBuffer, 0x210u, lpBytesReturned, 0);
}
static inline UINT  GetCode(UINT* diskdata, int arg1, int arg2)
{
    UINT result = 0;
    int v4 = 0;
    UINT* v5 = 0;
    UINT v6 = 0;
    result = 0;
    if (arg1 <= arg2)
    {
        v4 = arg2 - arg1 + 1;
        v5 = &diskdata[arg1];
        do
        {
            v6 = *v5;
            ++v5;
            result += v6;
            --v4;
        } while (v4);
    }
    return result;
}
static inline unsigned int CalcHDCode(UINT* diskdata)
{
    UINT v1;
    UINT v2;

    v1 = GetCode(diskdata, 27, 46);
    v2 = GetCode(diskdata, 23, 26) + v1;
    return GetCode(diskdata, 10, 19) + v2 + ((diskdata[1] + diskdata[3] + diskdata[6] + diskdata[21]) << 16);
}

static inline UINT  ReadPhysicalDriveInNT()
{
    UINT diskdata[256] = { 0 };
    char Plaintext[4] = { 0 };
    HANDLE hPhysicalDriveIOCTL = { 0 };
    ESENDCMDINPARAMS InBuffer = { 0 };
    char Out[528] = { 0 };
    char OutBuffer[24] = { 0 };
    DWORD BytesReturned = { 0 };
    SENDCMDOUTPARAMS__ ReBuffer = { 0 };
    char* Rebuffval = { 0 };
    UINT* DiskData = { 0 };
    UINT ThisBuff = { 0 };
    UINT Ret = 0;

    hPhysicalDriveIOCTL = CreateFileA("\\\\.\\PhysicalDrive0", 0xC0000000, 3u, 0, 3u, 0, 0);
    if (hPhysicalDriveIOCTL == INVALID_HANDLE_VALUE) {
        return  0;
    }
    else {
        memset(&OutBuffer, 0, 0x18u);
        BytesReturned = 0;
        DeviceIoControl(hPhysicalDriveIOCTL, 0x74080u, 0, 0, &OutBuffer, 0x18u, &BytesReturned, 0);
        if (OutBuffer[1] > 0u) {
            Plaintext[0] = (OutBuffer[1] & 0x10) != 0 ? -95 : -20;
            memset(&InBuffer, 0, 0x20u);
            InBuffer.bBuffer[0] = 0;
            memset(&ReBuffer, 0, 0x210u);

            if (DoIDENTIFY(hPhysicalDriveIOCTL, &InBuffer, &ReBuffer, Plaintext[0], 0, &BytesReturned)) {
                DiskData = diskdata;
                Rebuffval = (char*)ReBuffer.bBuffer;
                for (size_t i = 0; i < 100; i++) {
                    ++DiskData;
                    ThisBuff = *(WORD*)Rebuffval;
                    Rebuffval += 2;
                    *(DiskData - 1) = ThisBuff;
                }
                Ret = CalcHDCode(diskdata);
            }
        }
        CloseHandle(hPhysicalDriveIOCTL);
        //Ret;
    }
    return Ret;
}


typedef struct _SRB_IO_CONTROL
{
    ULONG HeaderLength;
    UCHAR Signature[8];
    ULONG Timeout;
    ULONG ControlCode;
    ULONG ReturnCode;
    ULONG Length;
} SRB_IO_CONTROL, * PSRB_IO_CONTROL;

#define  FILE_DEVICE_SCSI              0x0000001b
#define  SENDIDLENGTH  sizeof (ESENDCMDOUTPARAMS) + 512
#define  IOCTL_SCSI_MINIPORT_IDENTIFY  ( ( FILE_DEVICE_SCSI << 16 ) + 0x0501 )
#define  IOCTL_SCSI_MINIPORT 0x0004D008  //  see NTDDSCSI.H for definition

static inline  UINT   ReadIdeDriveAsScsiDriveInNT()
{
    unsigned __int32 Ret = 0;
    HANDLE hPhysicalDriveIOCTL;
    UINT* DiskData;
    char* Rebuffval;
    WORD ThisBuff;
    DWORD BytesReturned;
    UINT diskdata[256] = { 0 };
    char InBuffer[sizeof(SRB_IO_CONTROL) + SENDIDLENGTH] = { 0 };

    SRB_IO_CONTROL* cP = (SRB_IO_CONTROL*)InBuffer;
    ESENDCMDINPARAMS* pin = (ESENDCMDINPARAMS*)(InBuffer + sizeof(SRB_IO_CONTROL));

    hPhysicalDriveIOCTL = CreateFileA("\\\\.\\Scsi0:", 0xC0000000, OPEN_EXISTING, 0, OPEN_EXISTING, NULL, NULL);
    if (hPhysicalDriveIOCTL != INVALID_HANDLE_VALUE) {
        cP->HeaderLength = sizeof(SRB_IO_CONTROL);
        cP->Timeout = 10000;
        cP->Length = SENDIDLENGTH;
        cP->ControlCode = IOCTL_SCSI_MINIPORT_IDENTIFY;
        ::strncpy((char*)cP->Signature, "SCSIDISK", 8);
        if (DeviceIoControl(hPhysicalDriveIOCTL, 
            IOCTL_SCSI_MINIPORT, 
            &InBuffer, 
            sizeof(SRB_IO_CONTROL) + sizeof(ESENDCMDINPARAMS) - 1, 
            &InBuffer, 
            sizeof(SRB_IO_CONTROL) + SENDIDLENGTH, 
            &BytesReturned, 
            NULL)) 
        {
            DiskData = diskdata;
            Rebuffval = (char*)pin;
            for (size_t i = 0; i < 100; i++) {
                ++DiskData;
                ThisBuff = *(WORD*)Rebuffval;
                Rebuffval += 2;
                *(DiskData - 1) = ThisBuff;
            }
            Ret = CalcHDCode(diskdata);
        }
        CloseHandle(hPhysicalDriveIOCTL);
    }
    return Ret;
}

static inline int  get_crc32(BYTE* ARG, DWORD lenth)//1
{
    int crcval;
    DWORD Size;
    DWORD i;
    int Ret;
    int position;
    int crc;
    int table[256] = { 0 };
    Size = lenth;
    if (Size < 1) {
        return 0;
    }
    for (i = 0; i <= 255; i++) {
        crc = i;
        for (size_t h = 1; h <= 8; h++) {
            if ((crc & 1) != 0) {
                crc = (((crc >> 1) & 2147483647) ^ 3988292384); // crc xor EDB88320;
            }
            else {
                crc = ((crc >> 1) & 2147483647);
            }
        }
        table[i] = crc;
    }
    crcval = (int)4294967295;
    for (i = 0; i < Size; i++) {
        position = (ARG[i] ^ (crcval & 255)) + 1; // 查表;
        crcval = (((crcval >> 8) & 16777215) ^ table[position]);

    }
    Ret = ~(crcval);
    return Ret;
}

static inline int  Getjycode()//返回0说明未取到。这个主要是补充易不能在某些系统或是硬盘上取硬盘特征字。
{
    HANDLE hPhysicalDriveIOCTL;
    BYTE query[12] = { 0 };
    int cbBytesReturned = 0;
    BYTE buffer[1024] = { 0 };
    int buffersize;
    BOOL st = FALSE;
    int crc1 = 0;

    hPhysicalDriveIOCTL = CreateFileA("\\\\.\\PhysicalDrive0", 0, (1 | 2), 0, 3, 0, 0);
    if (hPhysicalDriveIOCTL == INVALID_HANDLE_VALUE){
        return  0;
    }

    buffersize = 1024;
    st = DeviceIoControl(hPhysicalDriveIOCTL, 2954240, lstrcpynA((LPSTR)query, (LPSTR)query, 0), 12, lstrcpynA((LPSTR)buffer, (LPSTR)buffer, 0), buffersize, (LPDWORD)cbBytesReturned, 0);
    if (st == TRUE) {
        crc1 = get_crc32(buffer, 1024);
    }

    CloseHandle(hPhysicalDriveIOCTL);
    return crc1;
}

/*
    调用格式： 〈整数型〉 取硬盘特征字 （） - 系统核心支持库->其他
    英文名称：GetHDiskCode
    返回电脑中第一个物理硬盘的物理特征字，该特征字是仅硬件相关的，也就是说与任何软件系统都无关（包括操作系统）。用户可以使用此特征字来限制自己的程序仅在某一台计算机上运行，以保护自己软件的版权。本命令可以在任何 Windows 系统版本下运行。命令执行后如果返回 0 ，表示此次取硬盘特征字失败。由于有可能是因为暂时的 I/O 冲突造成，因此失败后可以等待一段随机时间后再试（可以参看例程）。如果重复尝试四五次后仍然失败，表明该硬盘无法取出特征字。本命令为初级命令。
*/

LIBAPI(DWORD, krnln_GetHDiskCode)
{
    int Ret;
    if (!(Ret = ReadPhysicalDriveInNT())) {
        if (!(Ret = ReadIdeDriveAsScsiDriveInNT())) {
            if (!(Ret = Getjycode())) {
                return 0;
            }
        }
    }
    return Ret;
}