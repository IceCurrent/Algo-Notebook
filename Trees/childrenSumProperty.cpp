#include<iostream>
#include<queue>
using namespace std;

struct node{
    int key;
    node* right;
    node* left;

    node(int k){
        key = k;
    }
};

bool HasChildrenSumProperty(node* root){
    if(root == NULL){
        return true;
    }
     
    if(root->left == NULL && root->right == NULL){
        return true;
    }

    if(root->left == NULL){
        return root->key == root->right->key;
    }
    else if(root->right == NULL){
        return root->key == root->left->key;
    }

    if(HasChildrenSumProperty(root->left) && HasChildrenSumProperty(root->right)){
        return root->key == root->left->key + root->right->key;
    }
    else{
        return false;
    }
}

int main(){
    node* root = new node(20); 
    root->left = new node(8);
    root->right = new node(12);
    root->left->left = new node(3 );
    root->left->right = new node(5);

    if(HasChildrenSumProperty(root)){
        cout<<"YES"<<"\n";
    }
    else{
        cout<<"NO"<<"\n";
    }

    return 0;
}