//=====================================================================================
//               Developed As An Addition To Matt Pietrek's LibCTiny.lib
//                            By Fred Harris, January 2016
//
//                 cl strncpy.cpp /O1 /Os /c /W3 /DWIN32_LEAN_AND_MEAN
//=====================================================================================
#include <windows.h>
#include "string.h"

char* __cdecl strncpy(char* strDest, const char* strSource, size_t iCount)   
{ 
 size_t iLenSrc=strlen(strSource);
 for(size_t i=0; i<iCount; i++)
     strDest[i]=strSource[i];
 if(iCount>iLenSrc)
 {  
    for(size_t i=iLenSrc; i<iCount; i++)
        strDest[i]=0;     
 }
 
 return strDest; 
}


wchar_t* __cdecl wcsncpy(wchar_t* strDest, const wchar_t* strSource, size_t iCount)
{
 size_t iLenSrc=wcslen(strSource);
 for(size_t i=0; i<iCount; i++)
     strDest[i]=strSource[i];
 if(iCount>iLenSrc)
 {  
    for(size_t i=iLenSrc; i<iCount; i++)
        strDest[i]=0;     
 }
 
 return strDest;  
} 

/*
char* __cdecl strncpy(char* strDest, const char* strSource, size_t iCount)   
{                                              // 3rd param is size_t
 size_t iLenSrc=strlen(strSource);             // strlen returns size_t                                            
 lstrcpynA(strDest,strSource,(int)iCount);     // lstrcpyn wants an int here for 3rd param                                            
 strDest[iCount-1]=strSource[iCount-1];        // so try cast
 if(iCount>iLenSrc)
 {
    for(size_t i=iLenSrc; i<iCount; i++)
        strDest[i]=0;
 }

 return strDest;
}


wchar_t* __cdecl wcsncpy(wchar_t* strDest, const wchar_t* strSource, size_t iCount)   
{                                           // 3rd param is size_t
 size_t iLen=wcslen(strSource);             // strlen returns size_t                                            
 lstrcpynW(strDest,strSource,(int)iCount);  // lstrcpyn wants an int here for 3rd param                                            
 strDest[iCount-1]=strSource[iCount-1];     // so try cast
 if(iCount>iLen)
 {
    for(size_t i=iLen; i<iCount; i++)
        strDest[i]=0;
 }

 return strDest;
} 
*/ 
