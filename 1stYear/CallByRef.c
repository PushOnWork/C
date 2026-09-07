#include<stdio.h>
void callByRef(int *a){
    int y=100;
    *a=y;
}
int main(){
    int x=20;
    int *p=&x;
    printf("Before calling function: %d\n",x);
    callByRef(p);
    printf("After calling function: %d\n",x);
    int a=123;
    int b=10;
    printf("%d",a%b);
    return 0;
}