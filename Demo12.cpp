// Searching A String With String::InStr()
// cl Demo12.cpp Strings.cpp /O1 /Os /GS- TCLib.lib kernel32.lib user32.lib
// 4,608 Bytes With INTEGRAL_CONVERSIONS, FLOATING_POINT_CONVERSIONS, And FORMATTING Remmed Out
// 5,120 Bytes VC15 (VS 2008) x64
// 5,632 Bytes VC19, x64 With Full String Class
#define UNICODE
#define _UNICODE
#include <windows.h>
#include "stdlib.h"
#include "stdio.h"
#include "tchar.h"
#include "Strings.h"

int main()
{
 int iFound=0;
 String s1;
 
 s1=_T("C++ Can Be A Real Pain In The Butt To Learn!");
 s1.Print(_T("s1 = "),true);
 iFound=s1.InStr(_T("real"),true,true);
 if(!iFound)
    _tprintf(_T("Couldn't Locate 'real' In s1 With A Case Sensitive Search!\n"));
 iFound=s1.InStr(_T("real"),false,true);  
 _tprintf(_T("But A Case Insensitive Search Located 'real' At One Based Offset %d In s1!\n"),iFound);
 getchar();
 
 return 0;
}

// Output:
// ==========================================================================
// s1 = C++ Can Be A Real Pain In The Butt To Learn!
// Couldn't Locate 'real' In s1 With A Case Sensitive Search!
// But A Case Insensitive Search Located 'real' At One Based Offset 14 In s1!
