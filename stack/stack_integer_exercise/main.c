#include <stdio.h>
#include <stdlib.h>
#include "../common/stack-integer/headers/type.h"
#include "../common/stack-integer/headers/stack.h"

int main()
{
    Stack s1,s2;
    init(&s1,3);
    init(&s2,6);
    
    printf("1. Push integer\n");
    printf("2. Push character\n");
    printf("3. Pop \n");
    printf("4. Current size \n");
    printf("5. Free slots \n");

    printf("5. Exit \n");

    int choice,value,currentSize;

    while(1)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        currentSize = getSize(&s1);

        switch(choice)
        {
            case 1: printf("Enter integer value: ");
                    scanf("%d", &value);
                    push(&s1, value);
                    break;
            case 2: printf("Enter character: ");
                    // scanf("%s", &value);
                    // push_c(&s2, value);
            case 3: 
                    value = pop(&s1);
                    if (value != -9999)
                    {
                        printf("Poped data\n");
                    }
                    break;
            case 4: 
                    printf("Size of the Stack: %d \n", getSize(&s1));
                    break;

            case 5:  deallocate(&s1); 
                     exit(0);
            
        }
    }
    return 0;
}
