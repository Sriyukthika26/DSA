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

class queue_ll{
node*front;
int size;
node*rear;
public:
    queue_ll(){
        front = NULL;
        size=0;
        rear = NULL;
    }
    void enqueue(int val){
        node * new_node = new node(val);
        if(front==NULL){
            front = new_node;
            rear = new_node;
        }
        else{
            rear->next = new_node;
            rear = new_node;
        }
        size++;
    }

    int dequeque(){
        if(front == NULL){
            cout<<"Stack Underflow";
            return INT_MIN;
        }
        int x = front->data;
        node*temp = front;
        front = front->next;
        if(front ==NULL) rear = NULL;
        free(temp);
        size--;
        return x;
    }

    bool isempty(){
        return front == NULL;
    }
    int get_size(){
        return size;
    }

    void print_q(){
        if(front == NULL) return;
        node* temp = front;
        while(temp!=rear){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<temp->data;
    }

    int get_front(){
        if(front==NULL) return INT_MIN;
        return front->data;
    }

}; 
int main(){
    queue_ll q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeque();
    q.enqueue(40);
    q.print_q();

}