#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;
void insertBeginning(int data){
    struct Node* newNode=malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data=data;
    newNode->next=head;
    head=newNode;
}
void insertEnd(int data){
    struct Node* newNode=malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data=data;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
        return;
    }
    struct Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}
void insertAtPosition(int data, int position){
    if(position<1){
        printf("Invalid position\n");
        return;
    }
    if(position==1){
        insertBeginning(data);
        return;
    }
    if(head==NULL){
        printf("Empty");
        return;
    }
    struct Node* newNode=malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data=data;
    struct Node* temp=head;
    for(int i=1;i<position-1;i++){
        if(temp->next == NULL){
            printf("Position out of bounds\n");
            free(newNode);
            return;
        }
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
void deleteBeginning(){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    struct Node* temp=head;
    head=head->next;
    free(temp);
}
void deleteEnd(){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    if(head->next==NULL){
        free(head);
        head=NULL;
        return;
    }
    struct Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}
void deleteAtPosition(int position){
    if(position<1){
        printf("Invalid position\n");
        return;
    }
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    if(position==1){
        deleteBeginning();
        return;
    }
    struct Node* temp=head;
    for(int i=1;i<position-1;i++){
        if(temp==NULL||temp->next==NULL){
            printf("Position out of bounds\n");
            return;
        }
        temp=temp->next;
    }
    struct Node* nodeToDelete=temp->next;
    if(nodeToDelete==NULL){
        printf("Position out of bounds\n");
        return;
    }
    temp->next=nodeToDelete->next;
    free(nodeToDelete);
}
void display(){
    if(head==NULL){
        printf("Empty");
        return;
    }
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void search(int key){
    if(head==NULL){
        printf("Empty");
        return;
    }
    int pos = 1;
    struct Node *temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            printf("Found at position %d",pos);
            return;
        }
        temp=temp->next;
        pos++;
    }
    printf("Not Found");
}
void reverse(){
    struct Node *curr=head;
    struct Node *next=NULL;
    struct Node *prev=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}
int main(){
    struct Node *newNode1=malloc(sizeof(struct Node));
    struct Node *newNode2=malloc(sizeof(struct Node));
    struct Node *newNode3=malloc(sizeof(struct Node));
    newNode1->data=10;
    newNode2->data=20;
    newNode3->data=30;
    newNode1->next=newNode2;
    newNode2->next=newNode3;
    newNode3->next=NULL;
    head=newNode1;
    display();
    printf("Insertion at Beginning: ");
    insertBeginning(1);
    display();
    printf("Insertion at End: ");
    insertEnd(40);
    display();
    printf("Insertion at Position: ");
    insertAtPosition(25,3);
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