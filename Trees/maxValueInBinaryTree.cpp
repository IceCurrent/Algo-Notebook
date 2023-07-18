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

int findMax(int a, int b, int c){
    if(a > max(b, c)){
        return a;
    }
    else{
        return max(b, c);
    }
}

int maxVal(node* root){
    if(root == NULL){
        return INT_MIN;
    }

    return findMax(root->key, maxVal(root->left), maxVal(root->right));
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

    cout<<maxVal(root)<<"\n";
    return 0;
}