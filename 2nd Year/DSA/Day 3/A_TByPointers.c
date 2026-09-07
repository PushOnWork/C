#include<stdio.h>
int  access(int *arr,int index){
    return *(arr+(index));
}
void traverse(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%d ",*(arr+i));
    }
}
int main(){
    int arr[]={1,4,5,2,6,8,9,3,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int pos;
    printf("For Accessing:\n");
    printf("Enter position to access: ");
    scanf("%d",&pos);
    printf("Element at position %d is %d\n",pos,access(arr,pos));
    printf("For Trversing\n");
    traverse(arr,n);
    return 0;
}