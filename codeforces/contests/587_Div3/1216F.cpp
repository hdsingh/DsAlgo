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
template <typename T>void print(const T &v, bool show_index = false){int w = 3;if(show_index){for(int i=0; i<sz(v); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<endl;}
template <typename T>void print_vv(const T &vv){if(sz(vv)==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<sz(*vv.begin()); j++)cout<<setw(w)<<j<<" ";cout<<endl;int i = 0;for(auto &v: vv){cout<<i++<<" {";for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<"},\n";}cout<<endl;}
template <typename T> ostream& operator<<(ostream &os, const vector<T> &v){print(v); return os;};
template <typename T> ostream& operator<<(ostream &os, const vector<vector<T>> &vv){print_vv(vv); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const map<T,U>  &m){print_m(m); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const pair<T, U> &pr){debp(pr); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const vector<pair<T, U>> &vp){ print_vp(vp); return os;};

ll inf =  1e18L;
class SegmentTree{
public:
    int n;
    vl a, lazy;
    SegmentTree(int N){
        n = N;
        a.assign(4*n, inf);
        lazy.assign(4*n, inf); 
    }

    ll query(int pos, int sl, int sr, int idx){
        propagate(pos, sl, sr);
        if(sl==sr) return a[pos];
        int mid = (sl+sr)/2;
        if(idx<=mid){
            return query(2*pos,sl,mid,idx);
        }
        return query(2*pos+1,mid+1,sr,idx);
        
    }

    void update(int pos, int sl, int sr, int lt, int rt, ll val){
        propagate(pos,sl,sr);
        if(rt<sl || sr<lt) return;
        if(lt<=sl && sr<=rt){
            if(val<lazy[pos]){
                lazy[pos] = val;
                propagate(pos,sl,sr);
            }
            return;
        }
        int mid = (sl+sr)/2;
        update(2*pos,sl,mid,lt,rt,val);
        update(2*pos+1,mid+1,sr,lt,rt,val);
        min_self(a[pos], min(a[2*pos], a[2*pos+1]));
    }

    void propagate(int pos, int sl, int sr){
        if(lazy[pos]==inf) return;
        if(sl!=sr){
            min_self(lazy[2*pos], lazy[pos]);
            min_self(lazy[2*pos+1], lazy[pos]);
        }
        min_self(a[pos], lazy[pos]);
        lazy[pos] = inf;
    }

    ll query(int idx){
        if(idx<0 || idx>=n) return 0;
        return query(1,0,n-1,idx);
    }

    void update(int lt, int rt, ll val){
        min_self(rt,n-1);
        max_self(lt,0);
        update(1,0,n-1,lt,rt,val);
    }
};

// Point query  +  Range min update
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, K; 
    while(cin>>n>>K){
        string can; cin>>can;
        SegmentTree st(n);  
        forn(i,n){
            if(can[i]=='1'){
                ll prevCost = st.query(i-K-1);
                ll curCost = prevCost + i + 1;
                st.update(i-K,i+K, curCost);
            }else{
                ll prevCost = st.query(i-1);
                st.update(i,i,prevCost + i+1);
            }
        }
        cout<<st.query(n-1)<<"\n";
    }
    return 0;
}