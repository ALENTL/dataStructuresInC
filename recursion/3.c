#include <stdio.h>

void printN(int n) {
    if (n == 0) {
        return;
    }

    printN(n-1);
    printf("%d\n", n);
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printN(n);
}