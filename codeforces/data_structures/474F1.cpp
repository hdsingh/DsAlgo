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

// Count gcd of a range and number times it appears
// simply by using map

struct node{
    int gc = 0;
    map<int,int> cnt;
};

class SegmentTree {
    int n;
    vector<node> st;

    node make_node(int val) {
        node res;
        res.gc = val;
        res.cnt[val] = 1;
        return res;
    }
public:
    SegmentTree(vector<int>& a) {
        n = a.size();
        if(!n) return;

        int max_size = 4*n;
        st.clear(); st.resize(max_size, node());
        build(1,0,n-1,a);
    }

    void merge(node &cur, node &l, node &r){
        cur.gc = gcd(l.gc, r.gc);

        for(auto p: l.cnt)
            if(p.first && cur.gc % p.first==0)
                cur.cnt[p.first]+=p.second;

        for(auto p: r.cnt)
            if(p.first && cur.gc%p.first==0)
                cur.cnt[p.first]+=p.second;
    }

    void build(int pos, int l, int r, vi &a){
        if(l==r){
            st[pos] = make_node(a[l]);
            return;
        }
        int mid = (l+r)/2;
        build(2*pos,l,mid,a);
        build(2*pos+1,mid+1,r,a);
        merge(st[pos] ,st[2*pos] , st[2*pos+1]);
    }

    node query(int pos, int l, int r, int i, int j) {
        if(i>r || l>j) return make_node(0);
        if(i<=l && r<=j) return st[pos];
        int mid = (l+r)/2;
        node left = query(2*pos,l,mid,i,j);
        node right = query(2*pos+1,mid+1,r,i,j);
        node cur;
        merge(cur, left, right);
        return cur;
    }

    int query(int i,int j){
        node q = query(1,0,n-1,i,j);
        return j-i+1 - q.cnt[q.gc];
    }
};


int main(){
    int n;
    scanf("%d ", &n);
    vi a(n); forn(i,n) scanf("%d ", &a[i]);
    SegmentTree st(a);
    int t,l,r;
    scanf("%d ", &t);
    while(t--){
        scanf("%d %d", &l, &r);
        --l,--r;
        cout<<st.query(l,r)<<endl;
    }
    return 0;
}