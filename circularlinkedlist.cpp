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

bool isEmpty(node* head) {
    return head == NULL;
}

int length(node* head) {
    if (head == NULL) {
        return 0;
    }
    int count = 0;
    node* current = head;
    do {
        count++;
        current = current->link;
    } while (current != head);
    return count;
}

void insertAfter(node* head, int position, int data) {
    int len = length(head);
    if (position < 1 || position > len + 1) {
        cout << "Invalid position!" << endl;
        return;
    }

    node* newNode = new node();
    newNode->data = data;

    if (position == 1) {
        newNode->link = head->link;
        head->link = newNode;
    } else {
        node* current = head;
        for (int i = 1; i < position; i++) {
            current = current->link;
        }
        newNode->link = current->link;
        current->link = newNode;
    }
}

void deleteAtPosition(node** head, int position) {
    int len = length(*head);
    if (position < 1 || position > len) {
        cout << "Invalid position!" << endl;
        return;
    }

    if (position == 1) {
        node* last = *head;
        while (last->link != *head) {
            last = last->link;
        }
        node* temp = *head;
        *head = (*head)->link;
        last->link = *head;
        delete temp;
    } else {
        node* current = *head;
        for (int i = 1; i < position - 1; i++) {
            current = current->link;
        }
        node* temp = current->link;
        current->link = temp->link;
        delete temp;
    }
}

void reverseList(node** head) {
    if (*head == NULL) {
        return;
    }

    node* prev = NULL;
    node* current = *head;
    node* next = NULL;

    do {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    } while (current != *head);

    (*head)->link = prev;
    *head = prev;
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
