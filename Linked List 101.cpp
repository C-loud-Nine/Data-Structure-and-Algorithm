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
    }
    else{
        node* temp =*head;
        while(temp->link!=NULL) temp=temp->link;
            temp->link=ptr;
    }
}

void firstinsertion(node** head,int x){
    node* ptr=new node();
    ptr->data=x;
    ptr->link=NULL;
    if(*head!=NULL) ptr->link=*head;
    *head=ptr;
}

void lastinsertion(node** head,int x){
    node* ptr=new node();
    ptr->data=x;
    ptr->link=NULL;
    node* temp=*head;
    while(temp->link!=NULL) temp=temp->link;
        temp->link=ptr;
}

void beforeinsert(node** head,int x,int target){
    node* ptr=new node();
    node* temp=*head;
    ptr->data=x;
    
    if(*head==NULL){
        ptr->link=NULL;
        *head=ptr;
    }
    else if(temp->data==target){
        ptr->link=*head;
        *head=ptr;
    }
    else{
        while(temp->link!=NULL && temp->link->data!=target){
            temp=temp->link;
        }
        
        if(temp->link!=NULL){
            ptr->link=temp->link;
            temp->link=ptr;
        }
        else{
            ptr->link=NULL;
            temp->link=ptr;
        }
    }
    
}

void afterinsert(node** head,int x,int target){
    node* ptr=new node();
    node* temp=*head;
    ptr->data=x;
    while(temp->link!=NULL && temp->data!=target){
        temp=temp->link;
    }
        if(temp->link!=NULL){
            ptr->link=temp->link;
            temp->link=ptr;

        }
        else{
            ptr->link=NULL;
            temp->link=ptr;
        }
    
}

void insertat(node** head,int x,int pos){
    node* ptr=new node();
    node* temp=*head;
    ptr->data=x;
    if(pos==1){
        ptr->link=*head;
        *head=ptr;
    }
    else{
        for(int i=0;i<pos-2;i++){
            temp=temp->link;
        }
        ptr->link=temp->link;
        temp->link=ptr;
    }
}

void firstdeletion(node** head){
    node* temp=*head;
    *head=(*head)->link;
    delete temp;
}

void lastdeletion(node** head){
    node* temp=*head;
    while(temp->link->link!=NULL){
        temp=temp->link;
    }
    delete temp->link;
    temp->link=NULL;
}

void givendeletion(node** head,int x){
    node* temp=*head;
    
    if((*head)->data==x){
        *head=(*head)->link;
        delete temp;
    }
    else{
    while(temp->link!=NULL && temp->link->data!=x){
        temp=temp->link;
    }
     if (temp->link != NULL) { 
        node* temp2 = temp->link;
        temp->link = temp2->link;
        delete temp2;
        }
    }

}

void given_before_deletion(node** head,int x){
    node* temp=*head;

    if(temp->link->data==x){
        *head=(*head)->link;
        delete temp;
    }
    else{
    while(temp->link!=NULL && temp->link->link!=NULL && temp->link->link->data!=x){
        temp=temp->link;
    }
    
        if (temp->link != NULL) { 
            node* temp2 = temp->link;
            temp->link = temp2->link;
            delete temp2;
        }
    }
}

void given_after_deletion(node** head,int x){
    node* temp=*head;
    
    if((*head)->data==x){
        temp=temp->link;
        (*head)->link=temp->link;
        delete temp;
    }
    else{
    while(temp->link!=NULL && temp->data!=x ){
        temp=temp->link;
    }

    if(temp->link!=NULL){
        node *temp2=temp->link;
        temp->link=temp2->link;
        delete temp2;
        }
    }

}

void delete_at_index(node** head,int pos){
    node* temp=*head;
    if(pos==1){
       node* temp=*head;
       *head=(*head)->link;
       delete temp; 
    }
    else{
        for(int i=0;i<pos-1;i++){
            temp=temp->link;
        }
        node* temp2=temp->link;
        temp->link=temp->link->link;
        delete temp2;
    }
}

