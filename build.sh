#!/bin/bash
clear
echo "Building..."
gcc -c -g -std=gnu99 ./StrUtil.c -o ../lib/StrUtil.o
echo "Build Complete."
