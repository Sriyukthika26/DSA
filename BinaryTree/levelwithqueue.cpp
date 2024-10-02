#include<bits/stdc++.h>
using namespace std;
class TreeNode{
public:
    int key;
    TreeNode *left,*right;
    TreeNode(int m){
        key = m;
        left = right = NULL;
    }
};

class queNode{
public:
    queNode* next;
    TreeNode* ptr;
    queNode(TreeNode* random){
        ptr = random;
        next = NULL;
    }
};

class Queues{
public:
    queNode* front; queNode* rear;

    Queues(){
        front = rear = NULL;
    }

    void enqueue(TreeNode* r){
        queNode* new_node = new queNode(r);
        if(front==NULL){
            front = rear = new_node;
            return;
        }
        rear->next = new_node;
        rear = rear->next;
    }

    TreeNode* dequeue(){
        if(front==NULL) return NULL;
        queNode* temp = front;
        front = front->next;
        TreeNode* x = temp->ptr;
        free(temp);
        return x;
    }
    
    bool isempty(){
        return front==NULL;
    }

};

void levelorder(TreeNode* root){
    Queues q;
    q.enqueue(root);
    while(!q.isempty()){
        TreeNode* cNode = q.dequeue();
        cout<<cNode->key<<" ";
        if(cNode->left) q.enqueue(cNode->left);
        if(cNode->right) q.enqueue(cNode->right);
    }
}

int main(){
    
}