#!/bin/bash
aclocal
autoconf
autoheader
automake --foreign --add-missing --copy
