#include <stdio.h>
void selectionSort(int arr[],int n){
    for (int i=0;i<n-1;i++){
        int minIdx=i;
        for (int j=i+1;j<n;j++){
            if (arr[j]<arr[minIdx]){
                minIdx=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[minIdx];
        arr[minIdx]=temp;
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
    selectionSort(arr,n);
    printf("\nSorted array: ");
    display(arr,n);
    return 0;
}