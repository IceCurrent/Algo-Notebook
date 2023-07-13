#include<iostream>
using namespace std;

//SIMPLE SYNTACTIC REPRESENTATION
/*
    node* root;
    (*(root)).key = 3 can be written simply as root->key = 3;
*/

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

//TIME COMPLEXITY: O(n) -> n: number of nodes
//SPACE COMPLEXITY: O(h) -> h: height of tree

void Inorder(node* root){

    if(root == NULL){
        return;
    }

    Inorder(root->left);
    cout<<root->key<<" ";
    Inorder(root->right);

    return;
}

void PreOrder(node *root){
    if(root == NULL){
        return;
    }

    cout<<root->key<<" ";
    PreOrder(root->left);
    PreOrder(root->right);

    return;
}

void PostOrder(node *root){
    if(root == NULL){
        return;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->key<<" ";

    return;
}


int main(){
    node* root;

    root = new node(3);
    root->left = new node(4);
    root->right = new node(7);
    root->left->left = new node(5);
    root->left->left->right = new node (9);
    root->right->right = new node(19);
    root->left->left->left = new node(34);

    Inorder(root);
    cout<<"\n";

    PreOrder(root);
    cout<<"\n";

    PostOrder(root);
    cout<<"\n";
    return 0;
}