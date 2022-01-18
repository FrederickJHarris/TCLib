// Removing A Substring From A String With String::Remove().
// cl Demo14.cpp Strings.cpp /O1 /Os /GS- TCLib.lib user32.lib
// cl Demo14.cpp Strings.cpp /O1 /Os /MT user32.lib
// 5,120 Bytes With INTEGRAL_CONVERSIONS, FLOATING_POINT_CONVERSIONS, And FORMATTING Remmed Out
// 5,632 Bytes With Full String Class
// 5,120 Bytes VC15 (VS 2008) x64 Full String Class
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
 String s1=_T("C++ Can Be A Real Pain In The Butt To Learn!");
 s1.Print(true);
 String s2=s1.Remove(_T("Real"), true);
 s2.Print(true);
 getchar();
 
 return 0;
}

// Output:
// ============================================
// C++ Can Be A Real Pain In The Butt To Learn!
// C++ Can Be A  Pain In The Butt To Learn!
