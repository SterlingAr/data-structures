rm ./obj/stack.o ||:
rm ./stack_utils_char.a ||:

gcc -c -o  obj/stack.o source/stack.c
#create the library using the object files
/usr/bin/ar -cvq stack_utils_char.a obj/stack.o
