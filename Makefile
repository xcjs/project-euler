# This Makefile will be overly documented to provide a reference to GNU Make
# (myself being new to C++ and Make) and to assist others who may wish to learn
# from this project.

# The CC variable tells Make to use the specified compiler for this project (g++
# in this case).

CC = g++

# CFLAGS is a list of parameters to pass to the compiler.
#
# -Wall tells g++ to display all compiler warnings.

CFLAGS = -Wall

OUTPUT = obj/

MKDIR_P = mkdir -p

all: environment euler

.PHONY: environment
environment:
	$(MKDIR_P) $(OUTPUT)

euler: environment
	$(CC) $(CFLAGS) src/main.cpp -o $(OUTPUT)euler