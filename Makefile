CC=clang
WARNINGS=-Wall -Wextra -Werror
SOURCE= $(wildcard ./src/*.c)
INCLUDE=-I ./include
SHARED=libstrutil.so
PATH_INCLUDE=/usr/include

libstrutil.o: $(SOURCE)
	$(CC) $(INCLUDE) -c -pedantic -O2 -fpic -pipe -march=native $(WARNINGS) $(SOURCE)
	$(CC) $(INCLUDE) -shared $(WARNINGS) ./*.o -o $(SHARED)
	rm -f ./*.o

.PHONY: install
install:
	chown root:root $(SHARED)
	chcon -u system_u -t lib_t $(SHARED)
	mv ./$(SHARED) /lib
	mkdir -p $(PATH_INCLUDE)/strutil
	cp ./include/strutil.h $(PATH_INCLUDE)/strutil
	ldconfig

.PHONY: uninstall
uninstall:
	rm -f /lib/$(SHARED)
	rm -rf $(PATH_INCLUDE)/strutil
	ldconfig
