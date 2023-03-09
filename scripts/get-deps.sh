#!/bin/bash

set -e
if command -v dnf &> /dev/null; then
    sudo dnf install -y git autoconf automake g++ make libtool texinfo help2man ncurses-devel tinyxml2-devel cmake cdrdao python pip
elif command -v apt &> /dev/null; then
    sudo apt install --yes build-essential libtinyxml2-dev git cmake cdrdao python python3-pip
fi

pip3 install numpy
