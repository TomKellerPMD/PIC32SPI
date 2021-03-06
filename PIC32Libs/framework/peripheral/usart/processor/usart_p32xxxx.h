/*******************************************************************************
  Selector for PIC 32 family

  Company:
    Micrusarthip Technology Incorporated

  File Name:
    p32xxxx.h

  Summary:
    Selector for PIC 32 family for USART PLIB implementations

  Description:
    This file is the selector for PIC 32 family for USART PLIB implementations
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2012 released Micrusarthip Technology Inc.  All rights reserved.

Micrusarthip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Micrusarthip micrusartontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DusartUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICRusartHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PRusartUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END


#ifndef _USART_P32XXXX_H
#define _USART_P32XXXX_H

/* MK */
#if defined(__32MK1024GPE100__)
    #include "usart_p32mk1024gpe100.h"

/* MZ */
#elif defined(__32MZ1024ECG064__)
    #include "usart_p32mz1024ecg064.h"

#elif defined(__32MZ1024ECG100__)
    #include "usart_p32mz1024ecg100.h"

#elif defined(__32MZ1024ECG124__)
    #include "usart_p32mz1024ecg124.h"

#elif defined(__32MZ1024ECG144__)
    #include "usart_p32mz1024ecg144.h"

#elif defined(__32MZ1024ECH064__)
    #include "usart_p32mz1024ech064.h"

#elif defined(__32MZ1024ECH100__)
    #include "usart_p32mz1024ech100.h"

#elif defined(__32MZ1024ECH124__)
    #include "usart_p32mz1024ech124.h"

#elif defined(__32MZ1024ECH144__)
    #include "usart_p32mz1024ech144.h"

#elif defined(__32MZ1024ECM064__)
    #include "usart_p32mz1024ecm064.h"

#elif defined(__32MZ1024ECM100__)
    #include "usart_p32mz1024ecm100.h"

#elif defined(__32MZ1024ECM124__)
    #include "usart_p32mz1024ecm124.h"

#elif defined(__32MZ1024ECM144__)
    #include "usart_p32mz1024ecm144.h"
	
#elif defined(__32MZ2048ECG064__)
    #include "usart_p32mz2048ecg064.h"

#elif defined(__32MZ2048ECG100__)
    #include "usart_p32mz2048ecg100.h"

#elif defined(__32MZ2048ECG124__)
    #include "usart_p32mz2048ecg124.h"

#elif defined(__32MZ2048ECG144__)
    #include "usart_p32mz2048ecg144.h"

#elif defined(__32MZ2048ECH064__)
    #include "usart_p32mz2048ech064.h"

#elif defined(__32MZ2048ECH100__)
    #include "usart_p32mz2048ech100.h"

#elif defined(__32MZ2048ECH124__)
    #include "usart_p32mz2048ech124.h"

#elif defined(__32MZ2048ECH144__)
    #include "usart_p32mz2048ech144.h"

#elif defined(__32MZ2048ECM064__)
    #include "usart_p32mz2048ecm064.h"

#elif defined(__32MZ2048ECM100__)
    #include "usart_p32mz2048ecm100.h"

#elif defined(__32MZ2048ECM124__)
    #include "usart_p32mz2048ecm124.h"

#elif defined(__32MZ2048ECM144__)
    #include "usart_p32mz2048ecm144.h"


#elif defined(__32MZ0512EFE064__)
    #include "usart_p32mz0512efe064.h"

#elif defined(__32MZ0512EFF064__)
    #include "usart_p32mz0512eff064.h"

#elif defined(__32MZ0512EFK064__)
    #include "usart_p32mz0512efk064.h"

#elif defined(__32MZ0512EFE100__)
    #include "usart_p32mz0512efe100.h"
	
#elif defined(__32MZ0512EFF100__)
    #include "usart_p32mz0512eff100.h"
	
#elif defined(__32MZ0512EFK100__)
    #include "usart_p32mz0512efk100.h"

#elif defined(__32MZ0512EFE124__)
    #include "usart_p32mz0512efe124.h"

#elif defined(__32MZ0512EFF124__)
    #include "usart_p32mz0512eff124.h"

#elif defined(__32MZ0512EFK124__)
    #include "usart_p32mz0512efk124.h"
	
#elif defined(__32MZ0512EFE144__)
    #include "usart_p32mz0512efe144.h"

#elif defined(__32MZ0512EFF144__)
    #include "usart_p32mz0512eff144.h"

#elif defined(__32MZ0512EFK144__)
    #include "usart_p32mz0512efk144.h"
	
#elif defined(__32MZ1024EFE064__)
    #include "usart_p32mz1024efe064.h"
	
