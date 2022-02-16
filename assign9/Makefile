#
#  Sample Makefile for C programs 
#  hw6.c  list.c  list.h  mystruct.c  mystruct.h  queue.c  queue.h  stack.c  stack.h

# the name of this package. 
# The library and tar file, if any, will be named after it.
PACKAGE  = hw9
# The executable program
TARGET   = hw9
# The C source programs (.c) [multiple files]
# SOURCES  = list
# The C+ source program for testing your implementation
TEST     = hw9
#O_DIR    = O_$(HOSTTYPE)
SYSDIR   = /usr/local
CLASSDIR = $(SYSDIR)/class/cp2
BASEDIR  = .
INCDIR   = $(BASEDIR)/include 
LIBDIR   = -L$(BASEDIR)/lib #-L/usr/openwin/lib -L/usr/ucblib
LIBS     = $(LIBDIR) -lm -lc 

# You may not need to modify anything below

CXX      = gcc
CXXFLAGS = -std=c99 -Wall -I$(INCDIR) 
TARG     = $(TARGET)
LIB      = lib$(PACKAGE)_$(HOSTTYPE).a

SRCS     = ${SOURCES:%=%.c}
OBJS     = ${SRCS:%.c=%.o}
HEADERS  = ${SRCS:%.c=%.h} 
TESTSRC  = ${TEST:%=%.c}
TESTOBJ  = ${TESTSRC:%.c=%.o}
MAKEDEP  = makedepend

$(TARG) : $(O_DIR) $(OBJS) $(TESTOBJ)
	$(CXX) -o $@ $(CXXFLAGS) $(OBJS) $(TESTOBJ) $(LIBS) 

#$(O_DIR) :
#	mkdir $@

lib : $(O_DIR) $(LIB)
	@echo $@ Built

$(LIB) : $(OBJS)
	rm -f $(LIB)
	ar cr $@ $(OBJS)
	ranlib $@

%.o: %.c
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean: 
	rm -f $(OBJS) $(TESTOBJ) $(TARG) core* *~ Makefile.bak 


tags: 
	etags $(SRCS) $(HEADERS)

ztar:
	tar zcvf $(PACKAGE).tgz Makefile $(SRCS) $(HEADERS) $(TESTSRC) 

ci:
	ci -l Makefile $(SRCS) $(HEADERS) $(TESTSRC) 

depend : 
	$(MAKEDEP) -p$(O_DIR)/ -I$(INCDIR) $(SRCS) $(TESTSRC)

# DO NOT DELETE THIS LINE -- make depend depends on it.

