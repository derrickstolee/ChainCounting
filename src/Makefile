#
# Base Makefile for Progressions project.
#
TESTS 	=
 
TARGETS = chains.exe


OBJECTS = 	ChainManager.o	\
		chainfunctions.o	


CC 	= gcc
CXX = g++

OPT = -O0 -g 
# -O7
DEBUG =  
# -g 
# -static 
WARNINGS = -Wall


CFLAGS 		= $(OPT) $(DEBUG) $(WARNINGS)
CXXFLAGS 	= $(OPT) $(DEBUG) $(WARNINGS)
LFLAGS 		= $(OPT) $(DEBUG) $(WARNINGS)

TREESEARCHDIR = ../../TreeSearch

INCLUDES =  -I$(TREESEARCHDIR)

TREESEARCHOBJS	= $(TREESEARCHDIR)/SearchManager.o 
					
LIBOBJS			= $(TREESEARCHOBJS) $(NAUTYOBJS)
			
			
.SUFFIXES: .c .cpp .o .obj .exe 

all: $(OBJECTS) $(TESTS) $(TARGETS)


# The default object compiler
.c.o: $<
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) -c $< -o $@
        
.cpp.o: $<
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) -c $< -o $@
        
.cpp.exe: $< $(OBJECTS)  
	$(CXX) $(LFLAGS)			\
        	$(INCLUDES)	$(DEBUG)			\
        	$(LIBOBJS) $(LIBS)				\
        	`cat $@.objs`           		\
            $< -o $@
	cp $@ ../bin/
        
.c.exe: $< $(COBJECTS)
	$(CC) 	$(LFLAGS)			    \
        	$(INCLUDES)				\
        	$(NAUTYOBJS)  $(COBJECTS) $(LIBS)		\
            $< -o $@
	cp $@ ../bin/
        
clean:
	rm $(OBJECTS) $(TARGETS) $(TESTS)
	
cleanexe:
	rm $(TARGETS)

cleantest:
	rm $(TESTS)

clexe:
	rm $(TARGETS)
