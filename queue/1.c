#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int array[MAX], front, rear;

void initializeQueue();
int isEmpty();
int isFull();
int size();
void insert(int x);
int delete();
int peek();
void display();

int main() {
    int n, num;
    
    initializeQueue();

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        printf("Enter the element: ");
        scanf("%d", &num);
        insert(num);
    }

    display();

    printf("The first element is: %d\n", peek());
    
    printf("Deleting first element: \n");
    delete();
    display();

    printf("Size of the queue: %d\n", size());
}

void initializeQueue() {
    front = -1;
    rear = -1;
}

int isEmpty() {
    if (front == -1 || front == rear+1) {
        return 1;
    }

    else {
        return 0;
    }
}

int isFull() {
    if (rear == MAX-1) {
        return 1;
    }
    else {
        return 0;
    }
}

int size() {
    if (isEmpty()) {
        return 0;
    }
    else {
        return rear-front+1;
    }
}

void insert(int x) {
    if (isFull()) {
        printf("Queue Overflow!\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }
    rear = rear + 1;
    array[rear] = x;
}

int delete() {
    int x;
    if (isEmpty()) {
        printf("Queue Underflow!\n");
        exit(1);
    }

    x = array[front];
    front = front + 1;
}

int peek() {
    if (isEmpty()) {
        printf("Queue Underflow!\n");
        exit(1);
    }
    return array[front];
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue is: \n");
    for (int i=front; i<=rear; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}