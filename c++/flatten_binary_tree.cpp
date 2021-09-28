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

void flatten(node* root){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }

    if(root->left != NULL){
        flatten(root->left); 
        node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        node* t = root->right;
        while(t->right != NULL){
            t = t->right;
        } 
        t->right = temp;
    }
    flatten(root->right);
}

void inorder(node* root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->right->left = new node(4);
    root->right->right = new node(5);

        //    1
        //   / \
        //  2   3
        //     / \
        //    4   5

        //  flatten tree 
        flatten(root);

        inorder(root);

    return 0;
}