#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) int((a).size())
typedef long long ll;
typedef vector<int> vi;

const int inf = 1e9+10;

struct node{
    int val;
    node(){};
    node(int V): val(V) {};
};

class SegmentTree{
public:
    int n;
    vector<node> st;

    SegmentTree(vi &a){
        n = sz(a);
        st.resize(4*n);
        build(1,0,n-1, a);
    }

    void build(int pos, int l, int r, vi &a){
        if(l==r){
            st[pos] = node(a[l]);
            return;
        }
        int mid = (l+r)/2;
        build(2*pos, l, mid, a);
        build(2*pos+1, mid+1,r,a);
        merge(st[pos], st[2*pos], st[2*pos+1]);
    }

    void merge(node &cur, node &l, node &r){
        cur.val = min(l.val, r.val);   
    }

    node query(int pos, int sl, int sr, int l, int r){
        if(sr<l || r<sl) return node(inf);
        else if(l<=sl && sr<=r) return st[pos];
        int mid = (sl+sr)/2;
        node left = query(2*pos, sl, mid, l, r);
        node right = query(2*pos+1, mid+1, sr, l, r);
        node cur;
        merge(cur, left, right);
        return cur;
    }

    void update(int pos, int sl, int sr, int i, int &val){
        if(sl==sr){
            st[pos] = node(val);
            return;
        }
        int mid = (sl + sr)/2;
        if(i<=mid) 
            update(2*pos, sl, mid, i, val);
        else 
            update(2*pos+1, mid+1, sr, i, val);
        merge(st[pos], st[2*pos], st[2*pos+1]);
    }

    int query(int l, int r){
        return query(1,0,n-1, l, r).val;
    }

    void update(int i, int val){
        update(1,0,n-1,i,val);
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m; cin>>n>>m;
    vi a(n); forn(i,n) cin>>a[i];
    SegmentTree st(a);

    while(m--){
        int t, l,r; cin>>t>>l>>r;
        if(t==1){
            st.update(l,r);
        }else{
            cout<<st.query(l,r-1)<<"\n";
        }
    }

    return 0;
}