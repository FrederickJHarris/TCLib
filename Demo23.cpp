// C++ Replacement For PowerBASIC Str$().
// cl Demo23.cpp Strings.cpp /O1 /Os /GS- /link TCLib.lib user32.lib
// cl Demo23.cpp Strings.cpp /O1 /Os /MT user32.lib
// 5,120 VC15 (VStudio 2008) x64 UNICODE Full String Class
#define TCLib
#define UNICODE
#define _UNICODE
#include <windows.h>
#ifdef TCLib
   #include "stdio.h"
#else
   #include <stdio.h>
#endif
#include "tchar.h"
#include "Strings.h"

int main()
{
 String s1 = _T("Pi = ") + Str(3.14159);
 s1.Print(true);
 getchar();
 
 return 0;
}

// Output:
// =============
// Pi = 3.141590