#elif defined(__32MZ1024EFF064__)
    #include "usart_p32mz1024eff064.h"

#elif defined(__32MZ1024EFK064__)
    #include "usart_p32mz1024efk064.h"

#elif defined(__32MZ1024EFE100__)
    #include "usart_p32mz1024efe100.h"

#elif defined(__32MZ1024EFF100__)
    #include "usart_p32mz1024eff100.h"
	
#elif defined(__32MZ1024EFK100__)
    #include "usart_p32mz1024efk100.h"

#elif defined(__32MZ1024EFE124__)
    #include "usart_p32mz1024efe124.h"

#elif defined(__32MZ1024EFF124__)
    #include "usart_p32mz1024eff124.h"
	
#elif defined(__32MZ1024EFK124__)
    #include "usart_p32mz1024efk124.h"
	
#elif defined(__32MZ1024EFE144__)
    #include "usart_p32mz1024efe144.h"

#elif defined(__32MZ1024EFF144__)
    #include "usart_p32mz1024eff144.h"

#elif defined(__32MZ1024EFK144__)
    #include "usart_p32mz1024efk144.h"

#elif defined(__32MZ1024EFG064__)
    #include "usart_p32mz1024efg064.h"
	
#elif defined(__32MZ1024EFH064__)
    #include "usart_p32mz1024efh064.h"

#elif defined(__32MZ1024EFM064__)
    #include "usart_p32mz1024efm064.h"

#elif defined(__32MZ1024EFG100__)
    #include "usart_p32mz1024efg100.h"
	
#elif defined(__32MZ1024EFH100__)
    #include "usart_p32mz1024efh100.h"
	
#elif defined(__32MZ1024EFM100__)
    #include "usart_p32mz1024efm100.h"

#elif defined(__32MZ1024EFG124__)
    #include "usart_p32mz1024efg124.h"

#elif defined(__32MZ1024EFH124__)
    #include "usart_p32mz1024efh124.h"

#elif defined(__32MZ1024EFM124__)
    #include "usart_p32mz1024efm124.h"
	
#elif defined(__32MZ1024EFG144__)
    #include "usart_p32mz1024efg144.h"

#elif defined(__32MZ1024EFH144__)
    #include "usart_p32mz1024efh144.h"

#elif defined(__32MZ1024EFM144__)
    #include "usart_p32mz1024efm144.h"
	
#elif defined(__32MZ2048EFG064__)
    #include "usart_p32mz2048efg064.h"
	
#elif defined(__32MZ2048EFH064__)
    #include "usart_p32mz2048efh064.h"

#elif defined(__32MZ2048EFM064__)
    #include "usart_p32mz2048efm064.h"

#elif defined(__32MZ2048EFG100__)
    #include "usart_p32mz2048efg100.h"

#elif defined(__32MZ2048EFH100__)
    #include "usart_p32mz2048efh100.h"
	
#elif defined(__32MZ2048EFM100__)
    #include "usart_p32mz2048efm100.h"

#elif defined(__32MZ2048EFG124__)
    #include "usart_p32mz2048efg124.h"

#elif defined(__32MZ2048EFH124__)
    #include "usart_p32mz2048efh124.h"
	
#elif defined(__32MZ2048EFM124__)
    #include "usart_p32mz2048efm124.h"
	
#elif defined(__32MZ2048EFG144__)
    #include "usart_p32mz2048efg144.h"

#elif defined(__32MZ2048EFH144__)
    #include "usart_p32mz2048efh144.h"

#elif defined(__32MZ2048EFM144__)
    #include "usart_p32mz2048efm144.h"	

#elif defined(__32MZ1025DAA169__)
    #include "usart_p32mz1025daa169.h"

#elif defined(__32MZ1025DAA176__)
    #include "usart_p32mz1025daa176.h"

#elif defined(__32MZ1025DAA288__)
    #include "usart_p32mz1025daa288.h"

#elif defined(__32MZ1025DAB169__)
    #include "usart_p32mz1025dab169.h"

#elif defined(__32MZ1025DAB176__)
    #include "usart_p32mz1025dab176.h"

#elif defined(__32MZ1025DAB288__)
    #include "usart_p32mz1025dab288.h"

#elif defined(__32MZ1025DAG169__)
    #include "usart_p32mz1025dag169.h"

#elif defined(__32MZ1025DAG176__)
    #include "usart_p32mz1025dag176.h"

#elif defined(__32MZ1025DAH169__)
    #include "usart_p32mz1025dah169.h"

#elif defined(__32MZ1025DAH176__)
    #include "usart_p32mz1025dah176.h"

