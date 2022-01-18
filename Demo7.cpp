// String Constructors Which Directly Convert Numeric Data To String Objects
// cl Demo7.cpp Strings.cpp /O1 /Os /GS- TCLib.lib user32.lib
// cl Demo7.cpp Strings.cpp /O1 /Os user32.lib
// 4,608 Bytes VC15, VC19 x64 With Full String Class  
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
 String s1(123456789);
 s1.Print(true);
 String s2(-123456789);
 s2.Print(true);
 #ifdef x64
    String s3(1234567898765432);
    String s4(-1234567898765432);
    s3.Print(true);
    s4.Print(true);
 #endif
 String s5(-3.14159);
 s5.LTrim();
 s5.Print(true);
 getchar();
 
 return 0;
}

// Output:
// =============
// 123456789
// -123456789
// 1234567898765432
// -1234567898765432
// -3.141590