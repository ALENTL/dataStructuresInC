// If operand - add to postfix
// If left paranthesis - add to stack
/* If right paranthesis - pop and add to postfix all operators till left
 * paranthesis*/
/* Operator - pop and add to postfix those operators that have precendence
 * greater than or equal to the scanned operator*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int top = -1, stack[MAX];

void infixToPostfix(char infix[], char postfix[]);
void push(char symbol);
char pop();
int isEmpty();
int precedence(char symbol);

int main() {
  char infix[MAX], postfix[MAX];

  printf("Enter the infix expression: ");
  fgets(infix, sizeof(infix), stdin);

  // Remove newline character from the input string
  size_t len = strlen(infix);
  if (len > 0 && infix[len - 1] == '\n') {
    infix[len - 1] = '\0';
  }

  infixToPostfix(infix, postfix);
  printf("Postfix expression is: %s\n", postfix);

  return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
  char symbol, next;
  int p = 0;

  for (int i = 0; infix[i] != '\0'; i++) {
    symbol = infix[i];

    if (symbol == ' ' || symbol == '\t') {
      continue;
    }

    switch (symbol) {
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
      while (!isEmpty() && precedence(stack[top]) >= precedence(symbol)) {
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

void push(char symbol) {
  if (top >= MAX - 1) {
    printf("Stack Overflow!\n");
    exit(1);
  }
  stack[++top] = symbol;
}

char pop() {
  if (isEmpty()) {
    printf("Stack Underflow!\n");
    exit(1);
  }
  return stack[top--];
}

int isEmpty() { return top == -1; }

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
    return -1; // Return a negative value for non-operators
  }
}
