// stdlib.h
#ifndef stdlib_h
#define stdlib_h
   #define NULL 0 
   extern "C" void*    __cdecl malloc  (size_t          size);
   extern "C" void     __cdecl free    (void*           pMem);
   extern "C" long     __cdecl atol    (const char*     pStr);
   extern "C" int      __cdecl atoi    (const char*     pStr);
   extern "C" long     __cdecl _wtol   (const wchar_t*  pStr);
   extern "C" int      __cdecl _wtoi   (const wchar_t*  pStr);
   extern "C" _int64   __cdecl _atoi64 (const char*     pStr);
   extern "C" _int64   __cdecl _wtoi64 (const wchar_t*  pStr);
   extern "C" double   __cdecl atof    (const char*     pStr);
   extern "C" double   __cdecl _wtof   (const wchar_t*  pStr);
   extern "C" int      __cdecl abs     (int             n);
   extern "C" long     __cdecl labs    (long            n);
   extern "C" _int64   __cdecl _abs64  (__int64         n);
   //extern "C" char*    __cdecl itoa    (int             iNumber, char*      pszBuffer, int radix);
   //extern "C" wchar_t* __cdecl _itow   (int             iNumber, wchar_t*   pszBuffer, int radix);
   //extern "C" char*    __cdecl _i64toa (_int64          iNumber, char*      pszBuffer, int radix);
   //extern "C" wchar_t* __cdecl _i64tow (_int64          iNumber, wchar_t*   pszBuffer, int radix);
   //extern "C" char*    __cdecl _ui64toa(unsigned _int64 iNumber, char*      pszBuffer, int radix);
   //extern "C" wchar_t* __cdecl _ui64tow(unsigned _int64 iNumber, wchar_t*   pszBuffer, int radix);
#endif
