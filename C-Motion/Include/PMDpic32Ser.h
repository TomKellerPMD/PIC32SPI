#ifndef PMD_Serial
#define	PMD_Serial

#define picHANDLE int

// using the Win32 API for serial port access functions
//#include <windows.h>

//  PMDw32ser.h -- Win32 serial IO
//
//  Performance Motion Devices, Inc.
//

enum {Protocol_PointToPoint,Protocol_ModeAddressBit=2,Protocol_IdleLine};

typedef struct tagPMDSerialIOData {

	PMDuint16 multiDropAddress;
	PMDuint16 protocol;

	PMDuint8 port;

	picHANDLE hPort;
	PMDuint32 baud;
	PMDuint8 parity;
	PMDuint8 stop;

	PMDuint16 bVerifyChecksum;
	PMDuint16 bDiagnostics;

} PMDSerialIOData;

// functions that can be called externally
void PMDSerial_InitData(PMDSerialIOData* transport_data);
PMDresult PMDSerial_Init(PMDAxisHandle* axis_handle);
void PMDCreateMultiDropHandle(PMDAxisHandle* dest_axis_handle, PMDAxisHandle* src_axis_handle, PMDAxis axis_number, PMDuint8 nodeID);

// call this function to initialize the interface
PMDresult PMDSetupAxisInterface_Serial(PMDAxisHandle* axis_handle, PMDAxis axis_number, PMDuint8 port_number);

// support functions that may be called directly
// once the port is initialized
int PMDSerial_SetConfig(void* transport_data,PMDuint32 b,PMDuint8 p);
int PMDSerial_SetTimeout(void* transport_data,long msec);
void PMDSerial_SetProtocol(void* transport_data,PMDuint16 mode);
void PMDSerial_SetMultiDropAddress(void* transport_data,PMDuint16 address);
PMDresult PMDSerial_WriteByte(void* transport_data, PMDuint8 data);
PMDresult PMDSerial_ReadByte(void* transport_data, PMDuint8* data);
PMDresult PMDSerial_FlushRecv(void* transport_data);
PMDresult PMDSerial_Sync(void* transport_data);



#endif
