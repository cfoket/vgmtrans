#!/bin/sh
set -e
cd `dirname "$0"`/src
echo 'C:\MinGW\ /MinGW' > /etc/fstab
mkdir build
cd build
cmake .. -G "MSYS Makefiles"  -D CMAKE_C_COMPILER="C:\Qt\5.5\mingw492_32\bin\gcc" -D CMAKE_CXX_COMPILER="C:\Qt\5.5\mingw492_32\g++"
make