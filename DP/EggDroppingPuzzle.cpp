#include<iostream>
#include<vector>
using namespace std;


int solve(int f, int e){

    if(e == 1){
        return f;
    }
    if(f == 1){
        return 1;
    }
    if(f == 0){
        return 0;
    }


    int ans = f+1;
    for(int i=1; i<=f; i++){
        ans = min(ans, max(solve(i-1, e-1), solve(f-i, e)));
    }    

    return ans+1 ;
}


int dpSolve(int f, int e){
    // int tb[e][f+1];

    // for(int i=0; i<e; i++){
    //     tb[i][0] = 0;
    //     tb[i][1] = 1;
    // }

    // for(int i=1; i<=f; i++){ 
    //     tb[1][i] = i;
    // }

    // for(int i=1; i<e; i++){

    //     for(int j=2; j<=f; j++){
            
    //         tb[i][j] = INT_MAX;
    //         for(int k=1; k<=j; k++){
    //             tb[i][j] = min(tb[i][j], max(tb[i][j-k], tb[i-1][k-1]));
    //         } 
    //         tb[i][j] += 1;
    //     }
        
    // }

    // return tb[e-1][f];


    // int tb[f+1][e+1];

    // for(int i=1; i<=e; i++){
    //     tb[0][e] = 0;
    //     tb[1][e] = 1;
    // }

    // for(int i=1; i<=f; i++){
    //     tb[i][1] = i;
    // }

    // for(int i=2; i<=f; i++){
    //     for(int j=2; j<=e; j++){
    //         tb[i][j] = INT_MAX;
    //         for(int k=1; k<=i; k++){
    //             tb[i][j] = min(tb[i][j], 1 + max(tb[i-k][j], tb[k-1][j-1]));
    //         }
    //     }
    // }

    // return tb[f][e];

    int tb[e+1][f+1];

    for(int i=1; i<=e; i++){
        tb[i][0] = 0;
        tb[i][1] = 1;
    }

    for(int i=1; i<=f; i++){
        tb[1][i] = i;
    }

    for(int i=2; i<=e; i++){
        for(int j=2; j<=f; j++){
            tb[i][j] = INT_MAX;

            for(int k=1; k<=j; k++){
                tb[i][j] = min(tb[i][j], 1 + max(tb[i][j-k], tb[i-1][k-1]));
            }
        }
    }

    return tb[e][f]; 
}


int main(){
    int e = 2, f = 10;

    cout<<solve(f, e)<<endl;
    cout<<dpSolve(f, e)<<endl;

    return 0;
}