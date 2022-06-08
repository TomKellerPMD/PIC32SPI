//Limits of Liability - Under no circumstances shall Performance Motion Devices, Inc. or its affiliates, partners, or suppliers be liable for any indirect
// incidental, consequential, special or exemplary damages arising out or in connection with the use this example,
// whether or not the damages were foreseeable and whether or not Performance Motion Devices, Inc. was advised of the possibility of such damages.
// Determining the suitability of this example is the responsibility of the user and subsequent usage is at their sole risk and discretion.
// There are no licensing restrictions associated with this example.

//  This contain the main() function for the PIC32 example

//#define PMD_CAN_INTERFACE
#define PMD_SPI_INTERFACE
//#define PMD_W32SERIAL_INTERFACE

#include "C-Motion.h"
#include "PMDutil.h"
#include "PMDdiag.h"
#include "PMDsys.h"
#include "Examples.h"


#include <sys/appio.h>
#include <stdio.h>

#define Error_Block int

void Controller_testFunction(PMDAxisHandle *obj, Error_Block *eb);
PMDresult Setup(PMDAxisHandle * phAxis);


PMDAxisHandle X;              // the x axis handle object

#define ARRAY_SIZE 21

//PMDint32 Xdata[ARRAY_SIZE];
PMDint32 Ydata[ARRAY_SIZE];
//PMDint32 inv[ARRAY_SIZE];
PMDint32 Xdata[21] = { 2235,1981,1727,1473,1219,965,711,457,203,-50,-304,-50,203,457,711,965,1219,1473,1727,1981,2235 };
PMDint32 inv[21] = { 0,8007,11523,14413,17031,19531,22030,24648,27538,31054,39062,47069,50585,53475,56093,58593,61092,63710, 66600,70116,78124 };




// Buffer numbers and addresses
#define BUF_TRACE   0
#define BUF_INPUT  10
#define BUF_X      11

#define AxisSmCMPStates int;
#define smSysEvtPack int;
#define bool int;

#define PMD_NO_ERROR PMD_ERR_OK;

//AxisSmCMPStates smStateCMPAxisZeroMotionCmdSingleAxisStartPeriodicMove(); // smSysEvtPack* sTaskmanagerData, bool* bEventHandled);

PMDresult CMPaxisZeroWriteBlockPMD(int start, int npoints, PMDAxisInterface pmdAxis);



int main()

