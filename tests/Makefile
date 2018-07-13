# Variables
CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 -pipe -O0 -ggdb -pg -D DEBUG
IFLAGS  = -I ../
LIB = ../debug/libstrutil.a


.PHONY: all clean

# Default build
EXES = test_contains \
       test_ends_with \
       test_index_of \
       test_indices_of \
       test_lowercase \
       test_remove_each \
	   test_replace_all \
	   test_split

all: $(EXES)

test_contains: test_contains.o
	$(CC) -o $@ $< $(LIB)

test_ends_with: test_ends_with.o
	$(CC) -o $@ $< $(LIB)

test_index_of: test_index_of.o
	$(CC) -o $@ $< $(LIB)

test_indices_of: test_indices_of.o
	$(CC) -o $@ $< $(LIB)

test_lowercase: test_lowercase.o
	$(CC) -o $@ $< $(LIB)

test_remove_each: test_remove_each.o
	$(CC) -o $@ $< $(LIB)

test_replace_all: test_replace_all.o
	$(CC) -o $@ $< $(LIB)

test_split: test_split.o
	$(CC) -o $@ $< $(LIB)

#test_substring: test_substring.o
#	$(CC) -o $@ $< $(LIB)

#test_trim: test_trim.o
#	$(CC) -o $@ $< $(LIB)

#test_uppercase: test_uppercase.o
#	$(CC) -o $@ $< $(LIB)

%.o: %.c
	$(CC) -c $(CFLAGS) $(IFLAGS) -o $@ $<

# Other rules
clean:
	rm -rf $(EXES)
	rm -rf *.o
	rm -rf gmon.out
