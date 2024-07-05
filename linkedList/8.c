#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void createList(struct Node *head);
void insertAtEnd(struct Node *head, int data);
void insertBefore(struct Node *head, int data, int num);
void insertAfterPosition(struct Node *head, int data, int pos);
void displayList(struct Node *head);
void deleteNode(struct Node *head, int data);
void reverse(struct Node *head);

int main() {
    struct Node *head;
    int pos, data;

    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 0;
    head->next = NULL;

    createList(head);

    printf("Enter the position of the successor element: ");
    scanf("%d", &pos);

    printf("Enter the value of the node: ");
    scanf("%d", &data);

    insertAfterPosition(head, data, pos);
    displayList(head);

    printf("Enter the node data to delete the node: ");
    scanf("%d", &data);

    deleteNode(head, data);
    displayList(head);

    reverse(head);
    displayList(head);
}

void createList(struct Node *head) {
    int n, num;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        printf("Enter the element to be inserted: ");
        scanf("%d", &num);

        insertAtEnd(head, num);
    }
}

void insertAtEnd(struct Node *head, int data) {
    struct Node *p, *temp;

    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;

    p = head;
    while (p->next != NULL) {
        p = p->next;
    }

    p->next = temp;
    temp->next = NULL;
}

void insertBefore(struct Node *head, int data, int num) {
    struct Node *p, *temp;

    p = head;

    while (p->next != NULL) {
        if (p->next->data == num) {
            break;
        }
        p = p->next;
    }

    if (p->next == NULL) {
        printf("Element %d not found in the list!\n", num);
    }

    else {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = data;

        temp->next = p->next;
        p->next = temp;
    }
}

void insertAfterPosition(struct Node *head, int data, int pos) {
    struct Node *temp, *p;

    p = head;

    for (int i=0; i<pos-1 && p != NULL; i++) {
        p = p->next;
    }

    if (p == NULL) {
        printf("NULL position!\n");
    }

    else {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = data;
        temp->next = p->next;
        p->next = temp;
    }
}

void displayList(struct Node *head) {
    if (head->next == NULL) {
        printf("Empty List!\n");
    }

    struct Node *p = head->next;
    printf("The list is: ");
    while (p != NULL) {
        printf("%d, ", p->data);
        p = p->next;
    }

    printf("\n");
}

void deleteNode(struct Node *head, int data) {
    struct Node *p, *temp;

    p = head;

    while (p->next != NULL) {
        if (p->next->data == data) {
            break;
        }
        p = p->next;
    }

    if (p->next == NULL) {
        printf("Element not found in the list!\n");
    }

    else {
        temp = p->next;
        p->next = temp->next;
        free(temp);
    }
}

void reverse(struct Node *head) {
    struct Node *prev, *next, *ptr;

    prev = NULL;
    ptr = head->next;

    while (ptr != NULL) {
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }

    head->next = prev;
}