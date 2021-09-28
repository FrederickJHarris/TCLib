//=====================================================================================
//               Developed As An Addition To Matt Pietrek's LibCTiny.lib
//                            By Fred Harris, January 2016
//
//                      cl strlen.cpp /c /W3 /DWIN32_LEAN_AND_MEAN
//=====================================================================================
#include <windows.h>
#include "string.h"

size_t __cdecl strlen(const char* strSource)
{
 return lstrlenA(strSource);
}

size_t __cdecl wcslen(const wchar_t* strSource)
{
 return lstrlenW(strSource);
}
