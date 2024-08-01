#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int stack[MAX], top;

void initializeStack();
void infixToPrefix(char infix[], char prefix[]);
char *strrev(char *str);
void push(char x);
char pop();
int precedence(char c);

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    infix[strcspn(infix, "\n")] = '\0';

    printf("The infix expression is %s\n", infix);

    infixToPrefix(infix, prefix);
    printf("The prefix expression is %s\n", prefix);

    return 0;
}

void initializeStack() {
    top = -1;
}

void infixToPrefix(char infix[], char prefix[]) {
    char temp, x;
    int i = 0, j = 0;

    strrev(infix);

    while (infix[i] != '\0') {
        temp = infix[i];

        if (isalnum(temp)) {
            prefix[j++] = temp;
        }

        else if (temp == ' ') {
            continue;
        }

        else if (temp == ')') {
            push(temp);
        }

        else if (temp == '(') {
            while ((x = pop()) != ')') {
                prefix[j++] = x;
            }
        }

        else {
            while (precedence(stack[top]) >= precedence(temp)) {
                prefix[j++] = pop();
            }
            push(temp);
        }

        i++;
    }

    while (top != -1) {
        prefix[j++] = pop();
    }

    prefix[j] = '\0';
    strrev(prefix);
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

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }

    return stack[top--];
}

int precedence(char c) {
    if (c == '(' || c == ')') {
        return 0;
    }

    else if (c == '+' || c == '-') {
        return 1;
    }

    else if (c == '*' || c == '/' || c == '%') {
        return 2;
    }
}
