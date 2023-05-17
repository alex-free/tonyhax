#!/bin/bash

cd "$(dirname "$0")"
cd ../boot-cd
cdrdao write --device /dev/cdrom --driver generic-mmc-raw --speed 1 --eject -n tonyhax-boot-cd-europe.cue 