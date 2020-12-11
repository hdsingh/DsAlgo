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
    // other parameters
    node(){};
    // node input definition
    
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
        
        return cur;
    }

    void build(int pos, int lt, int rt){
        if(lt==rt){
            st[pos]  = node(); // allocate specific values
            return;
        }
        int mid = (lt+rt)/2;
        build(2*pos, lt, mid);
        build(2*pos+1, mid+1, rt);
        st[pos] = merge(st[2*pos], st[2*pos+1]);
    }

    void update(int pos, int sl, int sr, int lt, int rt, int val){
        propagate(pos, sl, sr);
        if(rt<sl || sr<lt) return;
        else if(lt<=sl && sr<=rt){
            st[pos].clazy = 1;
            // handle

            propagate(pos, sl, sr);
            return;
        }
        int mid = (sl+sr)/2;
        update(2*pos, sl, mid, lt, rt, val);
        update(2*pos+1, mid+1, sr, lt, rt, val);
        st[pos] = merge(st[2*pos], st[2*pos+1]);
    }

    node query(int pos, int sl, int sr, int lt, int rt){
        propagate(pos, sl, sr);
        if(rt<sl || sr<lt) return node();
        else if(lt<=sl && sr<=rt) return st[pos];
        int mid = (sl+sr)/2;
        node left = query(2*pos, sl, mid, lt, rt);
        node right = query(2*pos+1, mid+1, sr, lt, rt);
        return merge(left, right);        
    }

    node query(int pos, int sl, int sr, int idx){
        propagate(pos, sl, sr);
        if(sl==sr) return st[pos];
        int mid = (sl+sr)/2;
        if(idx<=mid){
            return query(2*pos,sl,mid,idx);
        }
        return query(2*pos+1,mid+1,sr,idx);
        
    }

    void propagate(int pos, int sl, int sr){
        if(!st[pos].clazy) return;
        if(sl!=sr){
            // handle

            st[2*pos].clazy = st[2*pos+1].clazy = 1;
        }
        // handle

        st[pos].clazy = 0;
    }

    void update(int lt, int rt, int v){
        update(1,0,n-1,lt,rt,v);
    }

    ll query(int lt, int rt){
        // return query(1,0,n-1,l,r); // query.val
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin>>n>>m;
    SegmentTree st(n);
    while(m--){
        int tp, l, r, v;
        cin>>tp;
        if(tp==1){
            cin>>l>>r>>v;
            st.update(l,r-1, v);
        }else{
            cin>>l>>r;
            cout<<st.query(l,r-1)<<"\n";
        }
    }
    return 0;
}


// https://codeforces.com/problemset/problem/914/D (Not lazy)
// https://atcoder.jp/contests/abc179/tasks/abc179_f
// https://codeforces.com/problemset/problem/1216/F
