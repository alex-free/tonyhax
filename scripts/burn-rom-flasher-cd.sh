#!/bin/bash

cd "$(dirname "$0")"
cd ../rom
cdrdao write --speed 1 --swap --eject tonyhax-rom-flasher.cue