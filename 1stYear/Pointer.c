#include <stdio.h>
int main(){
    int a = 10,b = 20;
    int sum = a + b;
    int *ptr = &sum; // Pointer to the sum variable
    printf("The sum of %d and %d is %d\n", a, b, sum);
    printf("Address of sum variable: %p\n", (void*)ptr);
    printf("Value pointed to by ptr: %d\n", *ptr);

    return 0;
}