#elif defined(__32MZ1064DAA169__)
    #include "usart_p32mz1064daa169.h"

#elif defined(__32MZ1064DAA176__)
    #include "usart_p32mz1064daa176.h"

#elif defined(__32MZ1064DAA288__)
    #include "usart_p32mz1064daa288.h"

#elif defined(__32MZ1064DAB169__)
    #include "usart_p32mz1064dab169.h"

#elif defined(__32MZ1064DAB176__)
    #include "usart_p32mz1064dab176.h"

#elif defined(__32MZ1064DAB288__)
    #include "usart_p32mz1064dab288.h"

#elif defined(__32MZ1064DAG169__)
    #include "usart_p32mz1064dag169.h"

#elif defined(__32MZ1064DAG176__)
    #include "usart_p32mz1064dag176.h"

#elif defined(__32MZ1064DAH169__)
    #include "usart_p32mz1064dah169.h"

#elif defined(__32MZ1064DAH176__)
    #include "usart_p32mz1064dah176.h"

#elif defined(__32MZ2025DAA169__)
    #include "usart_p32mz2025daa169.h"

#elif defined(__32MZ2025DAA176__)
    #include "usart_p32mz2025daa176.h"

#elif defined(__32MZ2025DAA288__)
    #include "usart_p32mz2025daa288.h"

#elif defined(__32MZ2025DAB169__)
    #include "usart_p32mz2025dab169.h"

#elif defined(__32MZ2025DAB176__)
    #include "usart_p32mz2025dab176.h"

#elif defined(__32MZ2025DAB288__)
    #include "usart_p32mz2025dab288.h"

#elif defined(__32MZ2025DAG169__)
    #include "usart_p32mz2025dag169.h"

#elif defined(__32MZ2025DAG176__)
    #include "usart_p32mz2025dag176.h"

#elif defined(__32MZ2025DAH169__)
    #include "usart_p32mz2025dah169.h"

#elif defined(__32MZ2025DAH176__)
    #include "usart_p32mz2025dah176.h"

#elif defined(__32MZ2064DAA169__)
    #include "usart_p32mz2064daa169.h"

#elif defined(__32MZ2064DAA176__)
    #include "usart_p32mz2064daa176.h"

#elif defined(__32MZ2064DAA288__)
    #include "usart_p32mz2064daa288.h"

#elif defined(__32MZ2064DAB169__)
    #include "usart_p32mz2064dab169.h"

#elif defined(__32MZ2064DAB176__)
    #include "usart_p32mz2064dab176.h"

#elif defined(__32MZ2064DAB288__)
    #include "usart_p32mz2064dab288.h"

#elif defined(__32MZ2064DAG169__)
    #include "usart_p32mz2064dag169.h"

#elif defined(__32MZ2064DAG176__)
    #include "usart_p32mz2064dag176.h"

#elif defined(__32MZ2064DAH169__)
    #include "usart_p32mz2064dah169.h"

#elif defined(__32MZ2064DAH176__)
    #include "usart_p32mz2064dah176.h"
    
/* MX */
#elif defined(__32MX120F064H__)
    #include "usart_p32mx120f064h.h"

#elif defined(__32MX130F128H__)
    #include "usart_p32mx130f128h.h"

#elif defined(__32MX130F128L__)
    #include "usart_p32mx130f128l.h"

#elif defined(__32MX230F128H__)
    #include "usart_p32mx230f128h.h"

#elif defined(__32MX230F128L__)
    #include "usart_p32mx230f128l.h"
	
#elif defined(__32MX530F128H__)
    #include "usart_p32mx530f128h.h"

#elif defined(__32MX530F128L__)
    #include "usart_p32mx530f128l.h"

#elif defined(__32MX150F256H__)
    #include "usart_p32mx150f256h.h"

#elif defined(__32MX150F256L__)
    #include "usart_p32mx150f256l.h"

#elif defined(__32MX250F256H__)
    #include "usart_p32mx250f256h.h"

#elif defined(__32MX250F256L__)
    #include "usart_p32mx250f256l.h"

#elif defined(__32MX550F256H__)
    #include "usart_p32mx550f256h.h"

#elif defined(__32MX550F256L__)
    #include "usart_p32mx550f256l.h"

#elif defined(__32MX170F512H__)
    #include "usart_p32mx170f512h.h"

#elif defined(__32MX170F512L__)
    #include "usart_p32mx170f512l.h"
	
#elif defined(__32MX270F512H__)
    #include "usart_p32mx270f512h.h"

#elif defined(__32MX270F512L__)
    #include "usart_p32mx270f512l.h"

