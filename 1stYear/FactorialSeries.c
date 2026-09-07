#include<stdio.h>
int main(){
    int n,sum=0;
    printf("Enter: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int fact=1;
        for(int j=1;j<=i;j++){
            fact=fact*j;
        }
        sum=sum+fact;
        fact=1;
    }
    printf("%d\n",sum);
return 0;
}