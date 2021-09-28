// Using doubles with printf and need for _fltused
// cl Demo2.cpp /O1 /Os /GS- TCLib.lib kernel32.lib
// 4,096 bytes x64 UNICODE VC19 (VS 2015)
#define UNICODE
#define _UNICODE
#include  <windows.h>
#include  "stdio.h"
#include  "tchar.h"
#define   x64
extern "C" int _fltused=1;

int _tmain()
{
 double dblNums[]={123456.78912, -456.9876, 9999.99999, -0.987654, 0.0, 1.985};
 int iLenRet=0;

 _tprintf(_T("i         dblNums[i]\n"));
 _tprintf(_T("====================\n"));
 for(size_t i=0; i<6; i++)
 {
     #ifdef x64
        _tprintf(_T("%-4Iu%16.2f\n"),i,dblNums[i]);
     #else
        _tprintf(_T("%-4u%16.2f\n"),i,dblNums[i]);
     #endif
 } 
 getchar();

 return 0;
}


#if 0


i         dblNums[i]
====================
0          123456.79
1            -456.99
2           10000.00
3              -0.99
4               0.00
5               1.99

#endif



/*
// cl Demo2.cpp /O1 /Os /GS- /MT
// 119,296 Bytes x64 ASCII VC19
#include  <cstdio>
#define x64

int main()
{
 double dblNums[]={123456.78912, -456.9876, 9999.99999, -0.987654, 0.0, 1.985};
 
 printf("i     dblNums[i]\n");
 printf("================\n");
 for(size_t i=0; i<6; i++)
 {
     #ifdef x64
        printf("%-4Iu%12.2f\n",i,dblNums[i]);
     #else
        printf("%-4u%12.2f\n",idblNums[i]);
     #endif
 } 
 getchar();

 return 0;
}

#if 0

i     dblNums[i]
================
0      123456.79
1        -456.99
2       10000.00
3          -0.99
4           0.00
5           1.99

#endif
*/
