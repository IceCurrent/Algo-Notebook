#include<iostream>
#include<stack>
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

// TIME COMPLEXITY: O(n);
// AUXILLARY SPACE: O(h);
void iterInorderTraversal(node* root){
    stack<node*> st;
    node* r = root;

    while(!st.empty() || r != NULL){
        while(r != NULL){
            st.push(r);
            r = r->left;
        }
        r = st.top();
        st.pop();
        cout<<r->key<<" ";

        r = r->right;
    }
        
    cout<<"\n";
    
}

int main(){ 
    node* root = new node(10);
    root->right = new node(30);
    root->left = new node(20);
    root->left->left = new node(40);
    root->left->right = new node(50);

    iterInorderTraversal(root);
    return 0;
}