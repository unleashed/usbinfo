## usbinfo

A small tool to quickly extract vendor information from USB devices.

Copyright (c) 2013 Alejandro Martinez Ruiz <alex at flawedcode dot org>
Licensed under the GPL version 3 or (at your option) any later version.
See https://www.gnu.org/licenses/ for more information.

## Installing

### Requirements

libudev and its development files are required. Please install the corresponding
package, and note that in systemd-enabled OSes this library might as well live
under some sort of systemd package.

### Building

This project uses GNU autotools for configuration.

Run `./autogen.sh`, then `./configure` and then `make install` as usual.
