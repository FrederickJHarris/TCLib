// cl alloc2.cpp /O1 /Os /GS- /c /W3 /DWIN32_LEAN_AND_MEAN
#include <windows.h>
#include "malloc.h"

void* __cdecl realloc(void* pMem, size_t size)
{
 if(pMem)
    return HeapReAlloc(GetProcessHeap(), 0, pMem, size);
 else 
    return HeapAlloc(GetProcessHeap(), 0, size);
}

void* __cdecl calloc(size_t nitems, size_t size)
{
 return HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, nitems * size);
}
