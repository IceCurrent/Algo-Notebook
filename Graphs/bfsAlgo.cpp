#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void bfs(vector<vector<int> > adjL, int src, vector<bool>& vis){
    //we have a connected graph and we are given a source, and we just 
    //have to traverse through all the nodes

    queue<int> q;
    q.push(src);
    vis[src] = true;

    while(!q.empty()){
        int u = q.front();
        cout<<u<<" ";
        q.pop();

        for(int i=0; i<adjL[u].size(); i++){
            if(!vis[adjL[u][i]]){
                vis[adjL[u][i]] = true;
                q.push(adjL[u][i]);
            }
        }
    } 
    
    return;
}

void bfs2(vector<vector<int> > adjL, vector<bool>& vis){
    //Here we aren't given any source and the graph might be possibly disconnected 

    for(int i=1; i<vis.size(); i++){
        if(!vis[i]){
            bfs(adjL, i, vis);
        }
    }

}

int connectedComponents(vector<vector<int> > adjL, vector<bool>& vis){
    int ans = 0;
    for(int i=1; i<vis.size(); i++){
        if(!vis[i]){
            bfs(adjL, i, vis);
            ans++;
        }
    }
    return ans;
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
    
    //bfs2(adjL, vis);

    //cout<<endl;

    cout<<connectedComponents(adjL, vis)<<endl;

    return 0;
}