{
    int rate_scalar = 0x10000;   // 1.0
    int exit_status = EXIT_FAILURE;
    PMDuint32 vmajor, vminor;
    PMDuint16 generation, motorType, numberAxes, chip_count, custom, major, minor, mode;
    PMDint32 xcmdpos, ycmdpos, xactpos;
    PMDresult result;
    int ReadSector;
    PMDint32 ReadDataIndex, WriteDataIndex, lastReadIndex;
    int counter;
    PMDuint16 status, runerr;
    PMDuint32 timenow, starttime, endtime;
  //  PMDresult result;

    ReadDataIndex = WriteDataIndex = 0;
    
    
    PMDAxisHandle hAxis1,hAxis2; // the axis handle object
  //  PMDuint32 vmajor, vminor;
    PMDuint16 special;  ///, custom, major, minor;
 //   PMDresult result;
    PMDAxisHandle * phAxis1,*phAxis2; 
    int * eb;

    InitDBPrintf();
    InitLED4();
    ControlLED4(GREEN);
    
    //Using RPB4 to toggle AxisIn
     TRISB&=0xFFEF;
     
    PMDGetCMotionVersion( &vmajor, &vminor );
    PMDprintf("\n\nPorted to MPLAB from C-Motion Version %d.%d \n", vmajor, vminor);
   

#if defined PMD_CAN_INTERFACE
    // open the CAN interface at 20,000 baud and NodeID=0
    PMD_ABORTONERROR(PMDSetupAxisInterface_CAN( &hAxis1, PMDAxis1, PMDCANBaud20000, 0 ))
#elif defined PMD_W32SERIAL_INTERFACE
    // Open the serial interface (57600 baud and point-to-point protocol)
    // The third parameter represents the COM port number (0=default of COM1)
    PMD_ABORTONERROR(PMDSetupAxisInterface_Serial( &hAxis1, PMDAxis1, 3 ))
#elif defined PMD_SPI_INTERFACE
    // Open the SPI interface
    // The third parameter represents the device number (0=first NI device found)
	PMDSetupAxisInterface_SPI(&X, PMDAxis1, 0);
#endif

     result=PMDGetVersion(&X, &generation, &motorType, &numberAxes, &special, &custom, &major, &minor);
     if(result)
     {
         PMDprintf("GetVersion error\n");;
     }
 //    phAxis1 = &hAxis1; 
  //   phAxis2 = &hAxis2; 
     
  //   result=PMDReset(&hAxis1);

  //   PMDCopyAxisInterface(&hAxis2, &hAxis1, PMDAxis2); 
     PMDTaskWait(100); 
  
 //    AllMagellanCommands(&hAxis1);
     
     PMDSetMotorType(&X,4);
     PMDSetOutputMode(&X,8);
     
   
    
     PMDSetBufferStart(&X, BUF_X, 0x800);
    PMDSetBufferLength(&X, BUF_X, ARRAY_SIZE);
   
    PMDSetBufferStart(&X, BUF_INPUT, 0x900);
    PMDSetBufferLength(&X, BUF_INPUT, ARRAY_SIZE);

    result = PMD_ERR_OK;

    while (!result) { result = CMPaxisZeroWriteBlockPMD(0, ARRAY_SIZE, &X); }
     
     
     
     
  //   Setup(&hAxis1);
    
//    Controller_testFunction(&hAxis1, eb);
    // If the above function returns an error has occurred.
    

#if(0)
    i=0;
    while(1)
    {
        ControlLED4(i);
        i++;
        if(i==8) i=0;
        PMDTaskWait(2000);
    }
#endif
    
      
    ControlLED4(RED);
       // Only axis1 needs to be closed to free any axis handle memory that was allocated. 
 
    PMDCloseAxisInterface(&X); 
    return 0; 

} 

PMDresult CMPaxisZeroWriteBlockPMD(int start, int npoints, PMDAxisInterface pmdAxis)
{
	int index;
    PMDresult result = PMD_NO_ERROR;
    PMDresult result1 = PMD_NO_ERROR;
    PMDresult result2 = PMD_NO_ERROR;
    PMDuint32 tLen,pLen;
    PMDint32 bufferPosData, bufferTimeData;
    char hL[100];
    int uiRetryCounter = 0;
    
    
    PMDGetBufferLength(pmdAxis, BUF_INPUT, &tLen);
  //  PMDGetBufferLength(pmdAxis, BUF_A, &pLen);
    
//PMD_BUFF_REWRITE:
 //           sendResponseViaSerial3("AX0_PT_WRTE:");

            PMDSetBufferWriteIndex(pmdAxis,BUF_X,0);   
            PMDSetBufferWriteIndex(pmdAxis,BUF_INPUT,0);  
            PMDSetBufferWriteIndex(pmdAxis,BUF_X,0);   
            PMDSetBufferWriteIndex(pmdAxis,BUF_INPUT,0);
            
            for(index = start; index < (start+npoints); index++)
            {     
           //     delay_us(10);
                result1 = PMDWriteBuffer(pmdAxis, BUF_X, Xdata[index]);
          //      delay_us(10);
                result2 = PMDWriteBuffer(pmdAxis, BUF_INPUT, inv[index] );
              //  sprintf(hL, "%ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld", pLen, tLen, ucInWritePosTimeBufferIndex, index, cRxCmdPosBuffer[index], cRxCmdTimeBuffer[index], result1, result2);                       
              //  sendResponseViaSerial2(hL);
            }
   
            PMDSetBufferReadIndex(pmdAxis,BUF_X,0);
            PMDSetBufferReadIndex(pmdAxis,BUF_INPUT,0);
            PMDSetBufferReadIndex(pmdAxis,BUF_X,0);
            PMDSetBufferReadIndex(pmdAxis,BUF_INPUT,0);
    
    //        sendResponseViaSerial3("AX0_PT_READ:");
            for(index = start; index < (start+npoints); index++)
            {
            //    delay_us(10);
                result1 = PMDReadBuffer(pmdAxis,BUF_X ,&bufferPosData);
                result2 = PMDReadBuffer(pmdAxis,BUF_INPUT ,&bufferTimeData);
               // sprintf(hL, "%ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld", pLen, tLen, ucInWritePosTimeBufferIndex, index, bufferPosData, bufferTimeData, result1, result2);                       
              //  sendResponseViaSerial2(hL);
               if(Xdata[index] != bufferPosData)
                {
                   PMDprintf("write error!!");
                   return -1;
                   
                }
                else if(inv[index] != bufferTimeData)
                {      
                   PMDprintf("write error!!");
                   return -1; 
                                      
                }

         //      PMDprintf("X:%d  inv:%d\n",bufferPosData, bufferTimeData);
            }

    return result;
}

