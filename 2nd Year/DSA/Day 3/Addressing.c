#include<stdio.h>
void rowMajor(int rows,int cols,int arr[][cols],int i,int j){
    int indexAdd=(i*cols+j);
    int *address=&arr[0][0]+indexAdd;
    printf("Address from Row Major = %d\n",address);
}
void columnMajor(int rows,int cols,int arr[][cols],int i,int j){
    int indexAdd=(j*rows+i);
    int *address=&arr[0][0]+indexAdd;
    printf("Address from Column Major = %d\n",address);
}
int main(){
    int rows,cols,ch,i,j;
    printf("Enter number of rows: ");
    scanf("%d",&rows);
    printf("Enter number of columns: ");
    scanf("%d",&cols);
    int arr[rows][cols];
    printf("Enter array elements:\n");
    for (i=0;i<rows;i++){
        for (j=0;j<cols;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("1.Row Major\n2.Column Major\n");
    scanf("%d",&ch);
    printf("Enter the row and col:\n");
    scanf("%d%d",&i,&j);
    switch(ch){
        case 1:
            rowMajor(rows,cols,arr,i,j);
            break;
        case 2:
            columnMajor(rows,cols,arr,i,j);
            break;
        default:
            printf("Invalid Input!");
    }
    return 0;
}