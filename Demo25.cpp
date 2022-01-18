// Another Example Of C++ Str() -- Replacement For PowerBASIC Str$().
// cl Demo25.cpp Strings.cpp /O1 /Os /GS- TCLib.lib user32.lib
// cl Demo25.cpp Strings.cpp /O1 /Os /MT user32.lib
// 5,120 bytes VC15 (VStudio 2008) x64 UNICODE
// 5,632 bytes VC19 (VStudio 2015) x64 UNICODE
#define TCLib
#define  UNICODE
#define  _UNICODE
#include <windows.h>
#ifdef TCLib
   #include "stdio.h"
#else
   #include <stdio.h>
#endif
#include "tchar.h"
#include "Strings.h"

int _tmain()
{
 int iPlot,iTree,iSpecies;
 
 iPlot=12, iTree=1, iSpecies=300;
 if(!iSpecies)
 { 
    String s1 = _T("Plot #") + Str(iPlot) + _T(" Tree #") + Str(iTree) + _T(" Species Equals Zero!");
    s1.Print(_T("Error Message!  "),true);
 }
 else
 { 
    _tprintf(_T("No Errors!\n")); 
    String s1 = _T("Plot #") + Str(iPlot) + _T(" Tree #") + Str(iTree) + _T(" Species=") + Str(iSpecies);   
    s1.Print(true);
 }
 getchar();

 return 0;
}

// Output:
// =============
//No Errors!
//Plot #12 Tree #1 Species=300
