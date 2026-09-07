#include<stdio.h>
int main(){
    int n, i, j; 
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n][n];
    printf("Enter the elements: ");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    printf("sum of diagonal elements: ");
    int sum = 0;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i==j||i+j==n-1){
                sum += arr[i][j];
            }
        }
    printf("%d", sum);
    return 0;
}