//========================================================================================
//                 Developed As An Addition To Matt Pietrek's LibCTiny.lib
//                              By Fred Harris, January 2016
//
// cl crt_con_a.cpp /D "_CRT_SECURE_NO_WARNINGS" /O1 /Os /GS- /c /W3 /DWIN32_LEAN_AND_MEAN 
//========================================================================================
#include <windows.h>
#pragma comment(linker, "/defaultlib:kernel32.lib")
#pragma comment(linker, "/nodefaultlib:libc.lib")
#pragma comment(linker, "/nodefaultlib:libcmt.lib")
extern "C" void __cdecl InitStdio(HINSTANCE);
extern "C" void __cdecl InitMath (HINSTANCE);
extern "C" int  __cdecl main();

extern "C" void __cdecl mainCRTStartup()
{
 HINSTANCE hLib=NULL;
 int iReturn=0;
 
 hLib=LoadLibrary("msvcrt.dll");
 if(hLib)
 { 
    InitStdio(hLib);
    InitMath (hLib);
    iReturn=main();
    FreeLibrary(hLib);    
 }
 ExitProcess(iReturn);
}
