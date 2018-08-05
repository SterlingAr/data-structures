#ifndef STACK_H
#define STACK_H

//prototype declarations

//type agnostic
int pop(Stack *);
void init(Stack *, int);
void deallocate(Stack *);
int getSize(Stack *);
int isOverflow(Stack *);
int isUnderflow(Stack *);

//push integers
void push(Stack *, int);
//push character
// void push_c(Stack *, char);

#endif