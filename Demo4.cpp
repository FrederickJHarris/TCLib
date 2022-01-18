// Hello, World Program With String Class
// cl Demo4.cpp Strings.cpp /O1 /Os /GS- TCLib.lib user32.lib
// cl Demo4.cpp Strings.cpp /O1 /Os user32.lib
// 3,584 Bytes VC15 x64 UNICODE With INTEGRAL_CONVERSIONS, FLOATING_POINT_CONVERSIONS, And FORMATTING Remmed Out
// 3,584 Bytes VC19 x64 UNICODE With INTEGRAL_CONVERSIONS, FLOATING_POINT_CONVERSIONS, And FORMATTING Remmed Out  
// 4,096 Bytes VC15 x64 UNICODE Full String Class  
// 4,096 Bytes VC19 x64 With Full String Class
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
#include "stdlib.h"
#include "Strings.h"

int main()
{
 String s1(_T("Hello, World!"));
 
 s1.Print(_T("s1         = "), true);
 _tprintf(_T("s1.lpStr() = %s\n"), s1.lpStr());
 getchar();
 
 return 0;
}



// Output:
// ==========================
// s1         = Hello, World!
// s1.lpStr() = Hello, World!


/*
// cl Test3.cpp /O1 /Os /GS- /EHsc kernel32.lib
// 136,192 bytes
#include <string>
#include <cstdio>
#include <tchar.h>

int main()
{
 std::wstring s1(L"Hello, World!");
 
 wprintf(L"s1.c_str() = %s\n", s1.c_str());
 getchar();
 
 return 0;
}
*/

