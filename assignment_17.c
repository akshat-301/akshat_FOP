#include <stdio.h>
#include <string.h>

// Function to calculate length
int stringLength(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

// Function to reverse string
void reverseString(char str[], char rev[]) {
    int len = stringLength(str);
    for (int i = 0; i < len; i++) {
        rev[i] = str[len - i - 1];
    }
    rev[len] = '\0';
}

// Function to check equality
int checkEqual(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }
    return (str1[i] == '\0' && str2[i] == '\0');
}

// Function to check palindrome
int isPalindrome(char str[]) {
    int len = stringLength(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to check substring
int isSubstring(char str[], char sub[]) {
    int len1 = stringLength(str);
    int len2 = stringLength(sub);

    for (int i = 0; i <= len1 - len2; i++) {
        int j;
        for (j = 0; j < len2; j++) {
            if (str[i + j] != sub[j]) {
                break;
            }
        }
        if (j == len2) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char str1[100], str2[100], rev[100], sub[100];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    printf("Enter substring to search: ");
    scanf("%s", sub);

    // Length
    printf("\nLength of first string: %d\n", stringLength(str1));

    // Reverse
    reverseString(str1, rev);
    printf("Reversed string: %s\n", rev);

    // Equality
    if (checkEqual(str1, str2))
        printf("Strings are equal\n");
    else
        printf("Strings are not equal\n");

    // Palindrome
    if (isPalindrome(str1))
        printf("First string is a palindrome\n");
    else
        printf("First string is not a palindrome\n");

    // Substring
    if (isSubstring(str1, sub))
        printf("Substring found\n");
    else
        printf("Substring not found\n");

    return 0;
}