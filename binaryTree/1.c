#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
  struct Node *left, *right;
  char info;
} Tree;

typedef struct {
  int front;
  int rear;
  Tree *queue[MAX];
} Queue;

Tree *getNode(char x);
void display(Tree *p, int level);
void preOrder(Tree *p);
void inOrder(Tree *p);
void postOrder(Tree *p);
void levelOrder(Queue *q, Tree *p);
int height(Tree *p);

void initializeQueue(Queue *q);
int isQueueFull(Queue *q);
int isQueueEmpty(Queue *q);
void insertQueue(Queue *q, Tree *item);
Tree *deleteQueue(Queue *q);

int main() {
  Tree *root = NULL;

  Queue *q = malloc(sizeof(Queue));

  initializeQueue(q);

  root = getNode('P');

  root->left = getNode('Q');
  root->right = getNode('R');

  root->left->left = getNode('A');
  root->left->right = getNode('B');

  display(root, 0);

  printf("\n\n");

  printf("Preorder: \n");
  preOrder(root);

  printf("\n\n");

  printf("Inorder: \n");
  inOrder(root);

  printf("\n\n");

  printf("Postorder: \n");
  postOrder(root);

  printf("\n\n");

  printf("Level Order: \n");
  levelOrder(q, root);

  printf("\n\n");

  printf("Height fo the tree: %d\n", height(root));

  return 0;
}

Tree *getNode(char x) {
  Tree *p = malloc(sizeof(Tree));
  p->info = x;
  p->left = p->right = NULL;

  return p;
}

void display(Tree *p, int level) {
  if (p == NULL) {
    return;
  }

  display(p->right, level + 1);
  printf("\n");

  for (int i = 0; i < level; i++) {
    printf("    ");
  }
  printf("%c", p->info);

  display(p->left, level + 1);
}

void preOrder(Tree *p) {
  if (p == NULL) {
    return;
  }

  printf("%c", p->info);
  preOrder(p->left);
  preOrder(p->right);
}

void inOrder(Tree *p) {
  if (p == NULL) {
    return;
  }

  inOrder(p->left);
  printf("%c", p->info);
  inOrder(p->right);
}

void postOrder(Tree *p) {
  if (p == NULL) {
    return;
  }

  postOrder(p->left);
  postOrder(p->right);
  printf("%c", p->info);
}

int height(Tree *p) {
  int leftHeight, rightHeight;

  if (p == NULL) {
    return 0;
  }

  leftHeight = height(p->left);
  rightHeight = height(p->right);

  if (leftHeight > rightHeight) {
    return 1 + leftHeight;
  }

  else {
    return 1 + rightHeight;
  }
}

void initializeQueue(Queue *q) {
  q->front = q->rear = -1;
}

int isQueueFull(Queue *q) {
  return q->rear == MAX - 1;
}

int isQueueEmpty(Queue *q) {
  if (q->front == -1 || q->front == q->rear + 1) {
    return 1;
  }
  return 0;
}

void insertQueue(Queue *q, Tree *item) {
  if (isQueueFull(q)) {
    printf("Queue Overflow!\n");
    exit(1);
  }

  if (q->front == -1) {
    q->front = 0;
  }

  q->queue[++q->rear] = item;
}

Tree *deleteQueue(Queue *q) {
  Tree *item;

  if (isQueueEmpty(q)) {
    printf("Queue Underflow!\n");
    exit(1);
  }

  item = q->queue[q->front++];

  return item;
}

void levelOrder(Queue *q, Tree *p) {
  if (p == NULL) {
    printf("Tree is empty!\n");
    return;
  }

  insertQueue(q, p);

  while (!isQueueEmpty(q)) {
    p = deleteQueue(q);
    printf("%c ", p->info);

    if (p->left != NULL) {
      insertQueue(q, p->left);
    }
    if (p->right != NULL) {
      insertQueue(q, p->right);
    }
  }
}
