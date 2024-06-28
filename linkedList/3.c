#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createSortedList(struct Node *start);
struct Node *insertInOrder(struct Node *start, int data);
void displayList(struct Node *start);
struct Node *mergeByData(struct Node *p, struct Node *q);
struct Node *mergeByLinks(struct Node *p, struct Node *q);

int main() {
    struct Node *start1 = NULL, *start2 = NULL, *startM;

    printf("Sorted List 1: \n");
    start1 = createSortedList(start1);
    displayList(start1);
    printf("Sorted List 2: \n");
    start2 = createSortedList(start2);
    displayList(start2);

    startM = mergeByData(start1, start2);
    printf("Sorted Merged List by data: ");
    displayList(startM);

    startM = mergeByLinks(start1, start2);
    printf("Sorted Merged List by links: ");
    displayList(startM);
}

struct Node *createSortedList(struct Node *start) {
    int n, num;
    printf("Enter the number of Nodes: ");
    scanf("%d", &n);

    start = NULL;

    for (int i=0; i<n; i++) {
        printf("Enter the element to be inserted: ");
        scanf("%d", &num);
        start = insertInOrder(start, num);
    }

    return start;
}

struct Node *insertInOrder(struct Node *start, int data) {
    struct Node *temp , *p;
    temp = (struct Node *) malloc(sizeof(struct Node));

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
    struct Node *p;

    if (start == NULL) {
        printf("Empty List!\n");
        return;
    }

    p = start;
    printf("The list is: ");

    while (p != NULL) {
        printf("%d, ", p->data);
        p = p->next;
    }
    printf("\n");
}

struct Node *mergeByData(struct Node *p, struct Node *q) {
    struct Node *startM, *temp, *pM;

    temp = (struct Node *) malloc(sizeof(struct Node));
    temp->next = NULL;
    startM = temp;

    if (p->data <= q->data) {
        temp->data = p->data;
        p = p->next;
    }
    else {
        temp->data = q->data;
        q = q->next;
    }

    pM = startM;

    while (p != NULL && q != NULL) {
        temp = (struct Node *)malloc(1*sizeof(struct Node));

        if (p->data <= q->data) {
            temp->data = p->data;
            p = p->next;
        }

        else {
            temp->data = q->data;
            q = q->next;
        }

        temp->next = NULL;
        pM->next = temp;
        pM = temp;
    }

    while (p != NULL) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = p->data;
        temp->next = NULL;
        pM->next = temp;
        pM = temp;
        p = p->next;
    }

    while (q != NULL) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = q->data;
        temp->next = NULL;
        pM->next = temp;
        pM = temp;
        q = q->next;
    }

    return startM;
}

struct Node *mergeByLinks(struct Node *p, struct Node *q) {
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