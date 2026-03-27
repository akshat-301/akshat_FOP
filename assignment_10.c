#include <stdio.h>
#include <math.h>

// Function to calculate factorial
long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int choice;
    double x, y;

    printf("Simple Calculator\n");
    printf("-----------------\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power (x^y)\n");
    printf("6. Factorial (x!)\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &x, &y);
            printf("Result = %.2lf\n", x + y);
            break;

        case 2:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &x, &y);
            printf("Result = %.2lf\n", x - y);
            break;

        case 3:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &x, &y);
            printf("Result = %.2lf\n", x * y);
            break;

        case 4:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &x, &y);
            if (y != 0)
                printf("Result = %.2lf\n", x / y);
            else
                printf("Error: Division by zero!\n");
            break;

        case 5:
            printf("Enter base (x) and exponent (y): ");
            scanf("%lf %lf", &x, &y);
            printf("Result = %.2lf\n", pow(x, y));
            break;

        case 6:
            printf("Enter an integer: ");
            scanf("%lf", &x);
            if (x < 0 || x != (int)x) {
                printf("Error: Factorial is defined only for non-negative integers.\n");
            } else {
                printf("Result = %lld\n", factorial((int)x));
            }
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
