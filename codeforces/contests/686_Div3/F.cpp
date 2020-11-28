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

class RMQ{
    int n;
    vi logs;
    vvi table;
public:
    RMQ(vi &a){
        n = a.size();
        logs.assign(n+1,0);
        for(int i=2; i<=n; ++i)
            logs[i] = logs[i/2]+1;
    
        table.assign(logs[n]+1, vi(n));

        for(int i=0; i<=logs[n]; ++i){
            int curLen = 1<<i;
            for(int j=0; j+curLen<=n; ++j){
                if(curLen==1)
                    table[i][j] = a[j];
                else 
                    table[i][j] = min(table[i-1][j], table[i-1][j + curLen/2]);
            }
        }
    }

    int query(int l, int r){
        if(l>r){
            // deb(l,r);
            return 1e9+100;
        }
        int p = logs[r-l+1];
        int plen = 1<<p;
        return min(table[p][l], table[p][r-plen+1]);
    }
};

// lmax is increasing from lt to rt
// for a fixed rt and moving to lt, rmq is decreasing
// So for a fixed value of rt, find the places in lmax having same rmax.
// Now Find if the min of elements bw lt and fixed rt satifies the condition.
// Since RMQ inside is sorted, binary search could be applied.
void solve(vi &a){
    int n = a.size();
    RMQ rmq(a);
    vi lmax(n), rmax(n);
    lmax[0] = a[0];
    fore(i,1,n) lmax[i] = max(a[i], lmax[i-1]);
    rmax[n-1] = a[n-1];
    for(int i=n-2; i>=0; --i)
        rmax[i] = max(a[i], rmax[i+1]);
    
    for(int i=n-1; i>=2; --i){
        int val = rmax[i];
        int lpos = lower_bound(all(lmax), val) - lmax.begin();
        int rpos = upper_bound(all(lmax), val) - lmax.begin();
        if(lpos==rpos || lpos>=i) continue;

        int lt = lpos, rt = min(rpos-1, i-1);
        while(lt<=rt){
            int mid = (lt+rt)/2;
            int cur = rmq.query(mid+1,i-1);
            if(cur==val){
                cout<<"YES\n";
                cout<<mid+1<<" "<<n - (mid+1) - (n-i)<<" "<<n-i<<"\n";
                return;
            }else if(cur<val){
                lt = mid+1;
            }else{
                rt = mid-1;
            }
        }
    }

    cout<<"NO\n";
}   

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n; cin>>n; 
        vi a(n); forn(i,n) cin>>a[i];
        solve(a);
    } 
    return 0;
}