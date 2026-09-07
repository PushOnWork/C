#include <stdio.h>
int main() {
    int num,sum=0;
    printf("Enter a number: ");
    scanf("%d", &num);
    while(sum>9||sum==0){
        sum=0;
        while(num>0){
            int digit=num%10;
            sum+=digit*digit;
            num/=10;
        }
        num=sum;
    }
    if(sum!=1)
        printf("Not a Happy Number\n");
    else
    printf("Happy Number\n");
    return 0;
}