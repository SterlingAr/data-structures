
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include "../common/stack-double/headers/type.h"
#include "../common/stack-double/headers/stack.h"


double evaluate(double operand1, double operand2, char operator){

    switch(operator){
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        default: exit(1);
    }
}

double eval_postfix_notation(const char * expr)
{
    Stack s1;

    init(&s1,30);

    int i = 0,
        j = 0;
    double  op1,op2,result;
    char  c, cs[2];

    cs[1] = '\0';

    char operandRegExpr[] = "(^[0-9])";
    char operatorRegExpr[] = "^(\\+|\\-|\\*|\\/)";

    regex_t operandReg, operatorReg;

    if(regcomp(&operandReg, operandRegExpr, REG_EXTENDED))
    {
        printf("Regex compilation failed.\n");
        exit(1);
    }

    if(regcomp(&operatorReg, operatorRegExpr, REG_EXTENDED))
    {
        printf("Regex compilation failed.\n");
        exit(1);
    }

    while(expr[i])
    {
        i++;
    }

    while(j < i)
    {

        c = expr[j];
        cs[0] = c;

        if(!regexec(&operandReg, cs, 0, NULL, 0))
        {
            push(&s1,strtod(&c,NULL));
        }
        else if(!regexec(&operatorReg, cs, 0, NULL, 0))
        {
            op1 = pop(&s1);
            op2 = pop(&s1);
            result = evaluate(op2,op1, c);
            push(&s1, result);
        }
        else
        {
            printf("Bad prefix notation given");
        }

        j++;
    }

    return ( pop(&s1));
}

double eval_prefix_notation(const char * expr)
{

    Stack s1;

    init(&s1,30);

    int i = 0;
    double  op1,op2,result;
    char  c, cs[2];

    cs[1] = '\0';

    char operandRegExpr[] = "(^[0-9])";
    char operatorRegExpr[] = "^(\\+|\\-|\\*|\\/)";

    regex_t operandReg, operatorReg;

    if(regcomp(&operandReg, operandRegExpr, REG_EXTENDED))
    {
        printf("Regex compilation failed.\n");
        exit(1);
    }

    if(regcomp(&operatorReg, operatorRegExpr, REG_EXTENDED))
    {
        printf("Regex compilation failed.\n");
        exit(1);
    }

    while(expr[i])
    {
        i++;
    }

    i--;//skip null terminator
    while(i >= 0)
    {

        c = expr[i];
        cs[0] = c;

        if(!regexec(&operandReg, cs, 0, NULL, 0))
        {
            push(&s1,strtod(&c,NULL));
        }
        else if(!regexec(&operatorReg, cs, 0, NULL, 0))
        {
            op1 = pop(&s1);
            op2 = pop(&s1);
            result = evaluate(op1,op2, c);
            push(&s1, result);
        }
        else
        {
            printf("Bad prefix notation given");
        }

        i--;
    }

    return pop(&s1);
}




int main()
{

    double prefixOpResult = eval_prefix_notation("-+5*56*29"); //expected result 17
    printf("Prefix notation result: %0.2f\n", prefixOpResult);

    double postfixOpResult = eval_postfix_notation("42$78*+54*-"); //expected result 17
    printf("Postfix notation result: %0.2f\n", postfixOpResult);

    return 0;
}