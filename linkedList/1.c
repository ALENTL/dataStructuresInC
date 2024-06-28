#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data; // Use data instead of info for clarity
  struct Node* next;
};

// Function prototypes (optional but good practice)
struct Node *createList(struct Node* start);
struct Node *insertInBeginning(struct Node *start, int data);
void insertAtEnd(struct Node *start, int data);
void displayList(struct Node *start);
int countNodes(struct Node *start);
int searchList(struct Node *start);
int searchPosn(struct Node *start, int pos);
void insertBeforeNode(struct Node *start);
void insertAfterNode(struct Node *start);
void insertnthPosn(struct Node *start);
struct Node *deleteFirstPosn(struct Node *start);
struct Node *deleteInBetween(struct Node *start);
struct Node *deleteAtEnd(struct Node *start);
struct Node *reverse(struct Node *start);

int main() {
  struct Node *start = NULL;
  int choice, data;

  start = createList(start); // Create the list
  displayList(start); // Display the created list
  // insertBeforeNode(start);
  // insertnthPosn(start);
  // displayList(start);

  // int count = countNodes(start);
  // printf("Number of nodes: %d\n", count);

  // searchList(start);
  // searchPosn(start, 3);

  start = reverse(start);
  displayList(start);

  return 0; // Indicate successful program termination
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

  for (i = 2; i <= n; i++) {
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

int countNodes(struct Node *start) {
  int count = 0;

  if (start == NULL) {
    printf("No nodes were found.\n");
    return 0;
  }
  struct Node *p = start;  

  while (p!= NULL) {
    count++;
    p = p->next;
  }

  return count;
}

int searchList(struct Node *start) {
  int num, position = 1;
  struct Node *p = start;

  printf("Enter the element to search in the list: ");
  scanf("%d", &num);

  while (p != NULL) {
    if (p->data == num) {
      break;
    }
    position++;
    p = p->next;
  }

  if (p == NULL) {
    printf("Element %d is not present in the list\n", num);
  }
  else {
    printf("Element %d found at position %d\n", num, position);
  }

  return 0;
}

int searchPosn(struct Node *start, int pos) {
  struct Node *p = start;
  
  for (int i=1; i<pos && p != NULL; i++) {
    p = p->next;
  }

  if (p == NULL) {
    printf("Position not found!\n");
  }
  else {
    printf("Value at position %d is %d\n", pos, p->data);
  }
}

void insertAfterNode(struct Node *start) {
  int pVal, nVal;
  printf("Enter the value of the previous node: ");
  scanf("%d", &pVal);

  if (start == NULL) {
    return;
  }

  struct Node *p = start;

  while (p != NULL) {
    if (p->data == pVal) {
      break;
    }

    p = p->next;
  }

  if (p == NULL) {
    printf("Previous node with the value %d not found!\n", pVal);
    return;
  }

  struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
  printf("Enter the value of the new node: ");
  scanf("%d", &nVal);

  temp->data = nVal;
  temp->next = p->next;
  p->next = temp;

  displayList(start);
}

void insertBeforeNode(struct Node *start) {
  int sVal, nVal;

  printf("Enter the value of the succeeding node: ");
  scanf("%d", &sVal);

  if (start == NULL) {
    return;
  } 

  struct Node *p = start;

  while (p != NULL) {
    if (p->next->data == sVal) {
      break;
    }
    p = p->next;
  }

  struct Node *temp = (struct Node *) malloc(sizeof(struct Node));

  printf("Enter the value of the new node: ");
  scanf("%d", &nVal);

  temp->data = nVal;
  temp->next = p->next;
  p->next = temp;

  displayList(start);
}

void insertnthPosn(struct Node *start) {
  if (start == NULL) {
    return;
  }

  int pos, nVal;
  printf("Enter the position of the element: ");
  scanf("%d", &pos);

  struct Node *p = start;

  for (int i=1; i<pos-1 && p != NULL; i++) {
    p = p->next;
  }

  struct Node *temp = (struct Node *) malloc(sizeof(struct Node));

  printf("Enter the new value of the node: ");
  scanf("%d", &nVal);

  temp->data = nVal;
  temp->next = p->next;
  p->next = temp;
}

struct Node *deleteFirstPosn(struct Node *start) {
  if (start == NULL) {
    printf("Empty list!\n");
    return start;
  }

  struct Node *temp;
  temp = start;
  start = start->next;
  free(temp);

  return start;
}

struct Node *deleteInBetween(struct Node *start) {
  int num;

  if (start == NULL) {
    printf("Empty List!\n");
    return start;
  }

  printf("Enter the element: ");
  scanf("%d", &num);

  struct Node *p, *temp;
  p = start;

  while (p != NULL) {
    if (p->next->data == num) {
      break;
    }
    p = p->next;
  }

  if (p->next == NULL) {
    printf("Element %d not found in the list\n", num);
  }

  else {
    temp = p->next;
    p->next = temp->next;
    free(temp);
  }

  return start;
}

struct Node *deleteAtEnd(struct Node *start) {
  if (start == NULL) {
    printf("Empty List!\n");
    return start;
  }

  else if (start->next == NULL) {
    free(start);
    return start;
  }

  struct Node *p, *temp;
  p = start;

  while (p->next->next != NULL) {
    p = p->next;
  }

  temp = p->next;
  p->next = temp->next;

  free(temp);

 return start;
}

struct Node *reverse(struct Node *start) {
  if (start == NULL) {
    printf("Empty List!\n");
    return start;
  }

  struct Node *prev, *ptr, *next;
  ptr = start;
  prev = NULL;

  while (ptr != NULL) {
    next = ptr->next;
    ptr->next = prev;
    prev = ptr;
    ptr = next;
  }
  start = prev;

  return start;
}