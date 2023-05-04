# THIGSGEN GNUMakefile by Alex Free
CC=gcc
CFLAGS=-Wall -Werror

clean-exe:
	rm -rf thigsgen.exe thigsgen

thigsgen: clean-exe
	$(CC) $(CFLAGS) thigsgen.c -o thigsgen

clean:
	rm -rf thigsgen.exe thigsgen linux_x86_64_static linux_x86_static windows_x86_64 windows_x86

linux-x86:
	make thigsgen CFLAGS="-m32 -static -Wall -Werror"

linux-x86_64:
	make thigsgen CFLAGS="-static -Wall -Werror"

windows-x86:
	make thigsgen CC="i686-w64-mingw32-gcc"

windows-x86_64:
	make thigsgen CC="x86_64-w64-mingw32-gcc"

linux-release:
	rm -rf $(PLATFORM)
	mkdir $(PLATFORM)
	cp -v thigsgen $(PLATFORM)

windows-release:
	rm -rf $(PLATFORM)
	mkdir $(PLATFORM)
	cp -v thigsgen.exe $(PLATFORM)/thigsgen.exe

linux-x86-release: linux-x86
	make linux-release PLATFORM=linux_x86_static

linux-x86_64-release: linux-x86_64
	make linux-release PLATFORM=linux_x86_64_static

windows-x86-release: windows-x86
	make windows-release PLATFORM=windows_x86

windows-x86_64-release: windows-x86_64
	make windows-release PLATFORM=windows_x86_64

all: linux-x86-release linux-x86_64-release windows-x86-release windows-x86_64-release
