// Parsing a comma delimited string with String::ParseCount() and String::Parse()
// cl Demo5.cpp Strings.cpp /O1 /Os /GS- TCLib.lib kernel32.lib user32.lib
// cl Demo5.cpp Strings.cpp /O1 /Os user32.lib
// g++ Demo5.cpp Strings.cpp -oDemo5_gcc.exe -mconsole -s -Os
// 4,096 Bytes With INTEGRAL_CONVERSIONS, FLOATING_POINT_CONVERSIONS, And FORMATTING Remmed Out
// 4,608 Bytes With Full String Class
// 5,120 Bytes VC15 x64 UNICODE Full String Class
// 5,120 Bytes VC19 (VS 2015) x64 UNICODE
// /Zc:sizedDealloc-
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
 int iParseCount=0;
 String* pStrs=NULL;
 String s1;
 
 s1=_T("Zero, One, Two, Three, Four, Five");
 s1.Print(_T("s1 = "),true);
 iParseCount=s1.ParseCount(_T(','));
 _tprintf(_T("iParseCount = %d\n\n"),iParseCount);
 pStrs=new String[iParseCount];
 s1.Parse(pStrs, _T(','), iParseCount);
 for(int i=0; i<iParseCount; i++)
 {
     pStrs[i].LTrim();
     pStrs[i].Print(true);
 }
 delete [] pStrs;
 getchar();
 
 return 0;
}

// Output:
// ==========================
// s1 = Zero, One, Two, Three, Four, Five
// iParseCount = 6

// Zero
// One
// Two
// Three
// Four
// Five