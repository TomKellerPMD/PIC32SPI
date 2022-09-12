//Limits of Liability - Under no circumstances shall Performance Motion Devices, Inc. or its affiliates, partners, or suppliers be liable for any indirect
// incidental, consequential, special or exemplary damages arising out or in connection with the use this example,
// whether or not the damages were foreseeable and whether or not Performance Motion Devices, Inc. was advised of the possibility of such damages.
// Determining the suitability of this example is the responsibility of the user and subsequent usage is at their sole risk and discretion.
// There are no licensing restrictions associated with this example.

// ****************************************************************
// PMDsys.c : add for PIC32 port
//
// Performance Motion Devices, Inc.
//

#include "PMDtypes.h"
#include "PMDsys.h"
#include "system/tmr/src/sys_tmr_local.h"

void ResetTimer(void)
{
         
    T4CON = 0x020; // Stop any 16/32-bit Timer4 operation
    T5CON = 0x000; // Stop any 16-bit Timer5 operation
    T4CONSET = 0x0038; // Enable 32-bit mode, prescaler 1:8,
    // internal peripheral clock source
    TMR4 = 0x0; // Clear contents of the TMR4 and TMR5
    PR4 = 0xFFFFFFFF; // Load PR4 and PR5 registers with 32-bit value
    T4CONSET = 0x8000; // Start Timer4/5
    return;
}


unsigned GetTickCount(void)
{

    return TMR4/(TIME_SCALE*1000);   // returns milliseconds
}


void Sleep(int us)
{
    ResetTimer();
    while((TMR4/TIME_SCALE)<us);
    return;
}


//****************************************************************
// ControlLED4(color)
// encoding for "color" argument
//#define OFF 0
//#define RED 1
//#define GREEN 2
//#define BLUE 3
//#define PURPLE 4
//#define YELLOW 5
//#define CYAN 6
//#define WHITE 7

// On the Curiosity PIC32MZEF board LED4 is a 3 channel RGB LED.
//LED4 red RPB5
//LED4 green RPB1
//LED4 blue RPB0
//active low
//

void ControlLED4(int color)
{
    switch (color)
    {
        case 0:  // all off
              LATBSET=0x0023;
              break;
           
        case 1:   // red
            LATBSET=0x0003;
            LATBCLR=0x0020;
            break;
        
        case 2:   //green
            LATBSET=0x0021;
            LATBCLR=0x0002;
            break;
        
        case 3:     //blue
            LATBSET=0x0022;
            LATBCLR=0x0001;
            break;
            
        case 4:     //purple
            LATBSET=0x0002;
            LATBCLR=0x0021;
             break;
        
        case 5:     //yellow
            LATBSET=0x0001;
            LATBCLR=0x0022;
             break;
        
        case 6:     //cyan
            LATBSET=0x0020;
            LATBCLR=0x0003;
             break;
             
        case 7:     //white
            LATBSET=0x0000;
            LATBCLR=0x0023;
             break;
             
             
        default:
            break;
    }
    return;
}


void InitLED4()
{
    TRISB&=0xFFDC;
}