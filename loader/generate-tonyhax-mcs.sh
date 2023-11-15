#!/bin/bash

set -euo pipefail

if [ $# -ne 4 ]; then
	echo "Usage: $0 raw-binary tpl-file mcs-file version"
	exit 1
fi

raw_binary="$1"
tpl_file="$2"
mcs_file="$3"
version="$4"

# Set addresses
if [ "$2" = "tonyhax-tpl-ff9-16kb.mcs" ]; then
	ro_start="801F4380"
elif [ "$2" = "tonyhax-tpl-16kb.mcs" ]; then
	ro_start="801F6200"
else
	echo "Error: Unknown what to specify ro_start for $2"
	exit 1
fi
echo "$ro_start"

# Create temporary file for the binary
bin_file=$(mktemp)
mv secondary.raw $bin_file

# Round filesize to nearest 128-byte block
truncate --size=%128 $bin_file
load_len=$(printf "%08X" $(stat -c %s $bin_file))

# Create file
cp "$tpl_file" "$mcs_file"
echo -n "tonyhax-i ${version}" | dd status=none conv=notrunc bs=1 seek=132 of="$mcs_file"
dd status=none conv=notrunc bs=1 seek=384 if=$bin_file of="$mcs_file"

# Insert address at 0xC0 and length at 0xC4, which is 0x40 and 0x44 inside the save file header
echo -ne "\x${ro_start:6:2}\x${ro_start:4:2}\x${ro_start:2:2}\x${ro_start:0:2}\x${load_len:6:2}\x${load_len:4:2}\x${load_len:2:2}\x${load_len:0:2}" | dd status=none conv=notrunc of="$mcs_file" bs=1 seek=192

# Cleanup
rm $bin_file
