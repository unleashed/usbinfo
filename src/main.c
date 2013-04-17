/*
 *  usbinfo - Copyright (c) 2013 Alejandro Martinez Ruiz <alex at flawedcode dot org>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.

 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.

 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
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
