#!/bin/sh
gcc -O2 -lm -o main main.c
./main > data.d
gnuplot plot.p
