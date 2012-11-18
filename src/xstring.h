#ifndef __XSTRING_H__
#define __XSTRING_H__

#include <stddef.h>

int xsnprintf(char *str, size_t size, int truncate_ok, const char *format, ...);
char *xstrncpy(char *dest, const char *src, size_t n);
/* NOTE: xstrncat requires n to be the whole size for dest, not size minus 1! */
char *xstrncat(char *dest, const char *src, size_t n);

#endif
