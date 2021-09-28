// tchar.h
#ifndef tchar_h
   #define tchar_h
   #ifdef  _UNICODE
      typedef wchar_t     TCHAR;
      #define _T(x)       L## x
      #define _tmain      wmain
      #define _tWinMain   wWinMain
      #define LPTSTR      LPWSTR
      #define _tfopen     _wfopen
      #define _fgetts     fgetws
      #define _tprintf    wprintf
      #define _ftprintf   fwprintf
      #define _stprintf   swprintf
      #define _ftscanf    fwscanf
      #define _tcslen     wcslen
      #define _tcscpy     wcscpy
      #define _tcscat     wcscat
      #define _tcsncpy    wcsncpy
      #define _tcscmp     wcscmp
      #define _tcsicmp    _wcsicmp
      #define _tcsncmp    wcsncmp
      #define _tcsnicmp   _wcsnicmp
      #define _tcsrev     _wcsrev
      #define _tcsrchr    _wcsrchr
      #define _ttol       _wtol
      #define _ttoi       _wtoi
      #define _ttoi64     _wtoi64
      #define _ttof       _wtof
   #else
      typedef char        TCHAR;
      #define _T(x)       x
      #define _tmain      main
      #define _tWinMain   WinMain
      #define LPTSTR      LPSTR
      #define _tfopen     fopen
      #define _fgetts     fgets
      #define _tprintf    printf
      #define _ftprintf   fprintf
      #define _ftscanf    fscanf
      #define _stprintf   sprintf
      #define _tcslen     strlen
      #define _tcscpy     strcpy
      #define _tcscat     strcat
      #define _tcsncpy    strncpy
      #define _tcscmp     strcmp
      #define _tcsicmp    _stricmp
      #define _tcsncmp    strncmp
      #define _tcsnicmp   _strnicmp
      #define _tcsrev     _strrev
      #define _tcsrchr    _strrchr
      #define _ttol       atol
      #define _ttoi       atoi
      #define _ttoi64     _atoi64
      #define _ttof       atof
   #endif
#endif
