#include<iostream>
#include<vector>
#include<queue>
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

int height(node* root){
    if(root == NULL){
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
}


// If we take a closer look at the problem then we'll find that 
// we just need to find the farthest node from the given leaf

// we can optimise it further and make it not use the height function
// Will do the optimisation later. 
int res = 0;
int timeToBurn(node* root, int leaf){
    if(root == NULL){
        return 0;
    }

    if(root->key == leaf){
        return 1;
    }
    //cout<<root->key<<"\n";
    int l = timeToBurn(root->left, leaf);
    int r = timeToBurn(root->right, leaf);


    if(l){
        res = max(res, l + height(root->right));
    }
    else if(r){
        res = max(res, r + height(root->left));
    }

    //cout<<"l = "<<l<<"  r = "<<r<<"  res = "<<res<<"\n";
    if(r == 0 && l== 0){
        return 0;
    }

    if(r && l){
        cout<<"Throw error"<<"\n";
    }

    return 1 + max(l, r);
}

int main(){
    node* root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->right->left = new node(50);
    root->right->right = new node(60);

    timeToBurn(root, 40);

    if(res == 0){
        cout<<-1<<"\n";
    }
    else{
        cout<<res+1<<"\n";
    }


    //cout<<height(root)<<"\n";

    return 0;
}