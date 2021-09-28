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

int search(int inorder[],int start,int end,int curr){

    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}

node* built_tree(int preorder[],int inorder[],int start,int end){
    // if(start>end){   //we dont need this but still for saftey we can use this
    //  return NULL;
    // }
    static int idx=start;
    int curr=preorder[idx];
    idx++;
    node* Node=new node(curr);
    if(start==end){
        return Node;
    }
    int pos=search(inorder,start,end,curr);
    Node->left=built_tree(preorder,inorder,start,pos-1);
    Node->right=built_tree(preorder,inorder,pos+1,end);
    

    return Node;
}

void inorder_print(node* root){

    if(root){
        
        inorder_print(root->left);
        cout<<root->data<<" ";
        inorder_print(root->right);
    }
}

int main(){

    int preorder[]={1,2,4,5,3,6,7};  
    int inorder[]={4,2,5,1,6,3,7};

    //buit tree
    node* root=built_tree(preorder,inorder,0,6);

    inorder_print(root);
    return 0;
}