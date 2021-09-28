//=====================================================================================
//               Developed As An Addition To Matt Pietrek's LibCTiny.lib
//                            By Fred Harris, January 2016
//
//                     cl _stricmp.cpp /c /W3 /DWIN32_LEAN_AND_MEAN
//=====================================================================================
#include <windows.h>
#include "string.h"

int __cdecl _stricmp(const char* string1, const char* string2)   
{
 return lstrcmpiA(string1,string2);
}

int __cdecl _wcsicmp(const wchar_t* string1, const wchar_t* string2)   
{
 return lstrcmpiW(string1,string2);
}

