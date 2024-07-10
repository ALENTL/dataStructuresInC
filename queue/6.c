#include <stdio.h>
#include <stdlib.h>

struct Node {
    int priority;
    int data;
    struct Node *next;
};

struct Node *front;

void initializeQueue();
void insert(int element, int priority);
int isEmpty();
void display();
int delete();

int main() {
    int n, data, prior;

    initializeQueue();

    printf("Enter the no of elements to push: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        printf("Enter the priority with data to push: ");
        scanf("%d %d", &prior, &data);

        insert(data, prior);
    }

    display();

    printf("Deleting element with data: %d\n", delete());
    display();
}

void initializeQueue() {
    front = NULL;
}

void insert(int element, int priority) {
    struct Node *temp, *p;

    temp = (struct Node *)malloc(sizeof(struct Node));

    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    temp->data = element;
    temp->priority = priority;

    if (isEmpty() || priority < front->priority) {
        temp->next = front;
        front = temp;
    }

    else {
        p = front;

        while (p->next != NULL && p->next->priority <= priority) {
            p = p->next;
        }

        temp->next = p->next;
        p->next = temp;
    }
}

int isEmpty() {
    if (front == NULL) {
        return 1;
    }

    return 0;
}

void display() {
    if (isEmpty()) {
        printf("Empty Queue!\n");
        return;
    }

    else {
        struct Node *ptr = front;

        printf("Queue is: \n");
        printf("Priority     Data\n");

        while (ptr != NULL) {
            printf("%d             %d\n", ptr->priority, ptr->data);
            ptr = ptr->next;
        }
    }
}

int delete() {
    struct Node *temp;
    int data;

    if (isEmpty()) {
        printf("Queue Underflow!\n");
        exit(1);
    }

    else {
        temp = front;
        data = temp->data;
        front = front->next;
        free(temp);
    }

    return data;
}