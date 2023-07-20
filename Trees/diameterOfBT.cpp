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


// Naive Solution 
// TIME COMPLEXITY: O(n^2) 
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

//Optimised Solution
//TIME COMPLEXITY: O(n)

// Here we can pre compute the heights and store it in an unordered map
// but this requires extra space for the map, and an overhead for filling it up with
// values (i.e it's pre-computation)
// int diameterOpt(node* root){
    
// }

// Most optimised solution:
// it has no overhead of maps
// basically here we can find the diameter of the tree while computing the height 
// of at that node, and use a max variable to store the max diameter
// SO BASICALLY HERE WE JUST MODIFY THE HEIGHT FUNCTION

int res = 0;
int height2(node* root){
    if(root==NULL){
        return 0;
    }

    int lh = height2(root->left);
    int rh = height2(root->right);

    res = max(res, rh+lh+1);
    return 1 + max(lh, rh);
    
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
    height2(root);

    cout<<res<<"\n";

    return 0;
}