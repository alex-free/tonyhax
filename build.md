# Building From Source

1) Install the `mipsel-none-elf` toolchain. The easist way is to use my [PSN00bSDK Builder](https://alex-free.github.io/psn00bsdk-builder):

`git clone https://github.com/alex-free/psn00bsdk-builder`

`cd psn00bsdk-builder`

`./build.sh`

`cd ../`

2) Clone Tonyhax International **recursively** from GitHub:

`git clone --recursive https://github.com/alex-free/tonyhax`


3) Install the required dependencies:

`cd tonyhax`

`make deps`

Build Tonyhax International:

`make`