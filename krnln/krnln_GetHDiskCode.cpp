#include "stdafx.h"
/*
	调用格式： 〈整数型〉 取硬盘特征字 （） - 系统核心支持库->其他
	英文名称：GetHDiskCode
	返回电脑中第一个物理硬盘的物理特征字，该特征字是仅硬件相关的，也就是说与任何软件系统都无关（包括操作系统）。用户可以使用此特征字来限制自己的程序仅在某一台计算机上运行，以保护自己软件的版权。本命令可以在任何 Windows 系统版本下运行。命令执行后如果返回 0 ，表示此次取硬盘特征字失败。由于有可能是因为暂时的 I/O 冲突造成，因此失败后可以等待一段随机时间后再试（可以参看例程）。如果重复尝试四五次后仍然失败，表明该硬盘无法取出特征字。本命令为初级命令。
*/

typedef struct _IDSECTOR
{
	USHORT  wGenConfig;
	USHORT  wNumCyls;
	USHORT  wReserved;
	USHORT  wNumHeads;
	USHORT  wBytesPerTrack;
	USHORT  wBytesPerSector;
	USHORT  wSectorsPerTrack;
	USHORT  wVendorUnique[3];
	CHAR    sSerialNumber[20];
	USHORT  wBufferType;
	USHORT  wBufferSize;
	USHORT  wECCSize;
	CHAR    sFirmwareRev[8];
	CHAR    sModelNumber[40];
	USHORT  wMoreVendorUnique;
	USHORT  wDoubleWordIO;
	USHORT  wCapabilities;
	USHORT  wReserved1;
	USHORT  wPIOTiming;
	USHORT  wDMATiming;
	USHORT  wBS;
	USHORT  wNumCurrentCyls;
	USHORT  wNumCurrentHeads;
	USHORT  wNumCurrentSectorsPerTrack;
	ULONG   ulCurrentSectorCapacity;
	USHORT  wMultSectorStuff;
	ULONG   ulTotalAddressableSectors;
	USHORT  wSingleWordDMA;
	USHORT  wMultiWordDMA;
	BYTE    bReserved[128];
} IDSECTOR, * PIDSECTOR;
typedef struct _SRB_IO_CONTROL {
	ULONG	HeaderLength;		// 
	UCHAR	Signature[8];		// 
	ULONG	Timeout;			// 
	ULONG	ControlCode;		// 
	ULONG	ReturnCode;			// 
	ULONG	Length;				// 
} SRB_IO_CONTROL, * PSRB_IO_CONTROL;

#define  DFP_RECEIVE_DRIVE_DATA   0x0007c088
#define  DFP_GET_VERSION          0x00074080
#define  IDE_ATAPI_IDENTIFY  0xA1  
#define  IDE_ATA_IDENTIFY    0xEC  
#define SENDIDLENGTH					(sizeof(SENDCMDOUTPARAMS) + IDENTIFY_BUFFER_SIZE)
#define FILE_DEVICE_SCSI				0x0000001b
#define IOCTL_SCSI_MINIPORT_IDENTIFY	((FILE_DEVICE_SCSI << 16) + 0x00000501)
#define  IOCTL_SCSI_MINIPORT 0x0004D008  //  see NTDDSCSI.H for definition
#define IDENTIFY_BUFFER_SIZE        512
typedef struct _IDEREGS {
	BYTE     bFeaturesReg;           // Used for specifying SMART "commands".
	BYTE     bSectorCountReg;        // IDE sector count register
	BYTE     bSectorNumberReg;       // IDE sector number register
	BYTE     bCylLowReg;             // IDE low order cylinder value
	BYTE     bCylHighReg;            // IDE high order cylinder value
	BYTE     bDriveHeadReg;          // IDE drive/head register
	BYTE     bCommandReg;            // Actual IDE command.
	BYTE     bReserved;                      // reserved for future use.  Must be zero.
} IDEREGS, * PIDEREGS, * LPIDEREGS;
typedef struct _SENDCMDINPARAMS {
	DWORD   cBufferSize;            // Buffer size in bytes
	IDEREGS irDriveRegs;            // Structure with drive register values.
	BYTE     bDriveNumber;           // Physical drive number to send
															// command to (0,1,2,3).
	BYTE     bReserved[3];           // Reserved for future expansion.
	DWORD   dwReserved[4];          // For future use.
	BYTE     bBuffer[1];                     // Input buffer.
} SENDCMDINPARAMS, * PSENDCMDINPARAMS, * LPSENDCMDINPARAMS;
typedef struct _GETVERSIONOUTPARAMS
{
	BYTE bVersion;      // Binary driver version.
	BYTE bRevision;     // Binary driver revision.
	BYTE bReserved;     // Not used.
	BYTE bIDEDeviceMap; // Bit map of IDE devices.
	DWORD fCapabilities; // Bit mask of driver capabilities.
	DWORD dwReserved[4]; // For future use.
} GETVERSIONOUTPARAMS, * PGETVERSIONOUTPARAMS, * LPGETVERSIONOUTPARAMS;

