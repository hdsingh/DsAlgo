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
    ll tot;
    ll cnt[40];
    node(){
        tot = 0;
        memset(cnt, 0, sizeof(cnt));
    };
};

class SegmentTree{
public:
    int n;
    vector<node> st;

    SegmentTree(vi &a){
        n = sz(a);
        st.resize(4*n, node());
        build(1,0,n-1,a);
    }

    void merge(node &cur, node &l, node &r){
        cur.tot = l.tot + r.tot;
        ll prev = 0;
        for(int i=39; i>=0; --i){
            cur.cnt[i] = l.cnt[i] + r.cnt[i];
            cur.tot+=(r.cnt[i]*prev);
            prev+=l.cnt[i];
        }
    }

    void build(int pos, int l, int r, vi &a){
        if(l==r){
            st[pos].cnt[a[l]] = 1;
            return;
        }
        int mid = (l+r)/2;
        build(2*pos, l, mid, a);
        build(2*pos+1, mid+1, r, a);
        merge(st[pos], st[2*pos], st[2*pos+1]);
    }

    void update(int pos, int sl, int sr, int &i, int &val, int &pval){
        st[pos].cnt[val]++;
        st[pos].cnt[pval]--;
        if(sl==sr) return;

        int mid = (sl+sr)/2;
        if(i<=mid)
            update(2*pos, sl, mid, i, val, pval);
        else 
            update(2*pos+1, mid+1, sr, i, val, pval);

        merge(st[pos], st[2*pos], st[2*pos+1]);        
    }

    node query(int pos, int sl, int sr, int l, int r){
        if(r<sl || sr<l) return node();
        else if(l<=sl && sr<=r) return st[pos];
        int mid = (sl+sr)/2;
        node left = query(2*pos, sl, mid, l, r);
        node right = query(2*pos+1, mid+1, sr, l, r);
        node cur;
        merge(cur, left, right);
        return cur;
    }

    ll query(int l, int r){
        node cur = query(1,0,n-1,l,r);
        return cur.tot;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin>>n>>m;
    vi a(n); forn(i,n) cin>>a[i], --a[i];
    SegmentTree st(a);
    while(m--){
        int tp, x, y; cin>>tp>>x>>y;
        --x, --y;
        if(tp==1){
            cout<<st.query(x, y)<<"\n";
        }else{
            int pval = a[x];
            a[x] = y;
            st.update(1,0,n-1,x,y,pval);
        }
    }
    return 0;
}