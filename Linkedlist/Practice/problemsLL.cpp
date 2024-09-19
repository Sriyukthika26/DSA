#include<bits/stdc++.h>
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
    node* head;

    LinkedList(){
        head= NULL;
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

//check if 2 linkedlists are equal or not
bool checkLL(node* head1, node* head2){
    node* t1 = head1;
    node* t2 = head2;
    while(t1!=NULL && t2!= NULL){
        if(t1->data != t2->data){
            return false;
        }
        t1 = t1->next;
        t2 = t2->next;
    }
    return (t1==NULL && t2 == NULL);
}

//return the node at which 2 linkedlists intersect

int main(){

}