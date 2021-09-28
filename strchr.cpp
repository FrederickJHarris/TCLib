//=====================================================================================
//               Developed As An Addition To Matt Pietrek's LibCTiny.lib
//                            By James C. Fuller March 2016
//
//                      cl strchr.cpp /c /W3 /DWIN32_LEAN_AND_MEAN
//=====================================================================================
#include <windows.h>
#include "string.h"

char * __cdecl _strchr (const char *s, int c)
{
    do {
        if (*s == c)
        {
            return (char*)s;
        }
    } while (*s++);
    return (0);
}

wchar_t * __cdecl _wcschr (const wchar_t *s, int c)
{
    do {
        if (*s == c)
        {
            return (wchar_t*)s;
        }
    } while (*s++);
    return (0);
}
