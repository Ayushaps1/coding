#include<iostream>
#include<queue>
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

int hight(node* root){
    if(root == NULL){
        return 0;
    }

    return max(hight(root->left),hight(root->right))+1;
}

int diameter(node* root){
    if(root == NULL)
        return 0;

    int lefthight=hight(root->left);
    int righthight=hight(root->right);
    int currentdiameter=lefthight+righthight+1;

    return max(max(diameter(root->left),diameter(root->right)),currentdiameter);
}

int diameter(node* root,int *h){
    if(root == NULL){
        return 0;
    }

    int lh=0,rh=0;
    int leftdiameter=diameter(root->left,&lh);
    int rightdiameter=diameter(root->right,&rh);
    int currentdiameter=lh+rh+1;

    *h=max(lh,rh)+1;

    return max(max(leftdiameter,rightdiameter),currentdiameter);
}


int main(){

    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);

    //height of tree
    cout<<hight(root)<<endl;

    //diameter of tree
    cout<<diameter(root)<<endl;

    //optimised diameter function
    int hight=0;
    cout<<diameter(root,&hight);

    return 0;
}