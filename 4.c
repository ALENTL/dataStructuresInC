#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createSortedList(struct Node *start);
struct Node *insertInOrder(struct Node *start, int data);
void displayList(struct Node *start);
struct Node *merge(struct Node *p, struct Node *q);

int main() {
    struct Node *start1 = NULL, *start2 = NULL, *startM;

    printf("\nSorted List 1: \n");
    start1 = createSortedList(start1);
    displayList(start1);
    
    printf("\nSorted List 2: \n");
    start2 = createSortedList(start2);
    displayList(start2);

    printf("\nMerged Sorted List: \n");
    startM = merge(start1, start2);
    displayList(startM);
}

struct Node *createSortedList(struct Node *start) {
    int n, num;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    start = NULL;

    for (int i=0; i<n; i++) {
        printf("Enter the element to add to the list: ");
        scanf("%d", &num);
        start = insertInOrder(start, num);
    }

    return start;
}

struct Node *insertInOrder(struct Node *start, int data) {
    struct Node *p, *temp;

    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;

    if (start == NULL || start->data > data) {
        temp->next = start;
        start = temp;

        return start;
    }

    else {
        p = start;

        while (p->next != NULL && p->next->data < data) {
            p = p->next;
        }

        temp->next = p->next;
        p->next = temp;

    }

    return start;
}

void displayList(struct Node *start) {
    if (start == NULL) {
        printf("The list is empty!\n");
        return;
    }

    struct Node *p = start;

    printf("The list is: ");
    while (p != NULL) {
        printf("%d, ", p->data);
        p = p->next;
    }
}

struct Node *merge(struct Node *p, struct Node *q) {
    struct Node *startM, *pM;

    if (p->data <= q->data) {
        startM = p;
        p = p->next;
    }

    else {
        startM = q;
        q = q->next;
    }

    pM = startM;

    while (p != NULL && q != NULL) {
        if (p->data <= q->data) {
            pM->next = p;
            pM = pM->next;
            p = p->next;
        }

        else {
            pM->next = q;
            pM = pM->next;
            q = q->next;
        }
    }

    if (p == NULL) {
        pM->next = q;
    }

    else {
        pM->next = p;
    }

    return startM;
}