// More assignments and operator=
// cl Demo9.cpp Strings.cpp /O1 /Os /GS- TCLib.lib user32.lib
// cl Demo9.cpp Strings.cpp /O1 /Os user32.lib
// 4,608 Bytes VC19 x64 UNICODE
// 5,120 Bytes VC15 x64 UNICODE 
//#define TCLib
#define UNICODE
#define _UNICODE
#include <windows.h>
#ifdef TCLib
   #include "stdio.h"
#else
   #include <stdio.h>
#endif
#include "Strings.h"

int main()
{
 String s1,s2,s3,s4,s5;
 
 s1 =  123456789;
 s1.Print(true);
 s2 = -123456789;
 s2.Print(true);
 #ifdef x64
    s3 =  1234567898765432;
    s4 = -1234567898765432;
    s3.Print(true);
    s4.Print(true);
 #endif   
 s5 =  3.141590;
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
// 3.141590
