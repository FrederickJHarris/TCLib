// Can Test For String Allocation Failures With String::blnSuccess(). 
// cl Demo24.cpp Strings.cpp /O1 /Os /GS- TCLib.lib kernel32.lib user32.lib
// 5,120 Bytes VC19 (VS 2015) x64 UNICODE
// Test Machine HP Envy Laptop Windows 10 Home x64 16 G RAM
#define UNICODE
#define _UNICODE
#include <windows.h>     //  32,000,000,000, i.e.,  32 billion wchar_ts --   64,000,000,000 bytes succeeds
#include "stdlib.h"      // 320,000,000,000, i.e., 320 billion wchar_ts --  640,000,000,000 bytes fails
#include "stdio.h"
#include "tchar.h"
#include "Strings.h"

int main()
{
 //size_t iNumber   = 320000000000;    // Fails       320,000,000,000
 size_t iNumber     = 32000000000;     // Succeeds     32,000,000,000
 String s1(iNumber,false);
  
 if(s1.blnSuccess())
 { 
    s1=L"Hello, World!";
    printf("Allocation Successful!\n");
    s1.Print(L"s1.lpStr() = ",true);
    printf("s1.Capacity() = %Iu\n",s1.Capacity());
    printf("s1.Len()      = %Iu\n",s1.Len());
 }   
 else
 { 
    printf("Allocation Failed!\n");
    printf("s1.lpStr = %Iu\n",s1.lpStr());
 }    
 getchar();
 
 return 0;
}




/*
// cl Test3.cpp /O1 /Os /GS- /EHsc kernel32.lib
// 136,192 bytes
#include <string>
#include <cstdio>
#include <tchar.h>

int main()
{
 std::wstring s1(L"Hello, World!");
 
 wprintf(L"s1.c_str() = %s\n", s1.c_str());
 getchar();
 
 return 0;
}
*/

