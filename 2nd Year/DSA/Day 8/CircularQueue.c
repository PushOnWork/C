#include<stdio.h>
#define size 5
int item[size];
int rear=-1,front=-1;
int isFull(){
    return (front == 0 && rear == size - 1) || (front == (rear + 1) % size);
}

int isEmpty(){
    return (front == -1);
}

void enqueue(int element){
    if (isFull()) {
        printf("Full\n");
    } else {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % size;
        item[rear] = element;
        printf("Inserted=%d\n", element);
    }
}

int dequeue(){
    int element;
    if (isEmpty()) {
        printf("Empty\n");
        return -1;
    }

    element = item[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }

    printf("Deleted element = %d\n", element);
    return element;
}

void display(){
    int i;
    if (isEmpty())
        printf("Empty\n");
    else {
        printf("Front = %d\n", front);
        for (i = front; i != rear; i = (i + 1) % size)
            printf("%d ", item[i]);
        printf("%d\n", item[rear]);
        printf("Rear = %d\n", rear);
    }
}
int main(){
    int choice,value;
    printf("\n1. Enqueue\n2. Dequeue\n3. Display\n");
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
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d",&choice);
    }
    return 0;
}