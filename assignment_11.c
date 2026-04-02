#include <stdio.h>
#include <math.h>

// Function to check if a number is prime
int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Function to calculate factorial
long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to print prime factors
void primeFactors(int n) {
    printf("Prime factors of %d: ", n);
    while (n % 2 == 0) {
        printf("2 ");
        n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            printf("%d ", i);
            n /= i;
        }
    }
    if (n > 2)
        printf("%d", n);
    printf("\n");
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    // Square root
    printf("Square root of %d = %.2f\n", num, sqrt(num));

    // Square
    printf("Square of %d = %d\n", num, num * num);

    // Cube
    printf("Cube of %d = %d\n", num, num * num * num);

    // Prime check
    if (isPrime(num))
        printf("%d is a prime number.\n", num);
    else
        printf("%d is not a prime number.\n", num);

    // Factorial
    printf("Factorial of %d = %lld\n", num, factorial(num));

    // Prime factors
    primeFactors(num);

    return 0;
}
