#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

/*
 * NOTE: We take the input from the user and store as infix
 * NOTE: We reverse the infix
 * NOTE: In reversing, if infix[i] == '(', then infix[i] = ')'
 * NOTE: else if infix[i] == ')', then infix[i] = '('
 * NOTE: Push the reversed infix expression to the stack
 * NOTE: Reverse content of the stack and display it as prefix
 */

typedef struct {
    int top;
    char stack[MAX];
} Stack;

// NOTE: Function to initialize empty stack
void initializeStack(Stack *stk);

// NOTE: Function to reverse the infix
char *strrev(char *str);

// NOTE: Function to convert the infix expression to postfix
void infixToPostfix(char infix[], char postfix[], Stack *stk);

// NOTE: Function to check whether stack is Full
int isFull(Stack *stk);

// NOTE: Function to check whether stack is Empty
int isEmpty(Stack *stk);

// NOTE: Function to push element to the stack
void push(char symbol, Stack *stk);

// NOTE: Function to pop element from the stack
char pop(Stack *stk);

// NOTE: Function to return precedence of operators
int precedence(char symbol);

int main() {
    Stack *stk = (Stack *)malloc(sizeof(Stack));
    initializeStack(stk);

    char infix[MAX], prefix[MAX], postfix[MAX];

    printf("Enter the infix expression with parantheses: ");
    fgets(infix, sizeof(infix), stdin);

    printf("The infix expression is:  %s", infix);

    strrev(infix);

    for (int i = 0; i < sizeof(infix); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        }

        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    memmove(infix, infix + 1, strlen(infix));

    printf("The reversed infix expression: %s\n", infix);

    infixToPostfix(infix, postfix, stk);
    printf("The postfix expression is: %s\n", postfix);

    strcpy(prefix, postfix);
    strrev(prefix);

    printf("The prefix expression is: %s\n", prefix);

    return 0;
}

void initializeStack(Stack *stk) {
    stk->top = -1;
}

char *strrev(char *str) {
    char *p1, *p2;

    if (!str || !*str)
        return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}

void infixToPostfix(char infix[], char postfix[], Stack *stk) {
    char symbol, next;
    int p = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        symbol = infix[i];

        if (symbol == ' ' || symbol == '\t') {
            continue;
        }

        switch (symbol) {
        case '(':
            push(symbol, stk);
            break;

        case ')':
            while ((next = pop(stk)) != '(') {
                postfix[p++] = next;
            }
            break;

        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
            while (!isEmpty(stk) &&
                   precedence(stk->stack[stk->top]) >= precedence(symbol)) {
                postfix[p++] = pop(stk);
            }
            push(symbol, stk);
            break;

        default:
            postfix[p++] = symbol;
        }
    }

    while (!isEmpty(stk)) {
        postfix[p++] = pop(stk);
    }
    postfix[p] = '\0';
}

void push(char symbol, Stack *stk) {
    if (isFull(stk)) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    stk->stack[++stk->top] = symbol;
}

int isFull(Stack *stk) {
    if (stk->top >= MAX - 1) {
        return 1;
    }
    return 0;
}

int isEmpty(Stack *stk) {
    if (stk->top == -1) {
        return 1;
    }
    return 0;
}

char pop(Stack *stk) {
    if (isEmpty(stk)) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return (stk->stack[stk->top--]);
}

int precedence(char symbol) {
    switch (symbol) {
    case '(':
        return 0;

    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
    case '%':
        return 2;

    case '^':
        return 3;

    default:
        return -1; // NOTE: Return a negative value for all non-operators
    }
}
