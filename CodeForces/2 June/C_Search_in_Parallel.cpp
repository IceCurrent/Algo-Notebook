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

int search(vi &r, int l){

    fo(i, r.size()){
        if(l == r[i]){
            r[i] = -1;
            return i+1;
        }
    }
    return -1;
}

void solve(int n, vi &r, int s1, int s2, vi &a, vi &b){
    
    int curr1 = s1;
    int curr2 = s2;

    // vi v(0);
    // vector<vi> m(1e6+7, v);

    // fo(i, n){
    //     m[r[i]].pb(i+1);
    // }



    for(int i=n-1; i>=0; i--){
        //int s = *max_element(r.begin(), r.end());
        int p = *max_element(r.begin(), r.end());

        int s = search(r, p);
        // vi p = m[r[i]];
        
        // int s = p[p.size()-1];
        // m[r[i]].pop_back();
        if(curr1 < curr2){
            
            a.pb(s);
            curr1 += s1;
        }
        else if(curr1 > curr2){

            b.pb(s);
            curr2 += s2;
        }
        else{
            if(s1 < s2){
                a.pb(s);
                curr1 += s1;
            }
            else{
                b.pb(s);
                curr2 += s2;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 1;
    cin>>tc;

    while(tc--){
        int n, s1, s2;
        cin>>n>>s1>>s2;

        vector<int> r(n);

        fo(i, n){
            cin>>r[i];
        }

        vi a(0);
        vi b(0);

        solve(n, r, s1, s2, a, b);
        
        cout<<a.size()<<" ";
        fo(i, a.size()){
            cout<<a[i]<<" "; 
        }
        cout<<endl;


        cout<<b.size()<<" ";
        fo(i, b.size()){
            cout<<b[i]<<" "; 
        }
        cout<<endl;

    }
    return 0;
}



/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
