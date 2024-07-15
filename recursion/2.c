#include <stdio.h>

void printN(int n) {
    if (n == 0) {
        return;
    }

    printf("%d\n", n);
    printN(n-1);
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printN(n);
}