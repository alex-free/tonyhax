#!/bin/bash
set -e
cd "$(dirname "$0")"
./gen-html.sh
cd ../
export PATH="${PWD}"/crosstool-ng/toolchain/bin:"${PWD}"/mkpsxiso/build:"$PATH"
make clean
make

