#compiler name
CC = g++

#compiler flags you want to use (other than profiling)
MYFLAGS = -O3

#flags for profiling (see hacker.doc for more information)
PROFILE = -g -pg

LIBDIR = ../lib

#static libraries to include (reverse dependency order)
LIBS = -L $(LIBDIR) \
       -lgame \
       -ltree \
       -lreset \
       -llock \
       -llogger \
       -lcommon \
       -lpthread

#header directories
HEADERS = -I ./game \
          -I ./tree \
          -I ./reset \
          -I ./lock \
          -I ./logger \
          -I ./common

#Directory which holds object files
OBJDIR = ../obj

#name of executable
EXECUTABLE = chessica

#any global include files
GLOBAL_INCLUDE = chess.h     \
                 constants.h \
                 hash.h      \
                 timer.h     

#########################################################################

CFLAGS = $(MYFLAGS) $(PROFILE)

#OPENINGS = b_k4_kga.o

OBJFILES = $(OBJDIR)/chess.o           \
           $(OBJDIR)/constants.o       \
           $(OBJDIR)/file.o            \
           $(OBJDIR)/hash.o            \
           $(OBJDIR)/test_main.o       \
           $(OBJDIR)/timer.o           

all: $(EXECUTABLE)

$(EXECUTABLE) : $(OBJFILES)

# Dependencies for the main prog
# Order:
#   common
#   reset

# Main Program
all : $(EXECUTABLE)

$(EXECUTABLE) : $(GLOBAL_INCLUDE) libcommon liblock liblogger libreset libtree libgame $(OBJFILES)
	$(CC) $(MYFLAGS) $(PROFILE) -o $(EXECUTABLE) $(OBJFILES) $(LIBS)

$(OBJDIR)/%.o : %.cpp $(GLOBAL_INCLUDE) 
	$(CC) $(HEADERS) -c $(CFLAGS) $< -o $@

libcommon :
	$(MAKE) -C common
	
liblock :
	$(MAKE) -C lock
	
liblogger :
	$(MAKE) -C logger
	
libreset :
	$(MAKE) -C reset
	
libtree :
	$(MAKE) -C tree
	
libgame :
	$(MAKE) -C game
	
clean : 
	$(MAKE) -C common clean
	$(MAKE) -C lock clean
	$(MAKE) -C logger clean
	$(MAKE) -C reset clean
	$(MAKE) -C tree clean
	rm -f $(EXECUTABLE) $(OBJDIR)/*

tarball :
	tar cf openings.tar openings

