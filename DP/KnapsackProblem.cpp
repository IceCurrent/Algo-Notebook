#include<iostream>
#include<vector>
using namespace std;

//0-1 Knapsack Problem
//to find = max Profit!


int maxProfit(vector<int> profits, vector<int> weights, int W, int N){

    //base case
    if(W <= 0 || N<=0){
        return 0;
    }

    int w = weights[N-1];
    weights.pop_back();

    int p = profits[N-1];
    profits.pop_back();

    int not_inc = maxProfit(profits, weights, W, N-1);

    int inc = 0;
    if(w <=  W){
        inc = maxProfit(profits, weights, W-w, N-1) + p;
    }
    

    return max(inc, not_inc);
}

int main(){

    int N = 4, W = 20;
    vector<int> profits = {10, 2, 1, 3};
    vector<int> weights = {10, 5, 10, 10};

    cout<<maxProfit(profits, weights, W, N)<<endl;
    


    return 0;
}