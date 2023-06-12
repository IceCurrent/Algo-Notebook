#include<iostream>
#include<vector>

using namespace std;

void lis_fill(vector<int> v, int k, vector<int>& lis){

    if(k == v.size()){
        return;
    }
    
    int maxLis = 0;
    for(int i=0; i<lis.size(); i++){
        
        if(v[i] < v[k]){
            maxLis = max(maxLis, lis[i]+1);
        }
    
    }

    lis.push_back(maxLis);
    return lis_fill(v, ++k, lis);

}

int lis_size(vector<int> v){
    vector<int> lis;
    lis.push_back(1);

    lis_fill(v, 1, lis);

    int ans = -1;

    for(int i=0; i<lis.size(); i++){
        ans = max(ans, lis[i]);
    }

    return ans ;
}

int solve(unordered_map<int, int> u){
    vector<int> s;

    for(pair<int, int> i: u){
        s.push_back(i.first);
    }

    sort(s.begin(), s.end());

    vector<int> v;

    for(int i: s){
         
        v.push_back(u[i]);
    }

    

    // for(int i: v){
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    return lis_size(v);
}

int main(){
    //unordered_map<int, int> u = {{8, 1}, {1, 2}, {4, 3}, {3, 4}, {2, 6}, {6, 7}, {7, 8}, {5, 5}};
    unordered_map<int, int> u = {{6, 2}, {4, 3}, {2, 6}, {1, 5}};

    cout<<solve(u)<<endl;
    return 0;
}