CC           = gcc
CFLAGS       = -std=c11 -pedantic -Wall -Wextra -march=native -fpic
IFLAGS 		 = ./
LIBFLAGS     = -shared
DEBUGFLAGS   = -O0 -ggdb3 -D DEBUG
RELEASEFLAGS = -O2

NAME    = strutil
TARGET  = lib$(NAME).so
HEADER  = $(NAME).h
SOURCES = $(shell find ./ -name '*.c')
OBJECTS = $(SOURCES:.c=.o)

PREFIX = $(DESTDIR)/usr/local
LIBDIR = $(PREFIX)/lib
INCLUDEDIR = $(PREFIX)/include/$(NAME)


all: $(TARGET)

$(TARGET): CFLAGS += $(RELEASEFLAGS)
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -I $(IFLAGS) $(LIBFLAGS) -o $(TARGET) $(SOURCES)

debug: CFLAGS += $(DEBUGFLAGS)
debug: $(OBJECTS)
	$(CC) $(CFLAGS) -I $(IFLAGS) $(LIBFLAGS) -o $(TARGET)-debug $(OBJECTS)

profile: CFLAGS += -pg
profile: debug

install: all
	install -D $(TARGET) $(LIBDIR)/$(TARGET)
	install -D $(HEADER) $(INCLUDEDIR)/$(HEADER)
	ldconfig

install-strip: all
	install -D -s $(TARGET) $(LIBDIR)/$(TARGET)
	install -D $(HEADER) $(INCLUDEDIR)/$(HEADER)
	ldconfig

uninstall:
	rm -f $(LIBDIR)/$(TARGET)
	rm -f $(INCLUDEDIR)/$(HEADER)
	rmdir $(INCLUDEDIR)
	ldconfig

clean:
	-rm -f $(OBJECTS)
	-rm -f $(TARGET)-debug

distclean: clean
	-rm -f $(TARGET)


.SECONDEXPANSION:

$(foreach OBJ,$(OBJECTS),$(eval $(OBJ)_DEPS = $(shell $(CC) -MM $(OBJ:.o=.c) | sed s/.*://)))
%.o: %.c $$($$@_DEPS)
	$(CC) $(CFLAGS) -I $(IFLAGS) -c -o $@ $<


.PHONY: all profile debug install install-strip uninstall clean distclean
