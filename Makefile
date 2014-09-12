# This Makefile will be overly documented to provide a reference to GNU Make
# (myself being new to C++ and Make) and to assist others who may wish to learn 
# from this project.

# The CC variable tells Make to use the specified compiler for this project (g++ 
# in this case).

CC = g++

# CFLAGS is a list of parameters to pass to the compiler.
#
# -Wall tells g++ to display all compiler warnings.

CFLAGS = -Wall -fpic

SRC = src/
LIBEULERSRC = $(SRC)libeuler/
LIBPROBLEMSSRC = $(LIBEULERSRC)problems/

OUTPUT = obj/

MKDIR_P = mkdir -p

all: environment libeuler euler

.PHONY: environment
environment:
	$(MKDIR_P) $(OUTPUT)

LIBEULERFILES = $(LIBPROBLEMSSRC)ProblemFactory.cpp $(LIBPROBLEMSSRC)ProblemFactory.h

libeuler: environment
	$(CC) $(CFLAGS) -c $(LIBEULERFILES) -o $(OUTPUT)libeuler.a

EULERDEPS = $(OUTPUT)libeuler.a

euler: $(EULERDEPS) environment
	$(CC) $(CFLAGS) $(SRC)euler.cpp -o $(OUTPUT)euler.o