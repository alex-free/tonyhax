#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Error: incorrect number of arguments. The first and only argument must be the filepath of the DuckStation executable"
    exit 1
fi

set -e
"$1" "$(dirname "$0")"/../boot-cd/tonyhax-boot-cd-europe.cue
