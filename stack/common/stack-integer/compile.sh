#first create the object files from the source files
rm obj/stack.o ||:
rm stack_utils_integer.a ||:
gcc -c -o  obj/stack.o source/stack.c
#create the library using the object files
/usr/bin/ar -cvq stack_utils_integer.a obj/stack.o


