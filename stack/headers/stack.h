#ifndef STACK_H
#define STACK_H



//type agnostic
int pop(Stack *);
void init(Stack *, int);
void deallocate(Stack *);
int getSize(Stack *);
int isOverflow(Stack *);
int isUnderflow(Stack *);

//prototype declarations
void push (Stack *, int);


//push character
void push_c (Stack *, char);
#endif