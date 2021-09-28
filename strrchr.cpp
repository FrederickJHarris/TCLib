//=====================================================================================
//               Developed As An Addition To Matt Pietrek's LibCTiny.lib
//                              By Fred Harris, May 2017
//
//                 cl strrchr.cpp /O1 /Os /c /W3 /DWIN32_LEAN_AND_MEAN
//=====================================================================================
#include <windows.h>
#include "string.h"


char* _strrchr(const char* string, int c)
{
 size_t iLen=strlen(string);
 for(size_t i=iLen; i<=iLen; i--)
 {
     if(string[i]==c)
        return (char*)&string[i];      
 }
 
 return NULL;
} 


wchar_t* _wcsrchr(const wchar_t* string, int c)
{
 size_t iLen=wcslen(string);
 for(size_t i=iLen; i<=iLen; i--)
 {
     if(string[i]==c)
        return (wchar_t*)&string[i];      
 }
 
 return NULL;
} 
