#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout << #x <<  " " << x << endl;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
const int inf = 1e9 + 5;

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";}cout<<endl;for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}

const int mod = 1e9+7;
const int nax = 1e5+5;
vvi edges(nax);

int mul(int a, int b){
    return (ll) a*b %mod;
}

// returns 
pii dfs(int a, int parent){
    int all_white = 1;
    int sth_black = 0;
    for(int b: edges[a]){
        if(b!=parent){
            pii p = dfs(b, a);
            // p.first: # of ways to col the subtree such that b is black

            int memo_all_white = all_white;
            all_white = mul(all_white, p.second);
            sth_black = (mul(memo_all_white, p.first) + mul(sth_black, p.first + p.second))%mod;
        }
    }

    return {all_white, (all_white+sth_black)%mod};
}

int main(){
    int n, x, y;
    cin>>n;
    forn(i, n-1){
        cin>>x>>y;
        edges[x].pb(y);
        edges[y].pb(x);
    }

    pair<int, int> p = dfs(1, -1);
    int ans = (p.first + p.second) %mod;
    cout<<ans<<endl;

    return 0;
}