#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> bfs(vector<vector<int> > adj, int src, vector<bool>& vis){

    vector<int> sol(adj.size());
    queue<int> q;
    q.push(src);
    
    sol[src] = 0;
    vis[src] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int k=0; k<adj[u].size(); k++){
            if(!vis[adj[u][k]]){
                q.push(adj[u][k]);
                sol[adj[u][k]] = sol[u]+1;
                vis[adj[u][k]] = true;    
            }
        }
    }

    return sol;
}

void shortestPath(vector<vector<int> > adj, int src){
    vector<bool> vis (adj.size(), false);
    vector<int> v = bfs(adj, 1, vis);
    
    for(int i=1; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<int> v(0);
    vector<vector<int> > adj(n+1, v);

    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
        
    }

    cout<<"input we recieved "<<endl;

    for(int i=1; i<=n; i++){
        
        cout<<i<<"--> ";
        for(int j=0; j<adj[i].size(); j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

    shortestPath(adj, 1);

    // for(int i: adj[1]){
    //     cout<<i<<" ";
    // }
    // cout<<endl;



    return 0; 
}