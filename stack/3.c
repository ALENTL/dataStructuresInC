#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top;

void initializeStack();
int isValid(char expr[]);
void push(char x);
int isEmpty();
int matchParanthesis(char leftPar, char rightPar);
char pop();

int main() {
    char expr[MAX];

    initializeStack();

    printf("Enter an expression: ");
    fgets(expr, sizeof(expr), stdin);

    if (isValid(expr)) {
        printf("Valid Expression!\n");
    }

    else {
        printf("Invalid Expression\n");
    }
}

void initializeStack() {
    top = -1;
}

int isValid(char expr[]) {
    char ch;

    for (int i=0; i<strlen(expr); i++) {
        if (expr[i] == '{' || expr[i] == '(' || expr[i] == '[') {
            push(expr[i]);
        }

        if (expr[i] == '}' || expr[i] == ')' || expr[i] == ']') {
            if (isEmpty()) {
                printf("Right parantheses are more than left parantheses\n");
                return 0;
            }

            else {
                ch = pop();

                if (!matchParanthesis(ch, expr[i])) {
                    printf("Mismatched parantheses are %c and %c\n", ch, expr[i]);
                    return 0;
                }
            }
        }
    }

    if (isEmpty()) {
        printf("Balanced Paranthese!\n");
        return 1;
    }

    else {
        printf("Left parantheses are more than right parantheses!\n");
        return 0;
    }
}

void push(char x) {
    if (top == MAX-1) {
        printf("Stack Overflow!\n");
        return;
    }

    top += 1;
    stack[top] = x;
}

int isEmpty() {
    if (top == -1) {
        return 1;
    }

    return 0;
}

int matchParanthesis(char leftPar, char rightPar) {
    if (leftPar == '(' && rightPar == ')') {
        return 1;
    }

    if (leftPar == '{' && rightPar == '}') {
        return 1;
    }

    if (leftPar == '[' && rightPar == ']') {
        return 1;
    }

    return 0;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        exit(1);
    }

    return stack[top--];
}