# [Tonyhax International](readme.md) -> Building From Source

_Note:_ Currently requires a Linux distro with either the `dnf` or `apt` package manager.

## Step By Step

1) Clone Tonyhax International **recursively** from GitHub:

`git clone --recursive https://github.com/alex-free/tonyhax`

2) Install the toolchain and additional required build dependencies:

`cd tonyhax`

`make toolchain deps`

3) Add the toolchain to your $PATH for the current shell:

`psn00b-env`

4) Build Tonyhax International:

`make`

## Or if your into one liners

`git clone --recursive https://github.com/alex-free/tonyhax && cd tonyhax && make toolchain deps && psnoob-env && make`

After the one liner or all of the stteps, its the same. Make sure you have executed the `psnoob-env` command in your current shell (only need to once) then execute `make`.

## Additional Information For Devs

Despite this using the psn00bsdk-builder and `psn00bsdk-env` command, tonyhax international, like original tonyhax, does not actually use the psn00bsdk, or any sdk for that matter. It is bare metal mipsel-none-elf toolchain, I just use the psn00bsdk-builder I made because it happens to install said toolchain on more then just one OS (like the original tonyhax only supports debian, I don't even use debian I use fedora). There are compiler flags that actually force it to ignore the SDK bits, and that is on purpose for size optimization and the fact that this does not use any sdk funcs. Tonyhax original and Tonyhax just use the so called 'buggy' BIOS funcs or it's own code that we've both created.

Tonyhax International uses specific FreePSXBootBuilder and PS1Compressor/pcsx-redux-support commits as well since newer ones cause bugs. I hope eventually this can be sorted out with the creators of those programs but please do not update these submodules or you'll make/release something broken.

The newer FreePSXBoot builder doesn't work on PSOne (SCPH-100-SCPH-103, but it has been a long time since this was found so it may be fixed now but need to verify on real hardware since I've added some memory card reset functions since then), and the newer PS1 compressor breaks save game exploits and gshax (this was a very recent thing with v1.6.0-v1.6.1 of International so as of April 12th 2026 still an issue).

There are currently some warnings because I have been using GCC 12, these are pedantic and don't affect anything for the code.
