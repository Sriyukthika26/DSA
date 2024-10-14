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
            prev = temp;
            if(temp->key>m) temp= temp->left;
            else temp = temp->right;
        }
        if(prev->key>m) prev->left = new_node;
        else prev->right = new_node;
    }

    TreeNode* Search(int x){
        TreeNode* temp =  root;
        while(temp!=NULL){
            if(temp->key==x) return temp;
            else if(temp->key>x) temp = temp->left;
            else temp = temp->right;
        }
    }

};

//find min elt in BST
    TreeNode* findmin(TreeNode* root){
        if(root==NULL) return NULL;
        while(root->left!=NULL){
            root = root->left;
        }
        return root;
    }

// returns root node after deleting the elt--> first searches then deletes, if elt not present , it returns the root as it is.

    TreeNode* helper(TreeNode* root){
        if(!root->left) return root->right;
        else if(!root->right) return root->left;
        TreeNode* templeft = root->left;
        while(templeft->right!=NULL) templeft = templeft->right;
        templeft->right= root->right;
        return root->left;
    }    

    TreeNode* Delete(TreeNode* root, int x){
        if(!root) return NULL;
        if(root->key == x) return helper(root);
        TreeNode* temp = root;
        while(root){
            if(root->key > x){
                if(root->left && root->left->key == x){
                    root->left = helper(root->left);
                    break;
                }
                else root = root->left;
            }
            else{
                if(root->right && root->right->key==x){
                    root->right = helper(root->right);
                    break;
                }
                else root = root->right;
            }
        }
        return temp;
    }

    //delete key - approach 2
    TreeNode* deletenode(TreeNode* root, int val){
        if(root == NULL) return root;
        if(val < root->key) root->left = deletenode(root->left, val);
        if(val > root->key) root->right = deletenode(root->right, val);
        else{
            if(root->left==NULL){
                TreeNode* temp = root->right;
                free(root);
                return temp;
            }
            else if(root->right==NULL){
                TreeNode* temp = root->left;
                free(root);
                return temp;
            }
            TreeNode* temp = findmin(root->right);
            root->key = temp->key;
            root->right = deletenode(root->right, temp->key);
            return root;
        }
    }

  //Recursive Search
    bool SearchRec(int x, TreeNode* root){
        if(root==NULL) return false;
        if(root->key==x) return true;
        if(root->key>x) return SearchRec(x, root->left);
        if(root->key<x) return SearchRec(x,root->right);
    }

    TreeNode* searchBST(TreeNode* root, int val) {             //return NULL, if does not exist
        if(root== NULL) return NULL;
        if(root->key == val) return root;
        if(root->key > val) return searchBST(root->left, val);
        if(root->key < val) return searchBST(root->right, val);

        return NULL;
    }

    // value just smaller than root value-- rightmost value of immediate leftsubtree
    TreeNode* jstsmall(TreeNode* root){
        TreeNode* temp = root;
        temp= temp->left;
        while(temp->right!=NULL){
            temp= temp->right;
        }
        return temp;
    }

    // value just bigger than root value-- leftmost value of immediate right subtree
    TreeNode* jstbig(TreeNode* root){
        TreeNode* temp = root;
        temp= temp->right;
        while(temp->left!=NULL){
            temp= temp->left;
        }
        return temp;
    }

// Function to return the ceil of given number in BST.(number >= given input)
int findCeil(TreeNode* root, int input) {
    int ans = -1;
    while(root!=NULL){
        if(root->key >= input){
            ans = root->key;
            root = root->left;
        }
        else root = root->right;
    }
    return ans;
}

// Function to return the floor of given number in BST.(number <= given input)
    int floor(TreeNode* root, int x) {
        int ans = -1;
        while(root){
            if(root->key <=x){
                ans = root->key;
                root = root->right;
            }
            else root = root->left;
        }
        return ans;
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

    TreeNode* new_root = Delete(tree.root, 15);
    cout<<SearchRec(15, new_root);
}
