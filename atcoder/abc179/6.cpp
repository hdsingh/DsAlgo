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

struct node{
    bool clazy = 0;
    int lazy = 1e9;
    int val = 0;
    // other parameters
    node(){};
    // node input definition
    node(int v):val(v){};
};

class SegmentTree{
public:
    int n;
    vector<node> st;

    SegmentTree(int N){
        n = N;
        st.resize(4*n);
        build(1,0,n-1); // pass a, if req
    }

    node merge(node &l, node &r){
        node cur;
        cur.val = min(l.val, r.val);
        return cur;
    }

    void build(int pos, int l, int r){
        if(l==r){
            st[pos]  = node(n); // allocate specific values
            return;
        }
        int mid = (l+r)/2;
        build(2*pos, l, mid);
        build(2*pos+1, mid+1, r);
        st[pos] = merge(st[2*pos], st[2*pos+1]);
    }

    void update(int pos, int sl, int sr, int l, int r, int val){
        propagate(pos, sl, sr);
        if(r<sl || sr<l) return;
        else if(l<=sl && sr<=r){
            st[pos].clazy = 1;
            // handle
            st[pos].lazy = val;
            propagate(pos, sl, sr);
            return;
        }
        int mid = (sl+sr)/2;
        update(2*pos, sl, mid, l, r, val);
        update(2*pos+1, mid+1, sr, l, r, val);
        st[pos] = merge(st[2*pos], st[2*pos+1]);
    }

    node query(int pos, int sl, int sr, int l, int r){
        propagate(pos, sl, sr);
        if(r<sl || sr<l) return node(1e9);
        else if(l<=sl && sr<=r) return st[pos];
        int mid = (sl+sr)/2;
        node left = query(2*pos, sl, mid, l, r);
        node right = query(2*pos+1, mid+1, sr, l, r);
        return merge(left, right);        
    }

    void propagate(int pos, int sl, int sr){
        if(!st[pos].clazy) return;
        if(sl!=sr){
            // handle
            min_self(st[2*pos].lazy, st[pos].lazy);
            min_self(st[2*pos+1].lazy, st[pos].lazy);
            st[2*pos].clazy = st[2*pos+1].clazy = 1;
        }
        // handle
        min_self(st[pos].val, st[pos].lazy);
        st[pos].lazy = 1e9;
        st[pos].clazy = 0;
    }

    void update(int l, int r, int v){
        update(1,0,n-1,l,r,v);
    }

    ll query(int l, int r){
        return query(1,0,n-1,l,r).val; // query.val
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, q;
    while(cin>>n>>q){
        SegmentTree rows(n), cols(n);
        ll tot = (n-2)*(n-2);
        while(q--){
            int tp, x; cin>>tp>>x;
            // deb(tp,x);
            if(tp==1){
                // cols
                ll mn = cols.query(x,x);
                int cover_now = (mn-2);
                // deb(mn, cover_now);
                cols.update(x,x,2);
                rows.update(2,min(n-1,mn),x);
                tot-=cover_now;
            }else{
                ll mn = rows.query(x,x);
                int cover_now = (mn-2);
                // deb(mn, cover_now);
                rows.update(x,x,2);
                cols.update(2,min(n-1,mn),x);
                tot-=cover_now;
            }
        }
        cout<<tot<<"\n";
    }
    return 0;
}