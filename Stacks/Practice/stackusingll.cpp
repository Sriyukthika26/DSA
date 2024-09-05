//Stack Implementation using Linkedlist
#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;
    node(int val){
        data = val;
        next=NULL;
    }
};

class stack_ll{
node* head;
int size;

public:
    stack_ll(){
        head=NULL;
        size = 0;
    }
    void push(int val){
        node* new_node = new node(val);
        new_node->next = this->head;
        head = new_node;
        size++;
    }
    int pop(){
        if(head==NULL){
            cout<<"stackUnderflow\n";
            return INT_MIN;
        }
        int x = head->data;
        node* temp = head;
        head = head->next;
        free(temp);
        size--;
        return x;
    }
    int gettop(){
        if(head==NULL){
            cout<<"Underflow"<<"\n";
            return INT_MIN;
        }
        return head->data;
    }

    bool isempty(){
        return this->head==NULL;
    }

    int stack_size(){
        return this->size;
    }


};

int main(){
stack_ll st;
st.push(5);
st.push(9);
st.push(8);
cout<<st.gettop()<<"\n";
cout<<st.pop()<<"\n";
cout<<st.pop()<<"\n";
cout<<st.gettop()<<"\n";
st.push(7);
st.push(6);
cout<<st.stack_size()<<"\n";
}

