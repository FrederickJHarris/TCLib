//==============================================================================================
//               Developed As An Addition To Matt Pietrek's LibCTiny.lib
//                             By Fred Harris, May 2016
//
//        cl atof.cpp /D "_CRT_SECURE_NO_WARNINGS" /c /W3 /DWIN32_LEAN_AND_MEAN 
//==============================================================================================
#include <windows.h>
#include "stdlib.h"
typedef SSIZE_T ssize_t;


double __cdecl atof(const char* pStr)
{
 ssize_t lTotal   = 0;
 char* pDecPt     = NULL;
 char c,cNeg      = NULL;
 double dblReturn;
 size_t iDiff;

 while(*pStr==32 || *pStr==8 || *pStr==48)
    pStr++;
 if(*pStr=='-')
 {
    cNeg='-';
    pStr++;
 }
 while(*pStr)
 {
    if(*pStr=='.')
    {
       pDecPt=(char*)pStr;
       pStr++;
    }
    else
    {
       if(*pStr>=48 && *pStr<=57)
       {
          c=*pStr++;
          lTotal=10*lTotal+(c-48); // Add this digit to the total.
       }
       else
          break;
    }   
 }
 if(pDecPt)
    iDiff=(int)(pStr-pDecPt-1);
 else
    iDiff=0;
 if(cNeg=='-')                  // If we have a negative sign, convert the value.
    lTotal=-lTotal;
 dblReturn=(double)lTotal;
 for(size_t i=0; i<iDiff; i++)
     dblReturn=dblReturn/10;

 return dblReturn;
}

double __cdecl _wtof(const wchar_t* pStr)
{
 ssize_t lTotal = 0;
 wchar_t* pDecPt=NULL;
 wchar_t c,cNeg=NULL;
 double dblReturn;
 size_t iDiff;

 while(*pStr==32 || *pStr==8 || *pStr==48)
    pStr++;
 if(*pStr==L'-')
 {
    cNeg=L'-';
    pStr++;
 }
 while(*pStr)
 {
    if(*pStr==L'.')
    {
       pDecPt=(wchar_t*)pStr;
       pStr++;
    }
    else
    {
       if(*pStr>=48 && *pStr<=57)
       {
          c=*pStr++;
          lTotal=10*lTotal+(c-48); // Add this digit to the total.
       }
       else
          break;   
    }
 }
 if(pDecPt)
    iDiff=(int)(pStr-pDecPt-1);
 else
    iDiff=0;
 if(cNeg==L'-')                  // If we have a negative sign, convert the value.
    lTotal=-lTotal;
 dblReturn=(double)lTotal;
 for(size_t i=0; i<iDiff; i++)
     dblReturn=dblReturn/10;

 return dblReturn;
}

/*
double __cdecl _wtof(const wchar_t* pStr)
{
 
 wchar_t* pDecPt    = NULL;
 wchar_t  c,cNeg    = NULL;
 __int64  lTotal    = 0;
 double   dblReturn = 0.0;
 ssize_t  iDiff     = 0;
 
 //#ifdef Debug
 //fprintf(fp,"    Entering _wtof()\n");
 //fwprintf(fp,L"      pStr = %s\n",pStr);
 //#endif
 while(*pStr==32 || *pStr==8 || *pStr==48)
    pStr++;
 if(*pStr==L'-')
 {
    cNeg=L'-';
    pStr++;
 }
 //fprintf(fp,"\n");
 while(*pStr)
 {
    if(*pStr==L'.')
    {
       pDecPt=(wchar_t*)pStr;
       pStr++;
    }
    else
    {
       c=*pStr++;
       lTotal=10*lTotal+(c-48); // Add this digit to the total.
    }
    //fwprintf(fp,L"      %c\t%d\n",c,lTotal);
 }
 //fprintf(fp,"\n");
 if(pDecPt)
    iDiff=(ssize_t)(pStr-pDecPt-1);
 else
    iDiff=0;
 //fprintf(fp,"      iDiff = %d\n\n",iDiff);
 if(cNeg==L'-')                  // If we have a negative sign, convert the value.
    lTotal=-lTotal;
 dblReturn=(double)lTotal;
 for(ssize_t i=0; i<iDiff; i++)
 {
     dblReturn=dblReturn/10;
     //fprintf(fp,"      %u\t%14.10f\n",i,dblReturn);
 }
 //#ifdef Debug
 //fprintf(fp,"\n    Leaving _wtof()\n\n");
 //#endif

 return dblReturn;
}
*/

