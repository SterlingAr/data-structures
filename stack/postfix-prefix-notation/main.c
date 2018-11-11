
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
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
        case '+': return operand2 + operand1;
        case '-': return operand2 - operand1;
        case '*': return operand2 * operand1;
        case '/': return operand2 / operand1;
    }
}

double eval_prefix_notation(const char * expr)
{

    Stack s1;

    init(&s1,30);

    int i = 0;
//    const char * pattern  = "(^[0-9])";
    char  c,
          cs[2];
    cs[1] = '\0';

    regex_t operandReg,
            operatorReg;

    if(regcomp(&operandReg, "(^[0-9])", REG_EXTENDED))
    {
        printf("Regex compilation failed.\n");
        exit(1);
    }

    if(regcomp(&operatorReg, "^(\\+|\\-|\\*|\\/)", REG_EXTENDED))
    {
        printf("Regex compilation failed.\n");
        exit(1);
    }

    while(expr[i])
    {
        i++;
    }

    while(i >= 0)
    {

        c = expr[i];

        if(c == '\0')
        {
            i--;
            continue;
        }

        //if c is operand, push
        //if c is operator,perform operation and push result to stack
        cs[0] = c;
        if(!regexec(&operandReg, cs, 0, NULL, 0))
        {
            push(&s1,strtod(&c,NULL));
        }
        else if(!regexec(&operatorReg, cs, 0, NULL, 0))
        {
            push(&s1,evaluate(pop(&s1), pop(&s1), c));
        }

        i--;
    }
    
    for(int j = 0; j <= s1.top; j++){
        printf("%0.2f\n", s1.item[j]);
    }
    return 0;
}


int main() {
     eval_prefix_notation("+3*32"); //expected result 9
//     eval_prefix_notation("+5/*233"); //expected result 9
//    eval_prefix_notation("-+5*56*29"); //expected result 17
    return 0;
}