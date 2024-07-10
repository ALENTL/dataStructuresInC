#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int array[MAX], front, rear;

void initializeQueue();
int isEmpty();
int isFull();
void insertFront(int x);
void insertRear(int x);
int deleteFront();
int deleteRear();
void display();

int main() {
    int n, num;

    initializeQueue();

    printf("Enter the number of elements to push front: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        printf("Enter the element to push: ");
        scanf("%d", &num);

        insertFront(num);
    }

    display();
    
    printf("Enter the number of elements to push rear: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        printf("Enter the element to push: ");
        scanf("%d", &num);

        insertRear(num);
    }

    display();

    printf("Deleting an element from the front: %d\n", deleteFront());
    display();

    printf("Deleting an element from the end: %d\n", deleteRear());
    display();

    return 0;
}

void initializeQueue() {
    front = rear = -1;
}

int isEmpty() {
    if (front == -1) {
        return 1;
    }

    return 0;
}

int isFull() {
    if ((front == 0 && rear == MAX-1) || (front == rear + 1)) {
        return 1;
    }

    return 0;
}

void insertFront(int x) {
    if (isFull()) {
        printf("Queue Overflow!\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    }

    else if (front == 0) {
        front = MAX-1;
    }

    else {
        front = front - 1;
    }

    array[front] = x;
}

void insertRear(int x) {
    if (isFull()) {
        printf("Queue Overflow!\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    if (rear == MAX-1) {
        rear = 0;
    }

    else {
        rear += 1;
    }

    array[rear] = x;
}

int deleteFront() {
    int x;

    if (isEmpty()) {
        printf("Queue Underflow!\n");
        exit(1);
    }

    x = array[front];

   if (front == rear) {
    front = rear = -1;
   } 

   else if (front == MAX-1) {
    front = 0;
   }

   else {
    front += 1;
   }

   return x;
}

int deleteRear() {
    int x;

    if (isEmpty()) {
        printf("Queue Underflow!\n");
        exit(1);
    }

    x = array[rear];

    if (front == rear) {
        front = rear = -1;
    }

    else if (rear == 0) {
        rear = MAX-1;
    }

    else {
        rear = rear-1;
    }

    return x;
}

void display() {
    if (isEmpty()) {
        printf("Empty Queue!\n");
        return;
    }

    printf("Queue is: \n");
    
    int i = front;

    if (front <= rear) {
        while (i <= rear) {
            printf("%d\t", array[i++]);
        }
    }

    else {
        while (i <= MAX-1) {
            printf("%d\t", array[i++]);
        }

        i = 0;

        while (i <= rear) {
            printf("%d\t", array[i++]);
        }
    }

    printf("\n");
}