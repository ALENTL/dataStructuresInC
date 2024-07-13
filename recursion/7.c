#include <stdio.h>

float power(float x, int n);

int main() {
    int num, powr;

    printf("Enter the number to find: ");
    scanf("%d", &num);

    printf("Enter the power of the number: ");
    scanf("%d", &powr);

    printf("The resultant is %f\n", power(num, powr));

    return 0;
}

float power(float x, int n) {
    if (n == 0) {
        return 1;
    }

    return x * power(x, n-1);
}