#elif defined(__32MX570F512H__)
    #include "usart_p32mx570f512h.h"
    
#elif defined(__32MX570F512L__)
    #include "usart_p32mx570f512l.h"
    
    
#elif defined(__32MX110F016B__)
    #include "usart_p32mx110f016b.h"

#elif defined(__32MX110F016C__)
    #include "usart_p32mx110f016c.h"

#elif defined(__32MX110F016D__)
    #include "usart_p32mx110f016d.h"

#elif defined(__32MX120F032B__)
    #include "usart_p32mx120f032b.h"

#elif defined(__32MX120F032C__)
    #include "usart_p32mx120f032c.h"

#elif defined(__32MX120F032D__)
    #include "usart_p32mx120f032d.h"
	
#elif defined(__32MX130F064B__)
    #include "usart_p32mx130f064b.h"

#elif defined(__32MX130F064C__)
    #include "usart_p32mx130f064c.h"

#elif defined(__32MX130F064D__)
    #include "usart_p32mx130f064d.h"

#elif defined(__32MX150F128B__)
    #include "usart_p32mx150f128b.h"

#elif defined(__32MX150F128C__)
    #include "usart_p32mx150f128c.h"

#elif defined(__32MX150F128D__)
    #include "usart_p32mx150f128d.h"

#elif defined(__32MX170F256B__)
    #include "usart_p32mx170f256b.h"

#elif defined(__32MX170F256D__)
    #include "usart_p32mx170f256d.h"

#elif defined(__32MX270F256B__)
    #include "usart_p32mx270f256b.h"

#elif defined(__32MX270F256D__)
    #include "usart_p32mx270f256d.h"
	
#elif defined(__32MX210F016B__)
    #include "usart_p32mx210f016b.h"

#elif defined(__32MX210F016C__)
    #include "usart_p32mx210f016c.h"

#elif defined(__32MX210F016D__)
    #include "usart_p32mx210f016d.h"

#elif defined(__32MX220F032B__)
    #include "usart_p32mx220f032b.h"

#elif defined(__32MX220F032C__)
    #include "usart_p32mx220f032c.h"

#elif defined(__32MX220F032D__)
    #include "usart_p32mx220f032d.h"
	
#elif defined(__32MX230F064B__)
    #include "usart_p32mx230f064b.h"

#elif defined(__32MX230F064C__)
    #include "usart_p32mx230f064c.h"

#elif defined(__32MX230F064D__)
    #include "usart_p32mx230f064d.h"

#elif defined(__32MX250F128B__)
    #include "usart_p32mx250f128b.h"

#elif defined(__32MX250F128C__)
    #include "usart_p32mx250f128c.h"

#elif defined(__32MX250F128D__)
    #include "usart_p32mx250f128d.h"

#elif defined(__32MX130F256B__)
    #include "usart_p32mx130f256b.h"

#elif defined(__32MX130F256D__)
    #include "usart_p32mx130f256d.h"

#elif defined(__32MX230F256B__)
    #include "usart_p32mx230f256b.h"

#elif defined(__32MX230F256D__)
    #include "usart_p32mx230f256d.h"
    
    
#elif defined(__32MX320F032H__)
    #include "usart_p32mx320f032h.h"

#elif defined(__32MX320F064H__)
    #include "usart_p32mx320f064h.h"

#elif defined(__32MX320F128H__)
    #include "usart_p32mx320f128h.h"

#elif defined(__32MX320F128L__)
    #include "usart_p32mx320f128l.h"

#elif defined(__32MX330F064H__)
    #include "usart_p32mx330f064h.h"

#elif defined(__32MX330F064L__)
    #include "usart_p32mx330f064l.h"

#elif defined(__32MX340F128H__)
    #include "usart_p32mx340f128h.h"

#elif defined(__32MX340F128L__)
    #include "usart_p32mx340f128l.h"

#elif defined(__32MX340F256H__)
    #include "usart_p32mx340f256h.h"

#elif defined(__32MX340F512H__)
    #include "usart_p32mx340f512h.h"

#elif defined(__32MX350F128H__)
    #include "usart_p32mx350f128h.h"

#elif defined(__32MX350F128L__)
    #include "usart_p32mx350f128l.h"

#elif defined(__32MX350F256H__)
    #include "usart_p32mx350f256h.h"

#elif defined(__32MX350F256L__)
    #include "usart_p32mx350f256l.h"

#elif defined(__32MX360F256L__)
    #include "usart_p32mx360f256l.h"

#elif defined(__32MX360F512L__)
    #include "usart_p32mx360f512l.h"

