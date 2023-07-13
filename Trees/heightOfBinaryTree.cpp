#include<iostream>
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

//TIME COMPLEXITY: O(n) -> n: number of nodes
//SPACE COMPLEXITY: O(h) -> h: height of tree

int height(node* root){
    if(root == NULL){
        return 0;
    }

    return max(1 + height(root->left), 1 + height(root->right));
}


int main(){
    node* root = new node(10);
    root->left = new node(8);
    root->right = new node(30);
    root->right->left = new node(40);
    root->right->right = new node(50);
    root->right->right->left = new node(70);

    cout<<height(root)<<"\n";

    return 0;
}