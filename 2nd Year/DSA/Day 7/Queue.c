#include<stdio.h>
#define size 6
int queue[size];
int rear=-1;
int front=-1;
void enqueue(int);
void display();
void dequeue();
int main(){
    int choice,value;
    printf("1. Enqueue\n2. Dequeue\n3. Display\n");
    scanf("%d",&choice);
    while(choice!=4){
        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d",&value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid choice\n");
        }
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d",&choice);
    }
    return 0;
}
void enqueue(int value){
    if(rear==size-1)
        printf("Full");
    else{
        if(front==-1)
            front=0;
        rear++;
        queue[rear]=value;
        printf("%d is inserted\n",value);
    }
}
void dequeue(){
    if(front==-1)
        printf("Queue is empty\n");
    else{
        printf("%d is deleted\n",queue[front]);
        front++;
    }
    if(front>rear)
        front=rear=-1;
}
void display(){
    if(front==-1)
        printf("Queue is empty\n");
    else{
        printf("Queue elements are:\n");
        for(int i=front;i<=rear;i++)
            printf("%d ",queue[i]);
    }
    printf("\n");
}