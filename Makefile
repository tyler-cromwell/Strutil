CC=clang
CFLAGS=-c -std=gnu99 -Wall -g -ggdb
SOURCE= $(wildcard ./strutil.c)
INCLUDE=-I ~/Code/C/include
OUT=-o
OBJ=strutil.o

all:
	$(CC) $(CFLAGS) $(INCLUDE) $(SOURCE) $(OUT) $(OBJ)
	cp ./strutil.h ~/Code/C/include/strutil.h
	mv ./$(OBJ) ~/Code/C/lib/$(OBJ)
