///Limits of Liability - Under no circumstances shall Performance Motion Devices, Inc. or its affiliates, partners, or suppliers be liable for any indirect
// incidental, consequential, special or exemplary damages arising out or in connection with the use this example,
// whether or not the damages were foreseeable and whether or not Performance Motion Devices, Inc. was advised of the possibility of such damages.
// Determining the suitability of this example is the responsibility of the user and subsequent usage is at their sole risk and discretion.
// There are no licensing restrictions associated with this example.

// DBPrint.c will utilize UART1 to send ASCII Debug print messages.
// Setup for 57600-N-8-1.  Use "Append line feeds to incoming line ends".
// TLK 9/15/21


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "peripheral/usart/plib_usart.h"
#include "DBPrint.h"

char * myitoa(int num, char* str, int base); 

void InitDBPrintf(void)
{
    
 // These should not be needed   
 //   TRISD&=0x7FFF;
 //   ANSELD&=0x7FFF;  
    
    
    RPD15R=1;    // RPD15 mapped to TX1
    U1BRG = 107; // Set Baud rate to 57600
    U1STA = 0;
    U1MODE = 0x8000; // Enable UART for 8-bit data
    // no parity, 1 Stop bit
    U1STA = 0x1400; // Enable Transmit and Receive
    
    return;   
}

void noprintf(char* format, ...)
{
    return;
}


/// This printf statement only has partial functionality
// Various printf formats should be tested before assuming to be correct.
void myprintf(char* format, ...)
{
  
  short hexarg;
  int decarg;
  char nib[4];
  char * arrayptr;
  char array[40];
  int i;
  va_list argp;
  
  va_start(argp, format);
   
  while (*format != '\0')
  {
    if (*format == '%')
    {
      format++;
      if (*format == '%')
      {
        while(!(U1STA&0x0100));
        U1TXREG=*format;
      }
      else if (*format == 'c')
      {
        char char_to_print = va_arg(argp, int);
        while(!(U1STA&0x0100));  // wait for FIFO space
        U1TXREG=char_to_print;
      }
      else if ((*format == '0')) 
      {
          
         hexarg = va_arg(argp, int);
         nib[3]=(char)(hexarg&0xF);
         nib[2]=(char) ((hexarg&0xF0)>>4);
         nib[1]=(char) ((hexarg&0xF00)>>8);
         nib[0]=(char) ((hexarg&0xF000)>>12);
         for(i=0;i<4;i++)
         {    
            if(nib[i]<10) nib[i]+=48;
            else nib[i]+=55;
            while(!(U1STA&0x0100));  // wait for FIFO space
            U1TXREG=nib[i];
         }
                                
         format+=2; 
      }
      else if(*format=='d')
      {
          arrayptr=&array;
          decarg=va_arg(argp,int);
          myitoa(decarg,arrayptr,10);
          
          while (*arrayptr != '\0')
          {
             while(!(U1STA&0x0100));  // wait for FIFO space
             U1TXREG=*arrayptr;
             arrayptr++;
          }
      }
      else if(*format=='s')
      {
          arrayptr=&array;
          arrayptr=va_arg(argp,char *);
          
          while (*arrayptr != '\0')
          {
             while(!(U1STA&0x0100));  // wait for FIFO space
             U1TXREG=*arrayptr;
             arrayptr++;
          }
         
         // this function does not know how to process the other 
         // %s formats for #_call and __FILE__ so just bail now
          
         while(!(U1STA&0x0100));  // wait for FIFO space
         U1TXREG='\r';    // add line feed since we are returning
           
         va_end(argp);
         return;
      }
    }
    else
    {
        if(*format == '\n')  *format='\r'; //  change newlines into carriage returns.  
      while(!(U1STA&0x0100));
      U1TXREG=*format;
    }
     while(!(U1STA&0x0100));
    format++;
  }
  va_end(argp);
  return;
}


void reverse(char str[], int length) 
{ 
    char *begin,*end,temp;
    int i;
    
    begin=str;
    end=str+length-1;
    
    for (i = 0; i < length/2; i++)
   {        
      temp   = *end;
      *end   = *begin;
      *begin = temp;
 
      begin++;
      end--;
   }
           
} 


char * myitoa(int num, char* str, int mybase) 
{ 
    int i = 0; 
    bool isNegative = false; 
  
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0) 
    { 
        str[i++] = '0'; 
        str[i] = '\0'; 
        return str; 
    } 
  
    // In standard itoa(), negative numbers are handled only with  
    // base 10. Otherwise numbers are considered unsigned. 
    if (num < 0 && mybase == 10) 
    { 
        isNegative = true; 
        num = -num; 
    } 
  
    // Process individual digits 
    while (num != 0) 
    { 
        int rem = num % mybase; 
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
        num = num/mybase; 
    } 
  
    // If number is negative, append '-' 
    if (isNegative) 
        str[i++] = '-'; 
  
    str[i] = '\0'; // Append string terminator 
  
    // Reverse the string 
    reverse(str, i); 
  
    return str; 
} 


