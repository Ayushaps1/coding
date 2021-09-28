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

node* insertInBST(node* root,int key){
    if(root ==NULL){
        return new node(key);
    }

    if(key<root->data){
        root->left = insertInBST(root->left,key);
    }
    else{
        root->right = insertInBST(root->right,key);
    }

    return root;
}

node* constructBST(int preorder[],int *preorderidx,int key,int min,int max,int n){
    if(*preorderidx >= n ){
        return NULL;
    }

    node* root = NULL;
    if(key > min && key < max ){
    
        root = new node(key);
        *preorderidx  = *preorderidx + 1;

        if(*preorderidx < n){
            root->left = constructBST(preorder,preorderidx,preorder[*preorderidx],min,key,n);
        }
        if(*preorderidx < n){
            root->right = constructBST(preorder,preorderidx,preorder[*preorderidx],key,max,n);
        }
        
    }

    return root;
}


void preorder(node* root){
    if(root){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){

    int a[6] ={7,5,4,6,8,9};

    node* root = NULL;
    for(int i=0;i<6;i++){
        root = insertInBST(root,a[i]);
    }

    preorder(root);
    cout<<endl;

    int preorderidx = 0;
    root = constructBST(a,&preorderidx,7,INT_MIN,INT_MAX,6);

    preorder(root);
    
    return 0;
}