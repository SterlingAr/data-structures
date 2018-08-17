#!/bin/bash
rm main ||:
gcc -o main main.c ../common/stack-char/stack_utils_char.a
