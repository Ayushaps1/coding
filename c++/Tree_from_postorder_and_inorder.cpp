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

node* built_tree(int postorder[],int inorder[],int start,int end){

     if(end<start){
        return NULL;
     }

    static int idx=end;
    int curr=postorder[idx];
    node* Node=new node(curr);
    idx--;
    if(start==end){
        return Node;
    }
    int pos=search(inorder,start,end,curr);
    Node->right=built_tree(postorder,inorder,pos+1,end);
    Node->left=built_tree(postorder,inorder,start,pos-1);

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

    int postorder[]={4,5,2,6,7,3,1};
    int inorder[]={4,2,5,1,6,3,7};                                         

    // buit tree
    node* root=built_tree(postorder,inorder,0,6);
    
    inorder_print(root);
    
    return 0;
}