#include<iostream>
#include<vector>
using namespace std;

//DP Solution

//tb[i][j] represents no. of ways for first i coins and j sum

int dp(int coins[], int sum, int n){
    int tb[n+1][sum+1];

    for(int i=0; i<=n; i++){
        tb[i][0] = 1;
    }

    for(int j=1; j<=sum; j++){
        tb[0][j] = 0;
    }

    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=sum; j++){
    //         cout<<tb[i][j]<<" ";
    //     }
    //     cout<<endl; 
    // }



    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){

            if(coins[i-1] > j){
                tb[i][j] = tb[i-1][j];
            }
            else{
                tb[i][j] = tb[i][j-coins[i-1]] + tb[i-1][j];
            }

        }
    }

    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=sum; j++){
    //         cout<<tb[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return tb[n][sum];
}

int main(){
    int n, x;
    cin>>n>>x;

    int coins[n];
    
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }

    // for(int i=0; i<n; i++){
    //     cout<<coins[i]<<" ";
    // }
    // cout<<endl;

   cout<<dp(coins, x, n)<<endl;

    return 0;
}