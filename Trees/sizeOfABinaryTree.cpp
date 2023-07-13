#include<iostream>
using namespace std;

// number of nodes in a binary tree is it's size

struct node{
    int key;
    node* left;
    node* right;

    node(int k){
        key = k;
    }
};


int size(node* root){
    if(root == NULL){
        return 0;
    }

    return (1 + size(root->left) + size(root->right));
    
}


int main(){
    node* root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(50);
    root->right->right = new node(60);
    root->right->right->left = new node(70);
    root->right->right->right = new node(80);

    cout<<size(root)<<"\n";

    return 0;
}