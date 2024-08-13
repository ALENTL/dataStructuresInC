#include <stdio.h>
#include <stdlib.h>

struct Node {
    int node;
    struct Node *left, *right;
};

int main() {
    struct Node *tree = (struct Node *)malloc(sizeof(struct Node));
}
