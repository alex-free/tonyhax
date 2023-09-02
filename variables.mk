
.DELETE_ON_ERROR:

.PHONY: clean

TONYHAX_VERSION=v1.3.9
CFLAGS=-Os -Wall -Wextra -Wno-main -Werror -mfp32 -mno-abicalls -fno-pic -fdata-sections -ffunction-sections -fno-builtin -nostdlib -DTONYHAX_VERSION=$(TONYHAX_VERSION)
