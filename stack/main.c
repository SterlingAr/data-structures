#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int *item;
    int top;
    int size; 
}Stack;

//prototype declarations
void init(Stack *, int);
void push (Stack *, int);
int pop(Stack *);
void deallocate(Stack *);
void getSize(Stack *);
void init(Stack *sp, int size)
{
    sp->top = -1;
    sp->item = (int *) malloc(sizeof(int) * size);
    if(sp->item == NULL)
    {
        printf("Unable to allocate memory \n");
        exit(1);
    }
    sp->size = size;
}

void push(Stack *sp, int value)
{
    if(sp->top == sp->size -1)
    {
        //move elements from old array to bigger arry
        int *temp;
        temp = (int *) malloc(sizeof(int) * sp->size * 2)
        if(temp == NULL)
        {
            printf("Stack overflow\n");
            return;
        }
        int i;
        for(i=0;i<=sp->top;i++)
        {
            temp[i] = sp->item[i];
        }
        free(sp->item);
        sp->item = temp;
    } 
    sp->top++;
    sp->item[sp->top] = value;
}

int pop(Stack *sp)
{
    if(sp->top == -1)
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

void getSize(Stack *sp)
{
    return sp->size;
}


int main()
{
    Stack s1;
    init(&s1,3);
    
    printf("1. Push \n");
    printf("2. Pop \n");
    printf("3. Exit \n");

    int choice,value;

    while(1)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("Size of the Stack: %d \n", getSize(&s1));
        switch(choice)
        {
            case 1: printf("Enter value: ");
                    scanf("%d", &value);
                    push(&s1, value);
                    break;
            case 2: 
                    value = pop(&s1);
                    if (value != -9999)
                    {
                        printf("Poped data\n");
                    }
                    break;
            case 3:  deallocate(&s1); 
                     exit(0);
            
        }
    }
    return 0;
}