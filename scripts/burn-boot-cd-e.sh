#!/bin/bash

cd "$(dirname "$0")"
cd ../boot-cd
# no need for --swap since disc has no audio tracks
cdrdao write --driver generic-mmc-raw --speed 1 --eject -n tonyhax-boot-cd-europe.cue 
