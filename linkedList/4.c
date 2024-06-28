#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createList(struct Node *start);
struct Node *insertInBeginning(struct Node *start, int data);
void insertAtEnd(struct Node *start, int data);
void displayList(struct Node *start);
struct Node *mergeSort(struct Node *start);
struct Node *divideList(struct Node *start);
struct Node *merge(struct Node *p, struct Node *q);

int main() {
    struct Node *start = NULL;

    start = createList(start);
    printf("Created List: !\n");
    displayList(start);

    start = mergeSort(start);
    printf("Merge Sorted List: \n");
    displayList(start);

    return 0;
}

struct Node *createList(struct Node *start) {
    int n, num;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the first element: ");
    scanf("%d", &num);
    start = insertInBeginning(start, num);

    for (int i=1; i<n; i++) {
        printf("Enter the next element: ");
        scanf("%d", &num);
        insertAtEnd(start, num);
    }

    return start;
}

struct Node *insertInBeginning(struct Node *start, int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;

    if (start == NULL) {
        temp->next = NULL;
        start = temp;
        return start;
    }

    temp->next = start;
    start = temp;

    return start;
}

void insertAtEnd(struct Node *start, int data) {
    struct Node *p, *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = data;
    temp->next = NULL;

    if (start == NULL) {
        start = temp;
        return;
    }

    p = start;

    while (p->next != NULL) {
        p = p->next;
    }

    p->next = temp;
    temp->next = NULL;
}

void displayList(struct Node *start) {
    if (start == NULL) {
        printf("Empty List!\n");
        return;
    }

    struct Node *p = start;

    printf("The list is: ");
    while (p != NULL) {
        printf("%d, ", p->data);
        p = p->next;
    }
    printf("\n");
}

struct Node *mergeSort(struct Node *start) {
    struct Node *start1, *start2, *startM;

    if (start == NULL || start->next == NULL) {
        return start;
    }

    start1 = start;
    start2 = divideList(start);

    start1 = mergeSort(start1);
    start2 = mergeSort(start2);

    startM = merge(start1, start2);

    return startM;
}

struct Node *divideList(struct Node *start) {
    struct Node *fast, *start2;

    fast = start->next->next;

    while (fast != NULL && fast->next != NULL) {
        start = start->next;
        fast = fast->next->next;
    }

    start2 = start->next;
    start->next = NULL;

    return start2;
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