#compiler name
CC = g++

#compiler flags you want to use (other than profiling)
MYFLAGS = -O3 -lpthread -fPIC

#flags for profiling (see hacker.doc for more information)
PROFILE = -g -pg
#PROFILE = 

#static libraries to include
LIBS = -L../lib -lreset \
       -L/usr/lib/x86_64-linux-gnu -lcppunit -ldl \
       -static

#header directories
HEADERS = -I ../src/common \
          -I ../src/reset 

#Directory which holds object files
OBJDIR = ../obj

#any global include files
GLOBAL_INCLUDE = 

#########################################################################

CFLAGS = $(MYFLAGS) $(PROFILE)

OBJFILES = $(OBJDIR)/test_chess.o \
           $(OBJDIR)/test_reset.o

all: $(OBJFILES) $(GLOBAL_INCLUDE) test_chess

$(OBJDIR)/%.o : %.cpp $(GLOBAL_INCLUDE)
	$(CC) $(HEADERS) -c $(CFLAGS) $< -o $@

# Declare the test programs indiviually
test_chess: $(OBJFILES) $(GLOBAL_INCLUDE)
	$(CC) -o test_chess $(OBJFILES) $(LIBS)

clean : 
	rm -f $(OBJFILES)

