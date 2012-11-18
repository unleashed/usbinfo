bin_PROGRAMS = usbinfo
nodist_usbinfo_SOURCES = version_data.h

BUILT_SOURCES = version_data.h
DISTCLEANFILES = version_data.h

AM_CFLAGS = $(libudev_CFLAGS)

usbinfo_SOURCES = main.c usbinfo.c xstring.c
noinst_HEADERS = usbinfo.h xstring.h

usbinfo_LDADD = $(libudev_LIBS)

version_data.h: Makefile
	../scripts/make-version
