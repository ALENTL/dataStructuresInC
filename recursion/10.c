#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char source, char temp, char dest);

int main() {
  int n;

  printf("Enter the number of disks: ");
  scanf("%d", &n);

  hanoi(n, 'A', 'B', 'C');
  return 0;
}

void hanoi(int n, char source, char temp, char dest) {
  if (n == 1) {
    printf("Move disk %d from %c -> %c\n", n, source, dest);
    return;
  }

  hanoi(n - 1, source, dest, temp);
  printf("Move disk %d from %c -> %c\n", n, source, dest);
  hanoi(n - 1, temp, source, dest);
}
