#include<stdio.h>
#define size 6
int items[size];
int top=-1;
int rear=-1;
int front=-1;
void enqueue(int value){
    if(rear==size-1)
        printf("Full");
    else{
        if(front==-1)
            front=0;
        rear++;
        items[rear]=value;
        printf("%d is inserted\n",value);
    }
}
void dequeue(){
    if(front==-1)
        printf("Queue is empty\n");
    else{
        printf("%d is deleted\n",items[front]);
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
            printf("%d ",items[i]);
    }
    printf("\n");
}
int isFull()
{
    if(top==size-1)
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
void push(int val)
{
    if(isFull())
        printf("Stack Overflow\n");
    else
    {
        top++;
        items[top]=val;
        printf("%d pushed to stack\n",val);
    }
}
void pop()
{
    if(isEmpty())
        printf("Stack Underflow\n");
    else
    {
        printf("%d popped from stack\n",items[top]);
        top--;
    }
}
int peek()
{
    if(isEmpty())
        printf("Stack is empty\n");
    else
        return items[top];
}
void display()
{
    if(isEmpty())
        printf("Stack is empty\n");
    else
    {
        printf("Stack elements are:\n");
        for(int i=top;i>=0;i--)
            printf("%d\n",items[i]);
    }
}
int main(){
    int choice1,choice2,value;
    printf("1. Stack\n2. Queue\n");
    scanf("%d",&choice1);
    switch(choice1){
        case 1:
            printf("1. Push\n2. Pop\n3. Peek\n4. Display\n");
            scanf("%d",&choice2);
            while(choice2!=5){
                switch(choice2){
                    case 1:
                        printf("Enter value to push: ");
                        scanf("%d",&value);
                        push(value);
                        break;
                    case 2:
                        pop();
                        break;
                    case 3:
                        printf("Top element is: %d\n",peek());
                        break;
                    case 4:
                        display();
                        break;
                    default:
                        printf("Invalid choice\n");
                }
                printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
                scanf("%d",&choice2);
            }
            break;
        case 2:
            printf("1. Enqueue\n2. Dequeue\n3. Display\n");
            scanf("%d",&choice2);
            while(choice2!=4){
                switch(choice2){
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
                scanf("%d",&choice2);
            }
            break;
        default:
            printf("Invalid choice\n");
    }
    return 0;
}