void reverse(node** head) {
    node* prev = NULL;
    node* current = *head;
    node* next = NULL;
    while (current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void sort(node** head){
    node *i,*j;
    int temp;
    for(i=*head;i!=NULL;i=i->link){
        for(j=i->link;j!=NULL;j=j->link){
            if(i->data>j->data){
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }
}
void merge(node** head,node** head1){
    node* temp=*head;
    node* temp1=*head1;
    while(temp->link!=NULL){
        temp=temp->link;
    }
    temp->link=temp1;
}

void alternate_merge(node** head, node* head1) {
    if (*head== NULL) {
        *head = head1;
        return;
    }
    if (head1 == NULL) {
        return;
    }
    node* curr1 = *head;
    node* curr2 = head1;
    while (curr1 != NULL && curr2 != NULL) {
        node* temp = curr2;
        curr2 = curr2->link;
        temp->link = curr1->link;
        curr1->link = temp;
        curr1 = temp->link;
    }
    if (curr2 != NULL) {
        curr1->link = curr2;
    }
}
void insert_sorted(node** head, int data) {
    node* new_node = new node();
    new_node->data = data;
    new_node->link = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    if (data < (*head)->data) {
        new_node->link = *head;
        *head = new_node;
        return;
    }

    node* curr_node = *head;
    while (curr_node->link != NULL && curr_node->link->data < data) {
        curr_node = curr_node->link;
    }

    new_node->link = curr_node->link;
    curr_node->link = new_node;
}


void remove_duplicates(node* head) {
    if (head == NULL) {
        return;
    }
    node* curr = head;
    while (curr != NULL) {
        node* temp = curr;
        while (temp->link != NULL) {
            if (temp->link->data == curr->data) {
                node* duplicate = temp->link;
                temp->link = duplicate->link;
                delete duplicate;
            } 
            else {
                temp = temp->link;
            }
        }
        curr = curr->link;
    }
}
void print(node** head)
{
    node*ptr=*head;
    while(ptr!=NULL)
    {
    cout<<ptr->data<<" ";
    ptr=ptr->link;
    }
    cout<<endl;
}

void merge_sorted_lists(node** head1_ptr, node** head2_ptr) {
    if (*head1_ptr == NULL) {
        *head1_ptr = *head2_ptr;
        return;
    }
    if (*head2_ptr == NULL) {
        return;
    }

    node** curr_node_ptr = head1_ptr;
    while (*curr_node_ptr != NULL && *head2_ptr != NULL) {
        if ((*head2_ptr)->data <= (*curr_node_ptr)->data) {
            node* temp = *head2_ptr;
            *head2_ptr = (*head2_ptr)->link;
            temp->link = *curr_node_ptr;
            *curr_node_ptr = temp;
        }
        curr_node_ptr = &((*curr_node_ptr)->link);
    }

    if (*head2_ptr != NULL) {
        *curr_node_ptr = *head2_ptr;
    }
}




int main(){
    int n,y;
    node* head=NULL;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>y;
        creation(&head,y);
    }
    
    // node* head1=NULL;
    // for(int i=0;i<n;i++){
    //     cin>>y;
    //     creation(&head1,y);
    // }
    
    //firstinsertion(&head,70);
    //lastinsertion(&head,99);
    //beforeinsert(&head,500,1);
    //afterinsert(&head,1000,5);
    //firstdeletion(&head);
    //lastdeletion(&head);
    //given_before_deletion(&head,2);
    //given_after_deletion(&head,1);
    //insertat(&head,30,6);
    //delete_at_index(&head,3);
    //reverse(&head1);
    //merge(&head,&head1);
    //sort(&head);
    //alternate_merge(&head,head1);
    //remove_duplicates(head);
    //insert_sorted(&head,4);
    //merge_sorted_lists(&head,&head1);


    print(&head);
}