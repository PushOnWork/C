#include <stdio.h>
int SumFibonacci(int a){
    if (a==0)
        return 0;
    if (a == 1)
        return a;
    return SumFibonacci(a - 1) + SumFibonacci(a - 2);
}
int main(){
    int n, sum = 0;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    sum += SumFibonacci(i);
    printf("Sum of first %d terms of Fibonacci series is: %d\n", n, sum);
    return 0;
}