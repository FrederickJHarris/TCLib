// Assigning Strings, Constructors and operator=
// cl Demo8.cpp Strings.cpp /O1 /Os /GS- TCLib.lib user32.lib
// cl Demo8.cpp Strings.cpp /O1 /Os user32.lib
// 4,096 Bytes  With INTEGRAL_CONVERSIONS, FLOATING_POINT_CONVERSIONS, And FORMATTING Remmed Out
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
 String s1,s2,s3;
 
 s1=_T('A');
 s2=_T("Hello, World!");
 s3=s2;
 s1.Print(true);
 s2.Print(true);
 s3.Print(true);
 getchar();
 
 return 0;
}

// Output:
// =============
// A
// Hello, World!
// Hello, World!
