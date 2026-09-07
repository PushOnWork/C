#include <stdio.h>
int Tribonacci(int a){
    if(a == 0|| a == 1 || a == 2)
        return 0;
    if(a == 3)
        return 1;
    return Tribonacci(a - 1) + Tribonacci(a - 2) + Tribonacci(a - 3);
}
int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Tribonacci Series: \n");
    for (int i = 1; i <= n; i++) {
        printf("%d, ", Tribonacci(i));
    }
    return 0;
}