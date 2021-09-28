#include<iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

// my way
void insertnode(node* &root,int val){
    if(root == NULL){
        root = new node(val);
        return;
    }

    if(val < root->data){
        insertnode(root->left,val);
    }
    else{
        insertnode(root->right,val);
    }
}

// 2nd way
node* insertNode(node* root,int val){
    if(root == NULL){
        return new node(val);
    }

    if(val < root->data){
        root->left = insertNode(root->left,val);
    }
    else{
        root->right = insertNode(root->right,val);
    }

    return root;
}

void inorder(node* root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }    
}

int main(){

    // for my way
    node* root = NULL;
    insertnode(root,3);
    insertnode(root,2);
    insertnode(root,4);
    insertnode(root,1);
    insertnode(root,6);
    insertnode(root,5);
    insertnode(root,7);
    
    inorder(root);
    
    // 2nd way
    node* Root = NULL;
    Root = insertNode(Root,3);
    Root = insertNode(Root,4);
    Root = insertNode(Root,1);
    Root = insertNode(Root,2);
    Root = insertNode(Root,6);
    Root = insertNode(Root,5);
    Root = insertNode(Root,7);
    
    cout<<endl;
    inorder(Root);

    return 0;
}