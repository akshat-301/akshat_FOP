#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i;

    printf("How many random numbers do you want? ");
    scanf("%d", &n);

    // Seed the random number generator with current time
    srand(time(0));

    printf("Pseudo-random numbers:\n");

    for (i = 0; i < n; i++) {
        int num = rand();  // generates a random number
        printf("%d\n", num);
    }

    return 0;
}