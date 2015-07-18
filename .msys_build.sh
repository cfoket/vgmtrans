#!/bin/sh
set -e
cd `dirname "$0"`/../build
echo 'C:\MinGW\ /MinGW' > /etc/fstab
mkdir build
cd build
cmake .. -G "MSYS Makefiles"
make