#if 0

The task outlined below was created by John Gleason of the PowerBASIC Forums 
to compare the speed of execution of C/C++ compared to PowerBASIC (they're 
about equal, turns out).  Doing the test properly requires seperate execution 
of each step; not taking a shortcut and looking at the end result and directly 
coding that.

1)Create 15,000,000 Bytes of Dashes;
2)Change Every 7th Dash To A "P";
3)Replace Every "P" With A "PU" (hehehe);
4)Replace Every Dash With An "8";
5)Put In A CrLf Every 90 Characters; // Insert - not replace, i.e, string grows two chars for each insert
6)Output Last 4K Characters To Message Box;

#endif

// cl Demo18.cpp /O1 /Os /GS- TCLib.lib kernel32.lib user32.lib
// cl Demo18.cpp /O1 /Os /MT user32.lib
// 4,608 Bytes x64; VC19
#define TCLib
#include <Windows.h>
#ifdef TCLib
   #include "stdio.h"
#else
   #include <stdio.h>
#endif
#include "string.h"

enum
{
 NUMBER         = 15000000,
 LINE_LENGTH    = 90,
 NUM_PS         = NUMBER/7+1,
 PU_EXT_LENGTH  = NUMBER+NUM_PS,
 NUM_FULL_LINES = PU_EXT_LENGTH/LINE_LENGTH,
 MAX_MEM        = PU_EXT_LENGTH+NUM_FULL_LINES*2
};

int WINAPI WinMain(HINSTANCE hIns, HINSTANCE hPrev, LPSTR lpCmdLn, int iShow)
{
 char szBuffer[48];
 int i=0,iCtr=0;
 char* s1=NULL;
 char* s2=NULL;

 DWORD tick=GetTickCount();
 s1=(char*)GlobalAlloc(GPTR,MAX_MEM);
 s2=(char*)GlobalAlloc(GPTR,MAX_MEM);
 s2[0]=0;

 for(i=0; i<NUMBER; i++, iCtr++)
 {
     if(iCtr==7)
     {
        s1[i]='P';
        iCtr=0;
     }
     else
        s1[i]='-';
 }
 
 iCtr=0;
 for(i=0; i<NUMBER; i++)
 {
     if(strncmp(s1+i,"P",1)==0)
     {
        strcpy(s2+iCtr,"PU");
        iCtr+=2;
     }
     else
     {
        s2[iCtr]=s1[i];
        iCtr++;
     }
     s2[iCtr]=0;
 }

 for(i=0; i<PU_EXT_LENGTH; i++)
 {
     if(s2[i]=='-')
        s2[i]=56;
 }

 char* pS1=s1;
 char* pS2=s2;
 i=0;
 while(i<PU_EXT_LENGTH)
 {
    *pS1 = *pS2;
    i++, pS1++, pS2++;
    if(i%LINE_LENGTH==0)
    {
       *pS1=13, pS1++;
       *pS1=10, pS1++;
    }
 };
 *pS1=0;

 s2[0]=0;
 strncpy(s2,pS1-4001,4000);
 s2[4000]=0;
 tick=GetTickCount()-tick;
 printf("tick = %u\n",(unsigned)tick);
 sprintf(szBuffer,"Here's Your String John In %u Ticks!",tick); 
 MessageBox(0,s2,szBuffer,MB_OK);
 GlobalFree(s1), GlobalFree(s2);
 
 return 0;
}
