/*****************************************************************************

   $Workfile: PMDsys.h $
   $Revision: 2 $

    Purpose: Operating System functions and includes

****************************************************************************/
#ifndef _PMDSYS_H
#define _PMDSYS_H

#include <stdlib.h>
#include <stdio.h>
//#include <stdarg.h>
//#include "PMDutil.h"
#include "DBPrint.h"

#if defined(_WIN32)
// disable deprecation warnings for vsprintf and other CRT functions
#pragma warning( disable : 4996 )

#include <windows.h>
#define PMDputch                  putch
#define PMDputs                   puts
#define PMDprintf                 printf
#define PMDsprintf                sprintf
#define PMDTaskWait(ms)           Sleep(ms)
#define PMDTaskAbort(code)        exit(code)
#define PMDDeviceGetTickCount()   GetTickCount()
#define GetCurrentMilliseconds()  GetTickCount()

#else // Linux

#define PMDputch                  putc
#define PMDputs                   puts

//#define PMDprintf(void) void
#define PMDprintf noprintf
//#define PMDprintf                 myprintf

#define PMDsprintf                sprintf
#define PMDTaskWait(ms)           Sleep(ms*1000)
#define PMDTaskAbort(code)        abort()
#define PMDDeviceGetTickCount(void)   GetTickCount()
#define GetCurrentMilliseconds(void)  GetTickCount()
#define INVALID_HANDLE_VALUE      ((long)-1)
#define HANDLE                    int
#define BOOL                      int

#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
//#include <linux/types.h>
#include <sys/time.h>
//#include <sys/file.h>
unsigned GetTickCount();
void ResetTimer(void);
void Sleep(int us);
void ControlLED4(int color);
void InitLED(void);

#define TIME_SCALE 12.400

#define OFF 0
#define RED 1
#define GREEN 2
#define BLUE 3
#define PURPLE 4
#define YELLOW 5
#define CYAN 6
#define WHITE 7



#endif


#endif
