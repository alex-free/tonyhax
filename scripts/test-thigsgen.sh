#!/bin/bash

set -e
cd "$(dirname "$0")"/../thigsgen
make clean

rm -rf TONYHAXINTGS0 test-1 test-2 test-3 test-4 test-5 test-6 test-7 test-8 test-9 test-10 test-11 test-12

make

if [ "$1" = "--clean" ]; then
    exit 0
fi

../gameshark/thigsgen test-1.txt
mkdir test-1
mv TONYHAXINTGS0 test-1/TONYHAXINTGS

../gameshark/thigsgen test-2.txt
mkdir test-2
mv TONYHAXINTGS0 test-2/TONYHAXINTGS

../gameshark/thigsgen test-3.txt
mkdir test-3
mv TONYHAXINTGS0 test-3/TONYHAXINTGS

../gameshark/thigsgen test-4.txt
mkdir test-4
mv TONYHAXINTGS0 test-4/TONYHAXINTGS

../gameshark/thigsgen test-5.txt
mkdir test-5
mv TONYHAXINTGS0 test-5/TONYHAXINTGS

../gameshark/thigsgen test-6.txt
mkdir test-6
mv TONYHAXINTGS0 test-6/TONYHAXINTGS

../gameshark/thigsgen test-7.txt
mkdir test-7
mv TONYHAXINTGS0 test-7/TONYHAXINTGS

../gameshark/thigsgen test-8.txt
mkdir test-8
mv TONYHAXINTGS0 test-8/TONYHAXINTGS

../gameshark/thigsgen test-9.txt
mkdir test-9
mv TONYHAXINTGS0 test-9/TONYHAXINTGS

../gameshark/thigsgen test-10.txt
mkdir test-10
mv TONYHAXINTGS0 test-10/TONYHAXINTGS

../gameshark/thigsgen test-11.txt
mkdir test-11
mv TONYHAXINTGS0 test-11/TONYHAXINTGS

../gameshark/thigsgen test-12.txt
mkdir test-12
mv TONYHAXINTGS0 test-12/TONYHAXINTGS
