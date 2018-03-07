C=gcc
CXX=g++
RM=rm -f
CPPFLAGS= -std=c++11
LDFLAGS=
LDLIBS= -lm

SRCS=main.cpp fifo.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: fifo_bin
debug: CPPFLAGS+=-g
debug: LDFLAGS+=-g
debug: fifo_bin

fifo_bin: $(OBJS)
	$(CXX) $(LDFLAGS)  $(OBJS) -o fifo_bin  $(LDLIBS) 

main.o: main.cpp fifo.h

fifo.o: fifo.cpp fifo.h

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) fifo_bin

