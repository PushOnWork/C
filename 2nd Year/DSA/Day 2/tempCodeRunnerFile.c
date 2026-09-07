#include<stdio.h>
int main(){
    int arr[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,91}};
    int i,j;
    scanf("%d%d",&i,&j);
    printf("address=%d\n",&arr[i][j]);
     int indexAdd=(i*4+j);
    int *address=(int *)arr+indexAdd;
    printf("address from calculation=%d",address);
}