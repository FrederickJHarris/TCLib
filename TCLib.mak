PROJ       = TCLib

OBJS       = crt_con_a.obj crt_con_w.obj crt_win_a.obj crt_win_w.obj InitStdio.obj InitMath.obj\
             crt_dll.obj newdel.obj alloc.obj alloc2.obj allocsup.obj  strlen.obj memcpy.obj \
             strcpy.obj strncpy.obj strcmp.obj _stricmp.obj _strnicmp.obj _strrev.obj strncmp.obj \
             _atoi64.obj atof.obj abs.obj memset.obj strchr.obj strrchr.obj strcat.obj memcmp.obj \
             atol.obj
        
CC         = CL
CC_OPTIONS = /D "_CRT_SECURE_NO_WARNINGS" /O1 /Os /GS- /c /W3 /DWIN32_LEAN_AND_MEAN

$(PROJ).LIB: $(OBJS)
    LIB /NODEFAULTLIB /machine:x64 /OUT:$(PROJ).lib $(OBJS)

.CPP.OBJ:
    $(CC) $(CC_OPTIONS) $<
