#include <stdio.h>
#include <stdlib.h>
#include "headers/type.h"
#include "headers/stack.h"


/*
1. Go on reading characters from source file until End-of-file is reached
2. PUSH each character read into the stack.
3. When done, POP characters from the stack and write them into the destination file until stack is underflow.

for this I need to define a stack of characters

-fopen file in read mode. 
-read file and put each character into stack
-fopen file in append mode.
-for each character in the stack fputc into new file. 

*/

int reverseText(char source[], char dest[]){
    FILE *fps, *fpd;
    const int SIZE = 50;

    Stack 

    fps = fopen(source, "r"); //read mode
    if(fps == NULL){
        printf("Error opening file %s\n ", source);
        return 0;
    }

    fpd = fopen(dest, "w");
    if(fpd == NULL){
        printf("Error opening file %s\n", dest);
        return 0;
    }

    
}

int main ()
{


}