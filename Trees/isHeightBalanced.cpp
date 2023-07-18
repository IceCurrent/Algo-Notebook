#include<iostream>
#include<queue>
using namespace std;

// find whether the difference between the heights of left subtree and right subtree should 
// not be more than 1

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

int height(node* root){
    if(root == NULL){
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
}

// naive Solution
bool isBalancedTree(node* root){

    if(root == NULL){
        return true;
    }

    if(isBalancedTree(root->left) && isBalancedTree(root->right)){
        return (abs(height(root->left)-height(root->right)) <= 1);
    }
    else{
        return false;
    }
}

// optimised solution

//here our function's return type not only tells us about whether the tree is balanced
//or not, but also tells us gives the height of the tree (actually it gives height+1);
//to make the solution more clear, we can make it give the actual height, and in the 
//case of non-balanced subtree we return -1;

//TIME COMPLEXITY: O(N);
int bal(node* root){
    if(root == NULL){
        return 1;
    }

    int l = bal(root->left);
    int r = bal(root->right);

    if(l && r){

        if(abs(l-r) <= 1){
            return 1 + max(l, r);
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
    
}

int main(){
    node* root = new node(18);
    root->left = new node(4);
    root->right = new node(20);
    root->right->left = new node(13);
    root->right->right = new node(70);
    root->right->right->right = new node(70);
    root->right->right->right->right  = new node(70);

    if(isBalancedTree(root)){
        cout<<"YES"<<"\n";
    }
    else{
        cout<<"NO"<<"\n";
    }

    if(bal(root)){
        cout<<"YES"<<"\n";
    }
    else{
        cout<<"NO"<<"\n";
    }

}