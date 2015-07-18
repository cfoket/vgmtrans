#!/bin/sh
set -e
echo 'C:\MinGW\ /MinGW' > /etc/fstab
cd src
mkdir build
cd build
cmake .. -G "MSYS Makefiles"
make