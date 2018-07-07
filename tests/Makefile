# Compiler flags
CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 -pipe -O0 -ggdb -pg -D DEBUG
IFLAGS  = -I ../


# Files
LIB = ../debug/libstrutil.a
SRCS = test_contains.c \
       test_ends_with.c \
       test_index_of.c \
       test_indices_of.c
       #$(wildcard ./*.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))
EXES = $(patsubst %.c, %, $(SRCS))


.PHONY: all clean

# Default build
all: $(EXES)

$(EXES): $(OBJS)
	$(CC) -o $@ $< $(LIB)

%.o: %.c
	$(CC) -c $(CFLAGS) $(IFLAGS) -o $@ $<

# Other rules
clean:
	rm -rf $(EXES)
	rm -rf $(OBJS)
	rm -rf gmon.out
