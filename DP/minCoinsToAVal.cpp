#include<iostream>
#include<vector>
using namespace std;

const int i_max = INT_MAX;

int recSolve(vector<int> coins, int val){

    if(coins.empty() || val < 0) {
        return i_max;
    }
    
    if(val == 0){
        return 0;
    }

    int c = coins[coins.size()-1];

    int inc = recSolve(coins, val-c);
    
    if(inc != i_max){
        inc++;
    }

    coins.pop_back();
    int not_inc = recSolve(coins, val);

    return min(inc, not_inc);

}


int dp_solve(vector<int> coins, int val){
    vector<int> tb(val+1);

    tb[0] = 0;

    for(int i=1; i<val+1; i++){
        tb[i] = i_max;
        for(int j=0; j<coins.size(); j++){
            if(i-coins[j] >=0){
                tb[i] = min(tb[i], tb[i-coins[j]]);
            }
        }
        if(tb[i] != i_max){
            tb[i]++;
        }
    }

    return tb[val];
}

int main(){
    vector<int> coins = {9, 6, 5, 1};
    int val = 11;

    cout<<recSolve(coins, val)<<endl;
    cout<<dp_solve(coins, val)<<endl;

    return 0;
}