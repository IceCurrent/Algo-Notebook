/* Header Files */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include<unordered_map>
#include<unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <climits>
using namespace std;

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define fo(i,n) for(int i=0;i<n;i++)
#define F first
#define S second
#define pb push_back

//for debugging (#converts the variable name into string literal)
#define deb(x) cout<<#x<<"="<<x<<endl

typedef unordered_set<int> usi;
typedef unordered_set<ll> usl;
typedef unordered_set <string> uss;
typedef pair<int,int> pii;
typedef pair<ll,ll> pl;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<string> vs;

int n, m;
const int mxN = 1e5+2;
vector<pair<ll, int> > adj[mxN];
ll dist[mxN];
//bool vis[mxN];

void dijkstra(int src){
    memset(dist, 0x3f, sizeof(dist));
    //memset(vis, false, sizeof(mxN));
    dist[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
    // the pairs inside pq are: <cost, vertex>
    // and since we have used minHeap here, it would be according to the cost value
    pq.push({0, 0});

    while(!pq.empty()){
        pair<ll, int> u = pq.top();
        pq.pop();

        //vis[u.S] = true;


        // I don't understand this optimization
        // But this is an extremely important optimization in 
        // Dijkstra's algorithm
        if(u.F > dist[u.S]){
            continue;
        }

        for(int i=0; (size_t)i<adj[u.S].size(); i++){

            ll edgecost = adj[u.S][i].F;
            int v = adj[u.S][i].S;


            if(dist[v] > dist[u.S] + edgecost){
                dist[v] = dist[u.S] + edgecost;
                pq.push({dist[v], v});
            }
        }
    }

}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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
}

