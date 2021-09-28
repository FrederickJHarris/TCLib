//=========================================================================================================
//                                              InitMath.cpp
//                                         Fred Harris, July 2016
//
//         cl InitMath.cpp /D "_CRT_SECURE_NO_WARNINGS" /O1 /Os /GS- /c /W3 /DWIN32_LEAN_AND_MEAN 
//=========================================================================================================
#include <windows.h>
extern "C" void InitMath(HINSTANCE hLib);
double (__cdecl* pow)(const double dblBase, const double dblExponent); 

void InitMath(HINSTANCE hLib)
{
 pow = (double (__cdecl*)(const double dblBase, const double dblExponent))GetProcAddress(hLib,"pow"); 
} 