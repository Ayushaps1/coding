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

int hight(node* root){
    if(root == NULL){
        return 0; 
    }

    return (max(hight(root->left),hight(root->right))+1);
}

// function to check if the tree is balanced or not

bool isbalanced(node* root){
    if(root == NULL){
        return true;                            // time complexity = O(n*n)
    }

    if(isbalanced(root->left) == false){
        return false;
    }
    if(isbalanced(root->right) == false){
        return false;
    }

    int lefth = hight(root->left);
    int righth = hight(root->right);

    if(abs(lefth - righth) <=1){
        return true;
    }
    else{
        return false;
    }
}

// optimsed balanced tree function

bool isbalanced(node* root,int* hight){
    if(root == NULL){
        return true;
    }

    int lh=0,rh=0;
    if(isbalanced(root->left,&lh) == false){
        return false;
    }
    if(isbalanced(root->right,&rh) == false){
        return false;
    }

    *hight = max(rh,lh)+1;

    if(abs(lh-rh) <= 1){
        return true;
    }
    else{
        return false;
    }

        
}

int main(){

//        1
//       / \
//      2   3
//     / \ / \
//    4  5 6  7

 node* root = new node(1);
 root->left = new node(2);
 root->right = new node(3);
 root->left->left = new node(4);
 root->left->right = new node(5);
 root->right->left = new node(6);
 root->right->right = new node(7);

//  is balanced tree
if(isbalanced(root)){
    cout<<"balanced tree"<<endl;
}
else{
    cout<<"unbalanced tree"<<endl;
}

/*             1
              / 
             2
            /
           3   

*/

node* root2 = new node(1);
root2->left  = new node(2);
root2->left->left  = new node(3);

if(isbalanced(root2)){
    cout<<"balanced tree"<<endl;
}
else{
    cout<<"unbalanced tree"<<endl;
}

// after otimization of balanced function
int hight=0;
if(isbalanced(root,&hight)){
    cout<<"balanced tree"<<endl;
}
else{
    cout<<"unbalanced tree"<<endl;
}



if(isbalanced(root2,&hight)){
    cout<<"balanced tree"<<endl;
}
else{
    cout<<"unbalanced tree"<<endl;
}


    return 0;
}