#include<iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;

    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

int countNode(node* root){
    if(root == NULL){
        return 0;
    }
    return(countNode(root->left)+countNode(root->right)+1);
}

int sum(node* root){
    if(root==NULL){
        return 0;
    }
    return(sum(root->left)+sum(root->right)+root->data);
}

int main(){

    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);

    // count number of nodes in a tree 
    cout<<countNode(root)<<endl;

    // sum of all nodes
    cout<<sum(root);
    return 0;
}