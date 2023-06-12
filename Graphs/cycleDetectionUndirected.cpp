#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool isCycleDfs(vector<vector<int> > adj, int src, int parent, vector<bool> &vis){
    vis[src] = true;

    for(int i=0; i<adj[src].size(); i++){
        if(!vis[adj[src][i]]){
            vis[adj[src][i]] = true;

            //at each vertex we go to one of it's unvisited children and ask
            //whether you detect a cycle or not
            if(isCycleDfs(adj, adj[src][i], src, vis)){
                return true;
            }
        }
        else{
            if(adj[src][i] != parent){
                return true;
            }
        }
    }

    return false;
}

bool cycleDetect(vector<vector<int> > adj, int n){
    vector<bool> vis(n, false);
    for(int i=0; i<n; i++){
        if(!vis[i]){
            if(isCycleDfs(adj, 0, -1, vis)){
                return true;
            }
        }
    }
    return false;
}

int main(){

    int n, m;
    cin>>n>>m;

    vector<int> v(0);
    vector<vector<int> > adj(n, v);

    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout<<cycleDetect(adj, n)<<endl;
    return 0;
}