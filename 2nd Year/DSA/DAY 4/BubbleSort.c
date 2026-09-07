#include <stdio.h>
void bubbleSort(int arr[],int n){
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        printf("After step %d: ",i+1);
        for (int k=0;k<n;k++){
            printf("%d ",arr[k]);
        }
        printf("\n");
    }
}
void display(int arr[],int n){
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[]={6,4,7,8,1,9,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("Original array: ");
    display(arr,n);
    bubbleSort(arr,n);
    printf("Sorted array: ");
    display(arr,n);
    return 0;
}