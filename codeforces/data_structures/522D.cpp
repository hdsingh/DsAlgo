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

// Offline Processing + Range minimum Query 
// 1. Sort the queries by l and move from r to l
// 2. for each a[i] find the distance to the next equal element a[j] to the right
// (if it does not exists then it is taken as inf)
// 3. While moving back update the next value for each l,
// and process its r values, that is find the minimum in the range l to r
// In this way updation of next elements will be done only when required 
// and ensure correctness of operation

const int nax = 5e5 +10;
const int inf = 1e9;
int n,m;

// Range min query
struct node{
    int val = inf;
};

class SegmentTree {
    vector<node> st;

    node make_node(int val) {
        node res;
        res.val = val;
        return res;
    }
public:
    SegmentTree() {
        int max_size = 4*n;
        st.clear(); st.resize(max_size, node());
    }

    void merge(node &cur, node l, node r){
        cur.val = min(l.val, r.val);
    }
    
    void update(int pos, int l, int r, int i, int val) {
        if(l==r){
            st[pos] = make_node(val);
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
        if(i>r || l>j) return make_node(inf);
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


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    vi a(n);
    forn(i,n) cin>>a[i];
    map<int,int> seen;
    vi next(n); // distance to the next same value
    for(int i=n-1; i>=0; --i){
        if(seen.count(a[i]))
            next[i] = seen[a[i]] - i;
        else 
            next[i] = inf;
        seen[a[i]] = i;
    }

    vector<vector<pii>> qs(nax);
    vi ans(m);

    int l, r;
    forn(i,m){
        cin>>l>>r;
        --l,--r;
        qs[l].push_back({r,i});
    }

    SegmentTree st;

    for(int l=n-1; l>=0; --l){
        if(next[l]!=inf){
            st.update(l + next[l], next[l]);
        }

        for(auto q: qs[l]){
            int min_dist = st.query(l,q.first);
            ans[q.second] = (min_dist==inf ? -1 : min_dist);
        }
    }

    for(auto x: ans) cout<<x<<"\n";
    
    

    return 0;
}