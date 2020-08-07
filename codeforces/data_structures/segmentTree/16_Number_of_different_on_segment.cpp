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

class SegmentTree{
public: 
    int n;
    vvi st;
    int res[40];

    SegmentTree(vi &a){
        n = sz(a);
        st.resize(4*n, vi(40));
        build(1,0,n-1,a);
    }

    void merge(vi &cur, vi &l, vi &r){
        forn(i,40){
            cur[i]=(l[i] + r[i]);
        }
    }

    void build(int pos, int l, int r, vi &a){
        if(l==r){
            st[pos][a[l]] = 1;
            return;
        }
        int mid = (l+r)/2;
        build(2*pos, l, mid, a);
        build(2*pos+1, mid+1, r, a);
        merge(st[pos], st[2*pos], st[2*pos+1]);
    }

    void update(int pos, int sl, int sr, int &i, int &val, int &prev){
        st[pos][prev]--;
        st[pos][val]++;

        if(sl==sr){
            return;
        }
        int mid = (sl+sr)/2;
        if(i<=mid)
            update(2*pos, sl, mid, i, val, prev);
        else 
            update(2*pos+1, mid+1, sr, i, val, prev);
    }

    void query(int pos, int sl, int sr, int l, int r){
        if(r<sl || sr<l) return;
        else if(l<=sl && sr<=r){
            forn(i,40) res[i]+=st[pos][i];
            return;
        }
        int mid = (sl + sr)/2;
        query(2*pos, sl, mid, l, r);
        query(2*pos+1, mid+1, sr, l, r);
    }

    int query(int l, int r){
        memset(res, 0, sizeof(res));
        query(1,0,n-1,l,r);
        int ans = 0;
        forn(i,40){
            if(res[i]) ++ans;
        }
        return ans;
    }
};

// It is better to use vi instead of map, since it introduces another log factor
// While update, instead of merging, we can simple add new and remove prev value 
// for the segments that are affected.
// In query we directly add the values to the single res array.
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin>>n>>m;
    vi a(n); forn(i,n) cin>>a[i], --a[i];
    SegmentTree st(a);
    while(m--){
        int tp, x, y; cin>>tp>>x>>y;
        --x, --y;
        if(tp==1){
            cout<<st.query(x,y)<<"\n";
        }else{
            int prev = a[x];
            a[x] = y;
            st.update(1,0,n-1,x,y, prev);
        }
    }
    return 0;
}