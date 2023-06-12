#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

// MAXIMUM LENGTH BITONIC SUBSEQUENCE
// BITONIC: a squence which is first increasing and then decreasing

void lis_calc(vector<int> v, vector<int>& lis, int k){

    if(k == v.size()){
        return;
    }

    int maxLis = -1;
    for(int i=0; i<lis.size(); i++){
        if(v[i] < v[k]){
            maxLis = max(maxLis, 1+lis[i]);
        }
    }

    lis.push_back(maxLis);

    return lis_calc(v, lis, ++k);
}

int lis_size(vector<int> v){
    vector<int> lis;
    lis.push_back(1);

    lis_calc(v, lis, 1);

    int ans = -1;

    for(int i : lis){
        if(ans < i){
            ans = i;
        }
    }

    return ans;
    
}

vector<int> slice(vector<int> v, int x, int y){

    
    vector<int> :: iterator s = v.begin();
    vector<int> :: iterator e = v.begin();

    s += x;
    e += y;

    vector<int> ans ;
    ans.assign(s, e);

    return ans;

}

vector<int> rev(vector<int> v){
    reverse(v.begin(), v.end());

    return v;
    
}


int solve(vector<int> v){
    
    int ans = 1;
    for(int i=1; i<v.size(); i++){

        int a = lis_size(slice(v, 0, i));
        int b = lis_size(rev(slice(v, i, v.size())));

        //cout<<a<<" "<<b<<endl;

        ans = max(ans, a+b);

    }

    return ans;
    
}

int main(){
    vector<int> v = {12, 11, 40, 5, 3, 1};

    cout<<solve(v)<<endl;

    return 0;
}