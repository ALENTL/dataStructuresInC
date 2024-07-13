#include <stdio.h>

void decimalToBinary(int num);

int main() {
    int num;

    printf("Enter the number to convert into binary: ");
    scanf("%d", &num);

    decimalToBinary(num);
}

void decimalToBinary(int num) {
    if (num == 0) {
        return;
    }

    decimalToBinary(num/2);

    printf("%d\n", num%2);
}