# TCLib
Code For Building My x64 Replacement C Runtime For Microsoft's C Runtime, i.e., LIBC, LIBCMT.

Using this replacement library the base size of static linked executables whether console or GUI
is around 3k to 3.5k with version 19 (from Visual Studio 2019 installation) of Microsoft's
Build Chain.  That compares very well against static linking with Microsoft's C Runtime, where
base sizes are in the 90k to 100k range.  So using my TCLib binaries are at least 30 times smaller.
Inspiration for this work was Matt Pietrek's Microsoft Systems Journal article about minimizing 
the sizes of executables from somewhere around 1998 or so.  I'll have to look up the exact date 
and and article and provide a link link to it.  I needed to modify and extend his code for x64 
and wide character support.

The other inspiration for this work was my movement around 2015 or so to C++ as my main Windows
desktop programming language.  Previously I had been a long time PowerBASIC coder for desktop 
systems.  With PowerBASIC the base sizes of executables were in the 7k or 8k range.  And this
included loading of the COM libraries, full dynamic multi-dimensional array support, unmatched
string handling, and full math library support.  The talented creator of PowerBASIC - Bob Zale,
passed away in 2011 before completing an x64 version of his compilers.  I wished to move my 
desktop coding work in Windows to x64 so I felt I had no alternative but to move fully to C++,
even though I took an extremely dim view of the bloated nature of Microsoft's implementation
of that language.

Among the uploaded files is TCLib.mak.  If you want to build TCLib.lib from the command prompt
(I do only command line compilation work - never tried to build it in Visual Studio) copy all 
the uploaded files to a directory of your choice, bring up the x64 Visual Studio command prompt, 
and execute...

nmake TCLib.mak

Let me know if you have any difficulties.  However, I have TCLib.lib uploaded in the file set, so you 
don't have to make it if you don't care to take the time.

Also in the file set are a lot of very small DemoXX.cpp files that exercise various functionalities
of TCLib.  Note I use this library with my String Class which is also in the file set.  That would be
Strings.h and Strings.cpp.  In that way my usage of C++ is rather eclectic in that I don't use 
anything from the C++ specific part of the C++ Standard Library.

In terms of limitations of TCLib there are several.  First, it can't be used with anything from
the C++ specific part of the C++ Standard Library.  Second, I have no destructors in it to delete
memory for static/globally defined/created objects.  I actually don't use globals or such objects
in my work, so that is no hinderance to me, but it might be for others.  

Finally, since Microsoft 'refactored' their whole standard libraries over the past several years or 
so, I've found I can't use some of their headers like I used to, for example, stdio.h, stdlib.h, 
etc.  So if using TCLib you'll have to use my custom headers which are uploaded and here.  See some
of the demo programs for details.  Usually I use conditional compilation statements in my code to
cover the situation where I want to build sometimes against TCLib, and at other times against
Microsoft's libraries.  So you'll see such idioms in my code as this....

[CODE]
// Strings.cpp
#define   TCLib
#define   UNICODE
#define   _UNICODE
#include  <windows.h>
#ifdef    TCLib
   #include  "string.h"
   #include  "stdio.h"
   #include  "tchar.h"
   #include  "memory.h"
   #define   NEW new
   extern "C" int _fltused=1;
#else
   #include  <string>
   #include  <cstdio>
   #include  <tchar.h>
   #include  <new>
   #define   NEW new(std::nothrow)
#endif
#include  "Strings.h"
[/CODE]
   
In terms of the sizes of programs (number of lines of code) one can build using TCLib I have never found 
any limitations.  I've used it for large mission critical enterprise software used by large organizations.
