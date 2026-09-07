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
void merge(int arr[],int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=arr[m+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1&&j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
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
        arr[k]=R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[],int l,int r){
    if(l<r){
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
int main(){
    int arr[]={6,4,7,8,1,9,5,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int choice;
    printf("1.Merge Sort\n2.Assignment1\n3.Assignment2\nChoose an option:\n");
    scanf("%d",&choice);
    int key,iterate;
    switch(choice){
        case 1:
            printf("Original array: ");
            display(arr,n);
            mergeSort(arr,0,n-1);
            printf("Sorted array: ");
            display(arr,n);
            break;
        case 2:
                printf("Enter a value to search: ");
                scanf("%d",&key);
                insertionSort(arr,n);
                int result=binarySearch(arr,key,0,n-1);
                if(result==-1)
                    printf("Not Found!");
                else
                    printf("Found at index = %d",result);
            break;
        case 3:
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
            break;
        default:
            printf("Invalid choice");
    }
    return 0;
}