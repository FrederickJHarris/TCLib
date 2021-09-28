//=====================================================================================
//               Developed As An Addition To Matt Pietrek's LibCTiny.lib
//                            By Fred Harris, January 2016
//
//                      cl strcmp.cpp /c /W3 /DWIN32_LEAN_AND_MEAN
//=====================================================================================
#include <windows.h>
#include "string.h"

int __cdecl strcmp(const char* string1, const char* string2)   
{
 return lstrcmpA(string1,string2);
}

int __cdecl wcscmp(const wchar_t* string1, const wchar_t* string2)   
{
 return lstrcmpW(string1,string2);
}
