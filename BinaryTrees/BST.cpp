#include<bits/stdc++.h>
using namespace std;

class treenode{
public:
    int data;
    treenode* left; treenode* right;
    treenode(int val){
        data = val; left = right = NULL;
    }
};

treenode* insert(treenode* root,int key){
    treenode* new_node = new treenode(key);
    if(root==NULL) return new_node;
    if(key< root->data) root->left = insert(root->left, key);
    else if(key>root->data) root->right = insert(root->right, key);
    return root;
}

void insert1(treenode* &root, int key){
    treenode* new_node = new treenode(key);
    if(root==NULL){
        root = new_node;
        return;
    }
    treenode* temp = root;
    treenode* prev = NULL;
    while(temp!=NULL){
        prev= temp;
        if(temp->data > key) temp = temp->left;
        else if(temp->data < key) temp = temp->right;
    }
    if(prev->data> key) prev->left = new_node;
    else prev->right = new_node;
}

bool search1(treenode* root, int key){
    if(root==NULL) return false;
    if(root->data==key) return true;
    if(root->data>key) return search1(root->left,key);
    if(root->data<key) return search1(root->right, key);
    
    return false;
}

treenode* search2(treenode* root, int key){
    if(root==NULL) return NULL;
    if(root->data==key) return root;
    else if(root->data>key) return search2(root->left, key);
    else if(root->data<key) return search2(root->right, key);

    return NULL;
}

int search3(treenode* root, int key){
    while(root!=NULL && root->data!=key){
        if(root->data>key) root = root->left;
        else if(root->data<key) root = root->right;
    }
    if(root==NULL) return -1;
    return root->data;
}

treenode* deletenode(treenode* root, int key){
    if(root == NULL) return root;
    if(key < root->data) root->left = deletenode(root->left, key);
    if(key > root->data) root->right = deletenode(root->right, key);
    else{
        treenode* temp = NULL;
        if(root->left==NULL || root->right==NULL){
            if(root->left) temp = root->left;
            else temp = root->right;
            free(root);
            return temp;
        }
            treenode* tp = root->right;
            while(tp->left!=NULL) tp=tp->left;
            root->data = tp->data;
            root->right = deletenode(root->right, tp->data);

        return root;
    }
}

int inorderarr(treenode* root, int arr[], int i){
    if(root==NULL) return i;
    i = inorderarr(root->left, arr, i);
    arr[i++] = root->data;
    i = inorderarr(root->right, arr, i);

    return i;
}

int main(){
    treenode* root = NULL;
    for(int i=0;i<6;i++){
        int x;
        cin>>x;
        //root = insert(root,x);
        insert1(root,x);
    }
    cout<<search3(root,15)<<"\n";
    // deletenode(root, 15);
    // cout<<search1(root,15)<<"\n";

    int arr[6];
    int i=0;
    inorderarr(root,arr, i);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
}