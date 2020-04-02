#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
template<class T, class U> inline void add_self(T &a, U b){a += b;if (a >= mod) a -= mod;if (a < 0) a += mod;}
template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}
const int inf = 1e9;


// 1. Calculate the degree of each node
// 2. In case of min, if there are c child nodes, we can have value
// leafs - c + 1, example in case of 3 children, and allowed value n, we cant have n-1, n-2, but can have n-3 on node
// 3. In case of max, we are just concerned with the min val be cause we cant take it
// Now for the max query: You want to lose the minimum possible

// Refer: https://codeforces.com/blog/entry/66539?#comment-505484

int n,x;
vi opr, deg;
vvi adj;
vi dp;

void dfs(int x){
    if(deg[x]==0){
        dp[x] = 1; return;
    }

    for(auto ad: adj[x]) dfs(ad);

    if(opr[x]==1){ // max
        for(auto ad: adj[x])
            dp[x] = min(dp[x], dp[ad]);
    }else{ //min
        dp[x] = 0;
        for(auto ad: adj[x])
            dp[x]+=dp[ad];
    }
}

int main(){
    while(cin>>n){
        opr.clear(); deg.clear(); adj.clear(); dp.clear();
        opr.resize(n); deg.resize(n); adj.resize(n); dp.resize(n,inf);

        forn(i,n) cin>>opr[i];

        forn(i,n-1){
            cin>>x; --x;
            adj[x].pb(i+1);
            deg[x]++;
        }

        int leafs = 0;
        for(auto d: deg)
            leafs+= (d==0);
        
        
        dfs(0); 
        int ans = leafs - dp[0] + 1;
        cout<<ans<<endl;

    }
    return 0;
}