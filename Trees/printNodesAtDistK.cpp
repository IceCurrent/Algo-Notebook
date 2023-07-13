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

void kDistNodes(node* root, int k){

    if(root == NULL){
        return;
    }
    if(k == 0){
        cout<<root->key<<" ";
        return;
    }

    kDistNodes(root->left, k-1);
    kDistNodes(root->right, k-1);

    return;
}

int main(){
    node* root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(50);
    root->right->right = new node(70);

    kDistNodes(root, 2);
    cout<<"\n";

    return 0;
}