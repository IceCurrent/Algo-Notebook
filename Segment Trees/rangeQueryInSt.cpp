#include<iostream>
#include<vector>

#define vi vector<int>
#define pb push_back
using namespace std;

//ss - segment start
//se - segment end 
//si - segment index
int makeSegTree(int arr[], int ss, int se, vi &tree, int si){
    if(ss == se){
        tree[si] = arr[ss];
        return tree[si];
    }

    int mid = (ss+se)/2;
    tree[si] = makeSegTree(arr, ss, mid, tree, 2*si+1)+makeSegTree(arr, mid+1, se, tree, 2*si+2);

    return tree[si];

}

int getSum(int qs, int qe, int ss, int se, int si){
    
}

int main(){
    int arr[] = {10, 20, 30, 40};

    vi tree(4*4, -1);

    makeSegTree(arr, 0, 3 , tree, 0);

    for(int i=0; i<tree.size(); i++){
        cout<<tree[i]<<" ";
    }
    cout<<endl;


    return 0;
}