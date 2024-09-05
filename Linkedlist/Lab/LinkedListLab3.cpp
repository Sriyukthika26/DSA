#include<bits/stdc++.h>
using namespace std;
class node{
public:
	node*prev;
	int data;
	node*next;
	node(int val){
		data = val;
		prev=NULL;
		next = NULL;		
	}
};
int num_elem(node*head){
	int k=1;
	node*temp = head;
	while(temp!=NULL){
		temp=temp->next;
		k++;
	}
	return k;
}
void insertatlast(node*&head,int val){
	node * new_node = new node(val);
	if(head==NULL){
		head=new_node;
		return;
	}
	node*temp = head;
	while(temp->next!= NULL){
		temp=temp->next;
	}
	new_node->prev = temp;
	temp->next = new_node;
	new_node->next=NULL;
}
void insert(node*&head,int j,int val){
	int k= num_elem(head);
	if(j>=k){
		insertatlast(head,val);
		return;
	}
	node*new_node = new node(val);
	if(j==0){
		new_node->next = head;
		head->prev=new_node;
		new_node=NULL;
		head=new_node;
		return;
	}
	node*temp = head;
	int pos=0;
	while(pos<j-1){
		temp=temp->next;
		pos++;
	}
	new_node->next = temp->next;
	new_node->prev = temp;
	temp->next->prev=new_node;
	temp->next=new_node;	
}

void del_elem(node*&head,int j){
	if(head==NULL){
		return;
	}
	int k = num_elem(head);
	if(j>=k){
		cout<<"ERROR!"<<"\n";
		return;
	}
	node*temp = head;
	if(j==0){
		head = head->next;
		head->prev=NULL;
		free(temp);
		return;
	}
	int pos=0;
	while(pos<j-1){
		temp=temp->next;
		pos++;
	}
	node*per = temp->next;
	temp->next= per->next;
	per->next->prev= temp;
	free(per);
}
void deleteX(node*&head,int x){
	if(head==NULL){
		return;
	}
	node * temp = head;
	node* del=NULL;
	while(temp!=NULL){
		if(temp->data=x) del = temp;
	}
	if(del==NULL){
		cout<<"ERROR!"<<"\n";
		return;
	}
	if(del->next==NULL && del->prev==NULL){
		free(del);
		return;
	}
	if(del->next==NULL){
		del->prev->next=NULL;
		free(del);
		return;
	}
	del->prev->next=del->next;
	del->next->prev=del->prev;
	free(del);
}
void getelemprev(node*&head,int j,int x){
	node * temp = head;
	node* del=NULL;
	while(temp!=NULL){
		if(temp->data=x) del = temp;
	}
	if(del==NULL){
		cout<<"ERROR!";
		return;
	}
	while(del!=NULL&&j--){
		del = del->prev;
	}
	if(del==NULL) cout<<head->data;
	else cout<<del->data;
}
void getelemnext(node*&head,int j,int x){
	node * temp = head;
	while(temp!=NULL&&temp->data!=x){
		temp=temp->next;
	}
	if(temp==NULL){
		cout<<"ERROR!";
		return;
	}
	while(temp!=NULL&&j--){
		temp = temp->next;
	}
	if(temp==NULL){
		node *per = head;
		while(per->next!=NULL){
			per = per->next;
		}
		cout<<per->data;
	}
	cout<<temp->data;
}
void display(node *head){
	node *temp = head;
	while(temp!=NULL){
		cout<<temp->data<<"<->";
		temp=temp->next;
	}
	cout<<"\n";
}

int main(){
	int n;
	cin>>n;
}
