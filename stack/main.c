#include <stdio.h>
#define SIZE 10

typedef struct 
{
    int item[SIZE];
    int top;
}Stack;

//prototype declarations
void push (Stack *, int);
int pop(Stack *);

int main()
{
    Stack s1, s2;
    return 0;
}