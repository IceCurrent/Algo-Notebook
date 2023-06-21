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


//remove consecutive duplicate elements from the vector
#define uniq(v) v.erase(unique(all(v)),v.end())


//for debugging (#converts the variable name into string literal)
#define deb(x) cout<<#x<<"="<<x<<endl



#define PI 3.1415926535897932384626433832795l 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

// ----------------------</BITWISE>-------------------------- 
/* a=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a,b) ((a) |= (1ULL<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))

// '!!' to make sure this returns 0 or 1
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b))))

#define BITMASK_SET(x, mask) ((x) |= (mask))
#define BITMASK_CLEAR(x, mask) ((x) &= (~(mask)))
#define BITMASK_FLIP(x, mask) ((x) ^= (mask))
#define BITMASK_CHECK_ALL(x, mask) (!(~(x) & (mask)))
#define BITMASK_CHECK_ANY(x, mask) ((x) & (mask))
// ----------------------</BITWISE END>--------------------------

// ----------------------</MATH>---------------------------------
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);} 

template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));} 

int mul(int a, int b, int c = MOD){ll res=(ll)a*b;
                         return(res>=c?res%c:res);}


//simple exponentiation
template<typename T>T expo(T e, T n){T x=1,p=e;while(n)
                         {if(n&1)x=x*p;p=p*p;n>>=1;}return x;} 

//exponentiation but the result is kept in bounds of MOD
template<typename T>T power(T e, T n, T m = MOD){T x=1,p=e;while(n)
                      {if(n&1)x=mul(x,p,m);p=mul(p,p,m);n>>=1;}return x;} 


template <class T> T absmax(T a, T b)
{return (abs(a)>abs(b)) ? a : b ;}

/****************** Prime Generator **********************/ 

//generate prime numbers till a
const int N=1e7+10; int prime[20000010]; 
bool isprime[N]; int nprime; 
template <typename T> void Sieve(T a) 
{nprime = 0;memset(isprime,true,sizeof(isprime));
isprime[1]=false;for(int i=2;i<N;i++){
if(isprime[i]){prime[nprime++]=i;for(int j=2;i*j<N;j++)
isprime[i*j]=false;}}}


//returns the number of prime factors of n
template <typename T> inline T PrimeFactors(T n)
{ll cnt=0,sum=1;for(int i=0; prime[i]*prime[i]<=n 
and i<nprime;i++){cnt=0;while(n%prime[i]==0)
{cnt++;n/=prime[i];}sum*=(cnt+1);}
if(n>1)sum*=2;return sum;} 
/****************** Prime Generator End **********************/ 

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

int k = 1;

void dfs(vector<vi> &adj, int src, int n, vi &disc, vb &vis, vi &low, vb &onStack, stack<int> &st){
    vis[src] = true;
    disc[src] = k;
    low[src] = k;
    onStack[src] = true;

    st.push(src);
    k++;


    for(int i=0; i<adj[src].size(); i++){

        if(onStack[adj[src][i]] && vis[adj[src][i]]){
            //and that's a back-edge 
            low[src] = min(low[src], disc[adj[src][i]]);
        }
        else if(!onStack[adj[src][i]] && vis[adj[src][i]]){
            //and that's a cross-edge
            //therefore we do not do anything
            continue;
        }

        if(!vis[adj[src][i]]){
            vis[adj[src][i]] = true;
            dfs(adj, adj[src][i], n, disc, vis, low, onStack, st);
            low[src] = min(low[src], low[adj[src][i]]);
        }
        
    }

    if(low[src] == disc[src]){
         while(st.top() != src){
            cout<<st.top()<<" ";
            st.pop();

            onStack[st.top()] = false;
        }
        cout<<st.top()<<"\n";
        onStack[st.top()] = false;
        st.pop(); 
    }

}

void SCCs(vector<vi> &adj, int n){
    vi disc(n+1, 0); 
    vi low(n+1, INT_MAX);

    vb vis(n+1, false);
    vb onStack(n+1, false);
    stack<int> st;

    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(adj, 1, n, disc, vis, low, onStack, st);
        }
    }

    // for(int i=1; i<=n; i++){
    //     cout<<disc[i]<<" "; 
    // }
    // cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vi v(0);
    vector<vi> adj(n+1, v);

    fo(i, m){
        int x, y;
        cin>>x>>y;

        adj[x].pb(y);
    }

    cout<<"strongly connected components are: "<<"\n";
    SCCs(adj, n);

    return 0;
}

