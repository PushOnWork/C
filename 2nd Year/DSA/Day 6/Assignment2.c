#include<stdio.h>
void display(int arr[],int n){
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubbleSort(int arr[],int n,int iteration){
    for (int i=0;i<iteration;i++){
        for (int j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=(low-1);
    for (int j=low;j<high;j++){
        if (arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}
void quickSort(int arr[],int low,int high){
    if (low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
int main(){
    int arr[]={6,4,7,8,1,9,5,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int iterate;
    printf("Enter no of Iteration for 1st sort: ");
    scanf("%d",&iterate);
    printf("Original Array: ");
    display(arr,n);
    bubbleSort(arr,n,iterate);
    printf("Afetr 1st Sort: ");
    display(arr,n);
    quickSort(arr,0,n-iterate-1);
    printf("Sorted array: ");
    display(arr,n);
    return 0;
}