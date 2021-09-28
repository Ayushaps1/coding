#include<iostream>
#include<vector>
using namespace std;

struct node{
    int data;
    node* left;                     //using concept of catalan number
    node* right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<node*> constructBST(int start,int end ){
    vector<node*>trees;
    if(start>end){
        trees.push_back(NULL);
        return trees;    
    }

    for(int i=start;i<=end;i++){
        vector<node*>leftsubtrees = constructBST(start,i-1);
        vector<node*>rightsubtrees = constructBST(i+1,end);

        for(int j=0;j<leftsubtrees.size();j++){
            node* left = leftsubtrees[j];
            for(int k=0;k<rightsubtrees.size();k++){
                node* right = rightsubtrees[k];
                node* root = new node(i);
                root->left = left;
                root->right = right;

                trees.push_back(root);
            }
        }
    }

    return trees;
}

void preorder(node* root){
    if(root){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){

    vector<node*>trees = constructBST(1,3);

    for(int i=0;i<trees.size();i++){
        cout<<i+1<<" : ";
        preorder(trees[i]);
        cout<<endl;
    }

    return 0; 
}