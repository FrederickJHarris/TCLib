//=====================================================================================
//               Developed As An Addition To Matt Pietrek's LibCTiny.lib
//                            By Fred Harris, January 2016
//
//                     cl memcpy.cpp /c /W3 /DWIN32_LEAN_AND_MEAN 
//=====================================================================================
//#include "memory.h"    // for some reason you can't put the prototype for this in
                         // memory.h

extern "C" void* __cdecl memcpy(void* pDest, void* pSrc, size_t iCount)
{
 char* pDestination=(char*)pDest;
 char* pSource=(char*)pSrc;

 for(size_t i=0; i<iCount; i++)
     pDestination[i]=pSource[i];

 return pDest;
}
