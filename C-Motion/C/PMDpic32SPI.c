//Limits of Liability - Under no circumstances shall Performance Motion Devices, Inc. or its affiliates, partners, or suppliers be liable for any indirect
// incidental, consequential, special or exemplary damages arising out or in connection with the use this example,
// whether or not the damages were foreseeable and whether or not Performance Motion Devices, Inc. was advised of the possibility of such damages.
// Determining the suitability of this example is the responsibility of the user and subsequent usage is at their sole risk and discretion.
// There are no licensing restrictions associated with this example.

//  PMDpic32.c -- SPI interface command/data transfer functions for based on Curiosity PIC32 MZEF
//  TLK 9/15/21
//  Performance Motion Devices, Inc.
//
//    CuriosityPIC32MZEF wiring on J5 (mikroBUS1) which connect to DK58113 J11:
//    RA9 HostStatus
//    CS SPI Select
//    SCK SPI Clock
//    MISO
//    MOSI
//    GND


#include <stdio.h>
#include <stdlib.h>

#include "PMDtypes.h"
#include "PMDdevice.h"
#include "PMDpic32SPI.h"

#include "peripheral/spi/plib_spi.h"


#define STRING_SIZE 256
#define SPI_RESULT(_call) \
	ret = _call; \
	if (-1 == ret) { \
		Printf(" call: " #_call "\n"); \
		return PMD_ERR_CommunicationsError; \
	}

#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))


// ------------------------------------------------------------------------
PMDuint16 PMDSPI_GetStatus(void* transport_data)
{
    return 0;
}

// ------------------------------------------------------------------------
PMDuint16 PMDSPI_IsReady(void* transport_data)
{
    return 1;
}

// ------------------------------------------------------------------------
PMDuint16 PMDSPI_HasInterrupt(void* transport_data)
{
    return 0;
}

// ------------------------------------------------------------------------
PMDuint16 PMDSPI_HasError(void* transport_data)
{
    return 0;
}

// ------------------------------------------------------------------------
PMDresult PMDSPI_HardReset(void* transport_data)
{
    return PMD_ERR_InvalidOperation; // unsupported
}

PMDresult PMDSPI_Close(void* transport_data)
{
    PMDSPI_IOData* SPI_transport_data = (PMDSPI_IOData*)transport_data;
    int StatusCode;

    if (transport_data != NULL)
    {
        SPI1CON=0x0620;    // DISABLE spi
        
    }
    free(transport_data);
    return PMD_ERR_OK;
}

// Set up default configuration for SPI port
void PMDSPI_InitData(PMDSPI_IOData* transport_data)
{
    transport_data->m_Handle = INVALID_HANDLE_VALUE;
    transport_data->m_bUseScript = FALSE;
    transport_data->m_Timeout = 2;
    transport_data->NumBitsPerSample = 16;
    transport_data->ClockPhase = 1; //kNi845xSpiClockPhaseSecondEdge;
    transport_data->ClockPhaseRead = transport_data->ClockPhase;
    transport_data->ClockPolarity = 1; //kNi845xSpiClockPolarityIdleLow;
    transport_data->ClockRate = 10000;
    transport_data->ChipSelect = 0;
    transport_data->ResourceName[0] = 0;
    transport_data->bVerbose = 0;
    



}

// Call into PIC32 library to initialize SPI.
PMDuint16 PMDSPI_InitPort(PMDSPI_IOData* transport_data, int device)
{
    int rData;
    int clk;
    clk=40000/transport_data->ClockRate;
    
    IEC0CLR=0x03800000;    // disable all interrupts
    SPI1CON = 0;           // Stops and resets the SPI1. 
    rData=SPI1BUF;         // clears the receive buffer
    IFS0CLR=0x03800000;    // clear any existing event
    IPC5CLR=0x1f000000;    // clear the priority
    IPC5SET=0x0d000000;    // Set IPL=3, Subpriority 1
    IEC0SET=0x03800000;    // Enable RX, TX and Error interrupts
    
    SPI1BRG=clk;           // use FPB/4 clock frequency
    SPI1STATCLR=0x40;      // clear the Overflow
    
    // Using RA9 as a digital input for HostSPIStatus
    //  Default to analog input so change to digital.
    ANSELA&=0xFDFF;
    
    // Deassert HostSPIEnable (RPD4)
    PORTD|=0x0010;
        
    //SS1/RPD4 and SDO1/RPD3 are outputs
    TRISD&=0xFFE7;
    
    RPD3R=5;    // specify function of RPD3 as SDO1
    
    ANSELD&=0xBFFF;
    SDI1R=0xB;  // specify SDI1 mapping to RPD14 
     
    SPI1CON=0x8620;        // SPI ON, 16 bits transfer, SMP=1, Master mode
    // from now on, the device is ready to transmit and receive data
   
    transport_data->m_Handle = 1;
    
    
    // init output used for debugging  PA1
    ANSELA&=0xFFFD;
    TRISA&=0xFFFD;
    PORTA&=0xFFFD;   //set PA1 low
    
          
  
    return PMD_ERR_OK;
}

// HostSPIEnable is connected to D4
void AssertHostSPIEnable()
{
     PORTD&=0xFFEF;
}

void DeAssertHostSPIEnable()
{
     PORTD|=0x0010;
}


// HostSPIStatus is connected to RA9
int GetHostSPIStatus(PMDSPI_IOData* transport_data)
{
   return PORTA&0x200;
    
}


int WaitUntilReady(PMDSPI_IOData* transport_data)
{
    
    ResetTimer();  //to ensure no rollover
    unsigned long EndTime = GetTickCount() + transport_data->m_Timeout;
    do {
        if (GetHostSPIStatus(transport_data) == 0)
            return 0;
    } while (GetTickCount() < EndTime);
    return PMD_ERR_Timeout;
}

int WaitUntilStatusHi(PMDSPI_IOData* transport_data)
{
    
    ResetTimer();  //to ensure no rollover
    unsigned long EndTime = GetTickCount() + transport_data->m_Timeout;
    do {
        if (GetHostSPIStatus(transport_data))
            return 0;
    } while (GetTickCount() < EndTime);
    return PMD_ERR_Timeout;
};


/*  
Sending a command
word    Host                        MC58113
------------------------------------------------------
        Assert ~HostSPIEnable   
1       8b axis 8b opcode           0
2       8b rsv  8b checksum         0
3       16b argument 1 (optional)   0
4       16b argument 2 (optional)   0
5       16b argument 3 (optional)   0
        De-assert ~HostSPIEnable    

        wait for HostSPIReady signal

Receiving a response
word    Host                        MC58113
------------------------------------------------------
        Assert ~HostSPIEnable   
1       0                           8b checksum  8b command status
2       0                           16b response 1 (optional)
3       0                           16b response 2 (optional)
4       0                           16b response 3 (optional)
        De-assert ~HostSPIEnable    
*/
PMDresult PMDSPI_Send(void* transport_data, PMDuint8 xCt, PMDuint16* xDat, PMDuint8 rCt, PMDuint16* rDat)
{
	PMDSPI_IOData* SPI_transport_data = (PMDSPI_IOData*)transport_data;


	union buff 
	{
		WORD  w[8];
		BYTE  b[16];
	} txbuff, rxbuff;

	int  ProcessorError;
	char  nbytes;
	char  nwords;
    int  c=0;
	int  i;
	int  sum;
	int  carry;
   	WORD* WriteData = txbuff.w;
	WORD  Nop[8];
	WORD* ReadData = rxbuff.w;
    PMDresult result;

	
 
    if( SPI_transport_data->m_Handle == INVALID_HANDLE_VALUE ) 
		 return PMD_ERR_NotConnected;

	memset(Nop, 0, 8);
	txbuff.b[c++] = (BYTE)(xDat[0]>>8); 	 // axis
	txbuff.b[c++] = (BYTE)(xDat[0] & 0xFF);  // opcode
	txbuff.b[c++] = 0;						 // reserved byte
	txbuff.b[c++] = 0;						 // checksum byte

    // byte swap command data
	for( i=1; i<xCt; i++ )
	{
	
        txbuff.b[c++] = (BYTE)(xDat[i] >> 8);
		txbuff.b[c++] = (BYTE)xDat[i];
	    
    }
	nbytes = c;

	/* calculate checksum */
	sum = 0xAA; // seed
	for( i=0; i<nbytes; i++ ) 
            sum+=txbuff.b[i]&0xFF;
    carry = sum >> 8;
	sum = sum & 0xFF;
	sum += carry;
	carry = sum >> 8;
	sum = sum & 0xFF;
	sum += carry;

	sum = ~sum;
	txbuff.b[3] = (PMDuint8)sum;		// checksum byte

    result=WaitUntilStatusHi(SPI_transport_data);
    if(result)
    {
        // if the HostSPIStatus signal is staying low, we're out of sync 
	    // so do a read to resync. 
        if (SPI_transport_data->bVerbose > 0)  PMDprintf("SPI resync\n");
        PMDSPI_WriteWords(transport_data, Nop, 1, ReadData);
        
        // check HostSPIStatus again.
        result=WaitUntilStatusHi(SPI_transport_data);
        if(result) return PMD_ERR_CommandError;    // Doing a read did not make HostSPIStatus high so synchronization failed.  
        
    }
    
 //   Sleep(75);
    
    // Ready to send a command
	nwords = nbytes / 2;
	PMDSPI_WriteWords(transport_data, WriteData, nwords, ReadData);
	
	// if any words in the return data are non-zero then we are out of sync so resend the command.
	if (ReadData[0] != 0)
	{
		PMDprintf("SPI resync\n");
		PMDSPI_WriteWords(transport_data, WriteData, nwords, ReadData);
	}

  //  Sleep(75);
	result=WaitUntilReady(SPI_transport_data);
    if(result) return result;
    	
    
    // read return words
	nwords = (rCt + 1); // +1 to include checksum word
	PMDSPI_WriteWords(transport_data, Nop, nwords, ReadData);

	// The first byte in response is the motion processor command status. 
	// A positive command status is # result words that are available. 
	ProcessorError = 0;
	if ((rxbuff.b[0]) < 0)
	{
		ProcessorError = -(rxbuff.b[0]);
	}

	sum = 0xAA;
	nbytes = nwords * 2;
	for( i=0; i<nbytes; i++ )
		sum += rxbuff.b[i]&0xFF;
	carry = sum >> 8;
	sum = sum & 0xFF;
	sum += carry;
	carry = sum >> 8;
	sum = sum & 0xFF;
	sum += carry;

	if( sum != 0xFF)
    {
		PORTA|=0x0002;   // set debug output
        PMDprintf("\n**Checksum error: (opcode 0x%02X)", xDat[0] );
		for(i=0; i<nwords; i++ )
			PMDprintf("  %04X", rxbuff.w[i] );
		PMDprintf(" S: %02X **\n", sum );
        
		return PMD_ERR_ChecksumError;
	}

	// copy return data skipping checksum word
	for( i=0; i<rCt; i++ )
	{
		rDat[i] = rxbuff.w[i+1];
	}
	// report error if one occured
	if( ProcessorError )
		return (PMDErrorCode)ProcessorError;

	return PMD_ERR_OK;
}

// Data provided in pWriteData and retrieved using pReadData is organized in big endian format.
PMDresult PMDSPI_WriteWords(void* transport_data, PMDuint16 *WriteData, int nwords, PMDuint16 *ReadData)
{
	PMDSPI_IOData* SPI_transport_data = (PMDSPI_IOData*)(transport_data);
	int nbytes = 2*nwords;
	uint8_t rxbuff[20];
	int i;
	int ret = 0;
	int delay = 0;
    short temp;
    short data;
    volatile short read1,read2,read3;   // volatile prevents optimization

	if (nbytes > ARRAY_SIZE(rxbuff))
		return PMD_ERR_CommandError;

	if (SPI_transport_data->bVerbose > 0 && WriteData[0] != 0) {
		PMDprintf("     send:");
		for (i = 0; i < nwords; i++)
			PMDprintf(" %04X", WriteData[i]);
		PMDprintf("\n");
	}

   // wait for SPIRBF bit to be clear which means shifting is complete
    temp=1;
    while(temp)
    {
        temp=SPI1STAT;
        temp&=0x0001;
    } 
    
    AssertHostSPIEnable();
    
    for(i=0;i<nwords;i++)
    {
        //byte swap data 
        data=WriteData[i]>>8;
        data&=0x00FF;
        data+=WriteData[i]<<8;
        
        SPI1BUF=data;
      
      
        // wait for SPIRBF bit to be set which means shifting is complete
        temp=0;
        while(!temp)
        {
            temp=SPI1STAT;
            temp&=0x0001;
        } 
    
        data=SPI1BUF;
        rxbuff[2*i]=data;
        rxbuff[2*i+1]=data>>8;
    }
     
    DeAssertHostSPIEnable();
	if (ret >= 0 && ReadData)
	{
		// do not Byte swap read data
		for (i = 0; i < nwords; i++)
		{
		   ReadData[i] = ((rxbuff[2*i+1]) << 8) + rxbuff[2*i];
        }
		if (SPI_transport_data->bVerbose > 0) 
		{
			PMDprintf("  receive:");
			for (i = 0; i < nwords; i++)
				PMDprintf(" %04X", ReadData[i]);
			PMDprintf("\n");
		}
	}
	return PMD_ERR_OK;
}



PMDresult PMDSPI_Init(PMDAxisHandle* axis_handle, int device)
{
    // setup function pointers
    axis_handle->transport.SendCommand = PMDSPI_Send;

    axis_handle->transport.GetStatus = PMDSPI_GetStatus;
    axis_handle->transport.IsReady = PMDSPI_IsReady;
    axis_handle->transport.HasInterrupt = PMDSPI_HasInterrupt;
    axis_handle->transport.HasError = PMDSPI_HasError;
    axis_handle->transport.HardReset = PMDSPI_HardReset;

    axis_handle->transport.bHasDPRAM = FALSE;
    axis_handle->transport.ReadDPRAM = NULL;
    axis_handle->transport.WriteDPRAM = NULL;

    axis_handle->transport.Close = PMDSPI_Close;

    return PMDSPI_InitPort(axis_handle->transport_data, device);
}



PMDresult PMDSetupAxisInterface_SPI(PMDAxisHandle* axis_handle,PMDAxis axis_number, int device)
{
    PMDSPI_IOData* transport_data;

    transport_data = (PMDSPI_IOData*) malloc( sizeof( PMDSPI_IOData ) );
    memset(transport_data, 0, sizeof(PMDSPI_IOData));

    // set the axis we are talking to with this handle
    axis_handle->axis = axis_number;

    // set the interface type 
    axis_handle->InterfaceType = InterfaceSPI;

    // the transport data is initialized first to setup the defaults
    PMDSPI_InitData(transport_data);

    axis_handle->transport_data = (void*) transport_data;

    // initialize the transport (inits function pointers)
    return PMDSPI_Init(axis_handle, device);
}

int PMDSPI_SetVerbose(void* transport_data, int verbose)
{
     int ret;

     PMDSPI_IOData* SPI_transport_data = (PMDSPI_IOData *)transport_data;
     ret = SPI_transport_data->bVerbose;
     SPI_transport_data->bVerbose = verbose;
     return ret;
}

long PMDSPI_SetTimeout(void *transport_data, long msec)
{
     long ret;

     PMDSPI_IOData* SPI_transport_data = (PMDSPI_IOData *)transport_data;
     ret = SPI_transport_data->m_Timeout;
     SPI_transport_data->m_Timeout = msec;
     return ret;
}

