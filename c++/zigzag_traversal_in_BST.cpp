#include<iostream>
#include<stack>
#include<queue>
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

void zigzagtraversal(node* root){
    if(root == NULL){
        return;           // time complexity = O(n)  (from O(2n))
    }

    stack<node*>currlevel;
    stack<node*>nextlevel;

    bool lefttoright = true;
    
    currlevel.push(root);

    while(!currlevel.empty()){
        node* temp = currlevel.top();
        currlevel.pop();

        if(temp){
            cout<<temp->data<<" ";

            if(lefttoright){
                
                if(temp->left){
                    nextlevel.push(temp->left);
                }
                if(temp->right){
                    nextlevel.push(temp->right);
                }

            }
            // right to left
            else{
                if(temp->right){
                    nextlevel.push(temp->right);
                }
                if(temp->left){
                    nextlevel.push(temp->left);
                }
            }
        }

        if(currlevel.empty()){
            lefttoright = !lefttoright;
            swap(nextlevel,currlevel);
        }

    }
}


// my way
void level(node* root){
    if(root == NULL){
        return;
    }

    queue<node*>q;

    q.push(root);
    bool lefttoright = false;   
    while(!q.empty()){
        int n = q.size();

        for(int i=0;i<n;i++){
            node* temp = q.front();
            q.pop();
            cout<<temp->data<<" ";

            if(lefttoright){
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            // right to left
            else{
                if(temp->right){
                    q.push(temp->right);
                }
                if(temp->left){
                    q.push(temp->left);
                }
            }           
        }
            lefttoright = !lefttoright;
        
    }
    
}

int main(){
    /*     12
          /  \
         9   15
        / \
       5  10
    */

    node* root = new node(12);
    root->left = new node(9);
    root->right = new node(15);
    root->left->left = new node(5);
    root->left->right = new node(10);

    // zigzag traversal test
    zigzagtraversal(root);
    cout<<endl;
    level(root);
    return 0;
}