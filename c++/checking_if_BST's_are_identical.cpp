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

bool isIdentical(node* root1,node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    
    else if(root1 == NULL || root2 == NULL){
        return false;
    }
    
    else{
        bool cond1 = (root1->data == root2->data);
        bool cond2 = isIdentical(root1->left,root2->left);
        bool cond3 = isIdentical(root1->right,root2->right);

        if(cond1 && cond2 && cond3){
            return true;
        }
        else{
            return false;
        }

    }
}

int main(){

/*
        2
       / \
      3   4
*/
node* root = new node(2);
root->left = new node(3);
root->right = new node(4);

// test
if(isIdentical(root,root)){
    cout<<"BST's are identical";
}
else{
    cout<<"BST's are not identical";
}
cout<<endl;
/*
        2
       / \
      3   5
*/
node* root2 = new node(2);
root->left = new node(3);
root->right = new node(5);

//test 2
if(isIdentical(root,root2)){
    cout<<"BST's are identical";
}
else{
    cout<<"BST's are not identical";
}
    return 0;
}