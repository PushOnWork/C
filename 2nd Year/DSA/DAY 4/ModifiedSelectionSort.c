#include <stdio.h>
void ModifiedSelectionSort(int arr[],int n){
    for (int i=0;i<n/2;i++){
        int minIdx=i,maxIdx=i;
        for (int k=i+1;k<n-i;k++){
            if (arr[k]<arr[minIdx]){
                minIdx=k;
            }
            if (arr[k]>arr[maxIdx]){
                maxIdx=k;
            }
        }
        if(maxIdx==i){
            maxIdx=minIdx;
        }
        int temp=arr[i];
        arr[i]=arr[minIdx];
        arr[minIdx]=temp;
        temp=arr[n-i-1];
        arr[n-i-1]=arr[maxIdx];
        arr[maxIdx]=temp;
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
    ModifiedSelectionSort(arr,n);
    printf("\nSorted array: ");
    display(arr,n);
    return 0;
}