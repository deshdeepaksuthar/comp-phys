#!/bin/sh
gcc -lm -o main main.c
./main > data.d
gnuplot plot.p
