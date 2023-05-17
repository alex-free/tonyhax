#!/bin/bash

set -e
cd "$(dirname "$0")"
xxd -i ../mottzilla-stealth-cheat-engine/Stealth_CheatEngine.EXE
echo "Copy from first 0xE0 byte to last 0x00 byte BEFORE last 0x4D"
