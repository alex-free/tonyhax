#!/bin/bash
set -e
cd "$(dirname "$0")"
cd ../
export PATH="${PWD}"/crosstool-ng/toolchain/bin:"${PWD}"/mkpsxiso/build:"$PATH"
make clean
# git doesn't allow us to store empty directories...
mkdir -p gshax/wipeout-usa
mkdir -p gshax/parasite-eve-usa
mkdir -p gshax/ridge-racer-usa
make