void Controller_clearMotionError(PMDAxisHandle *obj, Error_Block *eb)
{
    PMDuint16 resetMask;
    PMDuint16 eventStatus;
    PMDint32 actualPosition;

    PMDGetEventStatus(obj, &eventStatus);

    if(eventStatus & PMDEventStatusMotionError) {
        PMDRestoreOperatingMode(obj);

        // Reset the motion error bit
        //resetMask = ~(PMDEventMask_MotionError);
        PMDResetEventStatus(obj,0xFFEF);

        // Set the actualPosition to get the PMD to set commanded position to match the actual position
        // TODO: move this into a Stepper specific area
        PMDGetActualPosition(obj, &actualPosition);
        PMDGetActualPosition(obj, &actualPosition);
    }
}

void Controller_motionStart(PMDAxisHandle *obj, Error_Block *eb)
{
    PMDuint16 mode;

 //   mode =    PMDOperatingModeMask_AxisEnabled
  //                  + PMDOperatingModeMask_MotorOutputEnabled
   //                 + PMDOperatingModeMask_CurrentControlEnabled
    //                + PMDOperatingModeMask_PositionLoopEnabled
     //               + PMDOperatingModeMask_TrajectoryEnabled;

    mode=0x37;
    Controller_clearMotionError(obj, eb);

    PMDSetMotorCommand(obj, 0);
    PMDUpdate(obj);
    //enable drive
    
    //IGpio_write(obj->axis0DrivePower_IGpio, IGpio_Active, eb);
    // ~Enable?
    
    
    PMDResetEventStatus(obj, 0);
    PMDSetOperatingMode(obj, mode);
    PMDResetEventStatus(obj, 0);
    PMDSetOperatingMode(obj, mode);

    // ensure AxisIn is not active
    //IGpio_write(obj->encoder0Reset_IGpio, IGpio_Inactive, eb);
    LATBCLR=0x0010;
   // ControlLED4(YELLOW);
}


// Configure the profile parameters without an Update, as well as the stopping params
PMDresult Controller_startMove(PMDAxisHandle *obj, Error_Block *eb)
{
    PMDuint16 istatus,actstatus,status;
    PMDresult result;
    PMDSetVelocity(obj, 13000);
    PMDSetAcceleration(obj, 13000);
    PMDSetProfileMode(obj, PMDProfileModeTrapezoidal);
    PMDSetPosition(obj, 500000);
    int count;

        
    //Sleep(50);
    PMDSetBreakpointUpdateMask(obj,PMDBreakpoint1,0x0003);
    //Sleep(50);
    PMDSetBreakpointValue(obj,PMDBreakpoint1,0x00400040);
    //Sleep(50);
    PMDSetBreakpoint(obj, PMDBreakpoint1, PMDAxis1,PMDBreakpointActionUpdate, PMDBreakpointTriggerSignalStatus);
    Sleep(5000);
    LATBSET=0x0010;
    // Send the update to AxisIn
    //IGpio_write(obj->encoder0Reset_IGpio, IGpio_Active, eb);
    
  // Note:  if the breakpoint update is replaced with an Update command the problem goes away.
     
    //  Sleep(5);  
     istatus = 0;
     count=0;
     while (!istatus) 
     { 
         result=PMDGetActivityStatus(obj,&actstatus);
         if(result) break;
                                                
         result=PMDGetEventStatus(obj, &status);
         if(result) break;
                  
         actstatus&=0x0400;
         status&=0x0011;
         istatus=actstatus|status;
         count++;           
                     
    }
    
   
    return result;
     
}

