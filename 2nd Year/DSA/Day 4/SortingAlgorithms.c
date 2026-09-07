#include <stdio.h>
int StepChoice;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void display(int arr[],int n){
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void bubbleSort(int arr[],int n){
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
        if(StepChoice==1){
            printf("After step %d: ",i+1);
            display(arr,n);
        }
    }
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
        if(StepChoice==1){
            printf("After step %d: ",i);
            display(arr,n);
        }
    }
}
void selectionSort(int arr[],int n){
    for (int i=0;i<n-1;i++){
        int minIdx=i;
        for (int j=i+1;j<n;j++){
            if (arr[j]<arr[minIdx]){
                minIdx=j;
            }
        }
        swap(&arr[minIdx],&arr[i]);
        if(StepChoice==1){
            printf("After step %d: ",i+1);
            display(arr,n);
        }
    }
}
void modifiedBubbleSort(int arr[],int n){
    int flag;
    for (int i=0;i<n-1;i++){
        flag=0;
        for (int j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                flag=1;
            }
        }
        if(StepChoice==1){
        printf("After step %d: ",i+1);
        display(arr,n);
        }
        if (flag==0) {
            break;
        }
    }
}
void ModifiedSelectionSort(int arr[],int n){
    for (int i=0;i<n/2;i++){
        int minIdx=i,maxIdx=i;
        for (int k=i+1;k<n-i;k++){
            if (arr[k]<arr[minIdx]){
                minIdx=k;
            }
            if (arr[k]>arr[maxIdx]){
                maxIdx=k;
            }
        }
        if(maxIdx==i){
            maxIdx=minIdx;
        }
        swap(&arr[i],&arr[minIdx]);
        swap(&arr[n-i-1],&arr[maxIdx]);
        if(StepChoice==1){
            printf("After step %d: ",i+1);
            display(arr,n);
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
    if(StepChoice==1){
        printf("After step %d:-\n",i+1);
        printf("Pivot: %d\n",pivot);
        display(arr,high+1);
    }
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
    int arr[]={4,6,7,8,1,2,3,5,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("1.Bubble Sort\n2.Insertion Sort\n3.Selection Sort\n4.Modified Bubble Sort\n5.Modified Selection Sort\n6.Quick Sort\nEnter your choice: ");
    int ch;
    scanf("%d",&ch);
    printf("Want to the print each step?\n1.Yes\n2.No\nEnter your choice: ");
    scanf("%d",&StepChoice);
     printf("Original array: ");
        display(arr,n);
    switch(ch){
        case 1:
           bubbleSort(arr,n);
            printf("Sorted array: ");
            display(arr,n);
            break;
        case 2:
            insertionSort(arr,n);
            printf("Sorted array: ");
            display(arr,n);
            break;
        case 3:
            selectionSort(arr,n);
            printf("Sorted array: ");
            display(arr,n);
            break;
        case 4:
            modifiedBubbleSort(arr,n);
            printf("Sorted array: ");
            display(arr,n);
            break;
        case 5:
            ModifiedSelectionSort(arr,n);
            printf("Sorted array: ");
            display(arr,n);
            break;
        case 6:
            quickSort(arr,0,n-1);
            printf("Sorted array: ");
            display(arr,n);
            break;
        default:
            printf("Invalid choice\n");
    }
    return 0;
}