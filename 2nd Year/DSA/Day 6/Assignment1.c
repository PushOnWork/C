#include<stdio.h>
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int binarySearch(int arr[],int x,int low,int high){
    while(low<=high){
        int mid=low+(high-low)/2;
        if(x==arr[mid])
            return mid;
        if(x>arr[mid])
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}
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
int main(){
    int arr[]={6,4,7,8,1,9,5,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key;
    printf("Enter a value to search: ");
    scanf("%d",&key);
    insertionSort(arr,n);
    int result=binarySearch(arr,key,0,n-1);
    if(result==-1)
        printf("Not Found!");
    else
        printf("Found at index = %d",result);
    return 0;
}