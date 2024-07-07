#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *rear;

void initialize();
struct Node *insert(int num);
void display();
int isEmpty();
void delete();
int size();
int peek();

int main() {
    int n, num;

    initialize();

    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        printf("Enter the number to insert into the queue: ");
        scanf("%d", &num);

        rear = insert(num);
    }

    display();

    printf("Deleting first element: \n");
    delete();
    display();

    printf("The size of the queue is: %d\n", size());

    printf("The peak element is: %d\n", peek());
}

void initialize() {
    rear = NULL;
}

struct Node *insert(int num) {
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = num;
 
   if (rear == NULL) {
    temp->next = temp;
    rear = temp;
   }

   else {
    temp->next = rear->next;
    rear->next = temp;
    rear = temp;
   }

   return rear;
}

void display() {
    struct Node *p;
    p = rear->next;

    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }

    printf("The queue is: \n");
    do {
        printf("%d\t", p->data);
        p = p->next;
    } while(p != rear->next);
    printf("\n");
}

int isEmpty() {
    if (rear == NULL) {
        return 1;
    }
    return 0;
}

void delete() {
    struct Node *temp;

    if (isEmpty()) {
        printf("Queue Underflow!\n");
        exit(1);
    }

    else {
        if (rear->next == rear) {
            rear = NULL;
        }

        else {
            temp = rear->next;
            rear->next = temp->next;
            free(temp);
        }

        printf("Element deleted!\n");
    }
}

int size() {
    int s = 0;

    if (isEmpty()) {
        return s; 
    }

    struct Node *p = rear->next;

    do {
        s++;
        p = p->next;
    } while (p != rear->next);

    return s;
}

int peek() {
    if (isEmpty()) {
        printf("Queue Underflow!\n");
        exit(1);
    }

    else {
        return rear->next->data;
    }
}