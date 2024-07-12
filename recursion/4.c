#include <stdio.h>

int sum(int n) {
    if (n/10 == 0) {
        return n;
    }

    return sum(n/10) + n%10;
}

int main() {
    int num;

    printf("Enter the a digit to check for its sum: ");
    scanf("%d", &num);

    printf("The sum of the digits of %d is %d\n", num, sum(num));

    return 0;
}