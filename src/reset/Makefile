#compiler name
CC = g++

#compiler flags you want to use (other than profiling)
MYFLAGS = -O3 -fPIC

#libraries to use
LIBS = -L../../lib -lhelpers \
       -static

#header directories
HEADERS = -I ../helpers

#flags for profiling (see hacker.doc for more information)
PROFILE = -g -pg

#Directory which holds object files
OBJDIR = ../../obj

#any global include files
GLOBAL_INCLUDE = constants.h  \
                 reset.h  

LIBDIR = ../../lib
LIBNAME = libreset.a

#########################################################################

CFLAGS = $(MYFLAGS) $(PROFILE)

OBJFILES = $(OPENINGS) \
           $(OBJDIR)/bishop.o      \
           $(OBJDIR)/capture.o     \
           $(OBJDIR)/init.o        \
           $(OBJDIR)/io_reset.o    \
           $(OBJDIR)/king.o        \
           $(OBJDIR)/knight.o      \
           $(OBJDIR)/moves.o       \
           $(OBJDIR)/pawn.o        \
           $(OBJDIR)/print_reset.o \
           $(OBJDIR)/queen.o       \
           $(OBJDIR)/reset.o       \
           $(OBJDIR)/rook.o        \
           $(OBJDIR)/safe.o        \
           $(OBJDIR)/score.o       \
           $(OBJDIR)/test_safe.o 

all: $(OBJFILES) $(GLOBAL_INCLUDE)
	ar -cvq $(LIBDIR)/$(LIBNAME) $(OBJFILES)

$(OBJDIR)/%.o : %.cpp $(GLOBAL_INCLUDE)
	$(CC) $(HEADERS) -c $(CFLAGS) $< -o $@

clean : 
	rm -f $(OBJFILES)