void Controller_startStop(PMDAxisHandle *obj, Error_Block *eb)
{
    PMDuint16 status;
    PMDuint16 mask; // = PMDActivityMask_InMotion;
     
    PMDGetActivityStatus(obj, &status);

    status&=0x0400;
    if (status) {
      
        PMDSetAcceleration(obj, 13000);
        PMDSetVelocity(obj, 0);
        PMDSetProfileMode(obj, PMDProfileModeVelocity);
        PMDUpdate(obj);
    }
}

void Controller_motionEnd(PMDAxisHandle *obj, Error_Block *eb)
{
    PMDuint16 resetMask;
    PMDuint16 eventStatus;
    PMDuint16 signalStatus;

    PMDGetEventStatus(obj, &eventStatus);
    if(eventStatus & PMDEventStatusMotionError) {
        PMDGetSignalStatus(obj, &signalStatus);
    }

    PMDSetBreakpoint(obj, PMDBreakpoint1, PMDAxis1, PMDBreakpointActionNone, PMDBreakpointTriggerDisable);
    PMDSetBreakpoint(obj, PMDBreakpoint2, PMDAxis1, PMDBreakpointActionNone, PMDBreakpointTriggerDisable);
   

    PMDResetEventStatus(obj,0xBFFB);
 //   ControlLED4(PURPLE);
}

void Controller_setServo(PMDAxisHandle *obj, Error_Block *eb)
{
    PMDuint16 mode = 0x7;
       //    PMDOperatingModeMask_AxisEnabled
         //   + PMDOperatingModeMask_MotorOutputEnabled
          //  + PMDOperatingModeMask_CurrentControlEnabled;

    
    PMDSetOperatingMode(obj, mode);
    PMDSetMotorCommand(obj, 0);
    PMDUpdate(obj);
    //disable drive
    //IGpio_write(obj->axis0DrivePower_IGpio, IGpio_Inactive, eb);
 }

void Controller_testFunction(PMDAxisHandle *obj, Error_Block *eb)
{
   // ISynchedAxis_setActualPosition(obj->axis0_ISynchedAxis, 100000, eb);

    PMDresult result;
    PMDSetActualPosition(obj,0);
    
 //   SetupTrace(obj,0x1000);
        
    while(1) {
        Controller_motionStart(obj, eb);
        result=Controller_startMove(obj, eb);
        if(result) break;
    //    ControlLED4(GREEN);
        Sleep(200);
        Controller_startStop(obj, eb);
        Controller_motionEnd(obj, eb);
        Controller_setServo(obj, eb);
        Sleep(200);
    }
    
    
    // if this loop exits an error occurred.
  //  ControlLED4(RED);
    
}


