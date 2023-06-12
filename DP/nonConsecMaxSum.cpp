#include<iostream>
#include<vector>
using namespace std;

int solve(int arr[], int n){

    if(n == 0){
        return 0;
    }
    if(n == 1){
        return arr[0];
    }
    if(n == 2){
        return max(arr[0], arr[1]);
    }


    return max(arr[0] + solve(arr+2, n-2), arr[1] + solve(arr+3, n-3));
}

int dpSolve(int arr[], int n){
    int tb[n+1];

    tb[0] = 0;
    tb[1] = arr[0];
    tb[2] = max(arr[0], arr[1]);

    for(int i=3; i<=n; i++){
        tb[i] = max(tb[i-2]+arr[i-1], tb[i-1]);
    }

    return tb[n];
}

int main(){
 
    // int n = 6;
    // int arr[] = {10, 5, 15, 20, 2, 30};

    // int n = 4;
    // int arr[] = {8, 7, 6, 10};

    int n = 3;
    int arr[] = {1, 10, 2};


    
    cout<<solve(arr, n)<<endl;
    cout<<dpSolve(arr, n)<<endl;

    return 0;
}