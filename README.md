# What is Strutil?

  Strutil is a simple string library that I've been using to supplement the string functions in the [C Standard Library][C Standard Library]. It originally spawned from [T-Shell][T-Shell].

## Functions
  - `contains`: Tests if a sequence is contained in a string.
  - `endsWith`: Tests if a string ends with a given token.
  - `indexOf`: Gets the FIRST index of a character within a string.
  - `indexesOf`: Gets ALL indexes of a character withing a string
  - `lowercase`: Sets all letters to lowercase.
  - `removeThese`: Removes all given characters from a string.
  - `replaceAll`: Replaces each occurence of a character with a new character in a string.
  - `split`: Splits a string at each occurence of a token. Returns an array of Strings.
  - `startsWith`: Tests if a string starts with a given token.
  - `substring`: Gets a substring within a given range.
  - `trim`: Trims the leading and trailing spaces in a string.
  - `uppercase`: Sets all letters to uppercase.

## Documentation

  Man pages are on the way! For now read the comments above each function.

## Contributing
  Submit a pull request! Upon submission I will review any and all changes.

## Bugs
  All bugs and other issues should be reported on the github issue tracker.

## Building

  To use Strutil...<br>
	1) Insert `#include <strutil/strutil.h>` into your source file(s).<br>
	2) Compile with the `-lstrutil` flag.<br>
  It's as easy as that!

## Dependencies
  - glibc (2.16 or later) ([GNU C Library][Glibc])
  - gcc ([GNU Compiler Collection][GCC]) OR clang ([Clang][Clang]/[LLVM][LLVM])

## How to Install
  1) `./configure`<br>
  2) `make`<br>
  3) Install...<br>
  - `[sudo] make install` (with debug symbols)<br>
  - `[sudo] make install-strip` (without)<br>
  Note: The default compiler is [Clang][Clang], but feel free to change it.<br>

## How to Uninstall
  1) Run `[sudo] make uninstall`<br>
  That's it...

[T-Shell]: https://github.com/tyler-cromwell/T-Shell

[C Standard Library]: http://en.wikipedia.org/wiki/C_standard_library
[Glibc]: http://en.wikipedia.org/wiki/GNU_C_Library
[GCC]: http://en.wikipedia.org/wiki/GNU_Compiler_Collection
[Clang]: http://en.wikipedia.org/wiki/Clang
[LLVM]: http://en.wikipedia.org/wiki/LLVM

[Gmake]: http://www.gnu.org/software/make/
