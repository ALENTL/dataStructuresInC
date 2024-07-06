#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top;

void initializeStack();
int isEmpty();
int size();
void push(int x);
int pop();
int peek();
int isEmpty();
void display();

int main() {
    int n, num;
    initializeStack();

    printf("Enter the number of elements of the stack: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        printf("Enter the number to push to the stack: ");
        scanf("%d", &num);
        push(num);
    }
    
    display();

    printf("Removing the top element: ");
    pop();
    display();

    printf("The top element is: %d\n", peek());
}

void initializeStack() {
    top = NULL;
}

int isEmpty() {
    if (top == NULL) {
        return 1;
    }

    else {
        return 0;
    }
}

int size() {
    int s = 0;
    struct Node *p = top;

    while (p != NULL) {
        p = p->next;
        s++;
    }

    return s;
}

void push(int x) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;    
    top = temp;
}

int pop() {
    struct Node *temp;
    int x;

    if(isEmpty()) {
        printf("Stack Underflow!\n");
        exit(1);
    }

    else {
        temp = top;
        x = temp->data;
        top = top->next;
        free(temp);

        return x;
    }
}

int peek() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
        exit(1);
    }

    return top->data;
}

void display() {
    struct Node *p;

    p = top;

    if (isEmpty()) {
        printf("Stack underflow!\n");
        return;
    }

    else {
        printf("Stack is: \n");
        
        while (p != NULL) {
            printf("%d\t", p->data);
            p = p->next;
        }
        printf("\n");
    }
}