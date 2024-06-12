#!/bin/bash

set -e
    echo "Sudo privilages may be required to install build dependencies"
if command -v dnf &> /dev/null; then
    sudo dnf install -y git autoconf automake g++ make libtool texinfo help2man ncurses-devel tinyxml2-devel cmake cdrdao python pip libstdc++-static.i686 glibc-static.i686 libstdc++-static.x86_64 mingw64-gcc mingw32-gcc mingw32-gcc-c++ mingw64-gcc-c++
elif command -v apt &> /dev/null; then
    sudo apt install --yes build-essential libtinyxml2-dev git cmake cdrdao python3 python3-pip autoconf texinfo help2man gawk libtool-bin libtool ncurses-dev gcc-multilib mingw-w64-tools
else
    echo "Package manager is not apt or dnf, please add support for it here!"
    exit 1
fi

pip3 install numpy
