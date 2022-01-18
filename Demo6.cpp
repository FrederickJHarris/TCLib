// Copy Constructor
// cl Demo6.cpp Strings.cpp /O1 /Os /GS- TCLib.lib user32.lib  
// 3,584 Bytes VC19 x64 With INTEGRAL_CONVERSIONS, FLOATING_POINT_CONVERSIONS, And FORMATTING Remmed Out
// 4,608 Bytes With Full String Class
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
 String s1(_T("Hello, World!"));
 String s2(s1);
 
 s1.Print(true);
 s2.Print(true);
 getchar();
 
 return 0;
}

// Output:
// =============
// Hello, World!
// Hello, World!
