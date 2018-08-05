#include <stdio.h>
#include <stdlib.h>
#include "../common/stack-char/headers/type.h"
#include "../common/stack-char/headers/stack.h"
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
    int c;
    const int SIZE = 50;
  
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

    Stack temp;
    init(&temp,SIZE);

    //read character one by one(returned byt fputc) and push them to the stack
    do {
        c = fgetc (fps);
        push(&temp,  c);
    } while (c != EOF);
    fclose(fps);

    for(int i = temp.top; i >= 0; i--){
        fputc(temp.item[i], fpd);
    }
    

    return 0;
    
}

int main ()
{

    int f = reverseText("text.txt", "reversed-text.txt");
    return 0;

}