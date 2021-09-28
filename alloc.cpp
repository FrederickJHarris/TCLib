// cl alloc.cpp /O1 /Os /GS- /c /W3 /DWIN32_LEAN_AND_MEAN
#include <windows.h>
#include "malloc.h"

void* __cdecl malloc(size_t size)
{
 return HeapAlloc(GetProcessHeap(), 0, size);
}

void __cdecl free(void* pMem)
{
 HeapFree(GetProcessHeap(), 0, pMem);
}
