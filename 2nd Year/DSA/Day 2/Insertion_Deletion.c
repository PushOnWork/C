#include <stdio.h>
int arr[20],n;
//insertion of values
void insert(int x,int pos){
    for(int i=n;i>pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos]=x;
    n++;
}
//deletion of values
void delete(int pos){
    for (int i = pos;i<n-1;i++)
    arr[i]=arr[i+1];
    n--;
}
//display element
void display(){
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
}
int main(){
    int x,pos,del;
    printf("Enter no of elements: ");
    scanf("%d",&n);
    printf("Enter elements: \n");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter value to insert and its position: ");
    scanf("%d%d", &x,&pos);
    insert(x,pos);
    display();
    printf("\nEnter position to delete: ");
    scanf("%d",&del);
    delete(del);
    display();
    return 0;
}