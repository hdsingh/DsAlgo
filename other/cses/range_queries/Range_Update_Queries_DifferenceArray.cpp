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

class SegmentTree{
public:
    int n;
    vl st;

    SegmentTree(vl &a){
        n = sz(a);
        st.resize(4*n);
        build(1,0,n-1,a);
    }

    void build(int pos, int l, int r, vl &a){
        if(l==r){
            st[pos] = a[l];
            return;
        }
        int mid = (l+r)/2;
        build(2*pos, l, mid, a);
        build(2*pos+1, mid+1, r, a);
        st[pos] = st[2*pos] + st[2*pos+1];
    }

    void update(int pos, int sl, int sr, int i, int val){
        if(sl==sr){
            st[pos]+=val;
            return;
        }
        int mid = (sl+sr)/2;
        if(i<=mid)
            update(2*pos, sl, mid, i, val);
        else 
            update(2*pos+1, mid+1, sr, i, val);
        st[pos] = st[2*pos] + st[2*pos+1];
    }

    ll query(int pos, int sl, int sr, int l, int r){
        if(r<sl || sr<l) return 0;
        else if(l<=sl && sr<=r) return st[pos];
        int mid = (sl+sr)/2;
        ll left = query(2*pos, sl, mid, l, r);
        ll right = query(2*pos+1, mid+1, sr, l, r);
        return left + right;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin>>n>>m;
    vl a(n+1); forn(i,n) cin>>a[i];
    vl dif(n+1);
    dif[0] = a[0];
    fore(i,1,n+1)
        dif[i] = a[i] - a[i-1];
    SegmentTree st(dif);
    while(m--){
        int tp; cin>>tp;
        if(tp==1){
            int l, r, v; cin>>l>>r>>v; --l, --r;
            st.update(1,0,n,l,v);
            st.update(1,0,n,r+1,-v);
        }else{
            int p; cin>>p; --p;
            cout<<st.query(1,0,n,0,p)<<"\n";
        }
    }
    return 0;
}