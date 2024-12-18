#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char data[MAX][MAX];
    int top;
} Stack;

void initialize(Stack *stk);
int isEmpty(Stack *stk);
int isFull(Stack *stk);
void push(Stack *stk, char *str);
char *pop(Stack *stk);
int isOperator(char ch);
char *postfixToInfix(Stack *stk, char *postfix);

int main() {
    char postfix[MAX];
    Stack *stk = malloc(sizeof(Stack));

    initialize(stk);

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    char *infix = postfixToInfix(stk, postfix);
    printf("Infix expression: %s\n", infix);

    return 0;
}

void initialize(Stack *stk) {
    stk->top = -1;
}

int isEmpty(Stack *stk) {
    return stk->top == -1;
}

int isFull(Stack *stk) {
    return stk->top == MAX - 1;
}

void push(Stack *stk, char *str) {
    if (isFull(stk)) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stk->top++;
    strcpy(stk->data[stk->top], str);
}

char *pop(Stack *stk) {
    if (isEmpty(stk)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    char *str = stk->data[stk->top];
    stk->top--;
    return str;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%';
}

char *postfixToInfix(Stack *stk, char *postfix) {
    char op1[MAX], op2[MAX], temp[MAX * 3];

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (!isOperator(postfix[i])) {
            char str[2] = {postfix[i], '\0'};
            push(stk, str);
        } else {
            strcpy(op2, pop(stk));
            strcpy(op1, pop(stk));
            sprintf(temp, "(%s%c%s)", op1, postfix[i], op2);
            push(stk, temp);
        }
    }

    return pop(stk);
}
