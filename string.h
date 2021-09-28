// string.h
#ifndef string_h
#define string_h

#define wcsrchr _wcsrchr
#define strrchr _strrchr     

extern "C" size_t   __cdecl strlen(const char* pStr);
extern "C" size_t   __cdecl wcslen(const wchar_t* pStr);

extern "C" char*    __cdecl strcpy(char* strDestination, const char* strSource);
extern "C" wchar_t* __cdecl wcscpy(wchar_t* strDestination, const wchar_t* strSource);

extern "C" char*    __cdecl strcat(char* strDest, const char* strSource);
extern "C" wchar_t* __cdecl wcscat(wchar_t* strDest, const wchar_t* strSource); 

extern "C" char*    __cdecl strncpy(char* strDest, const char* strSource, size_t iCount);   
extern "C" wchar_t* __cdecl wcsncpy(wchar_t* strDest, const wchar_t* strSource, size_t iCount);  

extern "C" int      __cdecl strcmp(const char* string1, const char* string2);
extern "C" int      __cdecl wcscmp(const wchar_t* string1, const wchar_t* string2);

extern "C" int      __cdecl _stricmp(const char* string1, const char* string2);   
extern "C" int      __cdecl _wcsicmp(const wchar_t* string1, const wchar_t* string2);  

extern "C" int      __cdecl strncmp(const char* str1, const char* str2, size_t count);
extern "C" int      __cdecl wcsncmp(const wchar_t* str1, const wchar_t* str2, size_t count); 

extern "C" int      __cdecl _strnicmp(const char* str1, const char* str2, size_t count);
extern "C" int      __cdecl _wcsnicmp(const wchar_t* str1, const wchar_t* str2, size_t count);

extern "C" char*    __cdecl _strrchr(const char* string, int c);
extern "C" wchar_t* __cdecl _wcsrchr(const wchar_t* string, int c);

extern "C" char*    __cdecl _strchr(const char* s, int c);
extern "C" wchar_t* __cdecl _wcschr(const wchar_t* s, int c);

extern "C" char*    __cdecl _strrev(char* pStr); 
extern "C" wchar_t* __cdecl _wcsrev(wchar_t* pStr);

#endif
