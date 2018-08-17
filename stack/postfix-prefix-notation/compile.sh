#!/bin/bash
rm main ||:
gcc -o main main.c ../common/stack-double/stack_utils_double.a
