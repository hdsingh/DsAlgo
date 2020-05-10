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

struct participant{
    ll x,y,id;
    bool operator<(const participant &oth){
        return (x-y) < (oth.x - oth.y);
    }
};

// x1 y1
// x2 y2
const int nax = 3e5+10;
participant ps[nax];
ll pre_x[nax], suf_x[nax], pre_y[nax], suf_y[nax];
ll ans[nax];

int main(){
    int n,m,u,v;
    cin>>n>>m;
    fore(i,1,n+1){
        cin>>ps[i].x>>ps[i].y;
        ps[i].id = i;
    }

    forn(i,m){
        cin>>u>>v;
        ll temp = min({ps[u].x + ps[v].y, ps[u].y +ps[v].x});
        ans[u]-=temp;
        ans[v]-=temp;
    }

    sort(ps+1, ps+1+n);

    fore(i,1,n+1){
        pre_x[i] = pre_x[i-1] + ps[i].x;
        pre_y[i] = pre_y[i-1] + ps[i].y;
    }

    for(int i=n; i>=1; --i){
        suf_x[i] = suf_x[i+1] + ps[i].x;
        suf_y[i] = suf_y[i+1] + ps[i].y;
    }

    // since sorted acc to x1-y1  < x2 - y2
    // So on lt, x1 is less y1 is more,   on rt opp
    // so for cur pos's y we will take all prev x
    
    fore(i,1,n+1){
        int lcnt = i-1, rcnt = n-i;
        ll temp = pre_x[i-1] + ps[i].y * lcnt;
        temp+=    suf_y[i+1] + ps[i].x * rcnt;
        ans[ps[i].id] += temp;
    }

    fore(i,1,n+1)
        cout<<ans[i]<<" ";
    cout<<"\n";

    return 0;
}