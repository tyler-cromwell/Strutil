#!/bin/bash
clear
echo "Building..."
gcc -c -g -std=gnu99 -ggdb ./strutil.c -o ../lib/strutil.o
echo "Build Complete."
