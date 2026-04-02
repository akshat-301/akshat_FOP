#include <stdio.h>

// Function to compute GCD using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find smallest common divisor other than 1
int smallestCommonDivisor(int a, int b) {
    int min = (a < b) ? a : b;
    for (int i = 2; i <= min; i++) {
        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }
    return -1; // return -1 if no common divisor other than 1
}

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int scd = smallestCommonDivisor(num1, num2);
    if (scd != -1)
        printf("Smallest common divisor (other than 1) = %d\n", scd);
    else
        printf("No common divisor other than 1.\n");

    int resultGCD = gcd(num1, num2);
    printf("Greatest Common Divisor (GCD) = %d\n", resultGCD);

    return 0;
}
