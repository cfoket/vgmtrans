#!/bin/sh

cd src
mkdir build
cd build
cmake .. -G "MSYS Makefiles"
make