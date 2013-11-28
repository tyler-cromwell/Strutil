#!/bin/bash
clear
echo "Building..."
gcc -c -g -std=gnu99 -Wall -ggdb -I ~/Code/C/Projects/include ./strutil.c -o ../lib/strutil.o
echo "Build Complete."
