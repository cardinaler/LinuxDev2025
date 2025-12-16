#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([Guess your number game], [0.0.1], [BUG-REPORT-ADDRESS], [prog])
AM_INIT_AUTOMAKE([foreign])
LT_INIT([disable-static])
DX_INIT_DOXYGEN([prog])
AC_CONFIG_SRCDIR([src/prog.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
PKG_CHECK_MODULES([CHECK],[check])

# Checks for header files.
AC_CHECK_HEADERS([libintl.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([setlocale])

AC_CONFIG_FILES([Makefile src/Makefile Doxyfile tests/Makefile po/Makefile])
AC_OUTPUT
