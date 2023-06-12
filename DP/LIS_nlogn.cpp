#include<iostream>
#include<vector>
using namespace std;

int ceil(vector<int> t, int x){
    
    int start = 0;
    int end = t.size();

    while(start < end){

        if(x <= t[start]){
            return start;
        }

        int mid = (start + end)/2;

        if(x >= t[mid]){
            start = mid+1;
        }
        else{
            end = mid;
        }

    }

    return start;
}

int solve(vector<int> v){
    vector<int> aux;

    aux.push_back(v[0]);

    for(int i=1; i<v.size(); i++){
        if(v[i] >= aux[aux.size()-1]){
            aux.push_back(v[i]);
        }
        else{
            int j = ceil(aux, v[i]);
            //cout<<"j = "<<j<<endl;      
            aux[j] = v[i]; 
            
        }
        
    }

    return aux.size();
}

int main(){
    vector<int> v = {10, 5, 3 };

    cout<<solve(v)<<endl;

    // vector<int> d = {3, 10, 20};
    // cout<<ceil(d, 4)<<endl;

    return 0;
}