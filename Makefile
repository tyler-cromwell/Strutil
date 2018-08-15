# Names
NAME = strutil
HEADER = $(NAME).h
ARCHIVE = lib$(NAME).a
LNNAME = lib$(NAME).so
SONAME = $(LNNAME).2
TARGET = $(SONAME).0


# Compiler flags
AR      = ar
CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 -fPIC -pipe
IFLAGS  =
LDFLAGS = -shared -Wl,-Bsymbolic,-soname,$(SONAME)


# Files
SRCS = strutil_contains.c \
       strutil_ends_with.c \
       strutil_index_of.c \
       strutil_indices_of.c \
       strutil_insert.c \
       strutil_lcs.c \
       strutil_lowercase.c \
       strutil_remove.c \
       strutil_remove_each.c \
       strutil_replace_all.c \
       strutil_reverse.c \
       strutil_split.c \
       strutil_substring.c \
       strutil_trim.c \
       strutil_uppercase.c
OBJS = $(SRCS:.c=.o)


# Directories
PREFIX = $(DESTDIR)/usr
LIBDIR = $(PREFIX)/lib64
INCDIR = $(PREFIX)/include/$(NAME)


# Debug build settings
DBGDIR = debug
DBGSLIB = $(DBGDIR)/$(TARGET)
DBGALIB = $(DBGDIR)/$(ARCHIVE)
DBGOBJS = $(addprefix $(DBGDIR)/, $(OBJS))
DBGCFLAGS = -O0 -ggdb -pg -D DEBUG


# Release build settings
RELDIR = release
RELSLIB = $(RELDIR)/$(TARGET)
RELALIB = $(RELDIR)/$(ARCHIVE)
RELOBJS = $(addprefix $(RELDIR)/, $(OBJS))
RELCFLAGS = -O2


.PHONY: all clean debug release

# Default build
all: debug release


# Debug rules
debug: prep_debug $(DBGSLIB) $(DBGALIB)

$(DBGSLIB): $(DBGOBJS)
	$(CC) -o $(DBGSLIB) $^ $(LDFLAGS)

$(DBGALIB): $(DBGOBJS)
	$(AR) -r $(DBGDIR)/$(ARCHIVE) $^

$(DBGDIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $(DBGCFLAGS) -o $@ $<


# Release rules
install: release
	install -D $(HEADER) $(INCDIR)/$(HEADER)
	install -D $(RELDIR)/$(TARGET) $(LIBDIR)/$(TARGET)
	ln -fs $(SONAME) $(LIBDIR)/$(LNNAME)
	ldconfig

install-strip: release
	install -D $(HEADER) $(INCDIR)/$(HEADER)
	install -D -s $(RELDIR)/$(TARGET) $(LIBDIR)/$(TARGET)
	ln -fs $(SONAME) $(LIBDIR)/$(LNNAME)
	ldconfig

release: prep_release $(RELSLIB) $(RELALIB)

$(RELSLIB): $(RELOBJS)
	$(CC) -o $(RELSLIB) $^ $(LDFLAGS)

$(RELALIB): $(RELOBJS)
	$(AR) -r $(RELDIR)/$(ARCHIVE) $^

$(RELDIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $(RELCFLAGS) -o $@ $<


# Other rules
prep_debug:
	mkdir -p $(DBGDIR)/

prep_release:
	mkdir -p $(RELDIR)/

clean:
	rm -rf $(DBGDIR)/
	rm -rf $(RELDIR)/

uninstall:
	rm -rf $(LIBDIR)/$(LNNAME)
	rm -rf $(LIBDIR)/$(SONAME)
	rm -rf $(LIBDIR)/$(TARGET)
	rm -rf $(INCDIR)/$(HEADER)
	rmdir $(INCDIR)
	ldconfig
