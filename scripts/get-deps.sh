#!/bin/bash

if command -v dnf &> /dev/null; then
    sudo dnf install -y git autoconf automake g++ make libtool texinfo help2man ncurses-devel libtinyxml2-devel cmake cdrdao python pandoc
elif command -v apt &> /dev/null; then
    sudo apt install build-essential libtinyxml2-dev git cmake cdrdao python pandoc
fi