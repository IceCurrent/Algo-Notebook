#include<iostream>
#include<queue>
using namespace std;

struct node{
    int key;
    node* right;
    node* left;

    node(int k){
        key = k;
        right = NULL;
        left = NULL;
    }
};

//Complete Binary Tree: A binary tree is called complete if it is completely filled
//except possibly the last level (which is filled from left to right).


// most naive solution, in the history of academia. 
int numNodes(node* root){

    if(root == NULL){
        return 0;
    }

    queue<node*> q;
    q.push(root);
    int ans = 0;

    while(!q.empty()){

        int count = q.size();

        for(int i=0; i<count; i++){
            node* u = q.front();
            q.pop();

            ans++;

            if(u->left != NULL){
                q.push(u->left);
            }

            if(u->right != NULL){
                q.push(u->right);
            }
        }

    }
    return ans;
}


// OPTIMISED APPROACH:
// TIME COMPLEXITY: O(lgo(n)*log(n)) {Finding the time complexity is a good question in itself }

int numNodesOpt(node* root){
    // OK so, if we could find perfect subtrees in our complete binary tree 
    // then we can tell the number of nodes in them easily (2^n -1)
    int rh = 0, lh = 0;

    node* l = root;
    while(l != NULL){
        l = l->left;
        lh++;
    }

    node* r = root;
    while(r != NULL){
        r = r->right;
        rh++;
    }

    //cout<<"lh = "<<lh<<"   "<<"rh = "<<rh<<"\n";

    if(lh == rh){
        //perfect binary tree
        return pow(2, rh)-1;
    }
    
    //not a perfect binary tree
    return 1 + numNodesOpt(root->left) + numNodesOpt(root->right);

}

int main(){
    node* root = new node(10);
    root->right = new node(30);
    root->right->left = new node(31);
    root->right->right = new node(33);

    root->left = new node(20);
    root->left->left = new node(40);
    root->left->right = new node(50);
    root->left->left->left = new node(2);

    cout<<numNodes(root)<<"\n";
    cout<<numNodesOpt(root)<<"\n";
    return 0;
}