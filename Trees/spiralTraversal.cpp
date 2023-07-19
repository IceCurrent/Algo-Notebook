#include<iostream>
#include<queue>
#include<stack>
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

// we use a comination of stack and queue to carry out this traversal
//instead of stack I used deque for more ease

// TIME COMPLEXITY : O(n) {upper bounded by 4n} 
void spiral(node* root){
    queue<node*> q;
    q.push(root);
    deque<node*> dq;

    bool f = true; // if f == true, pop_front else pop_back

    while(!q.empty()){
        int count = q.size();

        for(int i=0; i<count; i++){
            node* u = q.front();
            q.pop();

            //cout<<u->key<<" ";
            dq.push_back(u);

            if(u->left != NULL){
                q.push(u->left);
            }

            if(u->right != NULL){
                q.push(u->right);
            }
        }

        while(!dq.empty()){
            if(f){
                cout<<dq.front()->key<<" ";
                dq.pop_front();
            }
            else{
                cout<<dq.back()->key<<" ";
                dq.pop_back();
            }
        }

        f = !f;
    }
    cout<<"\n";
    return; 
}

// The above solution can be optimised. So that each node goes into a data structure only
// once and comes out of it only once.

// so for that we maintain two stacks (or deques if you wish), right traversing row goes
// into stack 1, and left traversing row goes into stack 2

//TIME COMPLEXITY : O(n) {upper bounded by 2n}
void spiralOpt(node* root){
    stack<node*> lt, rt;
    lt.push(root);
    bool f = true; //left traversing mode on
    while(!lt.empty() || !rt.empty()){
        if(f){

            int cl = lt.size();

            for(int i=0; i<cl; i++){
                node* u = lt.top();
                lt.pop();

                cout<<u->key<<" "; 
                if(u->left != NULL){
                    rt.push(u->left);
                }

                if(u->right != NULL){
                    rt.push(u->right);
                }
            }
            
        }
        else{

            int cr = rt.size();

            for(int i=0; i<cr; i++){
                node* u = rt.top();
                rt.pop();

                cout<<u->key<<" ";
                if(u->right != NULL){
                    lt.push(u->right);
                }

                if(u->left != NULL){
                    lt.push(u->left);
                }
            } 
            
        }

        f = !f;
    }
    cout<<"\n";
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left  = new node(6);
    root->right->right = new node(7);
    root->right->left->left = new node(10);
    root->left->left->left = new node(8);
    root->left->left->right = new node(9);

    spiral(root);
    spiralOpt(root);

    return 0;
}