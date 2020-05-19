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

const int nax = 1e6+10;

// Range sum query mutable
struct node{
    int val = 0;
};

// for left greater
class SegmentTree1 {
    int n;
    vector<node> st;

    node make_node(int val) {
        node res;
        res.val = val;
        return res;
    }
public:
    SegmentTree1() {
        n = nax;
        int max_size = 4*n;
        st.clear(); st.resize(max_size, node());
    }

    void merge(node &cur, node l, node r){
        cur.val = l.val + r.val;
    }

    void update(int pos, int l, int r, int i, int val) {
        if(l==r){
            st[pos].val+=val;
            return;
        }
        int mid = (l+r)/2;
        // if index is <=mid it lies in left part
        if(i<=mid)
            update(2*pos,l,mid,i,val);
        else 
            update(2*pos+1,mid+1,r,i,val);

        merge(st[pos], st[2*pos] , st[2*pos+1]);
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

    void update(int i, int val){
        update(1,0,n-1,i,val);
    }

    int query(int i,int j){
        node q = query(1,0,n-1,i,j);
        return q.val;
    }
};

// for right lesser
class SegmentTree2 {
    int n;
    vector<node> st;

    node make_node(int val) {
        node res;
        res.val = val;
        return res;
    }
public:
    SegmentTree2(vector<int>& a) {
        n = a.size();
        if(!n) return;

        int max_size = 4*n;
        st.clear(); st.resize(max_size, node());
        build(1,0,n-1,a);
    }

    void merge(node &cur, node l, node r){
        cur.val = l.val + r.val;
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
    
    
    void update(int pos, int l, int r, int i, int val) {
        if(l==r){
            st[pos].val+=val;
            return;
        }
        int mid = (l+r)/2;
        // if index is <=mid it lies in left part
        if(i<=mid)
            update(2*pos,l,mid,i,val);
        else 
            update(2*pos+1,mid+1,r,i,val);

        merge(st[pos], st[2*pos] , st[2*pos+1]);
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

    void update(int i, int inc){
        update(1,0,n-1,i,inc);
    }

    int query(int i,int j){
        node q = query(1,0,n-1,i,j);
        return q.val;
    }
};

// since we need to find a[i]>a[j]>a[k] such that i<j<k
// we can find for j, the elements to its left which are greater
// and the elements to its right which are less than it
// tot+= greater_on_left[j] * lesser_on_right[j]
// Use coordinate compression to reduce the distinct values bw a range
// So we will maintain 2 trees, and move from lt to right
// 1. lt_greater: to count the elements greater than x on left
// 2. rt_lesser: to count the elements lesser than x on right
// for lt_gr, the elements will be added as we move lt to rt
// for rt_lesser, we will pre-build the tree and remove the elements as we move right
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vi a(n);
    forn(i,n) cin>>a[i];

    // coordinate compression
    set<int> s; 
    forn(i,n) s.insert(a[i]);
    // print(s);
    map<int,int> m;
    int i = 1;
    for(auto x: s) m[x] = i++;

    for(auto &x: a)
        x = m[x];
    
    vi cnt(nax);
    for(auto x: a)
        cnt[x]++;
    
    SegmentTree1 lt_greater;
    SegmentTree2 rt_lesser(cnt);

    ll tot = 0;
    forn(i,n){
        rt_lesser.update(a[i],-1);
        ll gr = lt_greater.query(a[i]+1,nax-1);
        ll ls = rt_lesser.query(1,a[i]-1);
        tot+=gr*ls;
        lt_greater.update(a[i],1);
    }
    cout<<tot<<endl;

    return 0;
}