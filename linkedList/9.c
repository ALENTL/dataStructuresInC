#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *insertInOrder(struct Node *start, int data);
void displayList(struct Node *start);
void search(struct Node *start, int num);

int main() {
    int num;

    struct Node *start = NULL;

    printf("Enter the data to be inserted: ");
    scanf("%d", &num);

    start = insertInOrder(start, num);

    printf("Enter the next data: ");
    scanf("%d", &num);
    start = insertInOrder(start, num);
    
    displayList(start);
}

struct Node *insertInOrder(struct Node *start, int data) {
    struct Node *p, *temp;

    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;

    if (start == NULL || start->data > temp->data) {
        temp->next = start;
        start = temp;

        return start;
    }

    else {
        p = start;

        while (p != NULL && p->next->data <=data) {
            p = p->next;
        }

        temp->next = p->next;
        p->next = temp;
    }

    return start;
}

void displayList(struct Node *start) {
    struct Node *p;

    if (start == NULL) {
        printf("Empty List!\n");
        return;
    }

    printf("The list is: ");
    
    p = start;
    while (p != NULL) {
        printf("%d, ", p->data);
        p = p->next;
    }

    printf("\n");
}

void search(struct Node *start, int num) {
    struct Node *p;
    int pos;

    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    p = start;
    pos = 1;

    while (p != NULL && p->data <= num) {
        if (p->data == num) {
            break;
        }

        pos++;
        p = p->next;
    }
    
    if (p == NULL || p->data != num) {
        printf("%d not found in the list!\n", num);
    }

    else {
        printf("%d found at position %d\n", num, pos);
    }
}