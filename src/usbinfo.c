#include <libudev.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "xstring.h"

#include "usbinfo.h"

static struct udev_device *device_get_from_path(struct udev *udev, const char *path)
{
	struct stat st;
	dev_t dev;

	if (stat(path, &st) < 0) {
		return NULL;
	}

	if (S_ISBLK(st.st_mode)) {
		dev = st.st_rdev;
	} else {
		dev = st.st_dev;
	}

	return udev_device_new_from_devnum(udev, 'b', dev);
}

static struct udev_device *device_get_root_usb_device(struct udev *udev, const char *path, struct udev_device **rootdev)
{
	/* Security through (micro) Obscurity (tm) */
	char obscured_usb[] = { 'v', 't', 'c', 0 };
	char obscured_usb_device[] = { 'v', 't', 'c', 96, 'e', 'f', 'w', 'j', 'd', 'f', 0 };
	char *p;
	struct udev_device *dev;

	dev = NULL;

	if (rootdev == NULL)
		goto err;

	*rootdev = device_get_from_path(udev, path);
	if (*rootdev == NULL) {
		goto err;
	}

	p = obscured_usb;
	do {
		(*p)--;
	} while (*++p);

	p = obscured_usb_device;
	do {
		(*p)--;
	} while (*++p);

	dev = udev_device_get_parent_with_subsystem_devtype(*rootdev, obscured_usb, obscured_usb_device);

err:
	return dev;
}

static int device_get_info(struct udev_device *dev, size_t maxlen, char *devpath, char *idvendor, char *idproduct, char *manufacturer, char *product, char *serial)
{
	int ret = 0;

	if (devpath != NULL) {
		if (xsnprintf(devpath, maxlen, 1, "%s", udev_device_get_devnode(dev)) < 0)
			ret--;
	}
	if (idvendor != NULL) {
		if (xsnprintf(idvendor, maxlen, 1, "%s", udev_device_get_sysattr_value(dev, "idVendor")) < 0)
			ret--;
	}
	if (idproduct != NULL) {
		if (xsnprintf(idproduct, maxlen, 1, "%s", udev_device_get_sysattr_value(dev, "idProduct")) < 0)
			ret--;
	}
	if (manufacturer != NULL) {
		if (xsnprintf(manufacturer, maxlen, 1, "%s", udev_device_get_sysattr_value(dev,"manufacturer")) < 0)
			ret--;
	}
	if (product != NULL) {
		if (xsnprintf(product, maxlen, 1, "%s", udev_device_get_sysattr_value(dev,"product")) < 0)
			ret--;
	}
	if (serial != NULL)
		if (xsnprintf(serial, maxlen, 1, "%s", udev_device_get_sysattr_value(dev, "serial")) < 0)
			ret--;

	return ret;
}

int get_usb_info(const char *path, size_t maxlen, char *devpath, char *idvendor, char *idproduct, char *manufacturer, char *product, char *serial)
{
	int ret = -1;
	struct udev *udev;
	struct udev_device *rootdev = NULL, *dev;

	udev = udev_new();
	if (udev == NULL)
		goto err;

	dev = device_get_root_usb_device(udev, path, &rootdev);
	if (dev == NULL) {
		/* rootdev could be assigned, so check it and free if needed */
		if (rootdev)
			goto err_rootdev;
		goto err_dev;
	}

	if (device_get_info(dev, maxlen, devpath, idvendor, idproduct, manufacturer, product, serial) < 0)
		goto err_rootdev;

	ret = 0;

err_rootdev:
	udev_device_unref(rootdev);	/* also frees up dev if it was allocated */
err_dev:
	udev_unref(udev);
err:
	return ret;
}
