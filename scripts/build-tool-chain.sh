#!/bin/bash

set -e
cd "$(dirname "$0")"/../crosstool-ng
./bootstrap
./configure --enable-local
make clean
make
cp ../ct-ng-config .config
rm -rf src
mkdir src
./ct-ng build
../scripts/build-mkpsxiso.sh
