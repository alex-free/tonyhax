#!/bin/bash

cd "$(dirname "$0")"
set -e
cd ../
cp -rv *.md ~/dev/alex-free.github.io/tonyhax-international
rm -rf ~/dev/alex-free.github.io/tonyhax-international/images
cp -rv images ~/dev/alex-free.github.io/tonyhax-international