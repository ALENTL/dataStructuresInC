#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front, *rear;

void initializeQueue();
int isEmpty();
void insert(int x);
int delete();
void display();
int peek();
int size();

int main() {
    initializeQueue();
}

void initializeQueue() {
    rear = NULL;
}

int isEmpty() {
    if (rear == NULL) {
        return 1;
    }

    else {
        return 0;
    }
}

void insert(int x) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;

    if (isEmpty()) {
        rear = temp;
        rear->next = rear;
    }
    else {
        temp->next = rear->next;
        rear->next = temp;
        rear = temp;
    }
}

int delete() {
    int x;
    struct Node *temp;

    if (rear == NULL) {
        printf("Queue Underflow!\n");
        exit(1);
    }

    else {
        temp = rear->next;
        rear->next = temp->next;
        
    }

    x = temp->data;
    free(temp);

    return x;
}

void display() {
    struct Node *p;

    if (isEmpty()) {
        printf("Empty Queue!\n");
        return;
    }

    printf("The queue is: \n");
    p = rear->next;

    do {
        printf("%d\t", p->data);
    } while (p != rear->next);
    printf("\n");
}

int peek() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        exit(1);
    }
    return rear->next->data;
}

int size() {
    struct Node *p;
    int s = 0;

    if (isEmpty()) {
        return 0;
    }

    p = rear->next;

    do {
        s++;
        p = p->next;
    } while (p != rear->next);

    return s;
}