typedef struct _DRIVERSTATUS {
	BYTE     bDriverError;           // Error code from driver,
															// or 0 if no error.
	BYTE     bIDEError;                      // Contents of IDE Error register.
															// Only valid when bDriverError
															// is SMART_IDE_ERROR.
	BYTE     bReserved[2];           // Reserved for future expansion.
	DWORD   dwReserved[2];          // Reserved for future expansion.
} DRIVERSTATUS, * PDRIVERSTATUS, * LPDRIVERSTATUS;
typedef struct _SENDCMDOUTPARAMS {
	DWORD                   cBufferSize;            // Size of bBuffer in bytes
	DRIVERSTATUS            DriverStatus;           // Driver status structure.
	BYTE                    bBuffer[1];             // Buffer of arbitrary length in which to store the data read from the                                                                                  // drive.
} SENDCMDOUTPARAMS, * PSENDCMDOUTPARAMS, * LPSENDCMDOUTPARAMS;
BOOL DoIDENTIFY(HANDLE hPhysicalDriveIOCTL, PSENDCMDINPARAMS pSCIP,
	PSENDCMDOUTPARAMS pSCOP, BYTE bIDCmd, BYTE bDriveNum,
	PDWORD lpcbBytesReturned)
{
	pSCIP->cBufferSize = IDENTIFY_BUFFER_SIZE;
	pSCIP->irDriveRegs.bFeaturesReg = 0;
	pSCIP->irDriveRegs.bSectorCountReg = 1;
	pSCIP->irDriveRegs.bSectorNumberReg = 1;
	pSCIP->irDriveRegs.bCylLowReg = 0;
	pSCIP->irDriveRegs.bCylHighReg = 0;

	pSCIP->irDriveRegs.bDriveHeadReg = 0xA0 | ((bDriveNum & 1) << 4);
	pSCIP->irDriveRegs.bCommandReg = bIDCmd;
	pSCIP->bDriveNumber = bDriveNum;
	pSCIP->cBufferSize = IDENTIFY_BUFFER_SIZE;
	return (DeviceIoControl(hPhysicalDriveIOCTL, DFP_RECEIVE_DRIVE_DATA,
		(LPVOID)pSCIP,
		sizeof(SENDCMDINPARAMS) - 1,
		(LPVOID)pSCOP,
		sizeof(SENDCMDOUTPARAMS) + IDENTIFY_BUFFER_SIZE - 1,
		lpcbBytesReturned, NULL));
}

static inline int  GetCode(DWORD* diskdata, int firstIndex, int lastIndex)
{
	int result = 0;
	int index = 0;
	DWORD* position = 0;
	DWORD v6 = 0;
	result = 0;
	if (firstIndex <= lastIndex)
	{
		index = lastIndex - firstIndex + 1;
		position = &diskdata[firstIndex];
		do
		{

			result += *position;
			++position;

			--index;
		} while (index);
	}
	return result;
}
int CalcHDCode(DWORD diskdata[256])
{
	DWORD mode = GetCode(diskdata, 27, 46);
	DWORD ser = GetCode(diskdata, 23, 26) + mode;
	return GetCode(diskdata, 10, 19) + ser + ((diskdata[1] + diskdata[3] + diskdata[6] + diskdata[21]) << 16);
}

