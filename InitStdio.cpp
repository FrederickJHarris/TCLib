//=========================================================================================================
//                                             InitStdio.cpp
//                                         Fred Harris, June 2016
//
//         cl InitStdio.cpp /D "_CRT_SECURE_NO_WARNINGS" /O1 /Os /GS- /c /W3 /DWIN32_LEAN_AND_MEAN 
//=========================================================================================================
#include <windows.h>

struct      FILE 
{
 char*      _ptr;
 int        _cnt;
 char*      _base;		
 int        _flag;
 int        _file;
 int        _charbuf;
 int        _bufsiz;
 char*      _tmpfname;
};

extern "C"  void InitStdio(HINSTANCE hLib);

//          From stdio.h                      Function Pointer Prototypes
FILE*       _iob;
char        (__cdecl* getchar        )(                                               );
FILE*       (__cdecl* fopen          )(const char* pszFile, const char* pszMode       );
FILE*       (__cdecl* _wfopen        )(const wchar_t* pszFile, const wchar_t* pszMode );
int         (__cdecl* fseek          )(FILE* stream, long offset, int origin          ); 
int         (__cdecl* _open_osfhandle)(intptr_t osfhandle, int flags                  );
FILE*       (__cdecl* _fdopen        )(int FileDescriptor, const char* mode           );
int         (__cdecl* feof           )(FILE* stream                                   );
int         (__cdecl* printf         )(const char* pFormat, ...                       );
int         (__cdecl* wprintf        )(const wchar_t* pFormat, ...                    );
int         (__cdecl* fprintf        )(FILE* fp, const char* format, ...              );
int         (__cdecl* fwprintf       )(FILE* fp, const wchar_t* format, ...           );
int         (__cdecl* fscanf         )(FILE* fp, const char* pFormat, ...             );
int         (__cdecl* fwscanf        )(FILE* fp, const wchar_t* pFormat, ...          );
int         (__cdecl* sprintf        )(char* buffer, const char* format, ...          );
int         (__cdecl* swprintf       )(wchar_t* buffer, const wchar_t* format, ...    );
char*       (__cdecl* fgets          )(char* pBuffer, int iSize, FILE* fp             );
wchar_t*    (__cdecl* fgetws         )(wchar_t* pBuffer, int iSize, FILE* fp          );
void        (__cdecl* rewind         )(FILE* fp                                       );
int         (__cdecl* fclose         )(FILE* fp                                       );

void InitStdio(HINSTANCE hLib)
{
 //              From stdio.h       Function Pointer Initializations/Assignments
 _iob            = (FILE*)                                                               GetProcAddress(hLib,"_iob"           );          
 getchar         = (char     (__cdecl*)(                                              )) GetProcAddress(hLib,"getchar"        );
 fopen           = (FILE*    (__cdecl*)(const char* pszFile, const char* pszMode      )) GetProcAddress(hLib,"fopen"          );
 fseek           = (int      (__cdecl*)(FILE* stream, long offset, int origin         )) GetProcAddress(hLib,"fseek"          );
 _wfopen         = (FILE*    (__cdecl*)(const wchar_t* pszFile, const wchar_t* pszMode)) GetProcAddress(hLib,"_wfopen"        );
 _open_osfhandle = (int      (__cdecl*)(intptr_t osfhandle, int flags                 )) GetProcAddress(hLib,"_open_osfhandle");
 _fdopen         = (FILE*    (__cdecl*)(int, const char* mode                         )) GetProcAddress(hLib,"_fdopen"        );
 feof            = (int      (__cdecl*)(FILE* stream                                  )) GetProcAddress(hLib,"feof"           );
 printf          = (int      (__cdecl*)(const char* pFormat,    ...                   )) GetProcAddress(hLib,"printf"         );
 wprintf         = (int      (__cdecl*)(const wchar_t* pFormat, ...                   )) GetProcAddress(hLib,"wprintf"        );
 fprintf         = (int      (__cdecl*)(FILE* fp, const char* format, ...             )) GetProcAddress(hLib,"fprintf"        );
 fwprintf        = (int      (__cdecl*)(FILE* fp, const wchar_t* format, ...          )) GetProcAddress(hLib,"fwprintf"       );
 fscanf          = (int      (__cdecl*)(FILE* fp, const char* pFmt, ...               )) GetProcAddress(hLib,"fscanf"         );
 fwscanf         = (int      (__cdecl*)(FILE* fp, const wchar_t* pFmt, ...            )) GetProcAddress(hLib,"fwscanf"        );
 sprintf         = (int      (__cdecl*)(char* buffer, const char* pFormat, ...        )) GetProcAddress(hLib,"sprintf"        );
 swprintf        = (int      (__cdecl*)(wchar_t* buffer, const wchar_t* pFormat, ...  )) GetProcAddress(hLib,"swprintf"       );
 fgets           = (char*    (__cdecl*)(char* pBuffer, int iSize, FILE* fp            )) GetProcAddress(hLib,"fgets"          );
 fgetws          = (wchar_t* (__cdecl*)(wchar_t* pBuffer, int iSize, FILE* fp         )) GetProcAddress(hLib,"fgetws"         );
 rewind          = (void     (__cdecl*)(FILE* fp                                      )) GetProcAddress(hLib,"rewind"         );
 fclose          = (int      (__cdecl*)(FILE* fp                                      )) GetProcAddress(hLib,"fclose"         );
}