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
typedef pair<ll, ll> pll;
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
template <typename T> ostream& operator<<(ostream &os, const vector<T> &v){print(v); return os;};
template <typename T> ostream& operator<<(ostream &os, const vector<vector<T>> &vv){print_vv(vv); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const map<T,U>  &m){print_m(m); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const pair<T, U> &pr){debp(pr); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const vector<pair<T, U>> &vp){ print_vp(vp); return os;};
#define x first
#define y second

struct node{
    bool clazy = 0;
    // other parameters
    ll len = 0, sum = 0, val = 0;
    node(){};
    // node input definition
    node(ll l, ll s, ll v): len(l), sum(s), val(v) {};
};

class SegmentTree{
public:
    int n;
    vector<node> st;

    SegmentTree(vi &a){
        n = sz(a);
        st.resize(4*n);
        build(1,0,n-1, a); // pass a, if req
    }

    node merge(node &l, node &r){
        node cur;
        cur.len = l.len + r.len;
        cur.sum = l.sum + r.sum;
        return cur;
    }

    void build(int pos, int l, int r, vi &a){
        if(l==r){
            st[pos]  = node(1,a[l],a[l]); // allocate specific values
            return;
        }
        int mid = (l+r)/2;
        build(2*pos, l, mid, a);
        build(2*pos+1, mid+1, r, a);
        st[pos] = merge(st[2*pos], st[2*pos+1]);
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

    node query(int pos, int sl, int sr, int l, int r){
        propagate(pos, sl, sr);
        if(r<sl || sr<l) return node();
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
            st[2*pos].val = st[2*pos+1].val = st[pos].val;
            st[2*pos].clazy = st[2*pos+1].clazy = 1;
        }
        // handle
        st[pos].sum = st[pos].val * st[pos].len;
        st[pos].val = st[pos].clazy = 0;
    }

    void update(int l, int r, int v){
        update(1,0,n-1,l,r,v);
    }

    ll query(int l, int r){
        return query(1,0,n-1,l,r).sum; // query.val
    }

};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n, q; cin>>n>>q;
        vi s(n), f(n);
        forn(i,n){
            char c; cin>>c;
            s[i] = (c-'0');
        }
        forn(i,n){
            char c; cin>>c;
            f[i] = (c-'0');
        }
        // print(f,1);
        SegmentTree st(f);
        vector<pii> qs(q);
        auto getArr = [&](){
            vi out(n);
            forn(i,n)
                out[i] = st.query(i,i);
            return out;
        };

        forn(i,q){
            cin>>qs[i].x>>qs[i].y;
        }
        reverse(all(qs));
        bool ok = 1;
        for(auto [l,r]: qs){
            --l,--r;
            // deb(l,r);
            int sum = st.query(l,r);
            int len = (r-l+1);
            int zeros = len - sum, ones = sum;
            // deb(zeros, ones, half);
            if(zeros==ones){
                ok = 0; break;
            }else if(zeros<ones){
                st.update(1,0,n-1,l,r,1);
            }else {
                st.update(1,0,n-1,l,r,0);
            }
            // print(getArr());
        }
        f = getArr();
        ok&=(f==s);
        // cout<<f<<s;
        cout<<(ok ? "YES\n" : "NO\n");

    }
    return 0;
}