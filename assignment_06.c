#include <stdio.h>

// Factorial using recursion
long factorialRecursive(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorialRecursive(n - 1);
}

// Factorial without recursion (iterative)
long factorialIterative(int n) {
    long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d using recursion: %ld\n", num, factorialRecursive(num));
        printf("Factorial of %d without recursion: %ld\n", num, factorialIterative(num));
    }

    return 0;
}
