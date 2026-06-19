#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *data;
  int capacity;
  int size;
} Heap;

// Menu Handler
void handleHeapOperations(Heap *heapNode, int isHeapMax);

// Core Heap Infrastructure
Heap *createHeap(int initialCapacity);
void freeHeap(Heap *heapNode);
void cheakAndResize(Heap *heapNode);
void swap(int *a, int *b);
void printHeap(Heap *heapNode, const char *heapName);

// Min-Heap Implementation
void minHeapSiftUp(Heap *heapNode, int index);
void minHeapSiftDown(Heap *heapNode, int index);
void minHeapInsert(Heap *heapNode, int value);
int extractMinimumFromHeap(Heap *heapNode, int *extractedValue);

// Max-Heap Implementation
void maxHeapSiftUp(Heap *heapNode, int index);
void maxHeapSiftDown(Heap *heapNode, int index);
void maxHeapInsert(Heap *heapNode, int value);
int extractMaximumFromHeap(Heap *heapNode, int *extractedValue);

int main() {
  Heap *minHeap = createHeap(4);
  Heap *maxHeap = createHeap(4);
  int choice;

  while (1) {
    printf("\n=================================");
    printf("\n       MAIN HEAP SELECTOR        ");
    printf("\n=================================");
    printf("\n1. Manage Min-Heap");
    printf("\n2. Manage Max-Heap");
    printf("\n3. Exit Application");
    printf("\nEnter your choice (1-3): ");
    if (scanf("%d", &choice) != 1) {
      printf("Invalid input. Retry!\n");
      break;
    }

    switch (choice) {
    case 1:
      handleHeapOperations(minHeap, 0); // 0 for Min-Heap
      break;
    case 2:
      handleHeapOperations(maxHeap, 1); // 1 for Max-Heap
      break;
    case 3:
      printf("Cleaning up memory and exiting. Goodbye!\n");
      freeHeap(minHeap);
      freeHeap(maxHeap);
      return 0;
    default:
      printf("Invalid option! Please select 1, 2, or 3.\n");
    }
  }
  return 0;
}

void handleHeapOperations(Heap *heapNode, int is_max_heap) {
  int choice, val, success;
  const char *heapName = is_max_heap ? "Max-Heap" : "Min-Heap";

  while (1) {
    printf("\n--- %s Menu ---", heapName);
    printf("\n1. Insert an element");
    printf("\n2. Delete / Extract Root");
    printf("\n3. Print Array Representation");
    printf("\n4. Return to Main Menu");
    printf("\nEnter choice (1-4): ");
    if (scanf("%d", &choice) != 1) {
      printf("Invalid data entered.\n");
      break;
    }

    switch (choice) {
    case 1:
      printf("Enter integer value to insert: ");
      scanf("%d", &val);
      if (is_max_heap) {
        maxHeapInsert(heapNode, val);
      } else {
        minHeapInsert(heapNode, val);
      }
      printf("Inserted %d successfully.\n", val);
      break;

    case 2:
      if (is_max_heap) {
        success = extractMaximumFromHeap(heapNode, &val);
      } else {
        success = extractMinimumFromHeap(heapNode, &val);
      }

      if (success) {
        printf("Extracted root value: %d\n", val);
      } else {
        printf("Operation Failed: Heap is empty!\n");
      }
      break;

    case 3:
      printHeap(heapNode, heapName);
      break;

    case 4:
      return;

    default:
      printf("Invalid option! Select 1-4.\n");
    }
  }
}

Heap *createHeap(int initialCapacity) {
  Heap *heapNode = (Heap *)malloc(sizeof(Heap));
  heapNode->data = (int *)malloc(initialCapacity * sizeof(int));
  heapNode->capacity = initialCapacity;
  heapNode->size = 0;

  return heapNode;
}

void freeHeap(Heap *heapNode) {
  if (heapNode) {
    free(heapNode->data);
    free(heapNode);
  }
}

void cheakAndResize(Heap *heapNode) {
  if (heapNode->size == heapNode->capacity) {
    heapNode->capacity *= 2;
    heapNode->data =
        (int *)realloc(heapNode->data, heapNode->capacity * sizeof(int));
  }
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void printHeap(Heap *heapNode, const char *heapName) {
  printf("%s Representation: [", heapName);
  for (int i = 0; i < heapNode->size; i++) {
    printf("%d%s", heapNode->data[i], (i == heapNode->size - 1) ? "" : ", ");
  }
  printf("] (Size: %d/%d)\n", heapNode->size, heapNode->capacity);
}

void minHeapSiftUp(Heap *heapNode, int index) {
  int parent = (index - 1) / 2;

  while (index > 0 && heapNode->data[index] < heapNode->data[parent]) {
    swap(&heapNode->data[index], &heapNode->data[parent]);
    index = parent;
    parent = (index - 1) / 2;
  }
}

void minHeapSiftDown(Heap *heapNode, int index) {
  int smallest = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  if (left < heapNode->size &&
      heapNode->data[left] < heapNode->data[smallest]) {
    smallest = left;
  }
  if (right < heapNode->size &&
      heapNode->data[right] < heapNode->data[smallest]) {
    smallest = right;
  }

  if (smallest != index) {
    swap(&heapNode->data[index], &heapNode->data[smallest]);
    minHeapSiftDown(heapNode, smallest);
  }
}

void minHeapInsert(Heap *heapNode, int value) {
  cheakAndResize(heapNode);
  heapNode->data[heapNode->size] = value;
  minHeapSiftUp(heapNode, heapNode->size);
  heapNode->size++;
}

int extractMinimumFromHeap(Heap *heapNode, int *extractedValue) {
  if (heapNode->size <= 0) {
    return 0;
  }

  *extractedValue = heapNode->data[0];
  heapNode->data[0] = heapNode->data[heapNode->size - 1];
  heapNode->size--;

  if (heapNode->size > 0) {
    minHeapSiftDown(heapNode, 0);
  }

  return 1;
}

void maxHeapSiftUp(Heap *heapNode, int index) {
  int parent = (index - 1) / 2;

  while (index > 0 && heapNode->data[index] > heapNode->data[parent]) {
    swap(&heapNode->data[index], &heapNode->data[parent]);
    index = parent;
    parent = (index - 1) / 2;
  }
}

void maxHeapSiftDown(Heap *heapNode, int index) {
  int largest = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  if (left < heapNode->size && heapNode->data[left] < heapNode->data[largest]) {
    largest = left;
  }
  if (right < heapNode->size &&
      heapNode->data[right] < heapNode->data[largest]) {
    largest = right;
  }

  if (largest != index) {
    swap(&heapNode->data[index], &heapNode->data[largest]);
    maxHeapSiftDown(heapNode, largest);
  }
}

void maxHeapInsert(Heap *heapNode, int value) {
  cheakAndResize(heapNode);
  heapNode->data[heapNode->size] = value;
  maxHeapSiftUp(heapNode, heapNode->size);
  heapNode->size++;
}

int extractMaximumFromHeap(Heap *heapNode, int *extractedValue) {
  if (heapNode->size <= 0) {
    return 0;
  }

  *extractedValue = heapNode->data[0];
  heapNode->data[0] = heapNode->data[heapNode->size - 1];
  heapNode->size--;

  if (heapNode->size > 0) {
    maxHeapSiftDown(heapNode, 0);
  }

  return 1;
}
