#compiler name
CC = g++

#compiler flags you want to use (other than profiling)
MYFLAGS = -O3

#flags for profiling (see hacker.doc for more information)
PROFILE = -g -pg

LIBDIR = ../lib

#static libraries to include (reverse dependency order)
LIBS = -L $(LIBDIR) \
       -ltree \
       -lreset \
       -llock \
       -lcommon \
       -lpthread

#header directories
HEADERS = -I ./tree \
          -I ./reset \
          -I ./lock \
          -I ./common

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
                 timer.h     

#########################################################################

CFLAGS = $(MYFLAGS) $(PROFILE)

#OPENINGS = b_k4_kga.o

OBJFILES = $(OBJDIR)/ab.o              \
           $(OBJDIR)/chess.o           \
           $(OBJDIR)/constants.o       \
           $(OBJDIR)/engine.o          \
           $(OBJDIR)/file.o            \
           $(OBJDIR)/game.o            \
           $(OBJDIR)/hash.o            \
           $(OBJDIR)/logger.o          \
           $(OBJDIR)/search.o          \
           $(OBJDIR)/test_main.o       \
           $(OBJDIR)/timer.o           \
           $(OBJDIR)/xboard.o 

all: $(EXECUTABLE)

$(EXECUTABLE) : $(OBJFILES)

# Dependencies for the main prog
# Order:
#   common
#   reset

# Main Program
all : $(EXECUTABLE)

$(EXECUTABLE) : $(GLOBAL_INCLUDE) libcommon liblock libreset libtree $(OBJFILES)
	$(CC) $(MYFLAGS) $(PROFILE) -o $(EXECUTABLE) $(OBJFILES) $(LIBS)

$(OBJDIR)/%.o : %.cpp $(GLOBAL_INCLUDE) 
	$(CC) $(HEADERS) -c $(CFLAGS) $< -o $@

libcommon :
	$(MAKE) -C common
	
liblock :
	$(MAKE) -C lock
	
libreset :
	$(MAKE) -C reset
	
libtree :
	$(MAKE) -C tree
	
clean : 
	$(MAKE) -C common clean
	$(MAKE) -C lock clean
	$(MAKE) -C reset clean
	$(MAKE) -C tree clean
	rm -f $(EXECUTABLE) $(OBJFILES)

tarball :
	tar cf openings.tar openings

