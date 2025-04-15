#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int val){
        data =val;
        next= NULL;
    }
};

class CircularLL{
public:
    node* head;

    CircularLL(){
        head = NULL;
    }

    void insertathead(int val){
        node * new_node = new node(val);
        if(!head){
            head = new_node;
            new_node->next = head;
            return;
        }
        node* tail = head;
        while(tail->next!= head){
            tail = tail->next;
        }
        tail->next = new_node;
        new_node->next= head;
        head = new_node;    
    }

    void insertattail(int val){
        node* new_node = new node(val);
        if(!head){
            head = new_node;
            new_node->next = head;
            return;
        }
        node* temp = head->next;
        while(temp->next!= head){
            temp = temp->next;
        }
        
        temp-> next = new_node;
        new_node->next = head;
    }

    void delatstart(){
        if(!head){
            return;
        }
        node* del = head;
        node* temp = head-> next;
        while(temp->next != head){
            temp = temp->next;
        }
        head = head-> next;
        temp->next= head;
        free(del);
    }

    void delatend(){
        if(!head) return;
        node* temp = head->next;
        while(temp->next->next!= head){
            temp= temp->next;
        }
        node* del = temp->next;
        temp->next = head;
        free(del);

    }

    void display(){
        node * temp = head;
        do{
        cout<<temp->data<<" ";
        temp = temp->next;
        }while(temp!= head);
        cout<<"\n";
    }

};

int main(){

    CircularLL cll;
    cll.insertathead(9);
    cll.insertathead(8);
    cll.insertathead(4);
    cll.display();

}