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
	node * head;	
	LinkedList(){
		head=NULL;
	}
	
	void insertattail(int val){
		node* new_node = new node(val);
		if(head==NULL){
			head = new_node;
			return;
		}
		node* temp = head;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = new_node;
	}
	
};

	void display(node* head){
		node*temp = head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<"\n";
	}

class Hashtable{
public:
	int n;
	vector<node*>a;
	Hashtable(node* &head){
		n = 10;
		a.resize(n);
		for(int i=0;i<n;i++){
			node* new_node = new node(-1);
			a[i] = new_node;
		}
		int h = (head->data)%n;
		node* new_node = new node(head->data);
		a[h] = new_node;
		node* temp = head;
		while(temp->next!= NULL){
			int h = (temp->next->data)%n;
			node* new_node = new node(temp->next->data);
			if(a[h]->data==-1){
				a[h]= new_node;
				temp = temp->next;
			}
			else{
				node*t = a[h];
				bool flag = false;
				while(t->next!=NULL){
					if(temp->next->data == t->data){
						flag = true;
						node* per = temp->next;
						temp->next = temp->next->next;
						free(per);
						break;
					}
					t = t->next;
				}
				if(!flag && temp->next->data != t->data){
					t->next = new_node;
					temp = temp->next;
				}
				else if(!flag){
					node* per = temp->next;
					temp->next = temp->next->next;
					free(per);
				}
			}

		}

	}
	
};


node* RevKnodes(node* head, int k,int n){
	if(n<k){
		return head;
	}

	node* prev = NULL;
	node* curr = head;
	int t=k;				//3->6->4->5->6->3->2->1
	while(t--&& curr!= NULL){
		node* temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	if(curr!=NULL){
	n = n-k;
	node* new_head = RevKnodes(curr,k,n);
	head->next = new_head;
	}
	return prev;
	
		
}

int main(){
	LinkedList ll;
	int n;
	int k;
	cin>>n>>k;
	int t =n;
	while(t--){
		int x;
		cin>>x;
		ll.insertattail(x);
	}
	
	// node* ans = RevKnodes(ll.head,k,n);
	// display(ans);
	Hashtable ht(ll.head);
	display(ll.head);
	
	
	
}
