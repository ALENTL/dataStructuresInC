#include <stdio.h>

void decimalToOctal(int num);

int main() {
    int num;

    printf("Enter the number to convert to octal: ");
    scanf("%d", &num);

    decimalToOctal(num);
}

void decimalToOctal(int num) {
    if (num == 0) {
        return;
    }

    decimalToOctal(num/8);
    printf("%d\n", num%8);
}