#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>

#include "xstring.h"

int xsnprintf(char *str, size_t size, int truncate_ok, const char *format, ...)
{
	int ret;
	va_list ap;

	va_start(ap, format);

	ret = vsnprintf(str, size, format, ap);
	if (ret < 0 || (ret >= size && !truncate_ok))
		ret = -1;

	va_end(ap);

	return ret;
}

char *xstrncpy(char *dest, const char *src, size_t n)
{
	strncpy(dest, src, n);
	dest[n-1] = '\0';

	return dest;
}

char *xstrncat(char *dest, const char *src, size_t n)
{
	/* strncat requires dest to have space for an extra \0, while we just take the whole size */
	strncat(dest, src, n - 1);

	return dest;
}
