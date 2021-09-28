//===================================================================
//   Developed As An Addition To Matt Pietrek's LibCTiny.lib
//                By Fred Harris, January 2016
//
//         cl strcat.cpp /c /W3 /DWIN32_LEAN_AND_MEAN
//===================================================================
#include <windows.h>
#include "string.h"

char* __cdecl strcat(char* strDest, const char* strSource)   
{                                           // 3rd param is size_t
 return lstrcatA(strDest, strSource);
}

wchar_t* __cdecl wcscat(wchar_t* strDest, const wchar_t* strSource)   
{                                           // 3rd param is size_t
 return lstrcatW(strDest, strSource);
}
