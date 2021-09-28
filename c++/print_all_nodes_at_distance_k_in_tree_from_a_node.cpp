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

// case 1
void printNodesAtsubtrees(node* root,int k){
    if(root == NULL || k<0){
        return ;
    }
    if(k == 0){
        cout<<root->data<<" ";
        return ; 
    }

    printNodesAtsubtrees(root->left,k-1);
    printNodesAtsubtrees(root->right,k-1);
}

// case 2
int printNodesAtk(node* root,node* target,int k) {
    if(root == NULL){
        return -1;
    }
    if(root == target){ 
        printNodesAtsubtrees(root,k);
        return 0;
    }
    
    int dl = printNodesAtk(root->left,target,k);
    if(dl != -1){
        if(dl + 1 == k){
            cout<<root->data<<" ";
        }
        else{
            printNodesAtsubtrees(root->right,k-dl-2);           
        }
        return dl+1;
    }

    int dr = printNodesAtk(root->right,target,k);
    if(dr != -1){
        if(dr + 1 == k){
            cout<<root->data<<" ";
        }
        else{
            printNodesAtsubtrees(root->left,k-dr-2);
        }
        return dr+1;
    }
    
    return -1;

}

int main(){

 /*
             1
            / \
           /   \
          2     3
          \    / \
           4   10 11
          / \ 
         5   6 
        / \ / \ 
       6  7 8  9 
 */

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(4);
    root->left->right->left = new node(5);
    root->left->right->left->left = new node(6);
    root->left->right->left->right = new node(7);
    root->left->right->right = new node(8);
    root->left->right->right->left = new node(9);
    root->right->left = new node(10);
    root->right->right = new node(11);

    // printing all nodes at a distance k from target node
    printNodesAtk(root,root->left,3);
    

     return 0;
}