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
};
int main(){
    node* new_node = new node(1);
    DLL dll;
    dll.head=new_node;
    dll.tail = new_node;
}