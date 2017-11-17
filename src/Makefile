#compiler name
CC = g++

#compiler flags you want to use (other than profiling)
MYFLAGS = -O3

#flags for profiling (see hacker.doc for more information)
PROFILE = -g -pg

#static libraries to include
LIBS = -L../lib -lcommon \
       -lreset \
       -lpthread \
       -static

#header directories
HEADERS = -I reset \
          -I common

#Directory which holds object files
OBJDIR = ../obj

#name of executable
EXECUTABLE = chessica

#any global include files
GLOBAL_INCLUDE = chess.h     \
                 constants.h \
                 game.h      \
                 hash.h      \
                 logger.h    \
                 score.h     \
                 timer.h     \
                 tree.h

#########################################################################

CFLAGS = $(MYFLAGS) $(PROFILE)

#OPENINGS = b_k4_kga.o

OBJFILES = $(OPENINGS) \
           $(OBJDIR)/ab.o              \
           $(OBJDIR)/chess.o           \
           $(OBJDIR)/constants.o       \
           $(OBJDIR)/engine.o          \
           $(OBJDIR)/file.o            \
           $(OBJDIR)/game.o            \
           $(OBJDIR)/hash.o            \
           $(OBJDIR)/logger.o          \
           $(OBJDIR)/io.o              \
           $(OBJDIR)/lock.o            \
           $(OBJDIR)/movetree.o        \
           $(OBJDIR)/print.o           \
           $(OBJDIR)/score_resettree.o \
           $(OBJDIR)/search.o          \
           $(OBJDIR)/test_ab.o         \
           $(OBJDIR)/test_main.o       \
           $(OBJDIR)/timer.o           \
           $(OBJDIR)/tree.o            \
           $(OBJDIR)/xboard.o 
#OBJs = $(addprefix $(OBJDIR)/$(OBJFILES)

all: $(EXECUTABLE)

common:
	$(MAKE) -C common
reset:
	$(MAKE) -C reset

$(EXECUTABLE) : $(OBJFILES) reset common

# Dependencies for the main prog
# Order:
#   common
#   reset

# Main Program

$(OBJDIR)/%.o : %.cpp $(GLOBAL_INCLUDE)
	$(CC) $(HEADERS) -c $(CFLAGS) $< -o $@

$(EXECUTABLE) : $(GLOBAL_INCLUDE)
	$(CC) $(MYFLAGS) -o $(EXECUTABLE) $(PROFILE) $(OBJFILES) $(LIBS)

clean : 
	rm -f $(EXECUTABLE) $(OBJFILES)

tarball :
	tar cf openings.tar openings

