#compiler name
CC = g++

#compiler flags you want to use (other than profiling)
MYFLAGS = -O3

#header directories
HEADERS = -I ../common \
          -I ../lock \
          -I ../logger \
          -I ../reset \
          -I ../tree

#flags for profiling (see hacker.doc for more information)
PROFILE = -g -pg

#Directory which holds object files
OBJDIR = ./obj

#any global include files
GLOBAL_INCLUDE = game.h 

LIBDIR = ../../lib
LIBNAME = libgame.a

#########################################################################

CFLAGS = $(MYFLAGS) $(PROFILE)

OBJFILES = $(OBJDIR)/ab.o              \
           $(OBJDIR)/engine.o          \
           $(OBJDIR)/game.o            \
           $(OBJDIR)/search.o          \
           $(OBJDIR)/xboard.o          

$(LIBDIR)/$(LIBNAME) : $(GLOBAL_INCLUDE) $(OBJFILES)
	@echo '****'
	@echo '**** Making Game library'
	@echo '****'
	rm -f $(LIBDIR)/$(LIBNAME) && ar -cvq $(LIBDIR)/$(LIBNAME) $(OBJFILES)

$(OBJDIR)/%.o : %.cpp $(GLOBAL_INCLUDE)
	$(CC) $(HEADERS) -c $(CFLAGS) $< -o $@

clean : 
	rm -f $(LIBDIR)/$(LIBNAME)
	rm -f $(OBJDIR)/*

