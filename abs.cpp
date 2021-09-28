//==============================================================================================
//               Developed As An Addition To Matt Pietrek's LibCTiny.lib
//                             By Fred Harris, March 2016
//
//         cl abs.cpp /D "_CRT_SECURE_NO_WARNINGS" /c /W3 /DWIN32_LEAN_AND_MEAN 
//==============================================================================================
#include "stdlib.h"

int __cdecl abs(int n)
{
 if(n<0)
    return -n;
 else
    return n;
}
 
_int64 __cdecl _abs64(__int64 n)
{
 if(n<0)
    return -n;
 else
    return n;
}

long labs(long n)
{
 if(n<0)
    return -n;
 else
    return n;
} 

/*
labs, llabs Visual Studio 2015Visual Studio 2015 

Calculates the absolute value of an integer.

long labs(long n);
long long llabs(long long n);

Parameters

n   Integer value.

Return Value

The labs and llabs functions return the absolute value of the argument. There is no error return.

Microsoft Specific

Because the range of negative integers that can be represented by using an integral type is larger than the 
range of positive integers that can be represented by using that type, it's possible to supply an argument 
to labs or llabs that can’t be converted. If the absolute value of the argument cannot be represented by the 
return type, the labs and llabs functions return the argument value unchanged. Specifically, labs(LONG_MIN) 
returns LONG_MIN, and llabs(LLONG_MIN) returns LLONG_MIN. This means that the labs and llabs functions 
cannot be used to guarantee a positive value.
*/
