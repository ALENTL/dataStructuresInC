#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a%b);
}

int main() {
    int dividend, factor;

    printf("Dividend: ");
    scanf("%d", &dividend);

    printf("Factor: ");
    scanf("%d", &factor);

    printf("The gcd is: %d\n", gcd(dividend, factor));

    return 0;
}