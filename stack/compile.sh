#first create the object files from the source files
rm obj/stack.o
rm stackxutils.a
rm main
gcc -c -o obj/stack.o source/stack.c
#create the library using the object files
/usr/bin/ar -cvq stackxutils.a obj/stack.o
#in order, specify output file, main function source file and library to use
gcc -o main main.c stackxutils.a
