#!/bin/bash
test -f Makefile && make distclean
rm -rf config.* configure autom4te.cache aclocal.m4 src/config.h src/stamp-h1 src/.deps src/*.o src/usbinfo src/version_data.h GIT-VERSION-FILE NEWS AUTHORS COPYING INSTALL README depcomp install-sh missing
find . -type f -name "*.in" -delete
find . -type f -name "Makefile" -delete
