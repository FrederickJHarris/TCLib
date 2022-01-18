// Concatenation With += And String::UCase() Demo.
// cl Demo19.cpp Strings.cpp /O1 /Os /GS- TCLib.lib user32.lib
// cl Demo19.cpp Strings.cpp /O1 /Os /MT user32.lib
// 5,632 Bytes VC19 (VS 2019) x64 UNICODE
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
 const wchar_t* szNames[]={L"frank ", L"Samuel ", L"Edward ", L"Martin ", L"Luther ", L"Frederick"};
 String s1,s2;

 for(size_t i=0; i<6; i++)
     s1+=szNames[i];
 s1.Print(true);
 s2=s1.UCase();
 s2.Print(true);
 getchar();

 return 0;
}

// Output
// ========================================
// frank Samuel Edward Martin Luther Frederick
// FRANK SAMUEL EDWARD MARTIN LUTHER FREDERICK

