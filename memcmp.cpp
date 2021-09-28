//=====================================================================================
//               Developed As An Addition To Matt Pietrek's LibCTiny.lib
//                              By Fred Harris, April 2016
//
//                     cl memcmp.cpp /c /W3 /DWIN32_LEAN_AND_MEAN 
//=====================================================================================

extern "C" int __cdecl memcmp(const void* buf1, const void* buf2, size_t iCount)
{
 char* p1=(char*)buf1;
 char* p2=(char*)buf2;
 for(size_t i=0; i<iCount; i++)
 {
     if(*p1<*p2)
        return -1;
     if(*p1>*p2)
        return 1;
     p1++, p2++;
 }

 return 0;
}