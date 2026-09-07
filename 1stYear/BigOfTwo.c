#include<stdio.h>
int main() {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    if (a > b) {
        printf("%d is greater than %d.\n", a, b);
    } else if (b > a) {
        printf("%d is greater than %d.\n", b, a);
    } else {
        printf("%d is equal to %d.\n", a, b);
    }
    return 0;
}