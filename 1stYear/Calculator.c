#include <stdio.h>
int main(){
    int a,b,prod,sum,sub,div;
    printf("Enter two integers: ");
    scanf("%d %d",&a,&b);
    sum=a+b;
    sub=a-b;
    prod=a*b;
    div=(a/b);
    printf("Sum: %d\n",sum);
    printf("Subtraction: %d\n",sub);
    printf("Product: %d\n",prod);
    printf("Division: %d",div);
    return 0;
}