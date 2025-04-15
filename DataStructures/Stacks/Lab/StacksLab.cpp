#include<bits/stdc++.h>
using namespace std;

int n;

class node{
public:
	int* arr;
	node*next;
	node(int n){
		next=NULL;
		arr = new int[n];
	}	
};

class Stacks{
	node*head;
	int top;
public:
	Stacks(int n){
		node* new_node = new node(n);
		top=-1;
		head=new_node;
	}
	void expand_push(int value){
		if(top==n-1){
			node* new_node = new node(n);
			new_node->next=head;
			top=-1;
			head=new_node;	
		}
		top++;
		head->arr[top]=value;	
	}
	
	node* linked_top(){
		return head;
	}
	
	int Stacks_top(){
		return top;
	}
	
	int shrink_pop(){
		if(linked_top()==NULL){
			cout<<"StacksUnderflow"<<"\n";
			return -1;
		}
		else if(top==-1){
			head = head->next;
			if(head!=NULL) top = n-1;
		}
		int x = head->arr[top];
		top--;
		return x;	
	}
	int elements(){
		node*temp = head;
		int ct=1;
		while(temp!=NULL){
			temp = temp->next;
			ct++;
		}
		int num = top+1;
		return num+(ct-1)*n;
	}
	
	void print_Stacks(){
		node* temp = head;
		while(temp!=NULL){
			if(top==-1){
				temp = temp->next;
				top = n-1;
				cout<<"\n";
			}
			cout<<temp->arr[top]<<" ";
			top--;
			
		}
	}
	
};
int main(){
	cin>>n;
	
	Stacks st(n);
	st.expand_push(5);
	st.expand_push(6);
	st.expand_push(8);
	st.expand_push(7);
	st.expand_push(5);
	st.expand_push(6);
	st.expand_push(8);
	st.expand_push(7);
	st.expand_push(5);
	st.expand_push(6);
	st.expand_push(8);
	cout<<st.shrink_pop();
	st.print_Stacks();
	
	return 0;
}
