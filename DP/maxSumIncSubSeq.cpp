#include<iostream>
#include<vector>
using namespace std;


int solve(vector<int> v){
    vector<int> msis;

    msis.push_back(v[0]);

    
    for(int i=1; i<v.size(); i++){
        int x = 0;
        for(int j=0; j<i; j++){
            if(v[j] < v[i]){
                x = max(x, v[i]+msis[j]);
            }
        }
        msis.push_back(x);
    }    
    

    int maxSum = -1;
    for(int i: msis){
        maxSum = max(maxSum, i);
    }
    return maxSum;
}

int main(){
    vector<int> v = {2, 4, 74, 83, 9};

    cout<<solve(v)<<endl;

    // vector<int> b = {1};
    // vector<int>:: iterator i;
    // i = upper_bound(b.begin(), b.end(), 4);

    // cout<<i-b.end()<<endl;
    // cout<<(b.begin()-i)<<endl;

    return 0;
}
