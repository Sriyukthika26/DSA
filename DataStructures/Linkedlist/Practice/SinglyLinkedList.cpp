//Singly linkedlist implementation and some problems

#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }

};
class LinkedList{
public:
    node*head;
    LinkedList(){
        head=NULL;
    }
    void inserAtLast(int val){
        node *new_node = new node(val);
        if(head==NULL){
            head= new_node;
            return;
        }
        node*temp = head;
        while(temp->next!=NULL){
            temp= temp->next;
        }
        temp->next = new_node;

    }
    void display(){
    node*temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
    }
};


void insertAtHead(node* &head, int val){
    node *temp = new node(val);
    temp->next = head;
    head=temp;
}


void insertAtk(node*&head,int k,int val){
    node*new_node = new node(val);
    node*temp=head;
    int pos=0;
    while(pos!=k-1){
        temp = temp->next;
        pos++;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void updatek(node*&head,int k,int val){
    node*temp=head;
    int pos=0;
    while(pos!=k){
        temp = temp->next;
        pos++;
    }
    temp->data=val;     
}


void deleteAthead(node* &head){
    node*temp = head;
    head = head->next;
    free(temp);
}
void deleteAtlast(node* &head){
    node*temp = head;
    while(temp->next->next != NULL){
        temp=temp->next;
    }
    node*per = temp->next;
    temp->next = NULL;
    free(per);   
}
void deleteAtK(node*&head,int k){

    if(k==0){
        deleteAthead(head);
        return;
    }
    node*temp = head;
    int pos =0;
    while(pos!=k-1){
        temp=temp->next;
        pos++;
    }
    node*per = temp->next;
    temp->next= temp->next->next;
    free(per);
}

// delete alternate elements of list
void del_alt(node* &head) {
    node* temp = head;
    while(temp->next!=NULL) {
        node* dele = temp->next;
        temp->next = dele->next;
        free(dele);
        if(temp->next!=NULL)
        temp = temp->next;
    }
}

// delete duplicate elements in list
void del_dupli(node *&head){
    node *temp = head;
    while(temp->next!=NULL){
        int prev= temp->data;
        node* re = temp->next;
        if(prev==re->data){
            temp->next = re->next;
            free(re);
        }
        if(temp->next!=NULL)
        temp=temp->next; 
    }
}

int main(){
    LinkedList ll;
    ll.inserAtLast(1);
    ll.inserAtLast(2);
    ll.inserAtLast(3);
    ll.inserAtLast(4);
    ll.display(); 

}

