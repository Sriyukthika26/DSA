#include<bits/stdc++.h>
using namespace std;

class treenode{
public:
    int data;
    treenode* left; treenode* right;
    int height;
    
    treenode(int key){
        data= key;
        left=right=NULL;
        height=1;
    }
};

int height(treenode* node){
    if(node==NULL) return 0;
    return node->height;
}

treenode* rightrotate(treenode* rt){
    treenode* rl = rt->left;
    treenode* T2 = rl->right;
    rl->right = rt;
    rt->left = T2;
    
    rt->height = 1+max(height(rt->left), height(rt->right));
    rl->height= 1+max(height(rl->left), height(rl->right));
    
    return rl;
}

treenode* leftrotate(treenode* rt){
    treenode* rr = rt->right;
    treenode* T2 = rr->left;
    rr->left = rt;
    rt->right = T2;
    
    rt->height = 1+max(height(rt->left), height(rt->right));
    rr->height = 1+max(height(rr->left), height(rr->right));
    
    return rr;
}

int getbalance(treenode* rt){
    return height(rt->left)-height(rt->right);
}

treenode* leftright(treenode* rt){
    rt->left = leftrotate(rt->left);
    return rightrotate(rt);
}

treenode* rightleft(treenode* rt){
    rt->right = rightrotate(rt->right);
    return leftrotate(rt);
}

treenode* insert(treenode* rt, int key){
    treenode* newnode = new treenode(key);
    if(rt==NULL) return newnode;
    if(rt->data>key) rt->left = insert(rt->left, key);
    if(rt->data< key) rt->right = insert(rt->right, key);
    
    rt->height = 1+max(height(rt->left), height(rt->right));
    int balance = getbalance(rt);
    if(balance>1 && key< rt->left->data){
        return rightrotate(rt);
    }
    if(balance>1 && key>rt->left->data){
        return leftright(rt);
    }
    if(balance<-1 && key>rt->right->data){
        return leftrotate(rt);
    }
    if(balance<-1 && key< rt->right->data){
        return rightleft(rt);
    }
    return rt;
}

treenode* deletenode(treenode* rt, int key){
    if(rt==NULL) return NULL;
    if(rt->data > key) return deletenode(rt->left, key);
    else if(rt->data < key) return deletenode(rt->right, key);
    else{
        treenode* temp =NULL;
        if(rt->left==NULL || rt->right==NULL){
            if(rt->left) temp= rt->left;
            else temp = rt->right;
            if(temp==NULL){
                temp = rt;
                rt=NULL;
            }else *rt = *temp;
            free(temp);
        }
        else{
            treenode* tp = rt->right;
            while(tp->left!=NULL) tp=tp->left;
            rt->data = tp->data;
            rt->right = deletenode(rt->right, tp->data);  
        }
    }
    if(rt==NULL) return NULL;
    rt->height = 1+max(height(rt->left), height(rt->right));
    int balance = getbalance(rt);
    if(balance > 1 && getbalance(rt->left)>=0){
        return rightrotate(rt);
    }
    if(balance>1 && getbalance(rt->left)<0){
        return leftright(rt);
    }
    if(balance<-1 && getbalance(rt->right)<=0){
        return leftrotate(rt);
    }
    if(balance<-1 && getbalance(rt->right)>0){
        return rightleft(rt);
    }
    
    return rt;
}

void inorder(treenode* root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main(){
    treenode* root = NULL;
    root = insert(root, 10); 
    root = insert(root, 20); 
    root = insert(root, 30); 
    root = insert(root, 40); 
    root = insert(root, 50); 
    root = insert(root, 25);

    cout << "Inorder traversal : \n"; 
    inorder(root); 
    
}