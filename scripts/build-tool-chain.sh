#!/bin/bash
set -e
cd "$(dirname "$0")"/../
cd crosstool-ng
./bootstrap
./configure --enable-local
make clean
make
cp ../.config .config
mkdir src
./ct-ng build
cd ../mkpsxiso
rm -rf ./build
cmake -S . -B ./build -DCMAKE_BUILD_TYPE=Release
cmake --build ./build