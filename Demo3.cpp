// Converting null terminated strings containing numbers to numeric format
// cl Demo3.cpp /O1 /Os /GS- TCLib.lib
// 3,072 bytes VC15 (VS 2008) x64 UNICODE
// 3,584 bytes VC19 (VS 2015) x64 UNICODE  34.57 times smaller than with C Std. Lib.
#define TCLib
#define UNICODE
#define _UNICODE
#include <windows.h>
#ifdef TCLib
   #include "stdio.h"
#else
   #include <stdio.h>
#endif
#include "stdlib.h"
#include "tchar.h"

int main()
{
 TCHAR szBuffer[]=_T("  -1234567898765432");
 _int64 iNum;
 
 iNum=_ttoi64(szBuffer);
 _tprintf(_T("iNum=%Id\n"), iNum);
 iNum=_abs64(iNum);
 _tprintf(_T("iNum=%Id\n"), iNum);
 getchar();

 return 0;
}
// Output:
// ==================
// iNum=-1234567898765432
// iNum=1234567898765432
