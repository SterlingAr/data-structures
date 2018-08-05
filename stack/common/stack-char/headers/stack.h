#ifndef STACK_H
#define STACK_H

//prototype declarations
void push(Stack *, char);
int pop(Stack *);
void init(Stack *, char);
void deallocate(Stack *);
int getSize(Stack *);
int isOverflow(Stack *);
int isUnderflow(Stack *);

#endif