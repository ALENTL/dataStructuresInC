#include <stdio.h>

int factorial(int num) {
    if (num <= 1) {
        return 1;
    }

    return num * factorial(num-1);
}

int main() {
    int num;

    printf("Enter the number to check factorial: ");
    scanf("%d", &num);

    printf("The factorial of num is %d\n", factorial(num));

    return 0;
}