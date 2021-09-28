// Dennis Ritchie Classic "Hello, World!"
// cl Demo1.cpp /O1 /Os /GS- /link TCLib.lib kernel32.lib
// cl Demo1.cpp /O1 /Os /GS- /c
// link Demo1.obj TCLib.lib kernel32.lib
// 2,048 bytes x86 ASCII, 2,048 bytes x86 UNICODE VC15
// 2,560 bytes x64 ASCII, 2,560 bytes x64 UNICODE VC15
// 3,072 bytes x64 ASCII, 3,072 bytes x64 UNICODE VC19
#define  UNICODE
#define  _UNICODE
#include <windows.h>
#include "stdio.h"
#include "tchar.h"

int _tmain()
{
 _tprintf(_T("Hello, World!\n"));
 getchar();

 return 0;
}

// Output:
// =============
// Hello, World!