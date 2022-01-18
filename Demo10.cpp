// String Object Concatenation
// cl Demo10.cpp Strings.cpp /O1 /Os /GS- TCLib.lib user32.lib
// cl Demo10.cpp Strings.cpp /O1 /Os /GS- /link TCLib.lib kernel32.lib user32.lib
// cl Demo10.cpp Strings.cpp /O1 /Os user32.lib
// 4,096 Bytes With INTEGRAL_CONVERSIONS, FLOATING_POINT_CONVERSIONS, And FORMATTING Remmed Out
// 4,608 Bytes With Full String Class
#define TCLib
#define UNICODE
#define _UNICODE
#include <windows.h>
#ifdef TCLib
   #include "stdlib.h"
   #include "stdio.h"
   #include "tchar.h"
#else
   #include <stdlib.h>
   #include <stdio.h>
   #include <tchar.h>
#endif
#include "Strings.h"

int main()
{
 String s1;
 
 for(size_t i=65; i<=90; i++)
 {
     s1=s1+i;
     s1.Print(true);
 }
 getchar();
 
 return 0;
}

// Output:
// =============
// A
// AB
// ABC
// ABCD
// ABCDE
// ABCDEF
// ABCDEFG
// ABCDEFGH
// ABCDEFGHI
// ABCDEFGHIJ
// ABCDEFGHIJK
// ABCDEFGHIJKL
// ABCDEFGHIJKLM
// ABCDEFGHIJKLMN
// ABCDEFGHIJKLMNO
// ABCDEFGHIJKLMNOP
// ABCDEFGHIJKLMNOPQ
// ABCDEFGHIJKLMNOPQR
// ABCDEFGHIJKLMNOPQRS
// ABCDEFGHIJKLMNOPQRST
// ABCDEFGHIJKLMNOPQRSTU
// ABCDEFGHIJKLMNOPQRSTUV
// ABCDEFGHIJKLMNOPQRSTUVW
// ABCDEFGHIJKLMNOPQRSTUVWX
// ABCDEFGHIJKLMNOPQRSTUVWXY
// ABCDEFGHIJKLMNOPQRSTUVWXYZ