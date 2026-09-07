#include <stdio.h>
int BinarySearch(int arr[],int x,int low,int high){
    while(low<=high){
        int mid =low+(high-low)/2;
        if(x==arr[mid])
            return mid;
        if(x>arr[mid])
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}
int main(){
    int arr[]={10,15,20,25,30,35,40,45,50,55,60};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("Enter value to search: ");
    int x;
    scanf("%d",&x);
    int result=BinarySearch(arr,x,0,n-1);
    if(result==-1)
        printf("Not Found!");
    else
        printf("Found at %d index",result);
    return 0;
}