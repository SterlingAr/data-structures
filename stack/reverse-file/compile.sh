#!/bin/bash
#in order, specify output file, main function source file and library to use
echo "" > reversed-text.txt
gcc -o reversefile reversefile.c ../common/stack-char/stack_utils_char.a
