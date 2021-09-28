//========================================================================================
//                 Developed As An Addition To Matt Pietrek's LibCTiny.lib
//                              By Fred Harris, January 2016
//
// cl crt_win_a.cpp /D "_CRT_SECURE_NO_WARNINGS" /O1 /Os /GS- /c /W3 /DWIN32_LEAN_AND_MEAN 
//========================================================================================
#include <windows.h>
#pragma comment(linker, "/defaultlib:kernel32.lib")
#pragma comment(linker, "/nodefaultlib:libc.lib")
#pragma comment(linker, "/nodefaultlib:libcmt.lib")
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int);
extern "C" void __cdecl InitStdio(HINSTANCE);
extern "C" void __cdecl InitMath(HINSTANCE);

extern "C" void __cdecl WinMainCRTStartup(void)
{
 HINSTANCE hLib=NULL;
 int iReturn;

 hLib=LoadLibrary("msvcrt.dll");
 if(hLib)
 { 
    InitStdio(hLib);
    InitMath (hLib);    
    iReturn = WinMain(GetModuleHandle(NULL),NULL,NULL,SW_SHOWDEFAULT);
    FreeLibrary(hLib);    
 }
 ExitProcess(iReturn);
}
