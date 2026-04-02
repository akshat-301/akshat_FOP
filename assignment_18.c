#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to calculate length of string
int stringLength(char str[]) {
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

// Function to reverse string
void stringReverse(char str[], char rev[]) {
    int len = stringLength(str);
    for (int i = 0; i < len; i++) {
        rev[i] = str[len - i - 1];
    }
    rev[len] = '\0';
}

// Function to check equality of two strings
int stringEqual(char str1[], char str2[]) {
    return strcmp(str1, str2) == 0;
}

// Function to check palindrome
int isPalindrome(char str[]) {
    int len = stringLength(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1])
            return 0;
    }
    return 1;
}

// Function to check substring
int isSubstring(char str[], char sub[]) {
    return strstr(str, sub) != NULL;
}

int main() {
    char str[100], str2[100], rev[100], sub[100];

    printf("Enter a string: ");
    scanf("%s", str);

    // i) Length
    printf("\nLength of string: %d\n", stringLength(str));

    // ii) Reverse
    stringReverse(str, rev);
    printf("Reversed string: %s\n", rev);

    // iii) Equality check
    printf("\nEnter another string to check equality: ");
    scanf("%s", str2);
    if (stringEqual(str, str2))
        printf("Strings are equal.\n");
    else
        printf("Strings are not equal.\n");

    // iv) Palindrome check
    if (isPalindrome(str))
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");

    // v) Substring check
    printf("\nEnter a substring to search: ");
    scanf("%s", sub);
    if (isSubstring(str, sub))
        printf("Substring found!\n");
    else
        printf("Substring not found.\n");

    return 0;
}
