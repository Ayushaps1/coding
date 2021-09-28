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

node* LCA(node* root,int n1,int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }

    node* left=LCA(root->left,n1,n2);
    node* right=LCA(root->right,n1,n2);

    if(left != NULL && right != NULL){
        return root;
    }
    if(left != NULL){
        return left;
    }
    if(right != NULL){
        return right;
    }
    return NULL;
}

int findhight(node* root,int des,int dis){
    if(root == NULL){
        return -1; 
    }

    if(root->data == des){
        return dis;
    }

    int left = findhight(root->left,des,dis+1);
    
    if(left != -1){
        return left;
    }
    return findhight(root->right,des,dis+1);
}

int disBtwNodes(node* root,int n1,int n2){
    if( root == NULL ){
        return -1;
    }

    node * lca = LCA(root,n1,n2);

    int d1 = findhight(lca,n1,0);
    int d2 = findhight(lca,n2,0);

    return (d1+d2); 
}

int main(){

  node* root=new node(1);
  root->left=new node(2);
  root->right=new node(3);
  root->left->left=new node(4);
  root->left->right=new node(5);
  root->right->left=new node(6);  
  root->right->right=new node(7);  

/*            1
             / \
            2   3
           / \ / \
          4  5 6  7
*/

 // finding distance between two nodes
    cout<<disBtwNodes(root,4,7);
    return 0;
}