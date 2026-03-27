#include <stdio.h>

int main() {
    float basic, hra, ta, gross, tax, net;

    printf("Enter Basic Salary: ");
    scanf("%f", &basic);

    // Calculate allowances
    hra = 0.10 * basic;   // 10% HRA
    ta  = 0.05 * basic;   // 5% TA

    // Calculate gross salary
    gross = basic + hra + ta;

    // Calculate professional tax (2% of gross salary)
    tax = 0.02 * gross;

    // Calculate net salary
    net = gross - tax;

    // Display results
    printf("\nBasic Salary = %.2f\n", basic);
    printf("HRA (10%%) = %.2f\n", hra);
    printf("TA (5%%) = %.2f\n", ta);
    printf("Gross Salary = %.2f\n", gross);
    printf("Professional Tax (2%%) = %.2f\n", tax);
    printf("Net Salary = %.2f\n", net);

    return 0;
}