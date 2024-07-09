#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int array[MAX];

int front, rear;

void initializeQueue();
int isEmpty();
int isFull();
void insert(int x);
int delete();
int peek();
void display();
int size();

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

    printf("Enter the number of elements to delete: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        int x = delete();
        printf("Deleted element: %d\n" , x);
    }

    display();

    printf("Peak element: %d\n", peek());
    printf("Size of the queue: %d\n", size());

    return 0;
}

void initializeQueue() {
    rear = -1;
    front = -1;
}

int isEmpty() {
    if (front == -1) {
        return 1;
    }

    return 0;
}

int isFull() {
    if ((front == 0 && rear == MAX-1) || (front == rear+1)) {
        return 1;
    }

    return 0;
}

void insert(int x) {
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
        rear = rear+1;
    }

    array[rear] = x;
}

int delete() {
    int x;

    if (isEmpty()) {
        printf("Queue Underflow!\n");
        exit(1);
    }

    x = array[front];

    if (front == rear) {
        front = -1;
        rear = -1;
    }

    else if (front == MAX-1) {
        front = 0;
    }

    else {
        front += 1;
    }

    return x;
}

int peek() {
    if (isEmpty()) {
        printf("Queue Underflow!\n");
        exit(1);
    }

    return array[front];
}

void display() {
    printf("Front = %d, Rear = %d\n", front, rear);

    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }

    int i = front;
    printf("Queue is: \n");

    if (front <= rear) {
        while (i <= rear) {
            printf("%d\t", array[i++]);
        } 
    }

    else {
        while (i<=MAX-1) {
            printf("%d\t", array[i++]);
        }

        i = 0;

        while (i <= rear) {
            printf("%d\t", array[i++]);
        }
    }

    printf("\n");
}

int size() {
    int i, s;

    if (isEmpty()) {
        return 0;
    }

    if (isFull()) {
        return 1;
    }

    i = front, s = 0;
    
    if (front <= rear) {
        while (i <= rear) {
            i++;
            s++;
        } 
    }

    else {
        while (i <= MAX-1) {
            i++;
            s++;
        }

        i = 0;

        while (i <= rear) {
            i++;
            s++;
        }
    }

    return s;
}