#include<stdio.h>
int  access(int *arr,int pos){
    return *(arr+(pos-1));
}
void traverse(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%d ",*(arr+i));
    }
}
int LinearSearch(int *arr,int n,int key){
    int c=-1;
    for(int i=0;i<n;i++){
        if(*(arr+i)==key){
            c=i;
            break;
        }
    }
    return c;
}
int main(){

}