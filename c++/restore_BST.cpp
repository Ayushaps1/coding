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

void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calpointer(node* root,node** first,node** mid,node** last,node** prev){
    if(root == NULL){
        return;
    }

    calpointer(root->left,first,mid,last,prev);

    if(*prev && root->data < (*prev)->data){
        if(!*first){
            *first = *prev;
            *mid = root;
        }
        else{
            *last = root;
        }
    }
    *prev = root;

    calpointer(root->right,first,mid,last,prev);
}

void restoreBST(node* root){
    if(root == NULL){
        return;
    }
    node* first = NULL;
    node* mid = NULL;
    node* last = NULL;
    node* prev = NULL;

    calpointer(root,&first,&mid,&last,&prev);

    //case 1
    if(first && last){
        swap(&(first->data),&(last->data));
    }
    //case 2
    else if(first && mid){
        swap(&(first->data),&(mid->data));
    }
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
        6
       / \
      9   3
     / \   \ 
    1   4  13
*/

node* root = new node(6);
root->left = new node(9);
root->right = new node(3);
root->left->left = new node(1);
root->left->right = new node(4);
root->right->right = new node(13);

inorder(root);
cout<<endl;

// test
restoreBST(root);

inorder(root);

    return 0;
}