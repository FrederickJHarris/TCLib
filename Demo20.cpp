// Comparing Null Terminated Strings The C Way.
// cl Demo20.cpp /O1 /Os /GS- TCLib.lib kernel32.lib user32.lib
// 2,048 bytes x86 ASCII, 2,048 bytes x86 UNICODE VC15
// 3,072 bytes x64 ASCII, 3,072 bytes x64 UNICODE VC19
#define  UNICODE
#define  _UNICODE
#include <windows.h>
#include "stdio.h"
#include "tchar.h"

int _tmain()
{
 TCHAR szName1[]=_T("Fred");
 TCHAR szName2[]=_T("fred");
 
 if(!_tcsicmp(szName1,szName2))
    _tprintf(_T("Strings Are Equal!\n"));
 else
    _tprintf(_T("Strings Are Not Equal!\n")); 
 getchar();

 return 0;
}

// Output:
// =============
// Strings Are Equal!