#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([Strutil], [1.1.0], [tyler@csh.rit.edu], [strutil], [https://github.com/tyler-cromwell/Strutil])
AC_CONFIG_SRCDIR([src/strutil_removeThese.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([foreign -Wall -Werror -Wportability])

# Checks for programs.
AC_PROG_CC_STDC
AM_PROG_CC_C_O
AM_PROG_AR

# Checks for header files.
AC_CHECK_HEADERS([stdio.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_REALLOC
AC_CHECK_FUNCS([memset])

AC_CONFIG_FILES([Makefile src/Makefile])
LT_INIT([disable-static pic-only])
AC_OUTPUT
