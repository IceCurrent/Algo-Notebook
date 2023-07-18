#include<iostream>
#include<queue>
using namespace std;

// at every level we've to print leftmost node

struct node{
    int key;
    node* left;
    node* right;

    node(int k){
        key = k;
        left = NULL;
        right = NULL;
    }
};

// idea is that when we do pre-order traversal, then we always visit the left nodes or
// left subtree first. 

int maxLevel = 0; //the level we've seen so far

void leftView(node* root, int level){
    if(root == NULL){
        return;
    }
    // here level is the current level.

    if(level > maxLevel){
        cout<<root->key<<" ";
        maxLevel = level;
    }

    leftView(root->left, level+1);
    leftView(root->right, level+1);
}


// Here we just do the bfs traversal and print the first element of each level
void leftViewIter(node* root){
   // it's like line by line level order traversal  

    if(root == NULL){
        return;
    }

    queue<node*> q;
    q.push(root);
    
    while(!q.empty()){
        int count = q.size();

        for(int i=0; i<count; i++){
            node* curr = q.front();
            q.pop();

            //this is the extra line that we add
            if(i == 0){
                cout<<curr->key<<" ";
            }

            if(curr->left != NULL){
                q.push(curr->left);
            }

            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
    }

}


int main(){

    node* root = new node(10);
    root->left = new node(20);
    root->right = new node(45);
    root->left->left = new node(94);
    root->left->right = new node(61);
    root->right->right = new node(29);
    root->right->right->left = new node(74);
    root->right->right->right = new node(98);

    leftView(root, 1);
    cout<<endl;

    leftViewIter(root);
    cout<<endl;

    return 0;
}