PMDresult Setup(PMDAxisHandle * phAxis)
{

    PMDresult result;
    
  PMD_RESULT(PMDSetOutputMode (phAxis, 7))
  PMD_RESULT(PMDSetProfileMode (phAxis, 0))
  PMD_RESULT(PMDSetPositionErrorLimit (phAxis, 44465535))
  PMD_RESULT(PMDSetSettleTime (phAxis, 0))
  PMD_RESULT(PMDSetSettleWindow (phAxis, 0))
  PMD_RESULT(PMDSetTrackingWindow (phAxis, 0))
  PMD_RESULT(PMDSetEncoderSource (phAxis, 0))
  PMD_RESULT(PMDSetPositionLoop (phAxis, PMDPositionLoopKp, 20))
  PMD_RESULT(PMDSetPositionLoop (phAxis, PMDPositionLoopKi, 0))
  PMD_RESULT(PMDSetPositionLoop (phAxis, PMDPositionLoopIlimit, 0))
  PMD_RESULT(PMDSetPositionLoop (phAxis, PMDPositionLoopKd, 0))
  PMD_RESULT(PMDSetPositionLoop (phAxis, PMDPositionLoopDerivativeTime, 1))
  PMD_RESULT(PMDSetPositionLoop (phAxis, PMDPositionLoopKout, 65535))


  PMD_RESULT(PMDSetCurrentControlMode (phAxis, 1))
  PMD_RESULT(PMDSetFOC (phAxis, 2, 0, 32767))
  PMD_RESULT(PMDSetFOC (phAxis, 2, 1, 32767))
  PMD_RESULT(PMDSetFOC (phAxis, 2, 2, 16384))
  PMD_RESULT(PMDSetCurrentLoop (phAxis, 2, 0, 0))
  PMD_RESULT(PMDSetCurrentLoop (phAxis, 2, 1, 0))
  PMD_RESULT(PMDSetCurrentLoop (phAxis, 2, 2, 16384))
  PMD_RESULT(PMDSetAxisOutMask (phAxis, 0, 0, 0x0001, 0x0000))
  PMD_RESULT(PMDSetFaultOutMask (phAxis, 0x0401))
  PMD_RESULT(PMDSetDriveFaultParameter (phAxis, PMDDriveFaultParameterOvervoltageLimit, 65535))
  PMD_RESULT(PMDSetDriveFaultParameter (phAxis, PMDDriveFaultParameterUndervoltageLimit, 0))
  PMD_RESULT(PMDSetCurrentFoldback (phAxis, PMDCurrentFoldbackContinuousCurrentLimit, 32768))
  PMD_RESULT(PMDSetCurrentFoldback (phAxis, PMDCurrentFoldbackI2tEnergyLimit, 32768))
  PMD_RESULT(PMDSetEventAction (phAxis, PMDEventActionEventPositiveLimit, 0x0008))
  PMD_RESULT(PMDSetEventAction (phAxis, PMDEventActionEventNegativeLimit, 0x0008))
  PMD_RESULT(PMDSetEventAction (phAxis, PMDEventActionEventMotionError, 0x0005))
  PMD_RESULT(PMDSetEventAction (phAxis, PMDEventActionEventCurrentFoldback, 0x0007))
  PMD_RESULT(PMDSetDrivePWM (phAxis, PMDDrivePWMLimit, 16384))
  PMD_RESULT(PMDSetDriveFaultParameter (phAxis, PMDDriveFaultParameterTemperatureLimit, 32767))
  PMD_RESULT(PMDSetDriveFaultParameter (phAxis, PMDDriveFaultParameterTemperatureHysteresis, 0))
  PMD_RESULT(PMDSetDriveFaultParameter (phAxis, PMDDriveFaultParameterShuntVoltage, 65535))
  PMD_RESULT(PMDSetDriveFaultParameter (phAxis, PMDDriveFaultParameterShuntPWMDutyCycle, 0))
  PMD_RESULT(PMDSetDriveFaultParameter (phAxis, PMDDriveFaultParameterBusCurrentSupplyLimit, 65534))
  PMD_RESULT(PMDSetDriveFaultParameter (phAxis, PMDDriveFaultParameterBusCurrentReturnLimit, 65534))
  
  PMD_RESULT(PMDUpdate (phAxis))
  PMD_RESULT(PMDSetOperatingMode (phAxis, 0x0003))
  PMD_RESULT(PMDSetPhaseInitializeTime(phAxis,4000))         
  PMD_RESULT(PMDSetMotorCommand (phAxis, 3277))
  PMD_RESULT(InitializePhase (phAxis))
  PMD_RESULT(PMDSetMotorCommand (phAxis, 0))
  PMD_RESULT(PMDSetOperatingMode (phAxis, 0x0037))
  PMD_RESULT(PMDSetGearRatio (phAxis, 0x00000000))
  return result;

}




  

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

// *****************************************************************************

/** 
  @Function
    int ExampleInterfaceFunctionName ( int param1, int param2 ) 

  @Summary
    Brief one-line description of the function.

  @Remarks
    Refer to the example_file.h interface header for function usage details.
 */
int ExampleInterfaceFunction(int param1, int param2) {
    return 0;
}


/* *****************************************************************************
 End of File
 */
