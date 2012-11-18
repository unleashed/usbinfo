#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

PACKAGE=usbinfo
VERSION=0.1.0

AC_PREREQ([2.69])

AC_INIT([usbinfo], [0.1.0], [support@nowcomputing.com])
AC_CONFIG_SRCDIR([src/usbinfo.c])
AC_CONFIG_HEADERS([src/config.h])

AM_INIT_AUTOMAKE($PACKAGE, $VERSION)

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_MAKE_SET

# Checks for libraries.
PKG_CHECK_MODULES([libudev], [libudev >= 175])

# Checks for header files.
AC_CHECK_HEADERS([stddef.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T
AC_CHECK_MEMBERS([struct stat.st_rdev])

# Checks for library functions.

AC_OUTPUT(Makefile src/Makefile)
