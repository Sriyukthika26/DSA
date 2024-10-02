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

class Tree{
public:
    TreeNode* root;
    Tree(){
        root = NULL;
    }
};

//Recursive Inorder traversal
void inorderTraversal(TreeNode* root){
    if(root== NULL) return;
    inorderTraversal(root->left);
    cout<<root->key<<" ";
    inorderTraversal(root->right);
}
//Iterative Inorder traversal
void inorderiter(TreeNode* root){
    if(root==NULL) return;
    stack<TreeNode*>s;
    TreeNode* curr = root;
    while(!curr || !s.empty()){
        while(!curr){
            s.push(curr);
            curr = curr->left;
        }

        curr= s.top();
        s.pop();
        cout<<curr->key<<" ";
        curr = curr->right;
    }
}


//iterative preorder
void preorderiter(TreeNode* root){
    if(root == NULL){
        return;
    }
    stack<TreeNode*>s;
    s.push(root);
    while(!s.empty()){
    TreeNode* cNode = s.top();
    cout<<cNode->key<<" ";
    s.pop();
    if(cNode->right) s.push(cNode->right);
    if(cNode->left) s.push(cNode->left);
    }
}


void preordertraversal(TreeNode* root){
    if(root== NULL) return;
    cout<<root->key<<" ";
    preordertraversal(root->left);
    preordertraversal(root->right);
}

void postorder(TreeNode* root){
    if(root== NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->key<<" ";
}
int main(){
    Tree t;
    t.root = new TreeNode(1);
    t.root->left = new TreeNode(2);
    t.root->left->left = new TreeNode(4);
    t.root->left->right = new TreeNode(5);

    
    preorderiter(t.root);
    cout<<"\n";

}
    