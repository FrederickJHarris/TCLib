// memory.h
#ifndef memory_h
#define memory_h

extern "C" void*     __cdecl memset  (void* p, int c, size_t count);
extern "C" wchar_t*  __cdecl wmemset (wchar_t* p, wchar_t c, size_t count);

#endif