#elif defined(__32MX370F512H__)
    #include "usart_p32mx370f512h.h"
	
#elif defined(__32MX370F512L__)
    #include "usart_p32mx370f512l.h"

#elif defined(__32MX420F032H__)
    #include "usart_p32mx420f032h.h"

#elif defined(__32MX430F064H__)
    #include "usart_p32mx430f064h.h"

#elif defined(__32MX430F064L__)
    #include "usart_p32mx430f064l.h"

#elif defined(__32MX440F128H__)
    #include "usart_p32mx440f128h.h"

#elif defined(__32MX440F128L__)
    #include "usart_p32mx440f128l.h"

#elif defined(__32MX440F256H__)
    #include "usart_p32mx440f256h.h"

#elif defined(__32MX440F512H__)
    #include "usart_p32mx440f512h.h"

#elif defined(__32MX450F128H__)
    #include "usart_p32mx450f128h.h"

#elif defined(__32MX450F128L__)
    #include "usart_p32mx450f128l.h"

#elif defined(__32MX450F256H__)
    #include "usart_p32mx450f256h.h"

#elif defined(__32MX450F256L__)
    #include "usart_p32mx450f256l.h"

#elif defined(__32MX460F256L__)
    #include "usart_p32mx460f256l.h"

#elif defined(__32MX460F512L__)
    #include "usart_p32mx460f512l.h"

#elif defined(__32MX470F512H__)
    #include "usart_p32mx470f512h.h"
	
#elif defined(__32MX470F512L__)
    #include "usart_p32mx470f512l.h"

	
#elif defined(__32MX534F064H__)
    #include "usart_p32mx534f064h.h"

#elif defined(__32MX534F064L__)
    #include "usart_p32mx534f064l.h"

#elif defined(__32MX564F064H__)
    #include "usart_p32mx564f064h.h"

#elif defined(__32MX564F064L__)
    #include "usart_p32mx564f064l.h"

#elif defined(__32MX564F128H__)
    #include "usart_p32mx564f128h.h"

#elif defined(__32MX564F128L__)
    #include "usart_p32mx564f128l.h"

#elif defined(__32MX575F256H__)
    #include "usart_p32mx575f256h.h"

#elif defined(__32MX575F256L__)
    #include "usart_p32mx575f256l.h"

#elif defined(__32MX575F512H__)
    #include "usart_p32mx575f512h.h"

#elif defined(__32MX575F512L__)
    #include "usart_p32mx575f512l.h"

#elif defined(__32MX664F064H__)
    #include "usart_p32mx664f064h.h"

#elif defined(__32MX664F064L__)
    #include "usart_p32mx664f064l.h"

#elif defined(__32MX664F128H__)
    #include "usart_p32mx664f128h.h"

#elif defined(__32MX664F128L__)
    #include "usart_p32mx664f128l.h"

#elif defined(__32MX675F256H__)
    #include "usart_p32mx675f256h.h"

#elif defined(__32MX675F256L__)
    #include "usart_p32mx675f256l.h"

#elif defined(__32MX675F512H__)
    #include "usart_p32mx675f512h.h"

#elif defined(__32MX675F512L__)
    #include "usart_p32mx675f512l.h"

#elif defined(__32MX695F512H__)
    #include "usart_p32mx695f512h.h"

#elif defined(__32MX695F512L__)
    #include "usart_p32mx695f512l.h"

#elif defined(__32MX764F128H__)
    #include "usart_p32mx764f128h.h"

#elif defined(__32MX764F128L__)
    #include "usart_p32mx764f128l.h"

#elif defined(__32MX775F256H__)
    #include "usart_p32mx775f256h.h"

#elif defined(__32MX775F256L__)
    #include "usart_p32mx775f256l.h"

#elif defined(__32MX775F512H__)
    #include "usart_p32mx775f512h.h"

#elif defined(__32MX775F512L__)
    #include "usart_p32mx775f512l.h"

#elif defined(__32MX795F512H__)
    #include "usart_p32mx795f512h.h"

#elif defined(__32MX795F512L__)
    #include "usart_p32mx795f512l.h"

#elif defined(__32WK2057GPB132__)
    #include "usart_p32wk2057gpb132.h"
	
#elif defined(__32WK2057GPD132__)
    #include "usart_p32wk2057gpd132.h"	
	
#elif defined(__32MXGENERIC__)
    #include "usart_p32mxgeneric.h"

#elif defined(__32M4KCORE__)
    #include "usart_p32m4kcore.h"

#else
    #error Unknown processor!
#endif

#endif // _USART_P32XXXX_H


/*******************************************************************************
 End of File
 */
