#!/bin/bash

cd "$(dirname "$0")"
cd ../boot-cd
cdrdao write --speed 1 --eject tonyhax-boot-cd.cue 
