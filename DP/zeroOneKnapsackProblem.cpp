#include<iostream>
#include<vector>
using namespace std;


//2 parameter changing, therefore 2D array

int recSolve(vector<int> v, vector<int> w, int cap){

    if(cap == 0 || v.empty()){
        return 0;
    }

    int it = v[v.size()-1];
    int wei = w[w.size()-1];

    v.pop_back();
    w.pop_back();

    int inc = -1;
    if(wei <= cap){
        inc = it + recSolve(v, w, cap-wei);
    }

    int not_inc = recSolve(v, w, cap);

    return max(inc, not_inc);
}

int dpSolve(vector<int> v, vector<int> w, int cap){

    int arr[v.size()+1][cap+1];
    for(int i=0; i<cap+1; i++){
        arr[0][i] = 0;
    }
    for(int i=0; i<v.size()+1; i++){
        arr[i][0] = 0;
    }
    for(int i=1; i<v.size()+1; i++){
        for(int j=1; j<cap+1; j++){
            if(w[i-1] > j){
                arr[i][j] = arr[i-1][j];
            }
            else{
                arr[i][j] = max(arr[i-1][j], v[i-1] + arr[i-1][j-w[i-1]]);
            }
        }
    }
    return arr[v.size()][cap];
}

int main(){
    vector<int> v = {10, 40, 30, 50};
    vector<int> w = {5, 4, 6, 3};
    int cap = 10;

    // v = {60, 100, 120};
    // w = {10, 20, 30};
    // cap = 50;

    cout<<recSolve(v, w, cap)<<endl;
    cout<<dpSolve(v, w, cap)<<endl;

    return 0;
}