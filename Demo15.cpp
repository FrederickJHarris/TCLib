// Formatting A String Object With Thousands Place Seperators And Rounding.
// cl Demo15.cpp Strings.cpp /O1 /Os /GS- TCLib.lib kernel32.lib user32.lib
// 8,704 Bytes With Full String Class, Which Is Mostly Needed
// 8,192 Bytes VC15 (VS 2008) x64 With Full String Class
// 9,728 Bytes VC19 (VS 2015) x64 With Full String Class
#define  UNICODE
#define  _UNICODE
#include <windows.h>
#include "stdlib.h"
#include "stdio.h"
#include "tchar.h"
#include "Strings.h"

int _tmain()
{
 double dblNum=-1234567898765.4321234;
 String s1;
 
 s1.Format(dblNum, 24, 3, _T(','), _T('.'), true);
 printf("s1.Len()=%Iu\n",s1.Len());
 s1.Print(_T("s1="),false);
 getchar();
  
 return 0;
}

// Output:
// ==========================
// s1.Len()=24
// s1=  -1,234,567,898,765.432

