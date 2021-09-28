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

node* searchInBST(node* root,int key){
    if(root == NULL){
        return NULL;
    }

    if(root->data == key){
        return root;
    }

    if(key < root->data){
        return searchInBST(root->left,key);
    }
    return searchInBST(root->right,key);
}

node* inorderSucc(node* root){
    node* temp = root;
    while(temp && temp->left == NULL){
        temp = temp->left;
    }
    return temp;
}

void deleteNode(node* root,int key){
    node* temp = root->left;
    free(root);
    root = temp;
}

void inorder(node* root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main(){

/*
        4
       / \
      2   5
     / \   \ 
    1   3   6
*/
    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->left = new node(3);
    root->right->right = new node(6);

    // searching in BST
    node* ans = searchInBST(root,5);
    cout<<ans->data;
    cout<<endl;
    // before deletion
    inorder(root);
    cout<<endl;

    deleteNode(root,5);
 
    // after deletion
    inorder(root);
    return 0;
}