
#include <stdio.h>
#include <stdlib.h>
#include "../common/stack-double/headers/type.h"
#include "../common/stack-double/headers/stack.h"

/*
prefix notation: +5/*233
read the expression from right to left. 

1. Push each operand into the stack.
2. When an operator is reached, pop the last two operands from the stack
   and save them in the variables operand1,operand2 respectively. 
3. Apply the operator on the operand1 and operand2 variables, like such and push the new operand to the stack: 
   result_operand = operand1 (+,-,*,/) operand2. 


*/

double eval_prefix_notation(char expr[]){
    Stack s1; 
    init(&s1,30);
    int i = 0;
    char c = '0';
  
    while(c != '\0'){
        c = expr[i];
        // printf("atof(&c) : %0.2f \n &c: %s \n c: %d \n", atof(&c), &c,c);
        if(c != '\0'){
            push(&s1,atof(&c));
        }
        i++;
    }

    for(int i = 0; i <= s1.top; i++){
        printf("%0.2f\n", s1.item[i]);
    }
    return 0;
}

int main() {

    eval_prefix_notation("333");
    return 0;
}