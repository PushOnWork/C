#include<stdio.h>
void display(int arr[],int n){
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void merge(int arr[],int p,int q,int r){
    int n1=q-p+1;
    int n2=r-q;
    int L[n1],M[n2];
    for (int i=0;i<n1;i++){
        L[i]=arr[p+i];
    }
    for (int j=0;j<n2;j++){
        M[j]=arr[q+1+j];
    }
    printf("Left array: ");
    display(L,n1);
    printf("Right array: ");
    display(M,n2);
    int i=0,j=0,k=p;
    while(i<n1 && j<n2){
        if(L[i]<=M[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=M[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=M[j];
        j++;
        k++;
    }
}
int main(){
    int arr[]={4,6,7,8,1,2,3,5,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("Original array: ");
    display(arr,n);
    merge(arr,0,n/2-1,n-1);
    printf("Merged array: ");
    display(arr,n);
    return 0;
}