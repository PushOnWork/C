#include <stdio.h>
int LinearSearch(int arr[],int n,int key){
    int c=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            c=i;
            break;
        }
    }
    return c;
}
int main(){
    int arr[10]={20,40,70,30,90,10,50,60,100,80};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Enter value to search: ");
    int x;
    scanf("%d",&x);
    int result =LinearSearch(arr,n,x);
    if(result==-1)
        printf("Not found!");
    else
        printf("Found at %d index",result);
    return 0;
}