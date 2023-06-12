#include<iostream>
#include<vector>
using namespace std;

int maximum(int a, int b, int c){
    if(a > max(b, c)){
        return a;
    }

    else{
        return max(b, c);
    }
}

int solve(int n, int a, int b, int c){

    if(n < 0){
        return -1;
    }
    else if(n == 0){
        return 0;
    }

    int res =  maximum(solve(n-a, a, b, c), solve(n-b, a, b, c), solve(n-c, a, b, c));

    if(res == -1){
        return res;
    }
    else{
        return res + 1; 
    }
}

int dp_solve_opt(int n, int a, int b, int c){
    vector<int> tb(n+1);
    tb[0] = 0;

    for(int i=1; i<n+1; i++){
        tb[i] = -1;

        if(i-a >= 0){
            tb[i] = max(tb[i], tb[i-a]);
        }

        if(i-b >= 0){
            tb[i] = max(tb[i], tb[i-b]);
        }

        if(i-c >= 0){
            tb[i] = max(tb[i], tb[i-c]);
        }

        if(tb[i] != -1){
            tb[i]++;
        }
    }

    return tb[n];
}

int dp_solve(int n, int a, int b, int c){

    vector<int> tb(n+1);
    tb.push_back(0);

    vector<int> v = {a, b, c};
    sort(v.begin(), v.end());

    a = v[0];
    b = v[1];
    c = v[2];

    for(int i=1; i<n+1; i++){
        for(int j=0; j<i; j++){
            if(i < a){
                tb[i] = -1;
            }

            else if(i < b){
                if(tb[i-a] != -1){
                    tb[i] = 1 + tb[i-a];
                }
                else{
                    tb[i] = -1;
                } 
            }

            else if(i < c){
                int s = max(tb[i-a], tb[i-b]);

                if(s != -1){
                    tb[i] = 1+ s;
                }
                else{
                    tb[i] = -1;
                }
            }

            else{
                int s = maximum(tb[i-a], tb[i-b], tb[i-c]);

                if(s != -1){
                    tb[i] = 1 + s;
                }
                else{
                    tb[i] = -1;
                }
            }
        }
    }
    return tb[n];
}

int main(){
    int n = 5, a = 1, b = 2, c = 3;

    cout<<solve(n, a, b, c)<<endl;
    cout<<dp_solve(n, a, b, c)<<endl;
    cout<<dp_solve_opt(n, a, b, c)<<endl;
    
    return 0;
}