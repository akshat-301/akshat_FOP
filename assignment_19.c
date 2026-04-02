#include <stdio.h>
#include <string.h>

struct Date {
    int day, month, year;
};

struct Employee {
    char name[50];
    char designation[50];
    char gender[10];
    struct Date doj;
    float salary;
};

// Function to count total employees
int totalEmployees(int n) {
    return n;
}

// Function to count male and female employees
void countGender(struct Employee emp[], int n) {
    int male = 0, female = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(emp[i].gender, "Male") == 0 || strcmp(emp[i].gender, "male") == 0)
            male++;
        else if (strcmp(emp[i].gender, "Female") == 0 || strcmp(emp[i].gender, "female") == 0)
            female++;
    }
    printf("\nMale Employees   : %d", male);
    printf("\nFemale Employees : %d\n", female);
}

// Function to list employees with salary > 10000
void highSalary(struct Employee emp[], int n) {
    printf("\nEmployees with salary > 10000:\n");
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (emp[i].salary > 10000) {
            printf("%s (%s) - %.2f\n", emp[i].name, emp[i].designation, emp[i].salary);
            found = 1;
        }
    }
    if (!found) printf("None\n");
}

// Function to list employees with designation "Asst Manager"
void asstManager(struct Employee emp[], int n) {
    printf("\nEmployees with designation 'Asst Manager':\n");
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(emp[i].designation, "Asst Manager") == 0) {
            printf("%s (%s)\n", emp[i].name, emp[i].gender);
            found = 1;
        }
    }
    if (!found) printf("None\n");
}

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee emp[n];

    // Accept employee details
    for (int i = 0; i < n; i++) {
        printf("\nEnter details of Employee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Designation: ");
        scanf("%s", emp[i].designation);
        printf("Gender (Male/Female): ");
        scanf("%s", emp[i].gender);
        printf("Date of Joining (dd mm yyyy): ");
        scanf("%d %d %d", &emp[i].doj.day, &emp[i].doj.month, &emp[i].doj.year);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }

    // Display results
    printf("\nTotal Employees: %d\n", totalEmployees(n));
    countGender(emp, n);
    highSalary(emp, n);
    asstManager(emp, n);

    return 0;
}
