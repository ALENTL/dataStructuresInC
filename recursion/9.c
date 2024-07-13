#include <stdio.h>

int fibonacci(int n);

int main() {
    int num;

    printf("Enter the number to check fibonacci: ");
    scanf("%d", &num);

    printf("The fibonacci of the number is %d\n", fibonacci(num));

    return 0;
}

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    return fibonacci(n-1) + fibonacci(n-2);
}