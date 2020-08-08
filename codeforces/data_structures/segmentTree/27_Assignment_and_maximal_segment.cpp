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
template<class T, class U> inline void mul_self(T &x, U y) { x*=y; x%=mod; }

#define _deb(x) cout<<x;
void _print() {cerr << "]\n";} template <typename T, typename... V>void _print(T t, V... v) {_deb(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
template <class T, class U> void print_m(const map<T,U> &m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}
template<class T, class U>void debp(const pair<T, U> &pr, bool end_line=1){cout<<"{"<<pr.first<<" "<<pr.second<<"}"; cout<<(end_line ? "\n" : ", ");}
template <class T> void print_vp(const T &vp, int sep_line=0){if(vp.empty()){cout<<"Empty"<<endl; return;}if(!sep_line) cout<<"{ ";for(auto x: vp) debp(x,sep_line);if(!sep_line) cout<<"}\n";cout<<endl;}
template <typename T>void print(const T &v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<sz(v); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<endl;}
template <typename T>void print_vv(const T &vv){if(sz(vv)==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<sz(*vv.begin()); j++)cout<<setw(w)<<j<<" ";cout<<endl;int i = 0;for(auto &v: vv){cout<<i++<<" {";for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<"},\n";}cout<<endl;}

struct node{
    bool clazy = 0;
    ll pref = 0, suf = 0, mx = 0, sum = 0, val = 0, len = 0;
    // other parameters
    node(){};
    // node input definition
    node(ll v, ll l) : pref(v), suf(v), mx(v), sum(v), len(l) {};
};

class SegmentTree{
public:
    int n;
    vector<node> st;

    SegmentTree(int N){
        n = N;
        st.resize(4*n);
        build(1,0,n-1);
    }

    void build(int pos, int l, int r){
        if(l==r){
            st[pos]  = node(0,1); // allocate specific values
            return;
        }
        int mid = (l+r)/2;
        build(2*pos, l, mid);
        build(2*pos+1, mid+1, r);
        st[pos] = merge(st[2*pos], st[2*pos+1]);
    }

    node merge(node &l, node &r){
        node cur;
        cur.mx = max({r.mx, l.mx, l.suf + r.pref});  
        cur.pref = max(l.pref, l.sum + r.pref);
        cur.suf = max(r.suf, r.sum + l.suf);
        cur.sum = l.sum + r.sum; 
        cur.len = l.len + r.len;   
        return cur;
    }

    void update(int pos, int sl, int sr, int l, int r, int val){
        propagate(pos, sl, sr);
        if(r<sl || sr<l) return;
        else if(l<=sl && sr<=r){
            st[pos].clazy = 1;
            // handle
            st[pos].val = val;
            propagate(pos, sl, sr);
            return;
        }
        int mid = (sl+sr)/2;
        update(2*pos, sl, mid, l, r, val);
        update(2*pos+1, mid+1, sr, l, r, val);
        st[pos] = merge(st[2*pos], st[2*pos+1]);
    }

    void propagate(int pos, int sl, int sr){
        if(!st[pos].clazy) return;
        if(sl!=sr){
            // handle
            st[2*pos].val = st[2*pos+1].val = st[pos].val;
            st[2*pos].clazy = st[2*pos+1].clazy = 1;
        }
        // handle
        st[pos].pref = st[pos].suf = st[pos].sum = st[pos].mx = st[pos].val*st[pos].len; 
        max_self(st[pos].mx, 0ll);
        st[pos].val = st[pos].clazy = 0;
    }

    void update(int l, int r, int v){
        update(1,0,n-1,l,r,v);
    }

    ll query(){
        return st[1].mx;
    }

};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin>>n>>m;
    SegmentTree st(n);
    while(m--){
        int l, r, v; cin>>l>>r>>v;
        st.update(l,r-1,v);
        cout<<st.query()<<"\n";
    }
    return 0;
}