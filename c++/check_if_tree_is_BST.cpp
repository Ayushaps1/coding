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

bool checkBST(node* root,node* min,node* max){
    if(root == NULL){
        return true;
    }

    if(min != NULL && root->data < min->data){
        return false;
    }

    if(max != NULL && root->data > max->data){
        return false;
    }

    int left = checkBST(root->left,min,root);
    int right = checkBST(root->right,root,max);

    return left && right;
}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    /*
            1
           / \
          2   3
    */

   // checking if the tree is BST
   if(checkBST(root,NULL,NULL)){
       cout<<"valid BST";
   }
   else{
       cout<<"invalid BST";
   }

    return 0;
}