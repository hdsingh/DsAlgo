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

class SegmentTree{
public:
    int n;
    vi st;

    SegmentTree(int _n){
        n = _n;
        st.resize(4*n);
        build(1, 0, n-1);
    }

    void build(int pos, int l, int r){
        if(l==r){
            st[pos] = 1;
            return;
        }
        int mid = (l + r)/2;
        build(2*pos, l, mid);
        build(2*pos+1, mid+1, r);
        st[pos] = st[2*pos] + st[2*pos+1];
    }

    void update(int pos, int sl, int sr, int i){
        if(sl==sr){
            st[pos] = 0;
            return;
        }
        int mid = (sl + sr)/2;
        if(i<=mid)
            update(2*pos, sl, mid, i);
        else 
            update(2*pos + 1, mid+1, sr, i);
        st[pos] = st[2*pos] + st[2*pos+1];
    }    

    // sort of opposite find kth
    int query(int pos, int sl, int sr, int k){
        if(k>st[pos]) return -1;
        if(sl==sr) return sl;
        int mid = (sl + sr)/2;
        if(st[2*pos+1]>=k)
            return query(2*pos+1, mid + 1, sr, k);
        return query(2*pos, sl, mid, k - st[2*pos+1]);
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;    
    SegmentTree st(n);
    vi a(n); forn(i,n) cin>>a[i];
    reverse(all(a));
    vi ans;
    for(auto x: a){
        int idx = st.query(1,0,n-1,x+1);
        assert(idx!=-1);
        ans.pb(idx+1);
        st.update(1,0,n-1,idx);
    }
    reverse(all(ans));
    print(ans);
    return 0;
}

// Using ordered set
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main1(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    vi a(n), ans(n);
    ordered_set<int> s;
    fore(i,1,n+1) s.insert(-i);
    forn(i,n) cin>>a[i];

    for(int i=n-1; i>=0; --i){
        auto pos = s.find_by_order(a[i]);
        ans[i] = -(*pos);
        s.erase(pos);
    }

    print(ans);
    
    return 0;
}