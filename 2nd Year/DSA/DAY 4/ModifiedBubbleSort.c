#include <stdio.h>
void modifiedBubbleSort(int arr[],int n){
    int flag;
    for (int i=0;i<n-1;i++){
        flag=0;
        for (int j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        printf("After step %d: ",i+1);
        for (int k=0;k<n;k++){
            printf("%d ",arr[k]);
        }
        printf("\n");
        if (flag==0) {
            break;
        }
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
    modifiedBubbleSort(arr,n);
    printf("Sorted array: ");
    display(arr,n);
    return 0;
}