// cl allocsup.cpp /O1 /Os /GS- /c /W3 /DWIN32_LEAN_AND_MEAN
#include <windows.h>
#include "malloc.h"

void* __cdecl _nh_malloc(size_t size, int nhFlag)
{
 return HeapAlloc(GetProcessHeap(), 0, size);
}

size_t __cdecl _msize(void* pMem)
{
 return HeapSize(GetProcessHeap(), 0, pMem);
}
