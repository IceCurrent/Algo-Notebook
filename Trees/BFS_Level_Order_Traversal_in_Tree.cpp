#include<iostream>
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

    return max(1 + height(root->left), 1 + height(root->right));
}

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

//TIME COMPLEXITY: O((n+h)*n)
void LevelOrder(node* root){

    int k = height(root);

    for(int i=0; i<=k; i++){
        kDistNodes(root, i);
    }

    return;
} 


//TIME COMPLEXITY: O(n)
//Auxillary Space : O(w) {where w: width of the binary tree}
//[which is O(n) in the worst case]
//We use here queue data structure (no recursion in bfs, just like graphs )
void LevelOrderEfficient(node* root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* u = q.front();
        q.pop();

        cout<<u->key<<" ";

        if(u->left != NULL){
            q.push(u->left);
        }

        if(u->right != NULL){
            q.push(u->right);
        }   
    } 

    return;
}

int main(){
    node* root;

    root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(8);
    root->left->right = new node(7);
    root->left->right->left = new node(9);
    root->left->right->right = new node(15);
    root->right->right = new node(6);
    

    //But this is Obviously inefficient
    LevelOrder(root);
    cout<<"\n"; 


    //This is the efficient one inspired directly from bfs 
    //traversal in graphs
    LevelOrderEfficient(root);
    cout<<"\n";
    

    return 0;
}