OS = $(shell uname)
CC = clang
CFLAGS = -pedantic -O2 -fPIC -pipe -march=native -Wall -Wextra -Werror
INCLUDES = -I ./include
LDFLAGS = -shared
SRC = $(wildcard ./src/*.c)
OBJS = $(SRC:c=o)
LIBRARY = libstrutil.so

.PHONY: all
all: $(LIBRARY)

$(LIBRARY): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(LIBRARY) $(OBJS) $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: install
install:
ifeq ($(OS),Linux)
	chown root:root $(LIBRARY)
	chcon -u system_u -t lib_t $(LIBRARY)
else ifeq ($(OS),FreeBSD)
	chown root:wheel $(LIBRARY)
	chmod 444 $(LIBRARY)
	chmod 444 $(wildcard ./include/*.h)
endif
	mv $(LIBRARY) /lib
	mkdir -p /usr/include/strutil
	cp ./include/strutil.h /usr/include/strutil
	ldconfig

.PHONY: uninstall
uninstall:
	rm -f /lib/$(LIBRARY)
	rm -rf /usr/include/strutil
	ldconfig

.PHONY: clean
clean:
	rm -rf ./src/*.o
