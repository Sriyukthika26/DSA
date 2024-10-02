#include<bits/stdc++.h>
using namespace std;
class TreeNode{
public:
    int key;
    TreeNode* right;
    TreeNode* left;

    TreeNode(int m){
        key = m;
        left = right = NULL;
    }
};

class BST{
public:
    TreeNode* root;
    BST(){
        root = NULL;
    }

    void insert(int m){
        TreeNode* new_node = new TreeNode(m);
        if(root==NULL){
            root = new_node;
            return;
        }
        TreeNode* temp = root;
        TreeNode* prev;
        while(temp!=NULL){
            if(temp->key>m){
                prev = temp;
                temp= temp->left;
            }
            else if(temp->key<m){
                prev = temp;
                temp = temp->right;
            }
        }
        if(prev->key>m){
            prev->left = new_node;
        }
        else prev->right = new_node;
    }

    TreeNode* Search(int x){
        TreeNode* temp =  root;
        while(temp!=NULL){
            if(temp->key==x){
                return temp;
            }
            else if(temp->key>x){
                temp = temp->left;
            }
            else temp = temp->right;
        }
    }
};

  //Recursive Search
    bool SearchRec(int x, TreeNode* root){
        if(root==NULL) return false;
        if(root->key==x) return true;
        if(root->key>x) return SearchRec(x, root->left);
        if(root->key<x) return SearchRec(x,root->right);
    }


    // value just smaller than root value-- rightmost value of leftsubtree
    TreeNode* jstsmall(TreeNode* root){
        TreeNode* temp = root;
        temp= temp->left;
        while(temp->right!=NULL){
            temp= temp->right;
        }
        return temp;
    }

    // value just bigger than root value-- leftmost value of right subtree
    TreeNode* jstbig(TreeNode* root){
        TreeNode* temp = root;
        temp= temp->right;
        while(temp->left!=NULL){
            temp= temp->left;
        }
        return temp;
    }


int main(){
    BST tree;
    tree.insert(12);
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
    tree.insert(9);
    tree.insert(10);
    tree.insert(8);
    tree.insert(20);
    tree.insert(17);
    tree.insert(13);
    TreeNode* found = tree.Search(15);
    cout<<found->key<<"\n";
    cout<<SearchRec(15,tree.root)<<"\n";
    TreeNode* result = jstsmall(tree.root);
    cout<<result->key<<"\n";
    TreeNode* res = jstbig(tree.root);
    cout<<res->key<<"\n";
}
