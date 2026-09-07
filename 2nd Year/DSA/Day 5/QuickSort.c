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
int partition(int arr[],int low,int high){
    int pivot=arr[high];
    printf("Pivot: %d\n",pivot);
    int i=(low-1);
    for (int j=low;j<high;j++){
        if (arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    display(arr,high+1);
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
    printf("Original array: ");
    display(arr,n);
    quickSort(arr,0,n-1);
    printf("Sorted array: ");
    display(arr,n);
    return 0;
}