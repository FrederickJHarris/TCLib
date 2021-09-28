// Parsing A Comma Delimited String And Putting It Back Together; First Demo of String::Right().
// cl Demo11.cpp Strings.cpp /O1 /Os /GS- /Zc:sizedDealloc- TCLib.lib kernel32.lib user32.lib
// cl Demo11.cpp Strings.cpp /O1 /Os /GS- TCLib.lib kernel32.lib user32.lib
// 6,144 Bytes With INTEGRAL_CONVERSIONS, FLOATING_POINT_CONVERSIONS, And FORMATTING Remmed Out
// 6,656 Bytes With Full String Class
// 6,144 Bytes VC15 (VS 2008) x64
// 7,168 Bytes VC19 (VS 2015) x64
#define  UNICODE
#define  _UNICODE
#include <windows.h>
#include "stdlib.h"
#include "stdio.h"
#include "tchar.h"
#include "Strings.h"

int main()
{
 String* pStrs=NULL;
 int iParseCount=0;
 String s1,s2;
 
 s1=_T("Zero,  One, Two  , Three ,  Four, Five   , Six, Seven, Eight , Nine, Ten");
 s1.Print(_T("s1 = "), true);
 iParseCount = s1.ParseCount(_T(','));
 _tprintf(_T("iParseCount = %d\n\n"),iParseCount);
 pStrs = new String[iParseCount];
 s1.Parse(pStrs, _T(','), iParseCount);
 for(int i=0; i<iParseCount; i++)
 {
     pStrs[i].Trim();
     pStrs[i].Print(true);
     s2 = s2 + _T(',') + pStrs[i];
 }
 s2.Print(_T("\ns1 = "),true);
 s2=s2.Right(s2.Len()-1);
 s2.Print(_T("s1 = "),true);
 delete [] pStrs;
 getchar();
 
 return 0;
}

// Output:
// =============
// s1 = Zero,  One, Two  , Three ,  Four, Five   , Six, Seven, Eight , Nine, Ten
// iParseCount = 11
//
// Zero
// One
// Two
// Three
// Four
// Five
// Six
// Seven
// Eight
// Nine
// Ten
//
// s1 = ,Zero,One,Two,Three,Four,Five,Six,Seven,Eight,Nine,Ten
// s1 = Zero,One,Two,Three,Four,Five,Six,Seven,Eight,Nine,Ten
