
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

//operand1 has priority
double evaluate(double operand1, double operand2, char operator){
    switch(operator){
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
    }
}

double eval_prefix_notation(char expr[]){
    Stack s1;
    init(&s1,30);
    int i = 0;
    double op1,op2;
    char c = '0';   
  
    do {
        c = expr[i];
        i++;
    } while(c!='\0');

    for(i; i >= 0; i--){
        c = expr[i];
        if(c != '\0'){
            switch(c){
                case '+': push(&s1,evaluate(pop(&s1), pop(&s1),'+'));
                          break;
                case '*': push(&s1,evaluate(pop(&s1), pop(&s1),'*'));
                          break;
                case '-': push(&s1,evaluate(pop(&s1), pop(&s1),'-'));
                          break;
                case '/': push(&s1,evaluate(pop(&s1), pop(&s1),'/'));
                          break;
                default: push(&s1,atof(&c));
            }
        }
    }

    for(int j = 0; j <= s1.top; j++){
        printf("%0.2f\n", s1.item[j]);
    }
    return 0;
}


int main() {
    // eval_prefix_notation("+3*32"); //expected result 9
    eval_prefix_notation("-+5*56*29"); //expected result 17
    return 0;
}