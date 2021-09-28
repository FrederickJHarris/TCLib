// stdio.h
#ifndef stdio_h
#define stdio_h

#define         SEEK_SET  0
#define         SEEK_CUR  1
#define         SEEK_END  2

struct          FILE 
{
 char*          _ptr;
 int            _cnt;
 char*          _base;		
 int            _flag;
 int            _file;
 int            _charbuf;
 int            _bufsiz;
 char*          _tmpfname;
};

extern FILE*    _iob;
extern char     (__cdecl* getchar)();
extern FILE*    (__cdecl* fopen)(const char* pszFile, const char* pszMode);
extern FILE*    (__cdecl* _wfopen)(const wchar_t* pszFile, const wchar_t* pszMode);
extern int      (__cdecl* _open_osfhandle)(intptr_t osfhandle, int flags );
extern FILE*    (__cdecl* _fdopen)(int FileDescriptor, const char* mode);
extern int      (__cdecl* fseek)(FILE* stream, long offset, int origin); 
extern int      (__cdecl* feof)(FILE* stream);
extern int      (__cdecl* printf)(const char* pFormat, ...);
extern int      (__cdecl* wprintf)(const wchar_t* pFormat, ...);
extern int      (__cdecl* fprintf)(FILE* fp, const char* format, ...);
extern int      (__cdecl* fwprintf)(FILE* fp, const wchar_t* format, ...);
extern int      (__cdecl* fscanf)(FILE* fp, const char* pFormat, ...);
extern int      (__cdecl* fwscanf)(FILE* fp, const wchar_t* pFormat, ...);
extern int      (__cdecl* sprintf)(char* buffer, const char* format, ...);
extern int      (__cdecl* swprintf)(wchar_t* buffer, const wchar_t* format, ...);
extern char*    (__cdecl* fgets)(char* pBuffer, int iSize, FILE* fp);
extern wchar_t* (__cdecl* fgetws)(wchar_t* pBuffer, int iSize, FILE* fp);
extern void     (__cdecl* rewind)(FILE* fp);
extern int      (__cdecl* fclose)(FILE* fp);

#endif
