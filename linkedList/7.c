#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void displayList(struct Node *last);
struct Node *createList(struct Node *last);
struct Node *insertInBeginning(struct Node *last, int data);
struct Node *insertInEmptyList(struct Node *last, int data);
struct Node *insertAtEnd(struct Node *last, int data);
struct Node *insertAfter(struct Node *last, int data, int num);
struct Node *deleteFirstNode(struct Node *last);
struct Node *onlyNodeDeletion(struct Node *last);
struct Node *deleteLastNode(struct Node *last);
struct Node *deleteAfterNode(struct Node *last, int data);
struct Node *concatenate(struct Node *p, struct Node *q);

int main() {
    int num, data;

    struct Node *last1 = NULL, *last2 = NULL;
    last1 = createList(last1);
    displayList(last1);

    last2 = createList(last2);
    displayList(last2);

    struct Node *last = concatenate(last1, last2); 
    displayList(last);
}

void displayList(struct Node *last) {
    struct Node *p;

    if (last == NULL) {
        printf("Empty List!\n");
        return;
    }

    p = last->next;

    printf("The list is: ");
    do {
        printf("%d, ", p->data);
        p = p->next;
    }
    while (p != last->next);

    printf("\n");
}

struct Node *insertInBeginning(struct Node *last, int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = last->next;
    last->next = temp;

    return last;
}

struct Node *insertInEmptyList(struct Node *last, int data) {
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = data;

    last = temp;
    last->next = last;

    return last;
}

struct Node *insertAtEnd(struct Node *last, int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;

    temp->next = last->next;
    last->next = temp;

    last = temp;

    return last;
}

struct Node *createList(struct Node *last) {
    int n, num;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    last = NULL;

    if (n == 0) {
        return last;
    }

    printf("Enter the first element: ");
    scanf("%d", &num);

    last = insertInEmptyList(last, num);

    for (int i=1; i<n; i++) {
        printf("Enter the next element: ");
        scanf("%d", &num);
        last = insertAtEnd(last, num);
    }

    return last;
}

struct Node *insertAfter(struct Node *last, int data, int num) {
    struct Node *p, *temp;
    p = last->next;

    do {
        if (p->data == num) {
            break;
        }

        p = p->next;
    }

    while (p != last->next);

    if (p == last->next && p->data != num) {
        printf("%d not found in the list!\n", num);
    }

    else {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = data;

        temp->next = p->next;
        p->next = temp;

        if (p == last) {
            last = temp;
        }

    }

    return last;
}

struct Node *deleteFirstNode(struct Node *last) {
    if (last == NULL) {
        printf("Empty List!\n");
        return last;
    }

    struct Node *temp = last->next;
    last->next = temp->next;

    free(temp);

    return last;
}

struct Node *onlyNodeDeletion(struct Node *last) {
    if (last == NULL) {
        printf("Empty List!\n");
        return last;
    }

    struct Node *temp = last->next;
    last = NULL;
    free(temp);

    return last;
}

struct Node *deleteLastNode(struct Node *last) {
    if (last == NULL) {
        printf("Empty List!\n");
        return last;
    }

    struct Node *p, *temp; 
    temp = last;

    p = last->next;

    while (p != NULL && p->next != last) {
        p = p->next;
    }

    p->next = last->next;
    free(temp);
    last = p;

    return last;
}

struct Node *deleteAfterNode(struct Node *last, int data) {
    if (last == NULL) {
        printf("Empty List!\n");
        return last;
    }

    struct Node *p = last->next, *temp;

    while (p != NULL && p->next != last) {
        if (p->data == data) {
            break;
        }
        p = p->next;
    }

    if (p->next == last) {
        printf("%d not found in the list!\n", data);
    }

    else {
        temp = p->next;
        p->next = temp->next;
        free(temp);
    }

    return last;
}

struct Node *concatenate(struct Node *p, struct Node *q) {
    struct Node *p1, *q1;
    
    if (p == NULL && q != NULL) {
        return q;
    }

    else if (q == NULL && p != NULL) {
        return p;
    }

    else if (p == NULL && q == NULL) {
        printf("Empty elements in both the list!\n");
        return NULL;
    }

    p1 = p->next, q1 = q->next;

    p->next = q1;
    q->next = p1;

    return q;
}