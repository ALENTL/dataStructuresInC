# INDEX

## LINKED LIST

<details>
  <summary><h3><a href="https://github.com/ALENTL/dataStructuresInC/blob/master/linkedList/1.c">1. Single Linked List</a></h3></summary>

- Create a linked list
- Inserting first element to linked list
- Inserting more elements to the end list
- Display the list
- Count the number of nodes in the list
- Search for an element in the list and returns its position
- Search for a position in the list and returns the value at that position
- Insert a node after a given node
- Insert a node before a node
- Insert a node at given position
- Delete a node from the first position
- Delete a node in between nodes
- Delete a node at the end
- Reverse the list
</details>
<details>
  <summary><h3><a href="https://github.com/ALENTL/dataStructuresInC/blob/master/linkedList/2.c">2. Sorting of Single Linked List</a></h3></summary>

- Sort by exchanging data
- Sort by exchanging nodal links
</details>
<details>
  <summary><h3><a href="https://github.com/ALENTL/dataStructuresInC/blob/master/linkedList/3.c"></a>3. Merge two sorted lists</h3></summary>

- Merging by creating a new list
- Merging by rearranging links
</details>
<details>
  <summary><h3><a href="https://github.com/ALENTL/dataStructuresInC/blob/master/linkedList/4.c"></a>4. Sorting a List using Merge Sort Algorithm</h3></summary>

- Using recursion to sort a linked list using merge sort algorithm
</details>
<details>
  <summary><h3><a href="https://github.com/ALENTL/dataStructuresInC/blob/master/linkedList/5.c"></a>5. Solving a Cycle List</h3></summary>

- Solving a list having cycle with Floyd's cycle detection algorithm
  - Inserting a cycle
  - Find the cycle
  - Removing the cycle
</details>
<details>
  <summary><h3><a href="https://github.com/ALENTL/dataStructuresInC/blob/master/linkedList/6.c"></a>6. Doubly Linked List</h3></summary>

- Linked list consisting of prev and next pointers and a data for each node
  - Create a doubly linked list
  - Insert at empty doubly linked list
  - Insert in the beginning of the doubly linked list
  - Insert at the end of the list
  - Insertion in between nodes
    - Insert after a node
    - Insert before a node
  - Deletion from doubly linked list
    - Deletion of the first node
    - Deletion of the only node
    - Deletion in between nodes
    - Deletion in last node
  - Reverse the list
</details>
<details>
  <summary><h3><a href="https://github.com/ALENTL/dataStructuresInC/blob/master/linkedList/7.c"></a>7. Circular Linked List</h3></summary>

- Display the list
- Insertion
  - Insert in empty list
  - Insert in beginning
  - Insert at end
  - Insertion after a node
- Deletion
- Concatenation of the list
</details>
<details>
  <summary><h3><a href="https://github.com/ALENTL/dataStructuresInC/blob/master/linkedList/8.c"></a>8. Linked List with Header Node</h3></summary>

- Create List
- Insertion
  - Before
  - After
  - At position
- Delete Node
- Reverse
</details>
<details>
  <summary><h3><a href="https://github.com/ALENTL/dataStructuresInC/blob/master/linkedList/9.c"></a>9. Sorted Linked List</h3></summary>

- Insert as sorted
- Search for the element
</details>
<br>

## STACK

### [1. Stack Using Arrays](https://github.com/ALENTL/dataStructuresInC/blob/master/stack/1.c)

- Initialize empty stack
- Push an element to the stack
- Pop the last element from the stack
- Find the size of the stack
- Find the top element of the stack
- Display the stack

### [2. Stack Using Linked List](https://github.com/ALENTL/dataStructuresInC/blob/master/stack/2.c)

- Initialize empty stack
- Push an element to the stack
- Pop the last element
- Find the size of the stack
- Find the top element of the stack
- Display the stack

### [3. Balanced Parantheses using Stack](https://github.com/ALENTL/dataStructuresInC/blob/master/stack/3.c)

- Initialize empty stack
- Push an element to the stack
- Pop an element from the stack
- Check if the stack is empty
- Check if the given parantheses are matching
- Check if the given expression has balanced parantheses

### [4. Infix to Postfix using stack](https://github.com/ALENTL/dataStructuresInC/blob/master/stack/4.c)

- Convert infix to postfix
- Push element to the stack
- Pop an element from the stack
- Check if the stack is empty
- Check the precendence of the operators
- Evaluate the postfix

### [5. Infix to Prefix using Stack](https://github.com/ALENTL/dataStructuresInC/blob/master/stack/5.c)

- Get infix expression from the user and store as infix
- Reverse the infix expression, also the brackets
- Convert the reversed infix expression to postfix
- Reverse the postfix expression to obtain prefix
- Display the prefix expression

### [6. Postfix to Infix using Stack](https://github.com/ALENTL/dataStructuresInC/blob/master/6.c)

- Get postfix expression from the user and store as postfix
- if operand, push it to the stack
- if operator, pop 2 elements from the stack, 
```c
sprintf(temp, "(%s%c%s)", operand2, operator, operand1)
```
- display the infix expression

### [7. Prefix to Infix using Stack](https://github.com/ALENTL/dataStructuresInC/blob/master/7.c)

- Get prefix expression from the user and store as prefix
- if operand, push it to the stack
- if operator, pop 2 elements from the stack, 
```c
sprintf(temp, "(%s%c%s)", operand1, operator, operand2)
```
- display the infix expression

<br>

## QUEUE

### [1. Queue Using Arrays](https://github.com/ALENTL/dataStructuresInC/blob/master/queue/1.c)

- Initialize empty queue
- Insert an element to the queue
- Delete an element from queue (as per FIFO)
- Find the size of the queue
- Find the peek element of the queue
- Display the queue

