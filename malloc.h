// malloc.h
#ifndef malloc_h
#define malloc_h

extern "C" void*  __cdecl malloc     (size_t size                  );
extern "C" void   __cdecl free       (void*  pMem                  );
extern "C" void*  __cdecl realloc    (void*  pMem,   size_t size   );
extern "C" void*  __cdecl calloc     (size_t nitems, size_t size   );
extern "C" void*  __cdecl _nh_malloc (size_t size,   int    nhFlag );
extern "C" size_t __cdecl _msize     (void*  pMem                  );

#endif