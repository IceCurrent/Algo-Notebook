#include<iostream>
#include<vector>
#include<queue>

#define F first
#define S second
using namespace std;



int n, m; 
const int mxN = 1e5+3;
vector<pair<int, int> > adj[mxN];
int dist[mxN];
//bool finalised[mxN];

void dijkstra(int src){
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({0, 0});
    
    memset(dist, 0x3f, sizeof(dist)); //0x3f is a way to initialise all the elements of the array to 
                                    // infinity using memset operation. Because memset assigns each byte

    dist[0] = 0;
    //memset(finalised, false, sizeof(finalised));

    while(!pq.empty()){
        pair<int, int> u = pq.top();
        pq.pop();



        //finalised[u.S] = true;

        // most important optimisation in Dijkstra
        // enables us to not use the finalised array

        if(u.F > dist[u.S]){
            continue;
        }

        for(int i=0; i<adj[u.S].size(); i++){
            int edgecost = adj[u.S][i].F;
            int v = adj[u.S][i].S;


            if(dist[v] > dist[u.S] + edgecost){
                dist[v] = dist[u.S] + edgecost;
                pq.push({dist[v], v});
            }   
        }
    }
}

int main(){
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w, --u, --v;

        adj[u].push_back({w, v});
    }
    
    dijkstra(0);

    for(int i=0; i<n; i++){
        cout<<dist[i]<<" ";
    }
    cout<<"\n";
    
    return 0;
}