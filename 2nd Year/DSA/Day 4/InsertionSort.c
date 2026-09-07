#include <stdio.h>
void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0&&key<arr[j]){
            arr[j+1]=arr[j];
            --j;
        }
        arr[j+1]=key;
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
    insertionSort(arr,n);
    printf("Sorted array: ");
    display(arr,n);
    return 0;
}