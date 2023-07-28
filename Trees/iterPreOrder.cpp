#include<iostream>
#include<stack>
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


// HIGHLY UN-OPTIMISED APPROACH
void iterPreOrder(node* root){
    // root-left-right

    // we have to have a LIFO data structure, basically stack
    node* r = root;
    stack<node*> st;
    queue<node*> q;
    while(!st.empty() || r != NULL){
        while(r != NULL){
            st.push(r);
            q.push(r);
            r = r->left;
        }

        r = st.top();
        st.pop();
        r = r->right;

    }

    while(!q.empty()){
        node* u = q.front();
        q.pop();
        cout<<u->key<<" ";

    }
    cout<<endl;

}

void iterPreOptimised(node* root){
    stack<node*> st;
    node* r = root;
    st.push(root);

    while(!st.empty()){
        r = st.top();
        st.pop();
        cout<<r->key<<" ";

        if(r->right != NULL){
            st.push(r->right);
        }
        
        // We pushed right subtree before left subtree because, stack follows LIFO 
        if(r->left != NULL){
            st.push(r->left);
        }

    }
    cout<<"\n";
    // O(n) time and O(n) extra space for stack
}

// Although the above solution is optimised, but we further reduce the extra space it
// takes into this super optimised solution

void iterPreOrderSuperOptimised(node* root){
    // root-left-right

    // The idea is to only store the right children into the stack. We are going
    // left, left left first, so we can print those nodes along the way, and just use the 
    // stack to store the right children into the stack

    node* r = root;
    stack<node*> st;
    st.push(r);

    while(!st.empty()){
        while(r != NULL){
            cout<<r->key<<" ";
            if(r->right != NULL){
                st.push(r->right);
            }
            r = r->left;
        }
        r = st.top();
        st.pop();
    }
    cout<<"\n";

    // This approach takes O(n) time but only O(h) extra space
}

int main(){
    node* root = new node(10);
    root->right = new node(30);
    root->left = new node(20);
    root->left->left = new node(40);
    root->left->right = new node(50);

    iterPreOrder(root);
    iterPreOptimised(root);
    iterPreOrderSuperOptimised(root);
    return 0;
}