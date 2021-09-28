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

void sumreplacement(node* root){
    if(root == NULL){
        return;                                                     // Time complexity= O(n)
    }
    sumreplacement(root->left);
    sumreplacement(root->right);
    if(root->left)                                                 //you can also use this = if(root->left != NULL)
        root->data += root->left->data;
    if(root->right)                                      // you can also use this = if(root->right != NULL)
        root->data += root->right->data;

}

void preorder(node* root){
    if(root){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){

    node* root = new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    
    preorder(root);
    cout<<endl;
    // sum replacement
    sumreplacement(root);

    preorder(root);
    return 0;
}