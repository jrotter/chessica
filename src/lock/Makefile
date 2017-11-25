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
OBJDIR = ./obj

#any global include files
GLOBAL_INCLUDE = lock.h

LIBDIR = ../../lib
LIBNAME = liblock.a

#########################################################################

CFLAGS = $(MYFLAGS) $(PROFILE)

OBJFILES = $(OBJDIR)/lock.o

$(LIBDIR)/$(LIBNAME) : $(GLOBAL_INCLUDE) $(OBJFILES)
	@echo '****'
	@echo '**** Making Lock library'
	@echo '****'
	rm -f $(LIBDIR)/$(LIBNAME) && ar -cvq $(LIBDIR)/$(LIBNAME) $(OBJFILES)

$(OBJDIR)/%.o : %.cpp $(GLOBAL_INCLUDE)
	$(CC) -c $(CFLAGS) $< -o $@

clean : 
	rm -f $(OBJDIR)/* $(LIBDIR)/$(LIBNAME)

