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

const int nax = 1e5 + 10;
int n, m;
vvi adj(nax), radj(nax);
vi indeg(nax), ord;
vi dp(nax);

void kahns(){
    queue<int> q;
    fore(i,1,n+1){
        if(indeg[i]==0) q.push(i);
    }

    int cnt = 0;
    while(sz(q)){
        int top = q.front(); q.pop();
        ord.pb(top);
        cnt++;
        for(auto ad: adj[top]){
            indeg[ad]--;
            if(indeg[ad]==0)
                q.push(ad);
        }
    }
}

// By observation:
// before visiting any node all its prev nodes must be visitied
// This is exactly topsort.
// A node could be reached from all its prev nodes
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);   
    cin>>n>>m;
    forn(i,m){
        int x, y; cin>>x>>y;
        adj[x].pb(y);
        radj[y].pb(x);
        indeg[y]++;
    }
    // method 1
    kahns();
    dp[1] = 1;
    for(auto node: ord){
        for(auto rad: radj[node]) // rev adjacent
            add_self(dp[node], dp[rad]);
    }
    cout<<dp[n]<<"\n";
    
    return 0;
}