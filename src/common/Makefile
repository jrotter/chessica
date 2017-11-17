#compiler name
CC = g++

#compiler flags you want to use (other than profiling)
MYFLAGS = -O3 -fPIC

#libraries to use
LIBS = 

#flags for profiling (see hacker.doc for more information)
PROFILE = -g -pg
#PROFILE = 

#Directory which holds object files
OBJDIR = ../../obj

#any global include files
GLOBAL_INCLUDE = common.h

LIBDIR = ../../lib
LIBNAME = libcommon.a

#########################################################################

CFLAGS = $(MYFLAGS) $(PROFILE)

OBJFILES = $(OBJDIR)/io_common.o  

all: $(OBJFILES) $(GLOBAL_INCLUDE)
	ar -cvq $(LIBDIR)/$(LIBNAME) $(OBJFILES)

$(OBJDIR)/%.o : %.cpp $(GLOBAL_INCLUDE)
	$(CC) -c $(CFLAGS) $< -o $@

clean : 
	rm -f $(OBJFILES)

