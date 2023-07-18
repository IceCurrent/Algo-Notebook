#include<iostream>
#include<queue>
using namespace std;


// NOTE THAT THIS IS A BIT INCOMPLETE, I HAVE NO FUCKING CLUE
// OF WHAT IT IS
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

// we have to convert a binary tree to a DLL, without using extra memory. That is, use
// the space allocated for binary tree to convert it to a DLL. We can have the left pointer
// of the tree to become the prev pointer of the DLL, and the right pointer to be next ptr

//and the order of elements in the DLL should be the Inorder traversal of the Binary Tree

node* previous = nullptr;


node* treeToDLL(node* root){
    if(root == NULL){
        return root;
    }

    node * head = treeToDLL(root->left);
    if(previous == NULL){
        head = root;
    }

    else{
        root->left = previous;
        previous->right = root;
    }

    previous = root;
    treeToDLL(root->right);
    return head;

}

int main(){
    node* root = new node(10);
    root->left = new node(20);
    root->left->left = new node(40);
    root->left->left->left = new node(80);
    root->right = new node(30);
    root->right->left = new node(20);
    root->right->right = new node(90);

    treeToDLL(root);
    return 0;
}