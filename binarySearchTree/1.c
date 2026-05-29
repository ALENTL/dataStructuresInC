#include <stdio.h>
#include <stdlib.h>

struct Node {
  struct Node *left;
  int info;
  struct Node *right;
};

struct Node *getNode(int x);
void display(struct Node *p, int level);
struct Node *searchNode(struct Node *p, int x);
struct Node *insertNode(struct Node *p, int x);
struct Node *deleteNode(struct Node *p, int x);
struct Node *minimumNode(struct Node *p);
struct Node *maximumNode(struct Node *p);
int treeHeight(struct Node *p);
void preOrder(struct Node *p);
void inOrder(struct Node *p);
void postOrder(struct Node *p);

int main() {
  struct Node *root = NULL;
  int choice;

  while (1) {
    printf("\n1. Display the Binary Search Tree\n");
    printf("2. Inserting nodes to Binary Search Tree\n");
    printf("3. Deleting a node from the Binary Search Tree\n");
    printf("4. Search for a node in the Binary Search Tree\n");
    printf("5. Find the smallest element from the Binary Search Tree\n");
    printf("6. Find the largest element from the Binary Search Tree\n");
    printf("7. To find the Tree Height!\n");
    printf("8. To display the preOrder Traversal of the Binary Search Tree\n");
    printf("9. To display the inOrder Traversal of the Binary Search Tree\n");
    printf(
        "10. To display the postOrder Traversal of the Binary Search Tree\n");

    printf("\nEnter your selection: ");
    scanf("%d", &choice);

    if (choice == 1) {
      if (root == NULL) {
        printf("The tree is empty!\n");
      } else {
        display(root, 0);
      }
    } else if (choice == 2) {
      int num;

      printf("Enter the node to insert: ");
      scanf("%d", &num);

      root = insertNode(root, num);

      if (root == NULL) {
        printf("The tree is empty!\n");
      } else {
        printf("The tree is: \n");
        display(root, 0);
        printf("\n");
      }

    } else if (choice == 3) {
      int num;

      printf("Enter the element to delete from the BST: ");
      scanf("%d", &num);

      root = deleteNode(root, num);
      if (root == NULL) {
        printf("The tree is empty!\n");
      } else {
        printf("The tree is: \n");
        display(root, 0);
        printf("\n");
      }
    } else if (choice == 4) {
      int num;

      printf("Enter the number to search for in the BST: ");
      scanf("%d", &num);

      struct Node *foundNode = searchNode(root, num);

      if (foundNode != NULL) {
        printf("%d was FOUND in the tree!\n", foundNode->info);
      } else {
        printf("%d was NOT found in the tree!\n", num);
      }
    } else if (choice == 5) {
      struct Node *minNode = minimumNode(root);
      if (minNode == NULL) {
        printf("The tree is empty!\n");
      } else {
        printf("Smallest element in the BST: %d\n", minNode->info);
      }
    } else if (choice == 6) {
      struct Node *maxNode = maximumNode(root);
      if (maxNode == NULL) {
        printf("The tree is empty!\n");
      } else {
        printf("Largest element in the BST: %d\n", maxNode->info);
      }
    } else if (choice == 7) {
      printf("Tree Height: %d\n", treeHeight(root));
    } else if (choice == 8) {
      printf("PreOrder Traversal: \n");
      preOrder(root);
      printf("\n");
    } else if (choice == 9) {
      printf("InOrder Traversal: \n");
      inOrder(root);
      printf("\n");
    } else if (choice == 10) {
      printf("PostOrder Traversal: \n");
      postOrder(root);
      printf("\n");
    } else if (choice == 11) {
      printf("Quitting!\n");
      exit(0);
    } else {
      printf("Invalid Option. Please retry!\n");
    }
  }
}

struct Node *getNode(int x) {
  struct Node *p = (struct Node *)malloc(sizeof(struct Node));
  p->info = x;
  p->left = NULL;
  p->right = NULL;

  return p;
}

struct Node *insertNode(struct Node *p, int x) {
  if (p == NULL) {
    p = getNode(x);
  } else if (x < p->info) {
    p->left = insertNode(p->left, x);
  } else if (x > p->info) {
    p->right = insertNode(p->right, x);
  } else {
    printf("%d already exists in the tree\n", x);
  }

  return p;
}

struct Node *searchNode(struct Node *p, int x) {
  if (p == NULL) {
    return NULL;
  }
  if (x < p->info) {
    return searchNode(p->left, x);
  }
  if (x > p->info) {
    return searchNode(p->right, x);
  }

  return p;
}

struct Node *deleteNode(struct Node *p, int x) {
  if (p == NULL) {
    printf("%d not found!\n", x);
    return p;
  }

  struct Node *smallestNodeOfRightSubtree, *childNode;

  if (x < p->info) {
    p->left = deleteNode(p->left, x);
  } else if (x > p->info) {
    p->right = deleteNode(p->right, x);
  } else {
    if (p->left != NULL && p->right != NULL) {
      smallestNodeOfRightSubtree = p->right;

      while (smallestNodeOfRightSubtree->left) {
        smallestNodeOfRightSubtree = smallestNodeOfRightSubtree->left;
      }
      p->info = smallestNodeOfRightSubtree->info;
      p->right = deleteNode(p->right, smallestNodeOfRightSubtree->info);
    } else {
      if (p->left != NULL) {
        childNode = p->left;
      } else {
        childNode = p->right;
      }
      free(p);
      p = childNode;
    }
  }
  return p;
}

struct Node *minimumNode(struct Node *p) {
  if (p == NULL) {
    return NULL;
  }

  if (p->left == NULL) {
    return p;
  }
  return minimumNode(p->left);
}

struct Node *maximumNode(struct Node *p) {
  if (p == NULL) {
    return NULL;
  }

  if (p->right == NULL) {
    return p;
  }
  return maximumNode(p->right);
}

void preOrder(struct Node *p) {
  if (p == NULL) {
    return;
  }
  printf("%d ", p->info);
  preOrder(p->left);
  preOrder(p->right);
}

void inOrder(struct Node *p) {
  if (p == NULL) {
    return;
  }
  inOrder(p->left);
  printf("%d ", p->info);
  inOrder(p->right);
}

void postOrder(struct Node *p) {
  if (p == NULL) {
    return;
  }
  postOrder(p->left);
  postOrder(p->right);
  printf("%d ", p->info);
}

int treeHeight(struct Node *p) {
  int leftSubTreeHeight, rightSubTreeHeight;

  if (p == NULL) {
    return 0;
  }

  leftSubTreeHeight = treeHeight(p->left);
  rightSubTreeHeight = treeHeight(p->right);

  if (leftSubTreeHeight > rightSubTreeHeight) {
    return leftSubTreeHeight + 1;
  }
  return rightSubTreeHeight + 1;
}

void display(struct Node *p, int level) {
  if (p == NULL) {
    return;
  }

  display(p->right, level + 1);
  printf("\n");

  for (int i = 0; i < level; i++) {
    printf("  ");
  }
  printf("%d", p->info);

  display(p->left, level + 1);
}
