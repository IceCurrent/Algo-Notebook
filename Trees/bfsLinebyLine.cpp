#include<iostream>
#include<queue>
using namespace std;

const int INF = 1000001;

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

// TIME COMPLEXITY: O(n+h) = O(n)  {because h is a lower order term than n}
// Auxillary space : O(w) = O(n)   {w: width of tree, equal to n/2 in worst case}
void bfs(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(q.size() > 1){
        node* u = q.front();
        q.pop();

        if(u == NULL){
            cout<<"\n";
            q.push(NULL);
            continue;
        }
        cout<<u->key<<" ";

        if(u->left != NULL){
            q.push(u->left);
        }

        if(u->right != NULL){
            q.push(u->right);
        }

    }
}

void bfs2(node* root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        int count = q.size();
        for(int i=0; i<count; i++){
            node* u = q.front();
            q.pop();

            if(u->left != NULL){
                q.push(u->left);
            }

            if(u->right != NULL){
                q.push(u->right);
            }

        }
        cout<<"\n";
    }
}


int main(){
    node* root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(50);
    root->right->right = new node(60);
    root->right->right->left = new node(70);
    root->right->right->left = new node(80);

    bfs(root);
    cout<<"\n";

    bfs(root);
    cout<<"\n";
    
    return 0;
}