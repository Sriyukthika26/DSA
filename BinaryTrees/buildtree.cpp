#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int key;
	node* left;
	node* right;
	node(int m){
		key = m;
		left = right = NULL;
	}
};


node* prein(int pre[], int ino[], int l, int h){
    if(l>h) return NULL;
    static int p= 0;
    int k = pre[p++];
    node* root = new node(k);
    if(l==h) return root;
    int index=-1;
    for(int i=0;i<=h;i++){
        if(k==ino[i]){
            index = i;
            break;
        }
    }
    root->left = prein(pre, ino, l,index-1);
    root->right = prein(pre, ino, index+1,h);

    return root;
}

node* postin(int pos[], int ino[], int l, int h){
    if(l>h) return NULL;
    static int p = h;
    int k = pos[p--];
    node* root = new node(k);
    if(l==h) return root;
    int idx=-1;
    for(int i=0;i<=h;i++){
        if(k==ino[i]){
            idx = i;
            break;
        }
    }
    
    root->right = postin(pos, ino, idx+1,h);
    root->left = postin(pos, ino, l, idx-1);
    return root;
}

class queNode{
public:
	node* ptr;
	queNode* next;
	
	queNode(node* random){
		ptr = random; next = NULL;
	}
};

class queues{
public:
	queNode* front; queNode* rear; 
	int size;
	queues(){
		front = rear=NULL;
		size=0;
	}
	
	void enqueue(node* random){
		queNode* temp=new queNode(random);
		if(front == NULL){
			front = rear=temp;
			size++;
			return;
		}
		rear->next = temp;
		rear= temp;
		size++;
	}
	
	void dequeue(){
		if(front == NULL){
			return ;
		}
		queNode* temp=front;
		front = front->next;
		free(temp);
		size--;
	}
	
	bool isempty(){
		return (front==NULL);	
	}
	
	int getSize(){
		return size;
	}
	
	node* getFront(){
		if (front==NULL){
			return NULL;
		}
		return front->ptr;
	}
};

void levelorder(node* root){
	if(root==NULL) return ;
	queues q;
	q.enqueue(root);
	while(!q.isempty()){

		node* cNode = q.getFront();
		q.dequeue();
		cout<<cNode->key<<" ";
		if(cNode->left)	q.enqueue(cNode->left);
		if(cNode->right)	q.enqueue(cNode->right);

	}
}

int main(){
	int postorder[] = {3,6,7,4,2,5,1};
	int inoder[] = {3,2,6,4,7,1,5};
    int preorder[]={1,2,3,4,6,7,5};
	node* root1 = prein(preorder, inoder, 0, 6);
    node* root = postin(postorder, inoder, 0, 6);
	levelorder(root);
    cout<<"\n";
    levelorder(root1);
	
	
}
