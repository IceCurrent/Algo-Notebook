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

const int mxN = 1e3+2;
int n, m;

int di[4] = {0, -1, 0, 1};
int dj[4] = {-1, 0, 1, 0};
char dc[4] = {'L', 'U', 'R', 'D'};

//p1, d1 are for the player/survivor
//p2, d2 are for the monsters 
int p1[mxN][mxN], p2[mxN][mxN];
int d1[mxN][mxN], d2[mxN][mxN];


string maze[mxN];

//v1 is for storing player's initial pos
//v2 is for storing the initial pos of all the monsters
vector<pii> v1, v2;
int si = -2, sj = -2;

bool vis[mxN][mxN];

bool dot(int i, int j){
    return i>=0 && i<n && j>=0 && j<m && maze[i][j] == '.' && !vis[i][j];
}

bool bfs(vector<pii> v, int d[mxN][mxN], int parent[mxN][mxN], bool noMove = true){
    queue<pii> q;

    memset(vis, 0, sizeof(vis));
    memset(d, 0, sizeof(d)); 

    fo(i, v.size()){
        q.push(v[i]);
        vis[v[i].F][v[i].S] = true;
    }

    while(!q.empty()){
        pii u = q.front();
        q.pop();

        fo(k, 4){
            int ni = u.F + di[k], nj = u.S + dj[k];
            if(dot(ni, nj)){
                noMove = false;
                vis[ni][nj] = true;

                pii en(ni, nj);
                q.push(en);

                parent[ni][nj] = k;
                d[ni][nj] = d[u.F][u.S]+1;
            }
        }

    }

    return noMove;

}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;

    fo(i, n){
        cin>>maze[i];

        fo(j, m){
            if(maze[i][j] == 'A'){
                si = i, sj = j;
                maze[i][j] = '.';
                pii p(si, sj);
                v1.pb(p);
            }

            if(maze[i][j] == 'M'){
                maze[i][j] = '.';
                pii p(i, j);
                v2.pb(p);
            }
        }
    }

    //bfs for the monsters
    bool nm2 = bfs(v2, d2, p2);

    //bfs for the player
    bool nm1 = bfs(v1, d1, p1);

    int ti = -1, tj = -1;

    //for boundary: (i, 0) && (i, m-1), just finding if at any
    //boundary location we have distance of player less than monsters
    //so that player could reach there before the monsters

    fo(i, n){

        //deb(d1[i][0]); deb(d2[i][0]);

        if(v2.empty() || nm2){
            if(d1[i][0]){
                ti = i; tj = 0;
            }

            if(d1[i][m-1]){
                ti = i; tj = m-1;
            }
        }

        if(d1[i][0] < d2[i][0]){
            ti = i; tj = 0;
        }

        //deb(d1[i][m-1]); deb(d2[i][m-1]);
        if(d1[i][m-1] < d2[i][m-1]){
            ti = i; tj = m-1;
        }
    }


    //for boundary: (0, j) && (n-1, j), just finding if at any
    //boundary location we have distance of player less than monsters
    //so that player could reach there before the monsters
    fo(j, m){

        if(v2.empty() || nm2){
            if(d1[0][j]){
                ti = 0; tj = j;
            }

            if(d1[n-1][j]){
                ti = n-1; tj = j;
            }
        }


        if(d1[0][j] < d2[0][j]){
            ti = 0; tj = j;
        }

        if(d1[n-1][j] < d2[n-1][j]){
            ti = n-1; tj = j;
        }
    }

    string path;

    if(si == 0 || si == n-1 || sj == 0 || sj == m-1){
        ti = si; tj = sj;
    }

    if(si == -2 || sj == -2){
        ti = -1; tj = -1;
    }

    if(ti == -1){
        cout<<"NO"<<"\n";
    }
    else{
        //cout<<"entered while"<<"\n";
        while(ti^si || tj^sj){
            int k = p1[ti][tj];
            path += dc[k];
            ti -= di[k]; tj -= dj[k];
        }
        //cout<<"completed while"<<"\n";
        reverse(all(path));
        cout<<"YES"<<"\n";
        cout<<path.size()<<"\n";
        cout<<path<<"\n";
    }
    

    return 0;
}

