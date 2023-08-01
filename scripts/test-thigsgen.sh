#!/bin/bash

set -e
cd "$(dirname "$0")"/../gameshark
make clean
make

rm -rf TONYHAXINTGS test-1 test-2 test-3 test-4 test-5 test-6 test-7 test-8 test-9 test-10 test-11 test-12

./thigsgen test-1.txt
mkdir test-1
mv TONYHAXINTGS test-1/TONYHAXINTGS

./thigsgen test-2.txt
mkdir test-2
mv TONYHAXINTGS test-2/TONYHAXINTGS

./thigsgen test-3.txt
mkdir test-3
mv TONYHAXINTGS test-3/TONYHAXINTGS

./thigsgen test-4.txt
mkdir test-4
mv TONYHAXINTGS test-4/TONYHAXINTGS

./thigsgen test-5.txt
mkdir test-5
mv TONYHAXINTGS test-5/TONYHAXINTGS

./thigsgen test-6.txt
mkdir test-6
mv TONYHAXINTGS test-6/TONYHAXINTGS

./thigsgen test-7.txt
mkdir test-7
mv TONYHAXINTGS test-7/TONYHAXINTGS

./thigsgen test-8.txt
mkdir test-8
mv TONYHAXINTGS test-8/TONYHAXINTGS

./thigsgen test-9.txt
mkdir test-9
mv TONYHAXINTGS test-9/TONYHAXINTGS

./thigsgen test-10.txt
mkdir test-10
mv TONYHAXINTGS test-10/TONYHAXINTGS

./thigsgen test-11.txt
mkdir test-11
mv TONYHAXINTGS test-11/TONYHAXINTGS

./thigsgen test-12.txt
mkdir test-12
mv TONYHAXINTGS test-12/TONYHAXINTGS