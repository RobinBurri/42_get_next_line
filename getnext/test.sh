#!/bin/bash
echo BUFFER_SIZE = 1
gcc -D BUFFER_SIZE=1 *.c
./a.out
echo BUFFER_SIZE = 42
gcc -D BUFFER_SIZE=42 *.c
./a.out
echo BUFFER_SIZE = 1000
gcc -D BUFFER_SIZE=1000 *.c
./a.out
echo BUFFER_SIZE = 1000000
gcc -D BUFFER_SIZE=1000000 *.c
./a.out
