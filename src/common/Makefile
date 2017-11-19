#compiler name
CC = g++

#compiler flags you want to use (other than profiling)
MYFLAGS = -O3

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

$(LIBDIR)/$(LIBNAME) : $(GLOBAL_INCLUDE) $(OBJFILES)
	@echo '****'
	@echo '**** Making Common library'
	@echo '****'
	rm -f $(LIBDIR)/$(LIBNAME) && ar -cvq $(LIBDIR)/$(LIBNAME) $(OBJFILES)

$(OBJDIR)/%.o : %.cpp $(GLOBAL_INCLUDE)
	$(CC) -c $(CFLAGS) $< -o $@

clean : 
	rm -f $(OBJFILES) $(LIBDIR)/$(LIBNAME)

