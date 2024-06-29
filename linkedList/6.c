#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *createList(struct Node *start);
struct Node *insertInEmptyList(struct Node *start, int data);
struct Node *insertInBeginning(struct Node *start, int data);
void insertAtEnd(struct Node *start, int data);
void insertAfterNode(struct Node *start, int data, int x);
struct Node *insertBeforeNode(struct Node *start, int data, int x);
struct Node *deleteAtStart(struct Node *start);
void displayList(struct Node *start);
struct Node *onlyNodeDeletion(struct Node *start);
struct Node *deleteBetweenNodes(struct Node *start, int data);
struct Node *deleteLastNode(struct Node *start);
struct Node *reverse(struct Node *start);

int main() {
    int num; 

    struct Node *start = NULL;
    start = createList(start);
    displayList(start);

    // printf("Enter the element to append before the node: ");
    // scanf("%d", &num);
    // printf("Enter the element before it should be placed: ");
    // scanf("%d", &data);
    // start = insertBeforeNode(start, num, data);

    printf("Reversed List: \n");
    start = reverse(start); 
    displayList(start);
}

struct Node *createList(struct Node *start) {
    int n, num;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    start = NULL;

    if (n == 0) {
        return start;
    }

    printf("Enter the first element in the list: ");
    scanf("%d", &num);

    start = insertInEmptyList(start, num);

    for (int i=1; i<n; i++) {
        printf("Enter the next element: ");
        scanf("%d", &num);
        insertAtEnd(start, num);
    }

    return start;
}

struct Node *insertInEmptyList(struct Node *start, int data) {
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;

    temp->prev = NULL;
    temp->next = NULL;
    start = temp;

    return start;
}

struct Node *insertInBeginning(struct Node *start, int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->prev = NULL;

    if (start == NULL) {
        temp->next = NULL;
        start = temp;
        return temp;
    }

    start->prev = temp;
    temp->next = start;
    start = temp;

    return start;
}

void insertAtEnd(struct Node *start, int data) {
    struct Node *p = start, *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    while (p->next != NULL) {
        p = p->next;
    }

    p->next = temp;
    temp->prev = p;
}

void insertAfterNode(struct Node *start, int data, int x) {
    struct Node *p = start, *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;

    while (p != NULL) {
        if (p->data == x) {
            break;
        }
        p = p->next;
    }

    if (p == NULL) {
        printf("Node with data %d not present in the list\n", x);
    }

    else {
        temp->next = p->next;
        temp->prev = p;

        if (p->next != NULL) {
            p->next->prev = temp;
        }

        p->next = temp;
    }
}

struct Node *insertBeforeNode(struct Node *start, int data, int x) {
    struct Node *p, *temp;

    if (start == NULL) {
        printf("Empty List!\n");
        return start;
    }

    if (start->data == x) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = data;
        temp->prev = NULL;
        temp->next = start;
        start->prev = temp;
        start = temp;

        return start;
    } 

    p = start;

    while (p != NULL) {
        if (p->data == x) {
            break;
        }
        p = p->next;
    }

    if (p == NULL) {
        printf("Element %d not found in the list\n", x);
    }

    else {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = data;
        temp->prev = p->prev;
        temp->next = p;
        p->prev->next = temp;
        p->prev = temp;
    }

    return start;

}

struct Node *deleteAtStart(struct Node *start) {
    if (start == NULL) {
        printf("Empty List!\n");
        return start;
    }

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp = start;
    start = start->next;
    start->prev = NULL;
    free(temp);

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

struct Node *onlyNodeDeletion(struct Node *start) {
    if (start == NULL || start->next != NULL) {
        printf("Give a list with only 1 node: \n");
        return start;
    }

    else {
        struct Node *temp = start;
        start = start->next;
        free(temp);
        return start;
    }

}

struct Node *deleteBetweenNodes(struct Node *start, int data) {
    struct Node *temp;
    temp = start->next;

    while (temp->next != NULL) {
        if (temp->data == data) {
            break;
        }

        temp = temp->next;
    }

    if (temp->next != NULL) {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }

    else {
        if (temp->data == data) {
            temp->prev->next = NULL;
            free(temp);
        }

        else {
            printf("Element %d not found\n", data);
        }
    }

    return start;
}

struct Node *deleteLastNode(struct Node *start) {
    struct Node *p, *temp;

    if (start == NULL) {
        printf("No nodes to delete!\n");
        return start;
    }

    p = start;

    while (p->next != NULL) {
        p = p->next;
    }

    temp = p;
    p->prev->next = NULL;
    p->next = NULL;
    temp->prev = NULL;

    free(temp);
    
    return start;
}

struct Node *reverse(struct Node *start) {
  if (start == NULL || start->next == NULL) {
    return start;  // Handle empty list or single node
  }

  struct Node *p1, *p2;
  p1 = start->next;
  p2 = p1->next;

  while (p2 != NULL) { // Check for end of list
    // Fix the issue: set next pointer first, then previous
    p2->next = p1;
    p2->prev = p2->next;
    p1 = p2;
    p2 = p2->next;
  }

  start->next->prev = NULL;  // Set the last node's prev to null
  start = p1;

  return start;
}
