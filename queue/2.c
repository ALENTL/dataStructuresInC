#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front, *rear;

void initializeQueue();
int size();
void insert(int x);
int delete();
int peek();
int isEmpty();
void display();

int main() {
    int n, num;

    initializeQueue();

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        printf("Enter the element: ");
        scanf("%d", &num);
        insert(num);
    }

    display();

    delete();
    display();

    printf("Size of the queue: %d\n", size());

    printf("Peak element in the queue: %d\n", peek());

    return 0;
}

void initializeQueue() {
    front = NULL;
    rear = NULL;
}

void insert(int x) {
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = x;
    temp->next = NULL;

    if (front == NULL) {
        front = temp;
    }

    else {
        rear->next = temp;
    }

    rear = temp;
}

int delete() {
    struct Node *temp;
    int x;

    if (isEmpty()) {
        printf("Queue Underflow!\n");
        exit(1);
    }

    temp = front;
    front = front->next;
    x = temp->data;
    free(temp);

    return x;
}

int peek() {
    int x;

    if (front == NULL) {
        printf("Queue Underflow!\n");
        exit(1);
    }

    x = front->data;

    return x;
}

int isEmpty() {
    if (front == NULL) {
        return 1;
    }

    else {
        return 0;
    }
}

int size() {
    int s = 0;

    struct Node *p = front;

    while (p != NULL) {
        p = p->next;
        s++;
    }

    return s;
}

void display() {
    struct Node *p;
    p = front;
    
    if (isEmpty()) {
        printf("Empty Queue!\n");
        return;
    }

    printf("Queue is: !\n");

    while (p != NULL) {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}