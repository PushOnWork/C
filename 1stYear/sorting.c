#include <stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int arr[10]={1,5,7,3,6,4,6,7,4,8};
    for(int i=0;i<10;i++){
        for(int j=0;j<5;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
            if(arr[10-j]>arr[10-(j+1)]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
    for(int i=0;i<10;i++)
    printf("%d",arr[i]);
    return 0;
}