# [Tonyhax International](readme.md) -> Building From Source

1) Install the `mipsel-none-elf` toolchain. The easist way is to use my [PSN00bSDK Builder](https://alex-free.github.io/psn00bsdk-builder):

`git clone https://github.com/alex-free/psn00bsdk-builder`

`cd psn00bsdk-builder`

`./build.sh`

`cd ../`

2) Clone Tonyhax International **recursively** from GitHub:

`git clone --recursive https://github.com/alex-free/tonyhax`


3) Add psn00bsdk to $PATH for the current shell (if you had used the psn00bsdk-builder):

`psn00b-env`

4) Install the required dependencies:

`cd tonyhax`

`make deps`

5) Build Tonyhax International:

`make`