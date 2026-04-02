#include <stdio.h>

struct Student {
    int rollNo;
    char name[50];
    float marks[3];   // marks in 3 subjects
    float total;
    float percentage;
};

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    // Accept student details
    for (int i = 0; i < n; i++) {
        printf("\nEnter details of student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNo);
        printf("Name: ");
        scanf("%s", students[i].name);

        students[i].total = 0;
        for (int j = 0; j < 3; j++) {
            printf("Enter marks in subject %d: ", j + 1);
            scanf("%f", &students[i].marks[j]);
            students[i].total += students[i].marks[j];
        }
        students[i].percentage = students[i].total / 3.0;
    }

    // Display student results
    printf("\n--- Student Results ---\n");
    for (int i = 0; i < n; i++) {
        printf("\nRoll No: %d", students[i].rollNo);
        printf("\nName   : %s", students[i].name);
        printf("\nMarks  : ");
        for (int j = 0; j < 3; j++) {
            printf("%.2f ", students[i].marks[j]);
        }
        printf("\nTotal  : %.2f", students[i].total);
        printf("\nPercent: %.2f%%", students[i].percentage);

        if (students[i].percentage >= 40)
            printf("\nResult : PASS\n");
        else
            printf("\nResult : FAIL\n");
    }

    return 0;
}
