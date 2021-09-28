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

int maxSumpathUtil( node* root,int &ans ){
    if(root == NULL){
        return 0;
    }

    int left = maxSumpathUtil(root->left,ans);
    int right = maxSumpathUtil(root->right,ans);

    int currmax = max(max(root->data,left + root->data),max(root->data + right,root->data+left+right));
    ans = max(ans,currmax);
    
    int singlepathsum = max(root->data,max(left + root->data,right + root->data));
    return singlepathsum;
}

int maxSumpath(node* root) {
    if(root == NULL) {
        return 0;
    }
    int ans = INT_MIN;
    maxSumpathUtil(root,ans);

    return ans;
}

int main(){

    node* root = new node(-10);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->right = new node(5);

  /*
            1
           / \
          2   3
         /     \
        4       5
  */

    // max sum path
    cout<<maxSumpath(root);

    return 0;
}