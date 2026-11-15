#include<stdio.h>
#include<stdlib.h>
struct dnode{
    int data;
    struct dnode *prev;
    struct dnode *next;
};
struct dnode *head=NULL;
void insertBeginningDLL(int val){
    struct dnode *newNode=malloc(sizeof(struct dnode));
    newNode->data=val;
    newNode->prev=NULL;
    newNode->next=head;
    if(head!=NULL){
        head->prev=newNode;
    }
    head=newNode;
}
void insertEndDLL(int val){
    struct dnode *newNode=malloc(sizeof(struct dnode));
    newNode->data=val;
    newNode->next=NULL;
    if(head==NULL){
        newNode->prev=NULL;
        head=newNode;
        return;
    }
    struct dnode *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}
void insertAtPositionDLL(int val,int position){
    if(position<=1){
        insertBeginningDLL(val);
        return;
    }
    struct dnode *newNode=malloc(sizeof(struct dnode));
    newNode->data=val;
    struct dnode *temp=head;
    for(int i=1;i<position-1&&temp!=NULL;i++) {
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Position out of range\n");
        free(newNode);
        return;
    }
    newNode->next=temp->next;
    newNode->prev=temp;
    if(temp->next!=NULL){
        temp->next->prev=newNode;
    }
    temp->next=newNode;
}
void deleteBeginningDLL(){
    if(head==NULL){
        printf("List is Empty\n");
        return;
    }
    struct dnode *temp=head;
    head=head->next;
    if(head!=NULL){
        head->prev=NULL;
    }
    free(temp);
}
void deleteEndDLL(){
    if (head==NULL){
        printf("List is Empty\n");
        return;
    }
    struct dnode *temp=head;
    if(temp->next==NULL){
        head=NULL;
        free(temp);
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
}
void deleteAtPositionDLL(int position){
    if(head==NULL){
        printf("List is Empty\n");
        return;
    }
    if(position==1){
        deleteBeginningDLL();
        return;
    }
    struct dnode *temp=head;
    for(int i=1;i<position&&temp!=NULL;i++){
        temp = temp->next;
    }
    if(temp==NULL){
        printf("Position out of range\n");
        return;
    }
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    if(temp->prev!=NULL){
        temp->prev->next=temp->next;
    }
    free(temp);
}
void displayDLL(){
    struct dnode *temp=head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void searchDLL(int key){
    struct dnode *temp=head;
    int pos=1;
    while (temp!=NULL){
        if(temp->data==key){
            printf("Found at position %d\n",key,pos);
            return;
        }
        temp=temp->next;
        pos++;
    }
    printf("Not found\n");
}
int main(){
    struct dnode *d1=malloc(sizeof(struct dnode));
    struct dnode *d2=malloc(sizeof(struct dnode));
    struct dnode *d3=malloc(sizeof(struct dnode));
    d1->data=10;
    d2->data=20;
    d3->data=30;
    d1->prev=NULL;
    d2->prev=d1;
    d3->prev=d2;
    d1->next=d2;
    d2->next=d3;
    d3->next=NULL;
    head=d1;
    displayDLL();
    printf("Insertion at Beginning: ");
    insertBeginningDLL(1);
    displayDLL();
    printf("Insertion at End: ");
    insertEndDLL(40);
    displayDLL();
    printf("Insertion at Position: ");
    insertAtPositionDLL(25,3);
    displayDLL();
    printf("Delete at Beginning: ");
    deleteBeginningDLL();
    displayDLL();
    printf("Delete at End: ");
    deleteEndDLL();
    displayDLL();
    printf("Delete at Position: ");
    deleteAtPositionDLL(3);
    displayDLL();
    searchDLL(40);
    return 0;
}