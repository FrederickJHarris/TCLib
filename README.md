# TCLib
Code For Building My x64 Replacement C Runtime For Microsoft's C Runtime, i.e., LIBC, LIBCMT.

Using this replacement library the base size of static linked executables whether console or GUI
is around 3k to 3.5k with version 19 (from Visual Studio 2019 installation) of Microsoft's
Build Chain.  Inspiration for this work was Matt Pietrek's Microsoft Systems Journal article
about minimizing the sizes of executables from somewhere around 1998 or so.  I'll have to look up
the exact date and link to it.  I needed to modify and extend his code for x64 and wide character 
support.