### [2. Queue Using Linked List](https://github.com/ALENTL/dataStructuresInC/blob/master/queue/2.c)

- Initialize empty queue
- Insert an element to the queue
- Delete an element from queue (as per FIFO)
- Find the size of the queue
- Find the peek element of the queue
- Display the queue

### [3. Queue Using Circular Linked List](https://github.com/ALENTL/dataStructuresInC/blob/master/queue/3.c)

- Initialize empty queue
- Insert an element to the queue
- Delete an element from queue (as per FIFO)
- Find the size of the queue
- Find the peek element of the queue
- Display the queue

### [4. Circular Queue](https://github.com/ALENTL/dataStructuresInC/blob/master/queue/4.c)

- Initialize empty queue
- Checking if the queue is full
- Checking if the queue is empty
- Inserting an element in the queue
- Deleting an element from the queue (as per FIFO)
- Find the size of the queue
- Find the peek element of the queue
- Display the queue

### [5. Deque](https://github.com/ALENTL/dataStructuresInC/blob/master/queue/5.c)

- Initialize empty deque
- Checking if deque is full
- Checking if deque is empty
- Inserting an element at the front of the deque
- Inserting an element at the end of the deque
- Deleting an element from the front of the deque
- Deleting an element from the rear of the deque
- Display the queue

### [6. Priority Queue](https://github.com/ALENTL/dataStructuresInC/blob/master/queue/6.c)

- Initialize empty queue
- Check if queue is empty
- Insert an element with it's priority
- Delete an element (follows FIFO)
- Display the queue

<br>

## RECURSION

### [1. Factorial using recursion](https://github.com/ALENTL/dataStructuresInC/blob/master/recursion/1.c)

- Using recursion to find the factorial of a number and returning it

```c
int factorial = n * factorial(n-1);
```

### [2. Finding numbers n to 1](https://github.com/ALENTL/dataStructuresInC/blob/master/recursion/2.c)

- Using recursion to find the numbers from n to 1

### [3. Finding numbers 1 to n](https://github.com/ALENTL/dataStructuresInC/blob/master/recursion/3.c)

- Using recursion to find the numbers from 1 to n

### [4. Finding sum of the digits of a number](https://github.com/ALENTL/dataStructuresInC/blob/master/recursion/4.c)

- Using recursion to find the sum of digits of a number

```c
int sum(int n) {
  if (n/10 == 0) {
    return n;
  }

  return sum(n/10) + n%10;
}
```

### [5. Converting decimal to binary](https://github.com/ALENTL/dataStructuresInC/blob/master/recursion/5.c)

- Using recursion to convert decimal to binary

### [6. Converting decimal to octal](https://github.com/ALENTL/dataStructuresInC/blob/master/recursion/6.c)

- Using recursion to convert decimal to octal

### [7. Finding nth power of a number](https://github.com/ALENTL/dataStructuresInC/blob/master/recursion/7.c)

- Using recursion to find the nth power and returning it

```c
int power(int num, pow) {
  if (pow == 0) {
    return 1;
  }

  return power(num, pow-1) * num;
}
```

### [8. Finding Greatest Common Divisor using Euclid's Algorithm](https://github.com/ALENTL/dataStructuresInC/blob/master/recursion/8.c)

- Using recursion to find the gcd of a number

```c
int gcd(a, b) {
  if (b == 0) {
    return a;
  }

  return gcd(b, a%b);
}
```

### [9. Finding fibonacci number of nth number](https://github.com/ALENTL/dataStructuresInC/blob/master/recursion/9.c)

- Finding fibonacci number

```c
fib(n) = fib(n-1) + fib(n-2)
```

### [10. Tower of hanoi](https://github.com/ALENTL/dataStructuresInC/blob/master/recursion/10.c)

- Moving disks (tower of hanoi) from source to destination with temp source

```c
hanoi(n, source, destination, tempSource)
```

<br>

## BINARY TREE

### [1. Binary Tree - Tree Representation](https://github.com/ALENTL/dataStructuresInC/blob/master/binaryTree/1.c)

- Creating a binary tree
- Finding height of the binary tree

```c
int height(struct Node *p) {
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
```

- Pre Order Traversal

```c
void preorder(struct Node *p) {
  if (p == NULL) {
    return;
  }

  printf("%c\n", p->info);
  preorder(p->left);
  preorder(p->right);
}
```

- Inorder Traversal

```c
void inorder(struct Node *p) {
  if (p == NULL) {
    return;
  }

  inorder(p->left);
  printf("%s\n", p->info);
  inorder(p->right);
}
```

- Post Order Traversal

```c
void postorder(struct Node *p) {
  if (p == NULL) {
    return;
  }

  postorder(p->left);
  postorder(p->right);
  printf("%s\n", p->info);
}
```

- Level Order Traversal

```c
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
```

<br>

## BINARY SEARCH TREE

### [1. Binary Search Tree - Tree Representation](https://github.com/ALENTL/dataStructuresInC/blob/master/binarySearchTree/1.c)
- Creating a Binary Search Tree
- Inserting nodes to Binary Search Tree
- Deleting node from a Binary Search Tree
- Searching a node in the Binary Search Tree
- Finding the smallest element from the Binary Search Tree
- Finding the largest element from the Binary Search Tree
- Find tree height
- To display InOrder, PreOrder and PostOrder Traversal results.

<br>

## HEAP

### [1. Heap - Heap Representation](https://github.com/ALENTL/dataStructuresInC/blob/master/heap/1.c)
- Creating and inserting elements to minimum and maximum heap
- Check and resize the heap
- Sift Up (Restore Up) and Sift Down (Restore Down) implementation for both minimum and maximum heap
- Pop and display minimum node from minHeap and maximum node from maxHeap

<br>
