#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Error: incorrect number of arguments. The first and only argument must be the version number of Tonyhax International that this diff is comparing to the original Tonyhax."
    exit 1
fi

cd "$(dirname "$0")"

if [ -e "../docs/tonyhax-vs-tonyhax-international-diffs/tonyhax-international-v"$1".diff" ]; then
    echo "Error: the file docs/tonyhax-vs-tonyhax-international-diffs/tonyhax-international-v"$1".diff already exists, please choose a different name as to not overwrite the previous diff"
    exit 1
fi

set -e
cd ../
make clean
tmp=$(mktemp -d --tmpdir og-tonyhax.XXX)
git clone https://github.com/socram8888/tonyhax "$tmp"
git diff --no-index "$tmp"/loader loader > docs/tonyhax-vs-tonyhax-international-diffs/tonyhax-international-v"$1".diff
rm -rf "$tmp"
