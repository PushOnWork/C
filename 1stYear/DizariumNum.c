#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int c=0;
int countDigits(int num) {
    if (num==0)
        return c;
    c++;
    return countDigits(num / 10);
}
int n;
bool isDizarium(int num) {
    int originalNum = num;
    float sum=0;
    int digits = countDigits(num);
    for (int i = digits; i >= 1; i--){
        int digit = num % 10;
        sum += pow(digit, i);
        num /= 10;
    }
    return sum == originalNum;
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (isDizarium(num))
        printf("%d is a Dizarium Number\n", num);
    else
        printf("%d is not a Dizarium Number\n", num);
    return 0;
}