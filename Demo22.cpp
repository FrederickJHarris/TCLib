// Character Conversions To Numeric Format Stop At First Non-Numeric Character.
// cl Demo22.cpp /O1 /Os /GS- TCLib.lib
// 3,584 bytes VC9 (VStudio 2008) x64 UNICODE
#define TCLib
#define  UNICODE
#define  _UNICODE
#include <windows.h>
#include "stdio.h"
#include "tchar.h"
extern "C" int _fltused=1;

int _tmain()
{
 TCHAR szNumber[]=_T("  3.14159_Fred");
 double dblNumber = 0.0;
 
 dblNumber = _wtof(szNumber);
 _tprintf(_T("dblNumber = %8.5f\n"),dblNumber);
 getchar();

 return 0;
}

// Output:
// =============
// dblNumber =  3.14159