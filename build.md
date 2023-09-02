# Building From Source

Obtain the **complete Tonyhax International current source tree from GitHub using git**, using the command below:

`git clone --recursive https://github.com/alex-free/tonyhax`

Next, install all the required dependencies:

* git 
* autoconf 
* automake
* g++ 
* make 
* libtool 
* texinfo 
* help2man 
* ncurses-devel 
* libtinyxml2-devel 
* cmake 
* cdrdao 
* python3
* python3-pip (and numpy, which is installed via this command: `pip3 install numpy`)

If you have the `dnf` or `apt` package manager, you can download the build dependencies automatically with the `get-deps.sh` script found in the `scripts` folder of the Tonyhax International [source tree](https//alex-free.github.io/tonyhax). **For any other OS, you'll need to find the above packages and install them manually yourself.** Please feel free to add support for your package manager.

Next, you need to build the tool-chain. Execute the `build-tool-chain.sh` script, which is found in the `scripts` directory of the source tree. **This will take some time to build, depending on how fast your computer is.**

With everything now installed, build Tonyhax International with the `build.sh` script found in the `scripts` directory of the Tonyhax International source tree. After you build Tonyhax International a release `.zip` file will be generated in the root of the source directory.