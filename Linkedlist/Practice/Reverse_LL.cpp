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

};

//printing elements in list
void disp(node*head){
    node*temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
};


// display element at required position
void displayatpos(node*head,int pos){
    node *temp = head;
    while(pos--){
        temp=temp->next;
    }
    cout<<temp->data;
}


// Printing the elements in reverse order of a list 
void reverse_ll_print(node* head){     
    node *temp = head;
    int n=0;
    while(temp!=NULL){
        temp=temp->next;            //not so efficient method
        n++;
    }
    for(int i=n-1;i>=0;i--){
        displayatpos(head,i);
        cout<<" ";
    }
}

// using Recursion
void rev_ll_print_eff(node*head){    //a better method
    if(head==NULL) return;
    rev_ll_print_eff(head->next);
    cout<<head->data<<" ";
}

//reversing the list
void rev_ll(node*&head){
    node*prev=NULL;
    node*curr = head;
    
    while(curr->next!=NULL){
        node*temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = curr;
}

int main(){
    LinkedList ll;
    ll.inserAtLast(1);
    ll.inserAtLast(2);
    ll.inserAtLast(3);
    ll.inserAtLast(4);
    disp(ll.head);
    rev_ll(ll.head);
    disp(ll.head);

}