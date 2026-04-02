#include <stdio.h>

int main() {
    int num, digit;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Digits in reverse order: ");
    while (num > 0) {
        digit = num % 10;   // extract last digit
        printf("%d", digit);
        num = num / 10;     // remove last digit
    }
    printf("\n");

    return 0;
}
