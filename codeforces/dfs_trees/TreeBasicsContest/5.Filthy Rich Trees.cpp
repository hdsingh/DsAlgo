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
template <typename T> ostream& operator<<(ostream &os, const vector<T> &v){print(v); return os;};
template <typename T> ostream& operator<<(ostream &os, const vector<vector<T>> &vv){print_vv(vv); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const map<T,U>  &m){print_m(m); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const pair<T, U> &pr){debp(pr); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const vector<pair<T, U>> &vp){ print_vp(vp); return os;};

struct node{
    double val = 0;
    node(){};
    node(double V): val(V){};
};

class SegmentTree {
    int n;
    vector<node> st;
public:
    SegmentTree(int N) {
        n = N;
        if(!n) return;

        int max_size = 4*n;
        st.resize(max_size, node());
    }

    node merge(node &l, node &r){
        node cur;
        cur.val = l.val + r.val;
        return cur;
    }
    
    void update(int pos, int sl, int sr, int i, double &val){
        if(sl==sr){
            st[pos] = val;
            return;
        }
        int mid = (sl+sr)/2;
        if(i<=mid)
            update(2*pos,sl,mid,i,val);
        else 
            update(2*pos+1,mid+1,sr,i,val);
        st[pos] = merge(st[2*pos], st[2*pos+1]);
    }

    node query(int pos, int sl, int sr, int l, int r){
        if(sr<l || r<sl) return node(0);
        else if(l<=sl && sr<=r) return st[pos];
        int mid = (sl+sr)/2;
        node left = query(2*pos,sl,mid,l,r);
        node right = query(2*pos+1, mid+1,sr, l,r);
        return merge(left,right);
    }

    void update(int i, double val){
        update(1,0,n-1,i,val);
    }

    double query(int i,int j){
        node q = query(1,0,n-1,i,j);
        return q.val;
    }
};

// Point update, range query
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;  
    cin>>n;
    vvi adj(n+1);
    forn(i,n-1){
        int x, y; cin>>x>>y;
        adj[x].pb(y); adj[y].pb(x);
    }
    vi tin(n+1), tout(n+1);
    int tim = 0;
    function<void(int,int)> dfs = [&](int node, int p){
        tin[node] = tim++;
        for(auto ad: adj[node]){
            if(ad==p) continue;
            dfs(ad, node);
        }
        tout[node] = tim-1;
    };
    dfs(1,0);
    // print(tin,1);
    // print(tout);
    
    SegmentTree st(n+1);
    int q; cin>>q;
    while(q--){
        int t, x, y; cin>>t>>x>>y;
        if(t==1){
            st.update(tin[x], log10(y));
        }else{
            double lx = st.query(tin[x], tout[x]);
            double ly = st.query(tin[y], tout[y]);
            double dif = lx-ly;
            dif = max(log10(1e-9), min(dif, log10(1e9)));
            dif = pow(10,dif);
            cout<<fixed<<setprecision(10)<<dif<<"\n";
        }
    }

    return 0;
}