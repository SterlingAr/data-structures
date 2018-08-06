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
    char c;
    init(&temp,SIZE);

    //read character one by one(returned byt fputc) and push them to the stack untill EOF 
    do {
        c = fgetc (fps);
        push(&temp,  c);
    } while (c != EOF);


    for(int i = temp.top; i >= 0; i--){
        fputc(temp.item[i], fpd);
    }

    //close file pointers and deallocate the memory. 
    fclose(fps);
    fclose(fpd);
    deallocate(&temp);

    return 1;
    
}

int main ()
{

    int f = reverseText("text.txt", "reversed-text.txt");

    if(f) {
        printf("File reversed successfully\n");
    } else {
        printf("An error ocurred while reversing the text file");
    }
    return 0;

}