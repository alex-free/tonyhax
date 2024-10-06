#!/bin/bash
set -e
cd "$(dirname "$0")"/../
export PATH="${PWD}"/crosstool-ng/toolchain/bin:"${PWD}"/mkpsxiso/build:"$PATH"
make clean
make -C loader -f Makefile.tocperfect
size loader/secondary.elf
