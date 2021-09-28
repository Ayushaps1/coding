#include<iostream>
#include<vector>
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

node* LCA(node* root,int a,int b){
    if(root == NULL){
        return NULL;
    }

    if(root->data == a || root->data == b){
        return root;
    }

    node* left = LCA(root->left,a,b);
    node* right = LCA(root->right,a,b);

    if(left != NULL && right != NULL){
        return root;
    }
    else if(left != NULL){
        return left;
    }
    return right;

}


// 2nd way to find LCA
bool getpath(node* root,int key,vector<int>&v){
    if(root == NULL){
        return false;
    }

    v.push_back(root->data);
    if(root->data == key){
        return true;
    }

    if(getpath(root->left,key,v) || getpath(root->right,key,v)){
       return true; 
    }

    v.pop_back();
    return false;
}

int lca(node* root,int n1,int n2){
    if(root == NULL){
        return -1;
    }

    vector<int>v1,v2;

    if(!getpath(root,n1,v1) || !getpath(root,n2,v2)){
        return -1;
    }

    for(int i=0;i<v1.size()&&v2.size();i++){
        if(v1[i] != v2[i]){
            return v1[i-1];
        }
    }

    return -1;
}

int main(){
    /*
            1
           / \ 
          2   3
         / \ / \
        4  5 6  7
    */

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    // Lowest common factor
    node* h = LCA(root,6,7);
    cout<<h->data<<endl;
    cout<<lca(root,6,7);
    return 0;
}