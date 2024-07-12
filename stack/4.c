// If operand - add to postfix
// If left paranthesis - add to stack
// If right paranthesis - pop and add to postfix all operators till left paranthesis
// Operator - pop and add to postfix those operators that have precendence greater than or equal to the scanned operator

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

size_t stack[MAX], top = -1;

void infixToPostfix(char infix[], char postfix[]);
void push(int symbol);
int pop();
int isEmpty();
int precendence(char symbol);
int evaluatePostfix(char postfix[]);
int power(int b, int a);

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    infixToPostfix(infix, postfix);
}

void infixToPostfix(char infix[], char postfix[]) {
    int p = 0;
    char next, symbol;

    for (int i=0; i<strlen(infix); i++) {
        symbol = infix[i];

        if (symbol == ' ' || symbol == '\t') {
            continue;
        }

        switch (symbol)
        {
        case '(':
            push(symbol);
            break;

        case ')':
            while ((next = pop()) != '(') {
                postfix[p++] = next;
            }
            break;

        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
            while (!isEmpty() && precendence(stack[top]) >= precendence(symbol)) {
                postfix[p++] = pop();
            }
            push(symbol);
            break;
        
        default:
            postfix[p++] = symbol;
        }
    }

    while (!isEmpty()) {
        postfix[p++] = pop();
    }
    postfix[p] = '\0';
}

void push(int symbol) {
    if (top > MAX) {
        printf("Stack Overflow!\n");
        exit(1);
    }

    stack[++top]  = symbol;
};

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
        exit(1);
    }

    return stack[top--];
}

int isEmpty() {
    if (top == -1) {
        return -1;
    }

    return 0;
}

int precendence(char symbol) {
    switch (symbol)
    {
    case '(':
        return 0;

    case '+':
    case '-':
        return 1;

    case '*':
    case '%':
    case '/':
        return 2;

    case '^':
        return 3;
    
    default:
        return 0;
    }
}

int evaluatePostfix(char postfix[]) {
    int x, y, result;

    for (int i=0; i<strlen(postfix); i++) {
        if (postfix[i] <= '9' && postfix[i] >= 0) {
            push(postfix[i]-'0');
        }

        else {
            x = pop();
            y = pop();

            switch (postfix[i])
            {
            case '+':
                push(y+x);
                break;

            case '-':
                push(y-x);
                break;

            case '*':
                push(y*x);
                break;

            case '/':
                push(y/x);
                break;
            
            case '%':
                push(y%x);
                break;
            
            case '^':
                push(power(y, x));
            
            default:
                break;
            }
        }
    }

    result = pop();
    return result;
}

int power(int b, int a) {
    int x = 1;

    for (int i = 0; i<a; i++) {
        x *= b;
    }

    return x;
}