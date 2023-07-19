#include<iostream>
#include<queue>
#include<deque>
using namespace std;

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

// diameter of binary tree is the longest distance between two leaf nodes

// we have to find the root of the diameter path, so we can go at every node:
// find the left height of it and the right height of it and check if that node can
// be the root of the diameter path

int height(node* root){
    if(root == NULL){
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
}

int findMax(int a, int b, int c){
    if(a >max(b, c)){
        return a;
    }
    else{
        return max(b, c);
    }
}

int diameter(node* root){

    if(root == NULL){
        return 0;
    }
    int rh = height(root->left);
    int lh = height(root->right);

    int d = rh + lh +1;
    //cout<<d<<"\n";
    if(rh == 0 || lh == 0){
        d++;
    }

    return findMax(d, diameter(root->left), diameter(root->right));
}

int main(){
    // node* root = new node(10);
    // root->left = new node(20);
    // root->right = new node(30);
    // root->right->left = new node(40);
    // root->right->left->left = new node(60);
    // root->right->right = new node(50);


    node* root = new node(10);
    root->right = new node(90);
    root->left = new node(20);
    root->left->left = new node(30);
    root->left->left->right = new node(50);
    root->left->left->left = new node(40);
    root->left->left->left->left = new node(60);
    root->left->right = new node(20);
    root->left->right->right = new node(20);
    root->left->right->right->right = new node(20);
    
    cout<<diameter(root)<<"\n";
    //cout<<height(root)<<"\n";

    return 0;
}