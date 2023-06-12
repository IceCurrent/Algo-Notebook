#include<iostream>
#include<vector>
using namespace std;

//WE HAVE TO COUNT COMBINATIONS HERE!

//Naive Recursive Solution
int countWays(vector<int> coins, int sum){

    if(sum == 0){
        return 1;
    }

    if(coins.empty()){
        return 0;
    }

    int c = coins[coins.size()-1];

    int inc = 0;
    if(c <= sum){
        inc =  countWays(coins, sum-c);
    }
    
    coins.pop_back();
    int not_inc = countWays(coins, sum);
    
    return inc + not_inc;
}


//DP Solution
int countWays_DP(vector<int> coins, int sum){

    if(sum == 0){
        return 1;
    }

    if(coins.empty()){
        return 0;
    }

    int c = coins[coins.size()-1];

    int inc = 0;
    if(c <= sum){
        inc =  countWays(coins, sum-c);
    }
    
    coins.pop_back();
    int not_inc = countWays(coins, sum);
    
    return inc + not_inc;
}


int main(){
    vector<int> coins = {2, 5, 3};
    int sum = 5  ;

    cout<<countWays(coins, sum)<<endl;
      
    return 0;
}