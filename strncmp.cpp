//===============================================================================================
//               Developed As An Addition To Matt Pietrek's LibCTiny.lib
//                            By Fred Harris, January 2016
//
//       cl strncmp.cpp /D "_CRT_SECURE_NO_WARNINGS" /c /W3 /DWIN32_LEAN_AND_MEAN 
//===============================================================================================
#include <windows.h>
#include "malloc.h"
#include "string.h"

int __cdecl strncmp(const char* str1, const char* str2, size_t count)
{
 for(size_t i=0; i<count; i++)
 {
     if(str1[i]<str2[i])
        return -1;
     if(str1[i]>str2[i])
        return 1;
 }
 
 return 0;
}

int __cdecl wcsncmp(const wchar_t* str1, const wchar_t* str2, size_t count)
{
 for(size_t i=0; i<count; i++)
 {
     if(str1[i]<str2[i])
        return -1;
     if(str1[i]>str2[i])
        return 1;
 }
 
 return 0;
}


//This code below runs 963 times slower than the code above!
/*
int __cdecl strncmp(const char* str1, const char* str2, size_t count)
{
 size_t iLen1=strlen(str1);
 size_t iLen2=strlen(str2);
 if(count>iLen1)
    return -1;
 if(count>iLen2)
    return 1;
 char* pStr1=(char*)malloc(count+1);
 char* pStr2=(char*)malloc(count+1);
 strncpy(pStr1,str1,count);
 strncpy(pStr2,str2,count);
 pStr1[count]=0;
 pStr2[count]=0;
 int iReturn=strcmp(pStr1,pStr2);
 free(pStr1);
 free(pStr2);

 return iReturn;
}


int __cdecl wcsncmp(const wchar_t* str1, const wchar_t* str2, size_t count)
{
 size_t iLen1=wcslen(str1);
 size_t iLen2=wcslen(str2);
 if(count>iLen1)
    return -1;
 if(count>iLen2)
    return 1;
 wchar_t* pStr1=(wchar_t*)malloc(count*2+2);
 wchar_t* pStr2=(wchar_t*)malloc(count*2+2);
 wcsncpy(pStr1,str1,count);
 wcsncpy(pStr2,str2,count);
 pStr1[count]=0;
 pStr2[count]=0;
 int iReturn=wcscmp(pStr1,pStr2);
 free(pStr1);
 free(pStr2);

 return iReturn;
}
*/