#include<iostream>
#include<queue>
using namespace std;

struct node{
    int key;
    node* left;
    node* right;

    node(int k){
        key = k;
        right = NULL;
        left = NULL;
    }
};
// to find the max nodes on the level which has the maximum number of nodes

//TIME COMPLEXITY: O(N);
int maxWidth(node* root){
    if(root == nullptr){
        return 0;
    }
    queue<node*> q;
    q.push(root);
    int wid = 0;
    while(!q.empty()){
        int count = q.size();
        wid = max(wid, count);
        for(int i=0; i<count; i++){
            node* u = q.front();
            q.pop();

            //cout<<u->key<<" ";

            if(u->left != NULL){
                q.push(u->left);
            }

            if(u->right != NULL){
                q.push(u->right);
            }

        }
        
    }
    return wid;
}


int main(){
    node* root = new node(10);
    root->left = new node(20);
    root->left->left = new node(40);
    root->left->left->left = new node(80);
    root->right = new node(30);
    root->right->left = new node(20);
    root->right->right = new node(90);


    cout<<maxWidth(root)<<"\n";
    return 0;
}