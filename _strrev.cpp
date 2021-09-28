//========================================================
// Developed As An Addition To Matt Pietrek's LibCTiny.lib
//              By Fred Harris, January 2016
//
//     cl _strrev.cpp /Oi /c /W3 /DWIN32_LEAN_AND_MEAN 
//========================================================
#include <windows.h>
#include "string.h"

char* __cdecl _strrev(char* pStr)
{
 size_t iLen,iHalf;
 char a,b;

 iLen=strlen(pStr), iHalf=iLen/2;
 for(size_t i=0; i<iHalf; i++)
 {
     a=pStr[i], b=pStr[iLen-i-1];
     pStr[i]=b, pStr[iLen-i-1]=a;
 }

 return pStr;
}

wchar_t* __cdecl _wcsrev(wchar_t* pStr)
{
 size_t iLen,iHalf;
 wchar_t a,b;

 iLen=wcslen(pStr), iHalf=iLen/2;
 for(size_t i=0; i<iHalf; i++)
 {
     a=pStr[i], b=pStr[iLen-i-1];
     pStr[i]=b, pStr[iLen-i-1]=a;
 }

 return pStr;
}
