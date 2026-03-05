# [Tonyhax International](readme.md) -> Building From Source

_Note:_ Currently requires a Linux distro with either the `dnf` or `apt` package manager.

1) Clone Tonyhax International **recursively** from GitHub:

`git clone --recursive https://github.com/alex-free/tonyhax`

2) Install the toolchain and additional required build dependencies:

`cd tonyhax`

`make toolchain deps`

3) Add the toolchain to your $PATH for the current shell:

`psn00b-env`

4) Build Tonyhax International:

`make`
