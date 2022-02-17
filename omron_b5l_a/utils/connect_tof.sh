sudo modprobe usbserial vendor=0x0590 product=0x00ca
sudo chgrp dialout /dev/ttyUSB0
sudo chmod 666 /dev/ttyUSB0
sudo adduser $USER dialout
