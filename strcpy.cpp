//=====================================================================================
//               Developed As An Addition To Matt Pietrek's LibCTiny.lib
//                            By Fred Harris, January 2016
//
//                      cl strcpy.cpp /c /W3 /DWIN32_LEAN_AND_MEAN
//=====================================================================================
#include <windows.h>
#include <string.h>

char* __cdecl strcpy(char* strDestination, const char* strSource)
{
 return lstrcpyA(strDestination, strSource);
}

wchar_t* __cdecl wcscpy(wchar_t* strDestination, const wchar_t* strSource)
{
 return lstrcpyW(strDestination, strSource);
}
