#include <stdio.h>
#include <math.h>

int main() {
    long long binary;
    int decimal = 0, base = 1, remainder;

    printf("Enter a binary number: ");
    scanf("%lld", &binary);

    while (binary > 0) {
        remainder = binary % 10;     // get last digit
        decimal += remainder * base; // add to decimal
        binary = binary / 10;        // remove last digit
        base = base * 2;             // increase base (2^n)
    }

    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}