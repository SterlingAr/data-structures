#include <stdio.h>
#include <stdlib.h>
#include "../headers/type.h"

void init(Stack *sp, int size)
{
    sp->top = -1;
    sp->item = (int *)malloc(sizeof(int) * size);

    if(sp->item == NULL)
    {
        printf("Unable to allocate memory. \n");
        exit(1);
    }
    sp->size = size;
}


int isOverflow(Stack *sp)
{
    return sp->top == sp->size-1;
}


void push(Stack *sp, int value)
{
    if(isOverflow(sp))
    {
        //move elements from old array to bigger array
        int *temp;
        temp = (int *)malloc(sizeof(int) * sp->size * 2);

        int i;
        for(i=0; i <= sp->top; i++)
        {
            temp[i] = sp->item[i];
        }
        free(sp->item);
        sp->item = temp;
        sp->size *= 2;
    }

    sp->top++;
    sp->item[sp->top] = value;
}

int isUnderflow(Stack *sp)
{
    return sp->top == -1;
}


int pop(Stack *sp)
{
    if(isUnderflow(sp))
    {
        printf("Stack underflow\n");
        return -9999; //function must always return integer
    }
    int v;
    v = sp->item[sp->top];
    sp->top--;
    return v;
}

void deallocate(Stack *sp)
{
    if(sp->size != NULL)
    {
        free(sp->item);
    }
    sp->top = -1;
    sp->size = 0;

}

int getSize(Stack *sp)
{

    return  sp->size;
}

