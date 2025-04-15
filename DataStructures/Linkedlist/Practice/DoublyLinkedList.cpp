//Doubly Linked list Implementation

#include <bits/stdc++.h>
using namespace std;

class node{
public:
    node*prev;
    int data;
    node* next;

    node(int val){
        prev = NULL;
        next=NULL;
        data = val;
    }
};

class DLL{
public:
    node*head;
    node*tail;
    DLL(){
        head=NULL;
        tail=NULL;
    }

    void insertathead(int val){
        node *new_node = new node(val);
        if(!head){
            head = tail = new_node;
            return;
        }
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }

    void insertatlast(int val){
        node * new_node = new node(val);
        if(!head){
            head = tail = new_node;
            return;
        }
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }

    void insertatk(int val, int k){
        node* temp = head;
        node* new_node = new node(val);
        k=k-2;
        while(k--){
            temp = temp->next;
        }
        new_node->next = temp->next;
        new_node->prev = temp;
        temp->next->prev = new_node;
        temp->next = new_node;

    }

    void display(){
        node * temp = head;
        while(temp!= NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"\n";
    }

    void deleteathead(){
        if(!head) return;

        node* temp = head;
        head = temp->next;
        if(!head){
            tail = NULL;
            return;
        }
        else head->prev = NULL;
        
        free(temp);
    }

    void deleteatlast(){
        if(!head) return;
        node * temp = tail;
        tail = tail->prev;
        if(!tail){
            tail = head = NULL;
        }
        else{
            tail->next = NULL;
        }
        free(temp);
    }

    void deleteatk(int k){
        k--;
        if(k==0){
            deleteathead();
            return;
        }
        node * temp = head;
        while(k--){
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }

};


//reverse doublyLL
void reverseLL(node* &head){
    node* curr = head;
    while(curr->next!=NULL){
        node* temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;    
        curr = temp;
    }
    curr->next = curr->prev;
    curr->prev = NULL;
    head = curr;

}

bool checkPalindrome(node* head, node*tail){
    while(head!= tail && tail != head->prev){
        if(head->data != tail->data){
            return false;
        }
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

//del if prev and next neighbours have same value
void delSameNeighNode(node* &head){
    node* curr = head->next;
    while(curr->next!=NULL){
        node* prev_node = curr->prev;
        node* next_node = curr->next;
        if(prev_node->data==next_node->data){
            prev_node->next = next_node;
            next_node->prev = prev_node;
            free(curr);
        }
        curr = next_node;
    }
}


int main(){
    node* new_node = new node(1);
    DLL dll;
    dll.insertatlast(1);
    dll.insertatlast(2);
    dll.insertatlast(3);
    dll.insertatlast(2);
    dll.insertatlast(1);
    dll.display();
    dll.insertatk(2,4);
    dll.display();
    // dll.deleteathead();
    // dll.display();
    // dll.deleteatk(3);
    // dll.display();
    // reverseLL(dll.head);
    // dll.display();
    // cout<<checkPalindrome(dll.head, dll.tail)<<"\n";
    delSameNeighNode(dll.head);
    dll.display();

}