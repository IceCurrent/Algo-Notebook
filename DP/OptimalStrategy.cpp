#include<iostream>
#include<vector>
using namespace std;  


int recSolve1(int c[], int i, int j, int sum){
    if(j == i+1){
        return max(c[i], c[j]);
    }

    return max(sum - recSolve1(c, i+1, j, sum-c[i]), sum - recSolve1(c, i, j-1, sum-c[j]));
}

int recSolve2(int c[], int i, int j){

    //better solution as it requires less space
    //our dp solution will be based upon this
    if(j == i+1){
        return max(c[i], c[j]);
    }

    return max(c[i] + min(recSolve2(c, i+1, j-1), recSolve2(c, i+2, j)), c[j] + min(recSolve2(c, i+1, j-1), recSolve2(c, i, j-2)));
}


int dpSolve(int c[], int n){
    int tb[n][n];

    //firstly we fill base case values when j is i+1;
    for(int i=0; i<n-1; i++){
        tb[i][i+1] = max(c[i], c[i+1]);
    }

    for(int gap =3; gap <n; gap+=2){

        for(int i=0; i+gap<n; i++){
            int j = i+gap;

            tb[i][j] = max(c[i] + min(tb[i+2][j], tb[i+1][j-1]), c[j] + min(tb[i+1][j-1], tb[i][j-2]));
            
        }

    }
    
    return tb[0][n-1];
}

int main(){

    int coins[4] = {20, 5, 4, 6};
    int sum = 0;
    for(int i=0; i<4; i++){
        sum += coins[i];
    }

    cout<<recSolve1(coins, 0, 3, sum)<<endl;
    cout<<recSolve2(coins, 0, 3)<<endl;
    cout<<dpSolve(coins, 4)<<endl;




    return 0;
}