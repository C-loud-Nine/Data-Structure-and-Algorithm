#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* link;
};

void creation(node** head,int x){
    node* ptr=new node();
    
    ptr->data=x;
    ptr->link=NULL;
    if(*head==NULL){
        *head=ptr;
        (*head)->link=*head;
    }
    else{
        node* temp =*head;
        while(temp->link!=*head) temp=temp->link;
            temp->link=ptr;
            ptr->link=*head;
            *head=ptr;
    }
}

void insertbegin(node** head,int x){
    node* ptr=new node();
    ptr->data=x;
    ptr->link=NULL;
    if(*head==NULL){
        *head=ptr;
        (*head)->link=*head;
    }
    else{
    node* temp=*head;
    while(temp->link!=*head){
        temp=temp->link;
    }
    temp->link=ptr;
    ptr->link=*head;
    *head=ptr;
    }
}

void insertend(node** head,int x){
    node* ptr=new node();
    ptr->data=x;
    ptr->link=NULL;
    
    if(*head==NULL){
        *head=ptr;
        (*head)->link=*head;
    }
    else{
    node* temp=*head;
    while(temp->link!=*head){
        temp=temp->link;
    }
    temp->link=ptr;
    ptr->link=*head;
    }
}

void deletebegin(node** head){
    if(*head==NULL){
        cout<<"EMPTY"<<endl;
    }
    else if((*head)->link==*head){
        delete *head;
        *head=NULL;
    }
    else{
        node* temp=*head;
        while(temp->link!=*head){
            temp=temp->link;
        }
        temp->link=(*head)->link;
        node* todel=*head;
        *head=(*head)->link;
        delete todel;

    }
}

void delend(node** head){
    if(*head==NULL){
        cout<<"EMPTY"<<endl;
    }
    else if((*head)->link==*head){
        delete *head;
        (*head)=NULL;
    }
    else{
        node* temp=*head;
        while(temp->link->link != *head){
            temp=temp->link;
        }
        node* todel=temp->link;
        temp->link=*head;
        delete todel;
    }
}

void print(node** head)
{
    node*ptr=*head;
    
    do{
    cout<<ptr->data<<" ";
    ptr=ptr->link;
    }while(ptr!=*head);
    
    cout<<endl;
}


int main(){
    int n,y;
    node* head=NULL;
    
    creation(&head,90);
    insertbegin(&head,1);
    insertbegin(&head,2);
    insertbegin(&head,3);
    insertbegin(&head,4);
    insertend(&head,6);
    insertend(&head,7);
    insertend(&head,8);
    insertend(&head,9);
    deletebegin(&head);
    delend(&head);
    print(&head);
    
}