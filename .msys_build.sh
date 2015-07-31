#!/bin/sh
set -e
PATH=$PATH:/mingw64/bin:/mingw32/bin;
cd `dirname "$0"`/src
echo 'C:\MinGW\ /MinGW' > /etc/fstab
mkdir build
cd build
#cmake -G "MSYS Makefiles" ..
cmake -G "MSYS Makefiles" ..

make