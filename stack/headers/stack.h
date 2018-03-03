#ifndef STACK_H
#define STACK_H

//prototype declarations
void init(Stack *, int);
void push (Stack *, int);
int pop(Stack *);
void deallocate(Stack *);
int getSize(Stack *);

#endif