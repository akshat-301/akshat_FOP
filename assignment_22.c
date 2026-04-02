#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], sub[100];
    int choice;

    printf("Enter a string: ");
    scanf("%s", str1);

    do {
        printf("\n--- String Operations Menu ---\n");
        printf("1. Calculate length of string\n");
        printf("2. Reverse string\n");
        printf("3. Equality check of two strings\n");
        printf("4. Check palindrome\n");
        printf("5. Check substring\n");
        printf("6. Concatenate two strings\n");
        printf("7. Copy string\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Length of string: %lu\n", strlen(str1));
                break;

            case 2: {
                char rev[100];
                strcpy(rev, str1);
                strrev(rev);  // in-built function (works in Turbo C/Windows compilers)
                printf("Reversed string: %s\n", rev);
                break;
            }

            case 3:
                printf("Enter another string: ");
                scanf("%s", str2);
                if (strcmp(str1, str2) == 0)
                    printf("Strings are equal.\n");
                else
                    printf("Strings are not equal.\n");
                break;

            case 4: {
                char temp[100];
                strcpy(temp, str1);
                strrev(temp);
                if (strcmp(str1, temp) == 0)
                    printf("The string is a palindrome.\n");
                else
                    printf("The string is not a palindrome.\n");
                break;
            }

            case 5:
                printf("Enter substring to search: ");
                scanf("%s", sub);
                if (strstr(str1, sub) != NULL)
                    printf("Substring found!\n");
                else
                    printf("Substring not found.\n");
                break;

            case 6:
                printf("Enter another string to concatenate: ");
                scanf("%s", str2);
                strcat(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;

            case 7:
                strcpy(str2, str1);
                printf("Copied string: %s\n", str2);
                break;

            case 0:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
