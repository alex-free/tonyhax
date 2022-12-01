#!/bin/bash

cd "$(dirname "$0")"
cd ../boot-cd
cdrdao write --speed 1 --swap --eject --device /dev/sr0 tonyhax-boot-cd-europe.cue 
