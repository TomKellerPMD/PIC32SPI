

#ifndef PMD_SPI
#define PMD_SPI
#include "PMDsys.h"
#include "PMDtypes.h"
#include "PMDdevice.h"

#define uInt8 char
#define uInt16 short
#define uInt32 int
#define int32 int
#define WORD short
#define DWORD int
#define BYTE char
//typedef char int8;


// specify the PIC ports being using for SPI

// Setup for Curiosity PIC32
// RD4 SPI Enable 0
// RA9 SPI Status 0
// RPD3 MOSI
// RPD14 MISO
// RPD1 SPI CLK

// Device #1 
#define SPI_ENB_0 PORTD
#define SPI_ENB_MSK_0 0x0010
#define ANSEL_ENB_0 ANSELD
#define TRIS_ENB_0 TRISD


#define ANSEL_STAT_0 ANSELA
#define SPI_STAT_0  PORTA
#define SPI_STAT_MSK_0 0x0200

#define ANSEL_SDO1_0 ANSELD
#define TRIS_SDO1_0 TRISD
#define SDO1_MSK 0x0008
#define SDO1_REG RPD3R

#define SDI1_MSK 0x4000
#define ANSEL_SDI1 ANSELD


//RA1 SPI Enable 1
//RA5 SPI Status 1
#define SPI_ENB_1 PORTA
#define SPI_ENB_MSK_1 0x0002
#define ANSEL_ENB_1 ANSELA
#define TRIS_ENB_1 TRISA


#define ANSEL_STAT_1 ANSELA
#define SPI_STAT_1  PORTA
#define SPI_STAT_MSK_1 0x0020


typedef struct tag_PMDSPI_IOData {
    HANDLE m_Handle;
    short NumBitsPerSample;
    int  ClockPhase;
    int  ClockPhaseRead;
    int  ClockPolarity;
    short ClockRate;
    int ChipSelect;
    BOOL m_bUseScript;
    long m_Timeout;
    PMDuint8 bVerbose;
    char     ResourceName[256];
} PMDSPI_IOData;

// functions that can be called externally
void PMDSPI_InitData(PMDSPI_IOData* transport_data, int device);

PMDresult PMDSPI_Init(PMDAxisHandle* axis_handle, int device);

// call this function to initialize the interface
PMDresult PMDSetupAxisInterface_SPI(PMDAxisHandle* axis_handle, PMDAxis axis_number, int device);

PMDresult PMDSPI_WriteWords(void* transport_data, PMDuint16 *WriteData, int nwords, PMDuint16 *ReadData);

// Set new verbosity, return old verbosity.
int PMDSPI_SetVerbose(void *transport_data, int level);

// Return old timeout.
long PMDSPI_SetTimeout(void *transport_data, long msec);
#endif  // def PMD_SPI
