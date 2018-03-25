#include <stdio.h>
#include <stdlib.h>
#include "headers/type.h"
#include "headers/stack.h"

void printBinary(unsigned int);

void printBinary(unsigned int n)
{
    Stack s;
    init(&s, 50);
    const int BASE = 2;
    while(n>0)
    {
        int rem = n % BASE;
        push(&s, rem);
        n = n / BASE;
    }
    //pop number at the top of the stack and show on screen 
    //deallocate memory on finish
    //note: use '->' only if left operand is a pointer.
    while(!isUnderflow(&s))
    {
        printf("%d", pop(&s));
    }
    deallocate(&s);
}

int main ()
{
    printBinary(50);

    return 0;
}