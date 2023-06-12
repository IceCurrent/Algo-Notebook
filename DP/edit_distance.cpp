#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

// INSERT, REPLACE, DELETE
// to find the min number of operations to make the string same

int findMin(int a, int b, int c){
    if(a<min(b, c)){
        return a;
    }
    else{
        return min(b, c);
    }
}


//Naive Recursion Solution
int rec(string s1, string s2, int m, int n){

    if(m==0){
        return n;
    } 

    if (n==0){
        return m; 
    }

    if(s1[m-1] == s2[n-1]){

        return rec(s1, s2, m-1, n-1);

    }
    else{
        int insert = rec(s1, s2, m, n-1);
        int replace = rec(s1, s2, m-1, n-1);
        int dele = rec(s1, s2, m-1, n);

        return 1 + findMin(insert, dele, replace);
    }

}

//DP based solution
int dp(string s1, string s2, int m, int n){
    int tb[m+1][n+1];

    for(int i=0; i<=m; i++){
        tb[i][0] = i;
    }

    for(int i=0; i<=n; i++){
        tb[0][i] = i;
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s1[i-1] == s2[j-1]){
                tb [i][j] = tb[i-1][j-1];
            }
            else{
                tb[i][j] = 1 + findMin(tb[i-1][j-1], tb[i][j-1], tb[i-1][j]);
            }
        }
    }

    return tb[m][n];
}

int main(){
    string s1 = "SUNDAY", s2 = "SATURDAY";

    int m = s1.length(), n = s2.length();

    cout<<rec(s1, s2, m, n)<<endl;
    cout<<dp(s1, s2, m, n)<<endl;

    return 0;
}