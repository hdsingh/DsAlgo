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

const int inf = 1e9+10;

class SegmentTree{
public:
    int n;
    vi st;
    int ans;

    SegmentTree(int _n){
        n = _n;
        st.resize(4*n, inf);
    }

    void update(int pos, int sl, int sr, int i, int val){
        if(sl==sr){
            st[pos] = val;
            return;
        }
        int mid = (sl + sr)/2;
        if(i<=mid)
            update(2*pos, sl, mid, i, val);
        else 
            update(2*pos+1, mid+1, sr, i, val);
        st[pos] = min(st[2*pos], st[2*pos+1]);
    }

    // query+update
    void query(int pos, int sl, int sr, int l, int r, int p){
        if(st[pos]>p) return; // if min_element in this seg is more skip
        if(r<sl || sr<l) return; // outside range
        if(sl==sr){  // reached leaf
            ++ans;
            st[pos] = inf;
            return;
        }
        int mid = (sl+sr)/2;
        // check both sides
        query(2*pos, sl, mid, l, r, p); 
        query(2*pos+1, mid+1, sr, l, r, p);
        st[pos] = min(st[2*pos], st[2*pos+1]);
    }

    void update(int i, int val){
        update(1,0,n-1,i,val);
    }

    int query(int l, int r, int p){
        ans = 0;
        query(1, 0, n-1, l, r, p);
        return ans;
    }
};

// instead of visiting the entire array, just visit the
// specific location, by checking the minimum value in the segment
// inside the range.

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m; cin>>n>>m;
    SegmentTree st(n);
    while(m--){
        int tp; cin>>tp;
        if(tp==1){
            int i, h; cin>>i>>h;
            st.update(i,h);
        }else{
            int l, r, p; cin>>l>>r>>p;
            cout<<st.query(l,r-1,p)<<"\n";
        }
    }
    return 0;
}