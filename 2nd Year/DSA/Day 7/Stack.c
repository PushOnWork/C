#include<stdio.h>
#define max 5
int top=-1;
int stack[max];
int isFull()
{
    if(top==max-1)
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
        stack[top]=val;
        printf("%d pushed to stack\n",val);
    }
}
void pop()
{
    if(isEmpty())
        printf("Stack Underflow\n");
    else
    {
        printf("%d popped from stack\n",stack[top]);
        top--;
    }
}
int peek()
{
    if(isEmpty())
        printf("Stack is empty\n");
    else
        return stack[top];
}
void display()
{
    if(isEmpty())
        printf("Stack is empty\n");
    else
    {
        printf("Stack elements are:\n");
        for(int i=top;i>=0;i--)
            printf("%d\n",stack[i]);
    }
}
int main(){
    int choice,value;
    printf("1. Push\n2. Pop\n3. Peek\n4. Display\n");
    scanf("%d",&choice);
    while(choice!=5){
        switch(choice)
        {
            case 1:
                printf("Enter value to push: ");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("Top element is %d\n",peek());
                break;
            case 4:
                display();
                break;
            default:
                printf("Invalid choice\n");
        }
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        scanf("%d",&choice);
    }
    return 0;
}