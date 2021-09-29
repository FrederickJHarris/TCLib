// String Replacements Where The Original String Grows; String::Replace().
// cl Demo17.cpp Strings.cpp /O1 /Os /GS- /Zc:sizedDealloc- TCLib.lib kernel32.lib user32.lib
// cl Demo17.cpp Strings.cpp /O1 /Os /GS- TCLib.lib kernel32.lib user32.lib
// 5,632 Bytes With INTEGRAL_CONVERSIONS, FLOATING_POINT_CONVERSIONS, And FORMATTING Remmed Out
// 6,144 Bytes With Full String Class
// 5,120 Bytes VC15 (VS 2008) x64 UNICODE
#define UNICODE
#define _UNICODE
#include <windows.h>
#include "stdlib.h"
#include "stdio.h"
#include "tchar.h"
#include "Strings.h"

int main()
{
 String s1=_T("AAAAPPAAAAAAAAAPAAPAAAAAAAAAAPA");
 s1.Print(true);
 String s2=s1.Replace(_T("P"), _T("PUUU"));
 s2.Print(true);
 getchar();
 
 return 0;
}

// Output:
// ==============================================
// AAAAPPAAAAAAAAAPAAPAAAAAAAAAAPA
// AAAAPUUUPUUUAAAAAAAAAPUUUAAPUUUAAAAAAAAAAPUUUA
