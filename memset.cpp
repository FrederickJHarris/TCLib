//=====================================================================================
//               Developed As An Addition To Matt Pietrek's LibCTiny.lib
//                            By Fred Harris, January 2016
//
//                     cl memset.cpp /c /W3 /DWIN32_LEAN_AND_MEAN 
//=====================================================================================
#include "memory.h"

void* __cdecl memset(void* p, int c, size_t count)
{
 char* pCh=(char*)p;
 for(size_t i=0; i<count; i++)
     pCh[i]=(char)c;
 return p;
}

wchar_t* __cdecl wmemset(wchar_t* p, wchar_t c, size_t count)
{
 for(size_t i=0; i<count; i++)
     p[i]=c;
 return p;
}
