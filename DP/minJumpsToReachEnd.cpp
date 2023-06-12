#include<iostream>
#include<vector>
using namespace std;


int recSolve(vector<int> v, int n, int k = 0){

    if(k == n-1){
        return 0;
    }

    int minJ = INT_MAX;
    for(int i=1; i<v[k]+1; i++){
        if(k + i < n){
            minJ = min(minJ, 1 + recSolve(v, n, k+i));
        }
    }

    return minJ;
}

int dpSolve(vector<int> v, int n){
    vector<int> tb(n);
    tb[0] = 0;

    for(int i=1; i<n; i++){
        tb[i] = INT_MAX;
        for(int j=0; j<i; j++){
            if(v[j] >= i-j){
                tb[i] = min(tb[i], tb[j]);
            }
        }

        if(tb[i] != INT_MAX){
            tb[i]++;
        }

    }

    return tb[n-1];
}
int main(){
    vector<int> v = {3, 4, 2, 1, 2, 1};
   // v = {4, 1, 5, 3, 1, 3, 2, 1, 8};

    cout<<recSolve(v, v.size())<<endl;
    cout<<dpSolve(v, v.size())<<endl;

    return 0;
}