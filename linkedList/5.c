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
void insertCycle(struct Node *start, int x);
struct Node *findCycle(struct Node *start);
void removeCycle(struct Node *start, struct Node *pC);

int main() {
    int num;

    struct Node *start = NULL, *ptr = NULL;
    start = createList(start);
    printf("List Created!\n");
    displayList(start);

    printf("Enter the number to where cycle is created: ");
    scanf("%d", &num);
    insertCycle(start, num);

    ptr = findCycle(start);

    if (ptr == NULL) {
      printf("No cycle detected. Terminating\n");
      return 0;
    }
    else {
      printf("Cycle found in the list\n");
      removeCycle(start, ptr);
      printf("Cycle Removed!\n");
    }

    displayList(start);
}

struct Node *createList(struct Node* start) {
  int n, i, data;
  printf("Enter the number of nodes: ");
  scanf("%d", &n);

  // Handle the case where the user enters 0 nodes
  if (n == 0) {
    return start; // Return the empty list
  }

  printf("Enter the first element: ");
  scanf("%d", &data);
  start = insertInBeginning(start, data); // Insert the first element

  for (i = 1; i < n; i++) {
    printf("Enter the next element: ");
    scanf("%d", &data);
    insertAtEnd(start, data); // Insert subsequent elements
  }

  return start;
}

struct Node *insertInBeginning(struct Node* start, int data) {
  struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
  temp->data = data;
  temp->next = start;
  return temp; // Return the new head of the list
}

void insertAtEnd(struct Node *start, int data) {
  struct Node *temp, *p;
  temp = (struct Node*)malloc(sizeof(struct Node));
  temp->data = data;
  temp->next = NULL;

  // Handle the case of an empty list
  if (start == NULL) {
    start = temp; // Set the head for the first element
    return;
  }

  // Traverse to the last node
  p = start;
  while (p->next != NULL) {
    p = p->next;
  }
  p->next = temp; // Link the last node to the new node
}

void displayList(struct Node *start) {
  struct Node *p;
  if (start == NULL) {
    printf("List is empty!\n");
    return;
  }

  printf("List is: ");
  p = start;
  while (p != NULL) {
    printf("%d, ", p->data);
    p = p->next;
  }
  printf("\n");
}

void insertCycle(struct Node *start, int x) {
  struct Node *p, *px = NULL, *prev;

  p = prev = start;

  while (p != NULL) {
    if (p->data == x) {
      px = p;
    }

    prev = p;
    p = p->next;
  }

  if (px != NULL) {
    prev->next = px;
  }
}

struct Node *findCycle(struct Node *start) {
  struct Node *slowP, *fastP;

  if (start->next == NULL) {
    return NULL;
  }

  slowP = fastP = NULL;

  while (fastP != NULL && fastP->next != NULL) {
    slowP = slowP->next;
    fastP = fastP->next->next;

    if (slowP == fastP) {
      return slowP;
    }
  }
  return NULL;
}

void removeCycle(struct Node *start, struct Node *pC) {
  struct Node *p, *q;
  int lenCycle, lenRemList, lenList;

  printf("The node at which the cycle was detected: %d\n", p->data);

  p = q = pC;
  
  lenCycle = 0;

  do {
    lenCycle++;
    q = q->next;
  } while (p != q);

  printf("The length of the cycle is %d\n", lenCycle);

  lenRemList = 0;

  while (p != q) {
    lenRemList++;
    p = p->next;
    q = q->next;
  }

  printf("The length of the non-cycle is %d\n", lenRemList);

  lenList = lenCycle + lenRemList;

  printf("The total length of the list: %d\n", lenList);

  for (int i=0; i<=lenList; i++) {
    p = p->next;
  }
  p->next = NULL;
}