def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]
def partition(arr,low: int,high: int)->int:
    pivot=arr[high]
    i=low-1
    for j in range(low,high):
        if(arr[j]<pivot):
            i+=1
            swap(arr,i,j)
    swap(arr,i+1,high)
    return i+1
def QuickSort(arr,low: int,high: int):
    if(low<high):
        p=partition(arr,low,high)
        QuickSort(arr,low,p-1)
        QuickSort(arr,p+1,high)
