#compiler name
CC = g++

#compiler flags you want to use (other than profiling)
MYFLAGS = -O3 -lpthread -fPIC

#libraries to use
LIBS = -lpthread

#flags for profiling (see hacker.doc for more information)
PROFILE = -g -pg
#PROFILE = 

#Directory which holds object files
OBJDIR = ../../obj

#any global include files
GLOBAL_INCLUDE = constants.h  \
                 reset.h  

#########################################################################

CFLAGS = $(MYFLAGS) $(PROFILE)

OBJFILES = $(OPENINGS) \
           $(OBJDIR)/bishop.o      \
           $(OBJDIR)/capture.o     \
           $(OBJDIR)/init.o        \
           $(OBJDIR)/io.o          \
           $(OBJDIR)/king.o        \
           $(OBJDIR)/knight.o      \
           $(OBJDIR)/moves.o       \
           $(OBJDIR)/pawn.o        \
           $(OBJDIR)/print.o       \
           $(OBJDIR)/queen.o       \
           $(OBJDIR)/reset.o       \
           $(OBJDIR)/rook.o        \
           $(OBJDIR)/safe.o        \
           $(OBJDIR)/score.o       \
           $(OBJDIR)/test_safe.o 

all: $(OBJFILES)
	gcc -shared -o libreset $(OBJFILES)

$(OBJDIR)/%.o : %.cpp $(GLOBAL_INCLUDE)
	$(CC) -c $(CFLAGS) $< -o $@

clean : 
	rm -f $(OBJDIR)/*.o

