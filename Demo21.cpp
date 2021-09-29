// Comparing String Objects The C++ Way And String::UCase().
// cl Demo21.cpp Strings.cpp /O1 /Os /GS- TCLib.lib kernel32.lib user32.lib
#define UNICODE
#define _UNICODE
#include <windows.h>
#include "stdlib.h"
#include "stdio.h"
#include "tchar.h"
#include "Strings.h"

int main()
{
 String s1(_T("Fred"));
 String s2(_T("fred"));
 
 if(s1.UCase()==s2.UCase())
    _tprintf(_T("Strings Are Case Insensitive Equal!"));
 else
    _tprintf(_T("Strings Are Case Insensitive Not Equal!"));
 getchar();
 
 return 0;
}

// Output:
// =============
// Strings Are Case Insensitive Equal!
