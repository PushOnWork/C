#include <stdio.h>
int main() {
    int age;
    printf("Enter age: ");
    scanf("%d", &age);
    if (age >= 18) 
        printf("%d is eligible to vote.\n", age);
    else 
        printf("%d is not eligible to vote.\n", age);
    return 0;
}