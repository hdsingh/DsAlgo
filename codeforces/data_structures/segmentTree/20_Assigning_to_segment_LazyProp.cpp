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
    vi st, lazy;
    const int nop = INT_MAX; // no operation

    SegmentTree(int _n){
        n = _n;
        st.resize(4*n), lazy.resize(4*n, nop);
    }

    void update(int pos, int sl, int sr, int l, int r, int val){
        propagate(pos, sl, sr);
        if(sr<l || r<sl) return;
        else if(l<=sl && sr<=r){
            lazy[pos] = val;
            propagate(pos, sl, sr);
            return;
        }
        int mid = (sl+sr)/2;
        update(2*pos, sl, mid, l, r, val);
        update(2*pos+1, mid+1, sr, l, r, val);
    }

    int query(int pos, int sl, int sr, int i){
        propagate(pos, sl, sr);
        if(sl==sr) return st[pos];
        int mid = (sl+sr)/2;
        if(i<=mid)
            return query(2*pos, sl, mid, i);
        return query(2*pos+1, mid+1, sr, i);
    }

    void propagate(int pos, int l, int r){
        if(lazy[pos]==nop) return;
        if(l!=r){
            lazy[2*pos] = lazy[2*pos+1] = lazy[pos];
        }
        st[pos] = lazy[pos];
        lazy[pos] = nop;
    }

    void update(int l, int r, int val){
        update(1, 0, n-1, l, r, val);
    }

    int query(int idx){
        return query(1,0,n-1,idx);
    }
};

class SegmentTree1{
public:
    int n;
    vi st, lazy;
    vb clazy;

    SegmentTree1(int _n){
        n = _n;
        st.resize(4*n), lazy.resize(4*n), clazy.resize(4*n);
    }

    void update(int pos, int sl, int sr, int l, int r, int val){
        propagate(pos, sl, sr);
        if(sr<l || r<sl) return;
        else if(l<=sl && sr<=r){
            clazy[pos] = 1;
            lazy[pos] = val;
            return;
        }

        int mid = (sl+sr)/2;
        update(2*pos, sl, mid, l, r, val);
        update(2*pos+1, mid+1, sr, l, r, val);         
    }

    int query(int pos, int sl, int sr, int i){
        propagate(pos, sl, sr);
        if(sl==sr) return st[pos];
        int mid = (sl+sr)/2;
        if(i<=mid)
            return query(2*pos, sl, mid, i);
        return query(2*pos+1, mid+1, sr, i);
    }

    void propagate(int pos, int sl, int sr){
        if(!clazy[pos]) return;
        if(sl!=sr){
            clazy[2*pos] = clazy[2*pos+1] = clazy[pos];
            lazy[2*pos] = lazy[2*pos+1] = lazy[pos];
        }
        st[pos] = lazy[pos];
        clazy[pos] = 0;
    }
    
    void update(int l, int r, int val){
        update(1, 0, n-1, l, r, val);
    }

    int query(int idx){
        return query(1,0,n-1,idx);
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin>>n>>m;
    SegmentTree1 st(n);
    while(m--){
        int tp; cin>>tp;
        if(tp==1){
            int l, r, v; cin>>l>>r>>v; 
            st.update(l,r-1,v);
        }else{
            int idx; cin>>idx;
            cout<<st.query(idx)<<"\n";
        }
    }
    return 0;
}