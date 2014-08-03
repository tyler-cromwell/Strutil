CC=clang
WARNINGS=-Wall -Wextra -Werror
SOURCE= $(wildcard ./src/*.c)
INCLUDE=-I ./include
OBJ=libstrutil.so
PATH_INCLUDE=/usr/include

libstrutil.o: $(SOURCE)
	$(CC) $(INCLUDE) -c -pedantic -O2 -fpic -pipe -march=native $(WARNINGS) $(SOURCE)
	$(CC) $(INCLUDE) -shared $(WARNINGS) -o $(OBJ) $(SOURCE)
	rm -f ./*.o

.PHONY: install
install:
	chown root:root $(OBJ)
	chcon -u system_u -t lib_t $(OBJ)
	mv ./$(OBJ) /lib
	mkdir -p $(PATH_INCLUDE)/strutil
	cp ./include/strutil.h $(PATH_INCLUDE)/strutil
	ldconfig

.PHONY: uninstall
uninstall:
	rm -f /lib/libstrutil.so
	rm -rf $(PATH_INCLUDE)/strutil
	ldconfig
