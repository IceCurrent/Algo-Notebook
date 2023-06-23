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

int n, m;
const int mxN = 1e4;
string s[mxN];


//direction arrays:
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, -1, 0, 1};

char dc[4] = {'U', 'L', 'D', 'R'};
int d[mxN][mxN];

char parent[mxN][mxN];

bool dot(int i, int j){
    return i>=0 && i<n && j>=0 && j<m && (s[i][j] == '.' || s[i][j] == 'B');
}

int si, sj;
int ei, ej;
string t;

int bfs(int i, int j){
    queue<pii> q;
    pii fen(i, j);
    q.push(fen);
    s[i][j] = '#';

    
    //cout<<q.front().F<<", "<<q.front().S<<endl;

    while(!q.empty()){
        pii u = q.front();

        if(u.F == ei && u.S == ej){
            int ni = u.F, nj = u.S;
            while(ni^si || nj^sj){
                t += parent[ni][nj];
                int k = d[ni][nj];
                ni -= di[k];
                nj -= dj[k];
            }
            return 1;
        }

        //cout<<u.F<<", "<<u.S<<endl;
        q.pop();

        for(int k=0; k<4; k++){
            int ni = u.F+di[k], nj = u.S+dj[k];
            if(dot(ni, nj)){
                s[ni][nj] = '#';
                pii en(ni, nj);
                q.push(en); 
                parent[ni][nj] = dc[k];
                d[ni][nj] = k;
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>s[i];

        //if you take input char by char, (like running two
        // loops and doing cin>>s[i][j]), then it would give
        // runtime error! So take inputs like one row as a 
        // string at one time!!
        
        for(int j=0; j<m; j++){
            if(s[i][j] == 'A'){
                si = i, sj = j;
            }

            if(s[i][j] == 'B'){
                ei = i, ej = j;
            }
        }
    }


    int ans = bfs(si, sj);
    
    if(ans == -1){
        cout<<"NO"<<"\n";
    }
    else if(ans == 1){
        cout<<"YES"<<"\n";
        cout<<t.length()<<"\n";

        reverse(all(t));
        cout<<t<<"\n";
    }
    else{
        cout<<"throw error"<<"\n";
    }


    return 0;
}

