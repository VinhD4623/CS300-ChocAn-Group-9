# Comprehensive Makefile for C++ projects (Atleast on PSU Linux Servers)
# This will automatically compile any .cpp files in the current directory.
# Some of the syntax was adapted from:
# https://gist.github.com/Wenchy/64db1636845a3da0c4c7
# http://nuclear.mutantstargoat.com/articles/make/

CC = g++
CFLAGS := -std=c++11

exe_file = run

# Handle debug case
DEBUG ?= 1
ifeq ($(DEBUG), 1)
	CFLAGS += -g -Wall
else
	CFLAGS += -DNDEBUG -O3
endif

SRCDIR = .
SRCEXT = cpp
SOURCES = $(shell find $(SRCDIR) -type f -name "*.$(SRCEXT)")
OBJECTS = $(SOURCES:.cpp=.o)
DEP = $(OBJECTS:.o=.d)

$(exe_file): $(OBJECTS)
	$(CC) $^ -o $(exe_file)

-include $(DEP)

%.d: %.$(SRCEXT)
	@$(CC) $(CFLAGS) $< -MM -MT $(@:.d=.o) >$@

%.o: %.$(SRCEXT)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.out *.o *.d $(exe_file)

.PHONY: clean

.PHONY: val
val:
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes --track-origins=yes ./monster 
