//=====================================================================================
//               Developed As An Addition To Matt Pietrek's LibCTiny.lib
//
//                          LIBCTINY -- Matt Pietrek 2001
//                           MSDN Magazine, January 2001
//
//                              With Help From Mike_V
//                       
//                           By Fred Harris, January 2016
//
//                    cl newdel.cpp /GS- /c /W3 /DWIN32_LEAN_AND_MEAN 
//=====================================================================================
#include <windows.h>

void* __cdecl operator new(size_t s)
{
 return HeapAlloc(GetProcessHeap(), 0, s);
}

void  __cdecl operator delete(void* p)
{
 HeapFree(GetProcessHeap(), 0, p);
}

void* operator new [] (size_t s)
{
 return HeapAlloc(GetProcessHeap(), 0, s);
}

void operator delete [] (void* p)
{
 HeapFree(GetProcessHeap(), 0, p);
}
