// cl crt_dll.cpp /O1 /Os /GS- /c /W3 /DWIN32_LEAN_AND_MEAN 
#include <windows.h>
#pragma comment(linker, "/defaultlib:kernel32.lib")
extern BOOL WINAPI DllMain(HINSTANCE hDllHandle, DWORD dwReason, LPVOID lpreserved);
extern "C" void __cdecl InitStdio(HINSTANCE);
extern "C" void __cdecl InitMath(HINSTANCE);

extern "C" BOOL WINAPI _DllMainCRTStartup(HINSTANCE  hDllHandle, DWORD dwReason, LPVOID  lpreserved)
{
 HINSTANCE hLib=NULL;
 BOOL retcode=FALSE;

 hLib=LoadLibrary("msvcrt.dll");
 if(hLib)
 { 
    InitStdio(hLib);
    InitMath (hLib);
    retcode = DllMain(hDllHandle, dwReason, lpreserved);
    FreeLibrary(hLib);    
 }
 
 return retcode;
}
