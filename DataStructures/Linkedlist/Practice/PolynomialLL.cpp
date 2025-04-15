//Polynomial Storing in Linkedlist

#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int coeff;
    int expo;
    node * next;

    node(int coefficient , int exponent){
        coeff = coefficient;
        expo = exponent;
        next = NULL;
    }
};

class Poly_LL{
public:
    node* head;
    Poly_LL(){
        head = NULL;
    }
//inserts exponents in descending order, if new expo = existing expo they get simplified eq: 2x^3 + 5x^3 = 8x^3
    void insert(int coefficient , int exponent){
        node *new_node = new node(coefficient , exponent);
        if(head==NULL|| exponent>=head->expo){
            if(head!=NULL && exponent == head->expo){
                head->coeff = head->coeff + coefficient;
                return;
            }
            new_node ->next = head;
            head = new_node;
            return;
        }
        node* temp = head;
        while(temp->next!=NULL && temp->next->expo>=exponent){
            temp = temp->next;
        }
        if(temp->expo == exponent){
            temp->coeff = temp->coeff + coefficient;
            return;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }

    void display(){
        node*temp = head;
        while(temp!=NULL){
            cout<<temp->coeff<<"x^"<<temp->expo;
            if(temp->next!=NULL) cout<<"+";
            temp = temp->next;
        }
        cout<<"\n";
    }

};

//Add two polynomials
void Add_poly(node* head1, node* head2){
    Poly_LL ll3;
    node * temp1 = head1; node*temp2 = head2;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->expo == temp2->expo){
            ll3.insert(temp1->coeff+temp2->coeff, temp1->expo);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if(temp1->expo > temp2->expo){
            ll3.insert(temp1->coeff, temp1->expo);
            temp1 = temp1->next;
        }
        if(temp2->expo > temp1->expo){
            ll3.insert(temp2->coeff, temp2->expo);
            temp2 = temp2->next;
        }
    }
    node * temp = ll3.head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    if(temp1 == NULL && temp2 != NULL){
        temp ->next = temp2;
    }
    else if(temp2 == NULL && temp1 != NULL){
        temp->next = temp1;
    }

    ll3.display();
    
}

//Multiply 2 polynomials
void Mul_poly(node*head1, node*head2){
    Poly_LL ll4;
    node* temp1 =head1; node* temp2 = head2;
    while(temp1!=NULL){
        while(temp2!=NULL){
            ll4.insert(temp1->coeff*temp2->coeff, temp1->expo+temp2->expo);
            temp2 = temp2->next;
        }
        temp2 = head2;
        temp1=temp1->next;
    }

    ll4.display();
}

int main(){
Poly_LL ll;
ll.insert(5,1);
ll.insert(3,2);
ll.insert(6,5);
ll.display();

Poly_LL ll2;
ll2.insert(3,4);
ll2.insert(6,7);
ll2.insert(2,3);
ll2.display();

Add_poly(ll.head,ll2.head);

Mul_poly(ll.head,ll2.head);


}