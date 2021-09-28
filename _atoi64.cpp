//==============================================================================================
//               Developed As An Addition To Matt Pietrek's LibCTiny.lib
//                             By Fred Harris, March 2016
//
//       cl _atoi64.cpp /D "_CRT_SECURE_NO_WARNINGS" /c /W3 /DWIN32_LEAN_AND_MEAN 
//==============================================================================================
#include "stdlib.h"


_int64 __cdecl _atoi64(const char* pStr)
{
 char c,cNeg=NULL;           // c holds the char; cNeg holds the '-' sign.
 _int64 lTotal=0;            // The running total.

 while(*pStr==32 || *pStr==8)
    pStr++;  
 if(*pStr=='-')
 { 
    cNeg='-';
    pStr++;
 }
 while(*pStr)
 { 
    if(*pStr>=48 && *pStr<=57)
    {
       c=*pStr++;
       lTotal=10*lTotal+(c-48); // Add this digit to the total.
    }
    else
       break;
 }
 if(cNeg=='-')               // If we have a negative sign, convert the value.
    lTotal=-lTotal; 
 
 return lTotal; 
}


_int64 __cdecl _wtoi64(const wchar_t* pStr)
{
 wchar_t c,cNeg=NULL;        // c holds the char; cNeg holds the '-' sign.
 _int64 lTotal=0;            // The running total.

 while(*pStr==32 || *pStr==8)
    pStr++;  
 if(*pStr==L'-')
 { 
    cNeg=L'-';
    pStr++;
 }
 while(*pStr)
 { 
    if(*pStr>=48 && *pStr<=57)
    {
       c=*pStr++;
       lTotal=10*lTotal+(c-48); // Add this digit to the total.
    }
    else
       break;
 }
 if(cNeg==L'-')              // If we have a negative sign, convert the value.
    lTotal=-lTotal; 
 
 return lTotal; 
} 