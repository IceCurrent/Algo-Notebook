#include<iostream>
#include<vector>
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

// A NAIVE APPROACH: to this problem is: we store the inorder traversal in the array
// and any one of postorder, preorder traversal in the array. But this solution requires
// two traversals of the array. 

// OPTIMISED APPROACH: we can make an array with only one traversal of the binary tree,
// We can use any standard traversal (like, pre/in/post/level order). And the key is to just
// use a NULL marker (say the value -1) to fill the null value places in the array

// SERIALIZATION: We convert a binary tree into an array such that when needed we can convert it back
void serialize(node* root, vector<int> &arr){
    // arr stores our serialized array

    // in general the serialized array is goin' to have a size of 2n+1 where no is the 
    // the number of nodes in the tree. (n+1 entries would be -1)

    // I would be doing this in the preoder fashion
    if(root == NULL){
        arr.push_back(-1);
        return;
    }
    arr.push_back(root->key);
    serialize(root->left, arr);
    serialize(root->right, arr);

    return;

    //TIME COMPLEXITY: O(n) 
}

// DESERIALIZATION: Converting the serialized array back to the original binary tree

int idx = 0;

node* deserialize(vector<int> &arr){
    //arr needs to be deserialized

    if(idx == arr.size()){
        return NULL;
    }
    
    if(arr[idx] == -1){
        idx++;
        return NULL;
    }


    node* root = new node(arr[idx]);
    idx++;
    root->left = deserialize(arr);
    root->right = deserialize(arr);

    return root;
    //TIME COMPLEXITY: O(n)
}



int main(){
    node* root = new node(10);
    root->right = new node(30);
    root->left = new node(20);
    root->left->left = new node(40);
    root->left->right = new node(50);

    vector<int> serArr;
    serialize(root, serArr);

    // for(int i=0; i<serArr.size(); i++){
    //     cout<<serArr[i]<<" ";
    // }
    // cout<<"\n";

    node* r = deserialize(serArr);
    

    cout<<r->key<<"\n"; 
    cout<<r->left->key<<"\n";
    cout<<r->right->key<<"\n";
    cout<<r->left->left->key<<"\n";
    cout<<r->left->right->key<<"\n";

    return 0;
}