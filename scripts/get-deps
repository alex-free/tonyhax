#!/bin/bash

if command -v dnf &> /dev/null; then

    if [ $EUID != 0 ]; then
        echo "Info: root privilages are required to install build dependencies"
        sudo dnf install -y git autoconf automake g++ make libtool texinfo help2man ncurses-devel tinyxml2-devel cmake cdrdao python libstdc++-static.i686 glibc-static.i686 libstdc++-static.x86_64 mingw64-gcc mingw32-gcc mingw32-gcc-c++ mingw64-gcc-c++ python3-numpy
    else
        dnf install -y git autoconf automake g++ make libtool texinfo help2man ncurses-devel tinyxml2-devel cmake cdrdao python pip libstdc++-static.i686 glibc-static.i686 libstdc++-static.x86_64 mingw64-gcc mingw32-gcc mingw32-gcc-c++ mingw64-gcc-c++ python3-numpy
    fi
elif command -v apt &> /dev/null; then

    if [ $EUID != 0 ]; then
        echo "Info: root privilages are required to install build dependencies"
        sudo apt install --yes build-essential libtinyxml2-dev git cmake cdrdao python3 python3-pip pipx autoconf texinfo help2man gawk libtool-bin libtool ncurses-dev gcc-multilib mingw-w64-tools python3-numpy g++-multilib gcc-multilib mingw-w64-tools g++-mingw-w64 zip dpkg-dev
    else
        apt install --yes build-essential libtinyxml2-dev git cmake cdrdao python3 autoconf texinfo help2man gawk libtool-bin libtool ncurses-dev gcc-multilib mingw-w64-tools python3-numpy g++-multilib gcc-multilib mingw-w64-tools g++-mingw-w64 zip dpkg-dev
    fi
else
    echo "Package manager is not apt or dnf, please add support for it here!"
    exit 1
fi
