#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k){
        key = k;
        left = NULL; right=NULL;
        height = 1;
    }
};

int height(Node *N){
    if(N==NULL) return 0;
    return N->height;
}

Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;

    y->height = 1+max(height(y->left), height(y->right));
    x->height = 1+ max(height(x->left), height(x->right));

    return x;
}

Node* leftRotate(Node* y){
    Node* x = y->right;
    Node* T2 = x->left;
    x->left = y;
    y->right = T2;

    y->height = 1+ max(height(y->left), height(y->right));
    x->height = 1+ max(height(x->left), height(x->right));

    return x;
}

int getBalance(Node* N){
    if(N==NULL) return 0;
    return height(N->right)- height(N->left);
}

Node* Insert(Node* N,int val){
    if(N == NULL) return new Node(val);
    if(N->key > val) N->left = Insert(N->left,val);
    else if(N->key<val) N->right = Insert(N->right, val);

    N->height = 1+max(height(N->left), height(N->right));

    int balance = getBalance(N);

    if(balance>1 && val> N->right->key){
        return leftRotate(N);
    }

    if(balance<-1 && val<N->left->key){
        return rightRotate(N);
    }

    if(balance<-1 && val>N->left->key){
        N->left = leftRotate(N->left);
        return rightRotate(N);
    }

    if(balance>1 && val<N->right->key){
        N->right= rightRotate(N->right);
        return leftRotate(N);
    }

    return N;
}
Node * getsuccesor(Node* node) {
    Node* current = node->right;
    while (current->left != NULL)
        current = current->left;

    return current;
}

Node* Delete(Node* N, int val){
    if(N ==NULL) return N;
    if(val< N->key) N->left = Delete(N->left, val);
    else if(val>N->key) N->right = Delete(N->right, val);
    else{

        if(N->left==NULL|| N->right==NULL){
            Node* temp=NULL;
            if(N->left) temp = N->left;
            else temp = N->right;
            if(temp==NULL){
                temp = N;
                N=NULL;
            }
            else{
                N->key = temp->key;
            }
            free(temp);
        }
       else {
            Node* temp = getsuccesor(N);
            N->key = temp->key;
            N->right = Delete(N->right, temp->key);
        }
    }

    if(N==NULL) return NULL;

    N->height = 1 + max(height(N->left), 
                   height(N->right));

    int balance = getBalance(N);
    if (balance > 1 && getBalance(N->left) >= 0)
        return rightRotate(N);

    if (balance > 1 && getBalance(N->left) < 0) {
        N->left = leftRotate(N->left);
        return rightRotate(N);
    }

    if (balance < -1 && getBalance(N->right) <= 0)
        return leftRotate(N);

    if (balance < -1 && getBalance(N->right) > 0) {
        N->right = rightRotate(N->right);
        return leftRotate(N);
    }

    return N;
}


void inorder(Node* root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

int main(){
    Node* root = NULL;
    root = Insert(root, 10); 
    root = Insert(root, 20); 
    root = Insert(root, 30); 
    root = Insert(root, 40); 
    root = Insert(root, 50); 
    root = Insert(root, 25);

    cout << "Inorder traversal : \n"; 
    inorder(root); 
}   
