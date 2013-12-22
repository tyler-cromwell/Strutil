CC=clang
CFLAGS=-c -std=gnu99 -Wall -g -ggdb
SOURCE= $(wildcard ./strutil.c)
INCLUDE=-I ~/Code/C/Projects/include
OUT=-o
OBJ=strutil.o

all:
	$(CC) $(CFLAGS) $(INCLUDE) $(SOURCE) $(OUT) $(OBJ)
	cp ./strutil.h ../T-Shell/include/strutil.h
	mv ./$(OBJ) ../T-Shell/lib/$(OBJ)
