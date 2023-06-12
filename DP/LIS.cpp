#include<iostream>
#include<vector>
#include<deque>
using namespace std;
 
void dp(vector<int> v, int k, vector<int>& lis, int maxLis = 0){
    
    if(k == v.size()){
        return;
    }

    for(int i=0; i<lis.size(); i++){
        if(v[k] > v[i]){
            maxLis = max(maxLis, lis[i]);
        }
    }

    lis.push_back(1+maxLis);
    return dp(v, ++k, lis); 
}

int main(){
    vector<int> v = {2, 6, 4, 3, 5, 7, 8, 1};

    vector<int> lis;
    lis.push_back(1);

    dp(v, 1, lis);

    int ans = -1;

    for(int i: lis){
        ans = max(ans, i);
    }

    cout<<ans<<endl;

    return 0;
}