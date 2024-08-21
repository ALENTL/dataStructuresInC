#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
  char stack[MAX][MAX];
  int top;
} Stack;

void initializeStack(Stack *stk);
char *strrev(char *str);
int isFull(Stack *stk);
int isEmpty(Stack *stk);
void push(Stack *stk, char *str);
char *pop(Stack *stk);
char *prefixToInfix(Stack *stk, char prefix[]);
int isOperator(char ch);

int main() {
  char *prefix;
  Stack *stk = malloc(sizeof(Stack));

  initializeStack(stk);

  printf("Enter the prefix expression: ");
  scanf("%s", prefix);

  strrev(prefix);

  char *infix = prefixToInfix(stk, prefix);
  printf("Infix expression: %s\n", infix);

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

int isFull(Stack *stk) {
  return stk->top == MAX - 1;
}

int isEmtpy(Stack *stk) {
  return stk->top == -1;
}

void push(Stack *stk, char *str) {
  if (isFull(stk)) {
    printf("Stack Overflow!\n");
    exit(1);
  }
  stk->top++;
  strcpy(stk->stack[stk->top], str);
}

char *pop(Stack *stk) {
  if (isEmtpy(stk)) {
    printf("Stack Underflow!\n");
    exit(1);
  }
  char *str = stk->stack[stk->top];
  stk->top--;
  return str;
}

int isOperator(char ch) {
  if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^') {
    return 1;
  }
  return 0;
}

char *prefixToInfix(Stack *stk, char prefix[]) {
  char op1[MAX], op2[MAX], temp[MAX * 3];

  for (int i=0; prefix[i] != '\0'; i++) {
    if (!isOperator(prefix[i])) {
      char str[2] = {prefix[i], '\0'};
      push(stk, str);
    }
    else {
      strcpy(op1, pop(stk));
      strcpy(op2, pop(stk));
      sprintf(temp, "(%s%c%s)", op1, prefix[i], op2);
      push(stk, temp);
    }
  } 
  return pop(stk);
}
