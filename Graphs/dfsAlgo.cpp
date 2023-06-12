#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int> > adjL, int src, vector<bool>& vis){
    vis[src] = true;
    cout<<src<<" ";

    for(int i=0; i<adjL[src].size(); i++){
        if(!vis[adjL[src][i]]){
            vis[adjL[src][i]] = true;
            dfs(adjL, adjL[src][i], vis);
        }
    }

    return;
}

void dfs2(vector<vector<int> > adjL, vector<bool>& vis){
    for(int i=1; i<vis.size(); i++){
        if(!vis[i]){
            dfs(adjL, i, vis);
        }
    }
}

int main(){
    int n, m;   
    cin>>n>>m;

    vector<int> v(0);
    vector<vector<int> > adjL(n+1, v);
    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;

        adjL[x].push_back(y);
        adjL[y].push_back(x);
    }

    cout<<"input we recieved: "<<endl;

    for(int i=1; i<n; i++){
        cout<<i<<"--> ";
        for(int j=0; j<adjL[i].size(); j++){
            cout<<adjL[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"output: "<<endl;
    vector<bool> vis(n+1, false);

    dfs(adjL, 1, vis);

    return 0;
}