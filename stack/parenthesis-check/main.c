#include <stdio.h>
#include <stdlib.h>
#include "../common/stack-char/headers/type.h"
#include "../common/stack-char/headers/stack.h"


int error = 0;

/*
@top_char Character at the top of the stack
@next_char Next character in the stream. 

if next_char is a closure to top_char return true 
*/
int checkClosure(char top_char, char next_char){

    char expected_closure = '\0';
    switch(top_char){
        case '[': expected_closure = ']';
                  break;
        case '{': expected_closure = '}';
                  break;
        case '(': expected_closure = ')';
                  break;
    }

    if(expected_closure != '\0' && expected_closure == next_char){
        return 1;
    }
    return 0;
}

/*
Reads  a string of chars, ignores all characters except brackets and checks that the syntax is correct
that is, that a opening bracket has closure. [] {} () 
*/
int validateSyntax(char operation[]){
    
    Stack s2;
    const int SIZE = 50;
    init(&s2,SIZE);
    int i = 0;
    char c = '0';
 
    while(c != '\0'){
        c = operation[i];
        if(c != '\0'){
            if(c == '(' || c == '{' || c == '[' ){
                if(operation[i+1] == '\0'){//in case there's an opening but no closure 
                    printf("Syntax error");
                    return 0;
                };
                push(&s2, c);
            } else if(c == ')' || c == '}' || c == ']'){

                if(s2.top == -1){
                    printf("Syntax error.");
                    return 0;
                } else if(checkClosure(s2.item[s2.top], operation[i])){
                    printf("Deleted from top: %c \n", pop(&s2));
                } else {
                    error = 1;
                    break;
                }

            }
        }
        i++;
    }

    for(int j = 0; j <= s2.top; j++){
        printf("%c",s2.item[j]);
    }

    if(error && s2.top != -1){
        printf("Syntax error.\n");
        return 0;
    }

    deallocate(&s2);
    printf("Syntax is OK!.\n");
    return 1;

}

int main(){

    int test = validateSyntax("3*[5-{(5-2)}+2] 3 [{( [{()}]f )}] [(a)]");
    return 0;
}