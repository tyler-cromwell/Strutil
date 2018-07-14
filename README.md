# What is Strutil?
Strutil is a simple string library that I've been using to supplement the string functions in the [C Standard Library][C Standard Library].

## Functions
- `contains`: Tests if a sequence is contained in a string.
- `ends_with`: Tests if a string ends with a given token.
- `index_of`: Gets the FIRST index of a character within a string.
- `indices_of`: Gets ALL indexes of a character withing a string
- `insert`: Inserts a string at the specified index.
- `lowercase`: Sets all letters to lowercase.
- `remove`: Removes characters from a string in the given range.
- `remove_each`: Removes all given characters from a string.
- `replace_all`: Replaces each occurence of a character with a new character in a string.
- `reverse`: Reverses the contents of a string.
- `split`: Splits a string at each occurence of a token. Returns an array of Strings.
- `starts_with`: Tests if a string starts with a given token.
- `substring`: Gets a substring within a given range.
- `trim`: Trims the leading and trailing spaces in a string.
- `uppercase`: Sets all letters to uppercase.

## Building
To use Strutil...<br>
1. Insert `#include <strutil/strutil.h>` into your source file(s).<br>
2. Compile with the `-lstrutil` flag.<br>

## Dependencies
- glibc (2.16 or later) ([GNU C Library][Glibc])
- gcc ([GNU Compiler Collection][GCC]) OR clang ([Clang][Clang]/[LLVM][LLVM])

## How to Install
```
$ make
$ sudo make install
```

## How to Uninstall
```
$ sudo make uninstall
```

## Contributing
Submit a pull request! Upon submission I will review any and all changes.

## Bugs
All bugs and other issues should be reported on the github issue tracker.


[C Standard Library]: http://en.wikipedia.org/wiki/C_standard_library
[Glibc]: http://en.wikipedia.org/wiki/GNU_C_Library
[GCC]: http://en.wikipedia.org/wiki/GNU_Compiler_Collection
[Clang]: http://en.wikipedia.org/wiki/Clang
[LLVM]: http://en.wikipedia.org/wiki/LLVM

[Gmake]: http://www.gnu.org/software/make/
