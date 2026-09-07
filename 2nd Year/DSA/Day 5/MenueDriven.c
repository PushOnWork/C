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
    // printf("Left array: ");
    // display(L,n1);
    // printf("Right array: ");
    // display(M,n2);
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
void mergeSort(int arr[],int low,int high){
    if(low<high){
        int mid=low+(high-low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int main(){
    int arr[]={4,6,7,8,1,2,3,5,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("Original array: ");
    display(arr,n);
    int choice;
    printf("Choose algorithm:\n1. Quick Sort\n2. Merge two arrays\n3. Merge Sort\nChoice: ");
    scanf("%d",&choice);
    if(choice==1){
        quickSort(arr,0,n-1);
        printf("Sorted array using Quick Sort: ");
        display(arr,n);
    }
    else if(choice==2){
        merge(arr,0,n/2-1,n-1);
        printf("Merged array using Merge Function: ");
        display(arr,n);
    }
    else if(choice==3){
        mergeSort(arr,0,n-1);
        printf("Sorted array using Merge Sort: ");
        display(arr,n);
    }
    else{
        printf("Invalid choice\n");
        return 1;
    }
    return 0;
}