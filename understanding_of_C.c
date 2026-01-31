#include<stdio.h>
int main() {
    int c;
    int a,b;
    printf("Please enter your first number: ");
    printf("Please enter your second number: ");
    scanf("%d %d",&a,&b);
    printf("Enter 1, for Addtion of numbers\n"
            "Enter 2, for Subtraction of numbers\n"
            "Enter 3, for Multiplication of numbers\n"
            "Enter 4, for Division of numbers");
    scanf("%d",&c);
    switch(c){
    case 1:
    printf("Addition of numbers is: %d", a+b);
    break;
    case 2:
    printf("Subtraction of numbers is %d", a-b);
    break;
    case 3:
    printf("Multiplication of numbers is %d", a*b);
    break;
    case 4:
    printf("Division of numbers is %d", a/b);
    break;
    default:
    printf("Invalid Input");
    }
    return 0;
}

    

