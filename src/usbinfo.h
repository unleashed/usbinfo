#ifndef __USBINFO_H__
#define __USBINFO_H__

#include <stddef.h>

int get_usb_info(const char *path, size_t maxlen, char *devpath, char *idvendor, char *idproduct, char *manufacturer, char *product, char *serial);

#endif
