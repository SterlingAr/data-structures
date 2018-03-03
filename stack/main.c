#include <stdio.h>
#include <stdlib.h>
#include "headers/type.h"
#include "headers/stack.h"

int main()
{
    static Stack s1;
    init(&s1,2);
    
    printf("1. Push \n");
    printf("2. Pop \n");
    printf("3. Current size \n");

    printf("4. Exit \n");

    int choice,value,currentSize;

    while(1)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        currentSize = getSize(&s1);

        printf("Size of the Stack: %d \n", currentSize);
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
            case 3: 
                     printf("Size of the Stack: %d \n", getSize(&s1));
                     break;

            case 4:  deallocate(&s1); 
                     exit(0);
            
        }
    }
    return 0;
}