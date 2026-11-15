#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
void insertBeginning(int val){
    struct node *newNode=malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data=val;
    if(head==NULL){
        head=newNode;
        newNode->next=head;
    }else{
        struct node *temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        newNode->next=head;
        temp->next=newNode;
        head=newNode;
    }
}
void insertEnd(int val){
    struct node *newNode=malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data=val;
    if(head==NULL){
        head=newNode;
        newNode->next=head;
    }else{
        struct node *temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=head;
    }
}
void insertAtPosition(int val,int position){
    if(position<=1){
        insertBeginning(val);
        return;
    }
    struct node *newNode=malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data=val;
    struct node *temp=head;
    for(int i=1;i<position-1&&temp->next!=head;i++){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
void deleteBeginning(){
    if(head == NULL){
        printf("List is Empty\n");
        return;
    }
    if(head->next==head){
        free(head);
        head=NULL;
        return;
    }
    struct node *temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    struct node *delNode=head;
    temp->next=head->next;
    head=head->next;
    free(delNode);
}
void deleteEnd(){
    if(head==NULL){
        printf("List is Empty\n");
        return;
    }
    if(head->next==head){
        free(head);
        head=NULL;
        return;
    }
    struct node *temp=head;
    struct node *prev=NULL;
    while(temp->next!=head){
        prev=temp;
        temp=temp->next;
    }
    prev->next=head;
    free(temp);
}
void deleteAtPosition(int position){
    if(head==NULL){
        printf("List is Empty\n");
        return;
    }
    if(position==1){
        deleteBeginning();
        return;
    }
    struct node *temp=head;
    struct node *prev=NULL;
    for(int i=1;i<position&&temp->next!=head;i++){
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    free(temp);
}
void display(){
    if(head==NULL){
        printf("List is Empty\n");
        return;
    }
    struct node *temp=head;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    } while (temp!=head);
    printf("\n");
}
void search(int key){
    if (head==NULL){
        printf("List is Empty\n");
        return;
    }
    struct node *temp=head;
    int pos=1;
    do{
        if(temp->data==key){
            printf("found at position %d\n",pos);
            return;
        }
        temp=temp->next;
        pos++;
    }while(temp!=head);
    printf("Not found\n",key);
}
int main(){
    struct node *newNode1=malloc(sizeof(struct node));
    struct node *newNode2=malloc(sizeof(struct node));
    struct node *newNode3=malloc(sizeof(struct node));
    newNode1->data=10;
    newNode2->data=20;
    newNode3->data=30;
    newNode1->next=newNode2;
    newNode2->next=newNode3;
    newNode3->next=newNode1;
    head=newNode1;
    display();
    printf("Insertion at Beginning: ");
    insertBeginning(1);
    display();
    printf("Insertion at End: ");
    insertEnd(40);
    display();
    printf("Insertion at Position: ");
    insertAtPosition(25,2);
    display();
    printf("Deletion at Beginning: ");
    deleteBeginning();
    display();
    printf("Deletion at End: ");
    deleteEnd();
    display();
    printf("Deletion at Position: ");
    deleteAtPosition(3);
    display();
    search(40);
    return 0;
}