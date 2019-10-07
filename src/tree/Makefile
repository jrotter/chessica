#compiler name
CC = g++

#compiler flags you want to use (other than profiling)
MYFLAGS = -O3

#header directories
HEADERS = -I ../common \
          -I ../lock \
          -I ../reset

#flags for profiling (see hacker.doc for more information)
PROFILE = -g -pg

#Directory which holds object files
OBJDIR = ./obj

#any global include files
GLOBAL_INCLUDE = tree.h 

LIBDIR = ../../lib
LIBNAME = libtree.a

#########################################################################

CFLAGS = $(MYFLAGS) $(PROFILE)

OBJFILES = $(OBJDIR)/ab_tree.o         \
           $(OBJDIR)/movetree.o        \
           $(OBJDIR)/print.o           \
           $(OBJDIR)/score.o           \
           $(OBJDIR)/test_ab.o         \
           $(OBJDIR)/tree.o

$(LIBDIR)/$(LIBNAME) : $(GLOBAL_INCLUDE) $(OBJFILES)
	@echo '****'
	@echo '**** Making ResetTree library'
	@echo '****'
	rm -f $(LIBDIR)/$(LIBNAME) && ar -cvq $(LIBDIR)/$(LIBNAME) $(OBJFILES)

$(OBJDIR)/%.o : %.cpp $(GLOBAL_INCLUDE)
	$(CC) $(HEADERS) -c $(CFLAGS) $< -o $@

clean : 
	rm -f $(LIBDIR)/$(LIBNAME)
	rm -f $(OBJDIR)/*

