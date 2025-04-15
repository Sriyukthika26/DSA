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

    void insertAtHead(int val){
    node *temp = new node(val);
    temp->next = head;
    head=temp;
    }

    void store(long long val){
        while(val!=0){
            int r = val%10;
            val =  val/10;
            insertAtHead(r); 
        }
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

void reverse_ll(node* &head){
    node * prev = NULL;
    node * current = head;
    while(current!= NULL){
        node * temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    head = prev;
}

void ADD(node*head1, node*head2){
    LinkedList ll3;
    int carry =0;
    node * temp1 = head1; node* temp2 = head2;
    while (temp1 != NULL && temp2 != NULL)
    {
        int addsum = (temp1->data+temp2->data+carry);
        carry = addsum/10;
        ll3.insertAtHead(addsum%10);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if(temp1==NULL){
        while (temp2 != NULL){
        int addsum = (temp2->data+carry);
        carry = addsum/10;
        ll3.insertAtHead(addsum%10);
        temp2 = temp2->next;
        }
        if(carry)
        ll3.insertAtHead(carry);
    }
    else if(temp2==NULL){
        while (temp1 != NULL){
        int addsum = (temp1->data+carry);
        carry = addsum/10;
        ll3.insertAtHead(addsum%10);
        temp1 = temp1->next;
        }
        if(carry)
        ll3.insertAtHead(carry);
    }
    
    ll3.display();
}

int main(){
    LinkedList ll1,ll2;
    ll1.store(8999999999999999999);
    ll2.store(8999999999999999999);
    ll1.display();
    ll2.display();
    reverse_ll(ll1.head);
    reverse_ll(ll2.head);
    ll1.display();
    ll2.display();
    ADD(ll1.head, ll2.head);
}




