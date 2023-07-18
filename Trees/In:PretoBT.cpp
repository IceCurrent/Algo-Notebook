#include<iostream>
#include<queue>
#define vi vector<int>
using namespace std;

struct node{
    int key;
    node* right;
    node* left;

    node(int k){
        key = k;
        left = NULL;
        right = NULL;
    }
};
int n;
int preIndex = 0;
vi pre, in;


// TIME COMPLEXITY: O(n);
node* inPreToBT(int ins, int ine){

    if(ins > ine){
        return NULL;
    }
    

    node* root = new node(pre[preIndex]);

    int inInd;
    for(int i=ins; i<=ine; i++){
        if(root->key == in[i]){
            inInd = i;
            break;
        }
    }

    preIndex++;
    root->left = inPreToBT(ins, inInd-1);
    root->right = inPreToBT(inInd+1, ine);

    return root;
}

void bfsLineByLine(node* root){
    if(root == NULL){
        return;
    }

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        int count = q.size();

        for(int i=0; i<count; i++){
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
        cout<<"\n";
    }
}

int main(){
    
    cin>>n;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;

        in.push_back(x);
    }

    for(int i=0; i<n; i++){
        int x;
        cin>>x;

        pre.push_back(x);
    }

    
    node* root = inPreToBT(0, n-1);

    bfsLineByLine(root);
    return 0;
}