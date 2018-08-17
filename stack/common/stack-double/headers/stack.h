#ifndef STACK_H
#define STACK_H

//prototype declarations
void push(Stack *, double);
double pop(Stack *);
void init(Stack *, int);
void deallocate(Stack *);
int getSize(Stack *);
int isOverflow(Stack *);
int isUnderflow(Stack *);

#endif