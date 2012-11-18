#include <stdio.h>
#include "usbinfo.h"

int main(int argc, char *argv[])
{
	int ret = -1;
	char devpath[128];
	char idvendor[128];
	char idproduct[128];
	char manufacturer[128];
	char product[128];
	char serial[128];

	if (argc < 2) {
		fprintf(stderr, "Usage: %s <device_or_mountpoint>\n", *argv);
		goto out;
	}

	ret = get_usb_info(argv[1], 128, devpath, idvendor, idproduct, manufacturer, product, serial);

	if (ret >= 0) {
		fprintf(stderr,	"Dev path\t= %s\n"
				"Vendor ID\t= %s\n"
				"Product ID\t= %s\n"
				"Manufacturer\t= %s\n"
				"Product\t\t= %s\n"
				"Serial Number\t= %s\n",
				devpath, idvendor, idproduct, manufacturer, product, serial);
	} else {
		fprintf(stderr, "Failed to get USB info\n");
	}

out:
	return (ret < 0);
}
