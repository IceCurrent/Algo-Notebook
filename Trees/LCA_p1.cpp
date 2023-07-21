#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int key;
    node* right;
    node* left;

    node(int k){
        key = k;
        right = NULL;
        left = NULL;
    }

};

// we are given two values and we have to find their lowest common ancestor
// the node can also be an ancestor of itself

// one of the applications of this problem is finding the distance between two nodes
const int mxN = 1e5+2;
int parent[mxN];

int LCA(node* root, int n1, int n2){

    if(root == NULL){
        return -1; 
    }

    if(root->key == n1 || root->key == n2){
        return root->key;
    }

    int l = LCA(root->left, n1, n2);

    if(l != -1){
        parent[l] = root->key;
    }

    int r = LCA(root->right, n1, n2);

    if(r != -1){
        parent[r] = root->key;
    }

    return root->key;
}


// this might look good but here we actually do two traversals of the binary tree
// we can optimise it further to make a solution in which we do only one traversal of
// of the binary tree
int solve(node* root, int n1, int n2){
    LCA(root, n1, n2);

    int p1 = n1;
    int p2 = n2;

    bool vis[mxN];
    memset(vis, false, sizeof(vis));

    while(p1^(root->key) || p2^(root->key)){

        vis[p1] = true;
        vis[p2] = true;

        if(vis[parent[p1]]){
            return parent[p1];
        }

        if(vis[parent[p2]]){
            return parent[p2];
        }

        if(!(p1^p2)){
            return p1;
        }

        p1 = parent[p1];
        p2 = parent[p2];
    }

    return root->key;

}

// and in this function we return the pointer to the LCA
node* LCAopt(node* root, int n1, int n2){
    /* so we do the simple traversal of the tree here
        when we reach a node, we have four possibilities:
        1. either the node is one of the target nodes
        2. the two target nodes are on two different sides of the current node 
        3. the two target nodes are at the same side of the current node
        4. there aren't any target nodes on any of the sides
    */

    if(root == NULL){
        return NULL;
    }

    //case -1 
    if(root->key == n1 || root->key == n2){
        return root;
    }

    //case -2
    node* r = LCAopt(root->right, n1, n2);
    node* l = LCAopt(root->left, n1, n2);

    if(r == NULL && l == NULL){
        return NULL;
    }

    if(r == NULL){
        return l;
    }

    if(l == NULL){
        return r;
    }

    return root;

}


int main(){

    node* root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->right->right = new node(50);
    root->right->left = new node(40);
    root->right->right->left = new node(70);
    root->right->right->right = new node(80);
    root->right->left->left = new node(60);

    // node* root = new node(10);
    // root->right = new node(90);
    // root->left = new node(20);
    // root->left->left = new node(30);
    // root->left->left->right = new node(50);
    // root->left->left->left = new node(40);
    // root->left->left->left->left = new node(60);
    // root->left->right = new node(210);
    // root->left->right->right = new node(120);
    // root->left->right->right->right = new node(1120);

    cout<<solve(root, 70, 60)<<"\n";
    cout<<LCAopt(root, 70, 60)->key<<"\n";

    return 0;
}