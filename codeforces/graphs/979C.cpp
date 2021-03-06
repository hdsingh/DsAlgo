#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) int((a).size())
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

#define _deb(x) cout<<x;
void _print() {cerr << "]\n";} template <typename T, typename... V>void _print(T t, V... v) {_deb(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
template <class T, class U> void print_m(const map<T,U> &m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}
template<class T, class U>void debp(const pair<T, U> &pr, bool end_line=1){cout<<"{"<<pr.first<<" "<<pr.second<<"}"; cout<<(end_line ? "\n" : ", ");}
template <class T> void print_vp(const T &vp, int sep_line=0){if(vp.empty()){cout<<"Empty"<<endl; return;}if(!sep_line) cout<<"{ ";for(auto x: vp) debp(x,sep_line);if(!sep_line) cout<<"}\n";cout<<endl;}
template <typename T>void print(const T &v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<sz(v); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<endl;}
template <typename T>void print_vv(const T &vv){if(sz(vv)==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<sz(*vv.begin()); j++)cout<<setw(w)<<j<<" ";cout<<endl;int i = 0;for(auto &v: vv){cout<<i++<<" {";for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<"},\n";}cout<<endl;}

const int nax = 3e5+10;
int n,X,Y;
vvi adj(nax);

// int , T/F
pii dfs(int x, int p,int op){
    if(x==op) return {0,0};
    pii here = {1,1};
    for(auto ad: adj[x]){
        if(ad==p) continue;
        pii cur = dfs(ad,x,op);
        if(cur.second==0) 
            here.second = 0;
        else{
            here.first+=cur.first;
        }
    }

    return here;
}

ll c2(ll x){
    if(x<2) return 0;
    return x*(x-1);
}

ll mul(ll a, ll b){
    if(a<=0 || b<=0) return 0;
    return a*b;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>X>>Y;
    int u,v;
    forn(i,n-1){
        cin>>u>>v;
        adj[u].pb(v); adj[v].pb(u);
    }

    pii F = dfs(X, 0, Y);
    pii B = dfs(Y, 0, X);
    ll ff = F.first, bb = B.first;

    // Can Choose
    // deb(ff,bb);
    // deb(c2(bb), c2(ff), c2(n-(bb+ff)),  mul(ff, n-(ff+bb)), mul(bb, n-bb), mul(n-(bb+ff),bb));
    // ll ans = c2(bb) + c2(ff) + c2(n-(bb+ff)) + mul(ff, n-(ff+bb)) + mul(bb, n-bb) + mul(n-(bb+ff),bb) + mul(n-(bb+ff),ff) ;
    // cout<<ans<<endl;

    // Cannot choose (B to F)
    ll ans = c2(n) - mul(bb, ff);
    cout<<ans<<endl;

    return 0;
}