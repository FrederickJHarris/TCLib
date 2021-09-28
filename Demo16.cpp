// More String Formatting And Rounding Using String::Format().
// cl Demo16.cpp Strings.cpp /O1 /Os /GS- TCLib.lib kernel32.lib user32.lib
// 9,728 Bytes With Full String Class, Which Is Mostly Needed
// 8,192 Bytes VC15 (VS 2008) x64 UNICODE 
#define UNICODE
#define _UNICODE
#include <windows.h>
#include "stdlib.h"
#include "stdio.h"
#include "tchar.h"
#include "Strings.h"

int _tmain()
{
 double dblNums[]={123456.78912, -456.9876, 9999.99999, -0.987654, 0.0, 1.985, 1.9754321};
 String s1;
 
 for(size_t i=0; i<=2; i++)
 {
     for(size_t j=0; j<sizeof(dblNums)/sizeof(dblNums[0]); j++)
     { 
         s1.Format(dblNums[j], 12, i, _T(','), _T('.'), true);
         s1.Print(true);
     }
     printf("\n\n");
 }
 getchar();
  
 return 0;
}

/*
    123,457
       -457
     10,000
         -1
          0
          2
          2


  123,456.8
     -457.0
   10,000.0
       -1.0
        0.0
        2.0
        2.0


 123,456.79
    -456.99
  10,000.00
      -0.99
       0.00
       1.99
       1.98
       

     123,457
        -457
      10,000
          -1
           0
           2
           2


   123,456.8
      -457.0
    10,000.0
        -1.0
         0.0
         2.0
         2.0


  123,456.79
     -456.99
   10,000.00
       -0.99
        0.00
        1.99
        1.98


       
*/
