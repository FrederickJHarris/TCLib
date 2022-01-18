// Removing Individual Characters From String Object With String::Remove().
// cl Demo13.cpp Strings.cpp /O1 /Os /GS- TCLib.lib user32.lib
// cl Demo13.cpp Strings.cpp /O1 /Os /MT user32.lib
// 4,096 Bytes With INTEGRAL_CONVERSIONS, FLOATING_POINT_CONVERSIONS, And FORMATTING Remmed Out 
// 4,608 Bytes VC15 (VS 2008) x64 With Full String Class
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
 String s1=_T("abcdefghijklmnopqrstuvwxyz");
 String s2=_T("aeiou");
 String s3=s1.Remove(s2.lpStr());
 s1.Print(true);
 s3.Print(true);
 getchar();
 
 return 0;
}

// Output:
// ==========================
// abcdefghijklmnopqrstuvwxyz
// bcdfghjklmnpqrstvwxyz
