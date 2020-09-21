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
const int mod = 998244353;
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
#define x first
#define y second

struct node{
    ll val = 0;
    node(){};
    node(ll V): val(V){};
};

class SegmentTree {
public:
    int n;
    vector<node> st;
    SegmentTree() {
        n = 2e5+10;
        int max_size = 4*n;
        st.clear(); st.resize(max_size, node());
    }

    node merge(node &l, node &r){
        node cur;
        add_self(cur.val, l.val);
        add_self(cur.val, r.val);
        return cur;
    }

    void update(int pos, int sl, int sr, int i, int &val){
        if(sl==sr){
            add_self(st[pos].val, val);
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
    int n, K;
    while(cin>>n>>K){
        vector<pii> segs(K);
        forn(i,K) cin>>segs[i].x>>segs[i].y;
        sort(all(segs));
        vl dp(n+2);
        dp[1] = 1;

        auto sum = [&](int l, int r){
            l = max(0,l); r = max(0,r);
            ll out = 0;
            for(int i=l; i<=r; ++i) 
                add_self(out, dp[i]);
            return out;
        };

        SegmentTree st;
        st.update(1,1);

        for(int i=2; i<=n; ++i){
            for(auto &seg: segs){
                int pl = max(0,i-seg.y);
                int pr = max(0,i-seg.x);
                
                // add_self(dp[i], sum(pl, pr));
                st.update(i, st.query(pl,pr));
            }
        }

        cout<<st.query(n,n)<<"\n";
        // cout<<dp[n]<<"\n";
    }
    return 0;
}