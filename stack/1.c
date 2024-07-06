#include <stdio.h>
#include <stdlib.h>

#define max 50

int a[max], top;

void initializeStack();
void push(int x);
void display();
int size();
int pop();
int peek();

int main() {
    int n, num, last;

    initializeStack();

    printf("Enter the number of elements of the stack: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        printf("Enter the element to push: ");
        scanf("%d", &num);

        push(num);
    }

    display();

    printf("Size of the stack: %d\n", size());

    printf("Removing the last element of the stack: ");
    top = pop();

    display();

    last = peek();
    if (last != -1) {
        printf("Top element is: %d\n", last);
    }
}

void initializeStack() {
    top = -1;
}

int size() {
    return top+1;
}

int isEmpty() {
    if (top == -1) {
        return 1;
    }

    else {
        return 0;
    }
}

int isFull() {
    if (top == max-1) {
        return 1;
    }

    else {
        return 0;
    }
}

void push(int x) {
   if (isFull()) {
    printf("Stack Overflow!\n");
    return;
   }

   ++top;
   a[top] = x;
}

int pop() {
    int x;
    if (isEmpty()) {
        printf("Stack Underflow!\n");
        return -1;
    }

    x = a[top];
    --top;
    return top;
}

int peek() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
        exit(1);
    }

    else {
        return a[top];
    }
}

void display() {
    printf("Top: %d\n", top);

    if (isEmpty()) {
        printf("Stack is empty!\n");
        return;
    }

    else {
        printf("Stack is: \n");
        for (int i=top; i>=0; i--) {
            printf("%d\t", a[i]);
        }
        printf("\n\n");
    }
}