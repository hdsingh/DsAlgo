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

ll n,A, R, M;
vl h;
vl pre;

// 1 1 2 2 3 4 4 4 5 6 7
// x: 4
// ls: 1 1 2 2 3 (5)
// gr: 5 6 7     (3)
ll cost(ll x){
    ll tot = 0;
    auto it1 = lower_bound(all(h),x);
    auto it2 = upper_bound(all(h),x);
    int posl = distance(h.begin(),it1);
    int posr = distance(h.begin(),it2);
    // deb(posl,posr);
    ll suml = (posl ? pre[posl-1] : 0);
    ll sumr = pre[n-1] - (posr ? pre[posr-1] : 0);
    // deb(suml,sumr);
    ll extra = sumr - x*(n-posr);
    ll slot = x*(posl ? posl : 0) - suml;

    ll shifts = min(extra,slot);
    if(M<=A+R){
        tot+=M*shifts;
    }else{
        tot+=(A+R)*shifts;        
    }
    // deb(extra, slot, shifts);

    extra-=shifts;
    slot-=shifts;
    if(extra>0) tot+=R*extra;
    if(slot>0) tot+=A*slot;

    return tot;
}

ll ternary_search(ll l, ll r){
    forn(i,400){
        ll m1 = l + (r-l)/3;
        ll m2 = r - (r-l)/3;
        ll f1 = cost(m1);
        ll f2 = cost(m2);
        if(f1>f2)
            l = m1;
        else 
            r = m2;
    }

    ll min_cost = LONG_LONG_MAX;
    for(ll x = l; x<=r; ++x)
        min_cost = min(min_cost, cost(x));
    
    return min_cost;
}

int main(){
    while(cin>>n>>A>>R>>M){
        h.resize(n); pre.clear(); pre.resize(n);
        forn(i,n) cin>>h[i];
        sort(all(h));
        partial_sum(h.begin(),h.end(), pre.begin());

        // print(h); print(pre);
        int l = h.front(), r = h.back();
        ll ans = ternary_search(l,r);
        cout<<ans<<endl;
    }

    return 0;
}