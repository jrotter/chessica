#compiler name
CC = g++

#compiler flags you want to use (other than profiling)
MYFLAGS = -O3

#header directories
HEADERS = -I ../common

#flags for profiling (see hacker.doc for more information)
PROFILE = -g -pg

#Directory which holds object files
OBJDIR = ./obj

#any global include files
GLOBAL_INCLUDE = constants_reset.h  \
                 reset.h            \
                 score.h

LIBDIR = ../../lib
LIBNAME = libreset.a

#########################################################################

CFLAGS = $(MYFLAGS) $(PROFILE)

OBJFILES = $(OBJDIR)/bishop.o              \
           $(OBJDIR)/capture.o             \
           $(OBJDIR)/constants.o           \
           $(OBJDIR)/init.o                \
           $(OBJDIR)/io_reset.o            \
           $(OBJDIR)/king.o                \
           $(OBJDIR)/knight.o              \
           $(OBJDIR)/moves.o               \
           $(OBJDIR)/pawn.o                \
           $(OBJDIR)/print.o               \
           $(OBJDIR)/queen.o               \
           $(OBJDIR)/reset.o               \
           $(OBJDIR)/rook.o                \
           $(OBJDIR)/safe.o                \
           $(OBJDIR)/score.o               \
           $(OBJDIR)/test_reset_helpers.o  \
           $(OBJDIR)/test_safe.o 

$(LIBDIR)/$(LIBNAME) : $(GLOBAL_INCLUDE) $(OBJFILES)
	@echo '****'
	@echo '**** Making Reset library'
	@echo '****'
	rm -f $(LIBDIR)/$(LIBNAME) && ar -cvq $(LIBDIR)/$(LIBNAME) $(OBJFILES)

$(OBJDIR)/%.o : %.cpp $(GLOBAL_INCLUDE)
	$(CC) $(HEADERS) -c $(CFLAGS) $< -o $@

clean : 
	rm -f $(LIBDIR)/$(LIBNAME)
	rm -f $(OBJDIR)/*

