#include<iostream>
#include<limits>
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

struct info{
    int size;
    int min;
    int max;
    int ans;
    bool isBST;
};

info largestBSTinBT(node* root){
    if(root == NULL){
        return{0,INT_MAX,INT_MIN,0,true};   // here we cannot use ()  
    }                                       // {} this is like as we initialize struct datatype
                                            //  info = {0,INT_MAX,INT_MIN,0,true};
    if(root->left == NULL && root->right == NULL){
        return{1,root->data,root->data,1,true};
    }

    info left = largestBSTinBT(root->left);
    info right = largestBSTinBT(root->right);

    info curr;
    curr.size = (1 + left.size + right.size);

    if(left.isBST && right.isBST && left.max<root->data && root->data<right.min){
        
        curr.min = min(left.min,min(right.min,root->data));
        curr.max = max(right.max,max(right.max,root->data));
        curr.isBST = true;
        curr.ans = curr.size;
        return curr;
    }
    curr.ans = max(left.ans,right.ans);
    curr.isBST = false;
    return curr;

}

int main(){
/*
        21
       /  \
      20  30
     /
    5 
*/
    node* root = new node(21);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(5);

    // finding largest BST in BT
    cout<<"largest BST in BT : "<<largestBSTinBT(root).ans;

    return 0;
}