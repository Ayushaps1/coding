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

node* constructBalBST(int a[],int start,int end){
    if(start > end){
        return NULL;
    }
    int mid = (start+end)/2;
    node* root = new node(a[mid]);
    root->left = constructBalBST(a,start,mid-1);
    root->right = constructBalBST(a,mid+1,end);

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

    int a[6] = {1,2,3,4,5,6};

    node* root = constructBalBST(a,0,5);

    inorder(root);

    return 0;
}