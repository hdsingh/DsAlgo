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
    vi st;

    SegmentTree(int _n){
        n = _n; 
        st.resize(4*n);
    }

    void update(int pos, int sl, int sr, int &i, int &val){
        if(sl==sr){
            st[pos]+=val;
            return;
        }
        int mid = (sl+sr)/2;
        if(i<=mid)
            update(2*pos, sl, mid, i, val);
        else update(2*pos+1, mid+1, sr, i, val);
        st[pos] = st[2*pos] + st[2*pos+1];
    }

    int query(int pos, int sl, int sr, int l, int r){
        if(sr<l || r<sl) return 0;
        else if(l<=sl && sr<=r) return st[pos];
        int mid = (sl+sr)/2;
        return query(2*pos, sl, mid, l, r) + query(2*pos+1, mid+1, sr, l, r);
    }

    int query(int l, int r){
        return query(1, 0, n-1, l, r);
    }

    void update(int pos, int val){
        update(1,0,n-1,pos,val);
    }
};

// RSumQ: Point Update, Range Query
// for any element that appears, turn on the st[i]
// at its last pos. If it has been on previously,
// turn of the previous pos and turn this pos on.
// For an ele, keep only its last pos on.
typedef tuple<int,int,int> tii;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, Q;
    while(cin>>n>>Q){
        SegmentTree st(n+1);
        vi a(n); forn(i,n) cin>>a[i];
        vi ans(Q);
        vector<tii> qs(Q); // {r,l,id}
        forn(i,Q){
            int l,r; cin>>l>>r; 
            --r, --l;
            qs[i] = {r,l,i};
        }
        sort(all(qs));

        vi last(n+1,-1);

        int prevr = -1;
        for(auto q: qs){
            auto [r,l,i] = q;
            while(prevr<r){
                ++prevr;
                // seen
                if(last[a[prevr]]!=-1){
                    st.update(last[a[prevr]],-1);
                }
    
                last[a[prevr]] = prevr;
                st.update(prevr,1);
            }
            ans[i] = st.query(l,r);
        }

        print(ans);

    }
    return 0;
}