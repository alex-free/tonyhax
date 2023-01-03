#!/bin/bash
set -e
cd "$(dirname "$0")"/../mkpsxiso
git submodule update --init --recursive
rm -rf ./build
cmake -S . -B ./build -DCMAKE_BUILD_TYPE=Release
cmake --build ./build