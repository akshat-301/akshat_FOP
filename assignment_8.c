#include <stdio.h>

int main() {
    int marks[5];
    int i, pass = 1;
    float total = 0, percentage;

    // Accept marks for 5 courses
    printf("Enter marks for 5 courses:\n");
    for (i = 0; i < 5; i++) {
        printf("Course %d: ", i + 1);
        scanf("%d", &marks[i]);
        if (marks[i] < 40) {
            pass = 0; // Student fails if any course < 40
        }
        total += marks[i];
    }

    if (pass == 0) {
        printf("\nResult: FAIL\n");
    } else {
        percentage = total / 5.0; // Aggregate percentage
        printf("\nResult: PASS\n");
        printf("Aggregate Percentage: %.2f%%\n", percentage);

        // Assign grade based on percentage
        if (percentage >= 75) {
            printf("Grade: Distinction\n");
        } else if (percentage >= 60) {
            printf("Grade: First Division\n");
        } else if (percentage >= 50) {
            printf("Grade: Second Division\n");
        } else if (percentage >= 40) {
            printf("Grade: Third Division\n");
        }
    }

    return 0;
}