int ReadPhysicalDriveInNT() {
	INT done = 0;
	BYTE IdOutCmd[sizeof(SENDCMDOUTPARAMS) + IDENTIFY_BUFFER_SIZE - 1];
	HANDLE hPhysicalDriveIOCTL = 0;

	hPhysicalDriveIOCTL = CreateFileA("\\\\.\\PhysicalDrive0",
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
		OPEN_EXISTING, 0, NULL);
	if (hPhysicalDriveIOCTL == INVALID_HANDLE_VALUE) {
		return 0;
	}
	else
	{
		GETVERSIONOUTPARAMS VersionParams;
		DWORD               cbBytesReturned = 0;
		memset((void*)&VersionParams, 0, sizeof(VersionParams));
		DeviceIoControl(hPhysicalDriveIOCTL, DFP_GET_VERSION,
			NULL,
			0,
			&VersionParams,
			sizeof(VersionParams),
			&cbBytesReturned, NULL);
		if (VersionParams.bIDEDeviceMap > 0)
		{
			BYTE             bIDCmd = 0;   // IDE or ATAPI IDENTIFY cmd
			SENDCMDINPARAMS  scip;
			//SENDCMDOUTPARAMS OutCmd;

			// Now, get the ID sector for all IDE devices in the system.
			// If the device is ATAPI use the IDE_ATAPI_IDENTIFY command,
			// otherwise use the IDE_ATA_IDENTIFY command
			bIDCmd = (VersionParams.bIDEDeviceMap & 0x10) ? IDE_ATAPI_IDENTIFY : IDE_ATA_IDENTIFY;

			memset(&scip, 0, sizeof(scip));
			memset(IdOutCmd, 0, sizeof(IdOutCmd));

			if (DoIDENTIFY(hPhysicalDriveIOCTL,
				&scip,
				(PSENDCMDOUTPARAMS)&IdOutCmd,
				(BYTE)bIDCmd,
				0,
				&cbBytesReturned))
			{
				DWORD diskdata[256];
				int ijk = 0;
				USHORT* pIdSector = (USHORT*)
					((PSENDCMDOUTPARAMS)IdOutCmd)->bBuffer;

				for (ijk = 0; ijk < 256; ijk++)
					diskdata[ijk] = pIdSector[ijk];



				done = CalcHDCode(diskdata);
			}
		}

		CloseHandle(hPhysicalDriveIOCTL);
	}
	return done;
}


int ReadIdeDriveAsScsiDriveInNT()
{
	int done = FALSE;
	int controller = 0;


	HANDLE hScsiDriveIOCTL = 0;


	//  Try to get a handle to PhysicalDrive IOCTL, report failure
	//  and exit if can't.

	//  Windows NT, Windows 2000, any rights should do
	hScsiDriveIOCTL = CreateFileA("\\\\.\\Scsi%0:",
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
		OPEN_EXISTING, 0, NULL);

	if (hScsiDriveIOCTL != INVALID_HANDLE_VALUE)
	{
		int drive = 0;

		char buffer[sizeof(SRB_IO_CONTROL) + SENDIDLENGTH];
		SRB_IO_CONTROL* p = (SRB_IO_CONTROL*)buffer;
		SENDCMDINPARAMS* pin =
			(SENDCMDINPARAMS*)(buffer + sizeof(SRB_IO_CONTROL));
		DWORD dummy;

		memset(buffer, 0, sizeof(buffer));
		p->HeaderLength = sizeof(SRB_IO_CONTROL);
		p->Timeout = 10000;
		p->Length = SENDIDLENGTH;
		p->ControlCode = IOCTL_SCSI_MINIPORT_IDENTIFY;
		strncpy((char*)p->Signature, "SCSIDISK", 8);

		pin->irDriveRegs.bCommandReg = IDE_ATA_IDENTIFY;
		pin->bDriveNumber = drive;

		if (DeviceIoControl(hScsiDriveIOCTL, IOCTL_SCSI_MINIPORT,
			buffer,
			sizeof(SRB_IO_CONTROL) +
			sizeof(SENDCMDINPARAMS) - 1,
			buffer,
			sizeof(SRB_IO_CONTROL) + SENDIDLENGTH,
			&dummy, NULL))
		{
			SENDCMDOUTPARAMS* pOut =
				(SENDCMDOUTPARAMS*)(buffer + sizeof(SRB_IO_CONTROL));
			IDSECTOR* pId = (IDSECTOR*)(pOut->bBuffer);
			DWORD diskdata[256];
			if (pId->sModelNumber[0])
			{
				//DWORD diskdata[256];
				int ijk = 0;
				USHORT* pIdSector = (USHORT*)pId;

				for (ijk = 0; ijk < 256; ijk++)
					diskdata[ijk] = pIdSector[ijk];



				done = CalcHDCode(diskdata);
			}
		}

		CloseHandle(hScsiDriveIOCTL);
	}


	return done;
}
int GetHD() {
	int ret = ReadPhysicalDriveInNT();
	if (!ret)
	{
		ret = ReadIdeDriveAsScsiDriveInNT();
	}
	return ret;
}
LIBAPI(DWORD, krnln_GetHDiskCode)
{
	return GetHD();
}