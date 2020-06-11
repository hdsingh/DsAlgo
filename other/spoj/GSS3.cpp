#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
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

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}

struct node{
    int sum, pre, suf, ans;
};

class SegmentTree {
    int n;
    vector<node> st;

    node make_node(ll val) {
        node res;
        res.sum = res.pre = res.suf = res.ans = val;
        return res;
    }
public:
    SegmentTree(vector<int>& a) {
        n = a.size();
        if(!n) return;

        int max_size = 4*n;
        st.clear(); st.assign(max_size, node());
        build(1,0,n-1,a);
    }

    node merge(const node &l, const node &r) {
    return node({ l.sum + r.sum,
                    max(l.pre, l.sum + r.pre),
                    max(r.suf, r.sum + l.suf),
                    max(max(l.ans, r.ans), l.suf + r.pre)
                });
    }

    void build(int pos, int l, int r, vi &a){
        if(l==r){
            st[pos] = make_node(a[l]);
            return;
        }
        int mid = (l+r)/2;
        build(2*pos,l,mid,a);
        build(2*pos+1,mid+1,r,a);
        st[pos] = merge(st[2*pos] , st[2*pos+1]);
    }

    void update(int i, int val, int pos, int l, int r) {
        if(l==r){
            st[pos] = make_node(val);
            return;
        }
        int mid = (l+r)/2;
        // if index is <=mid it lies in left part
        if(i<=mid)
            update(i,val,2*pos,l,mid);
        else 
            update(i,val,2*pos+1,mid+1,r);

        st[pos] = merge(st[2*pos] , st[2*pos+1]);
    }
    
    node query(int i, int j, int pos, int l, int r) {
        if(i>r || l>j ) return make_node(INT_MIN);
        if(i<=l && r<=j) return st[pos];
        int mid = (l+r)/2;
        node left = query(i,j,2*pos,l,mid);
        node right = query(i,j,2*pos+1,mid+1,r);
        if(left.sum==INT_MIN)
            return right;
        if(right.sum==INT_MIN)
            return left;
        return merge(left, right);
    }

    void update(int i, int val){
        update(i,val,1,0,n-1);
    }

    ll query(int i,int j){
        node out = query(i,j,1,0,n-1);
        return out.ans;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    vi a(n); forn(i,n){
        cin>>a[i];
    }

    // print(a);

    SegmentTree st(a);
    int m, t, x,y; cin>>m;
    while(m--){
        cin>>t>>x>>y;
        if(t==0){
            st.update(x-1,y);
        }else{
            cout<<st.query(x-1, y-1)<<endl;
        }
    }
    return 0;
}