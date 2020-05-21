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

const int inf = 1e7;
const int of = 0;
const int on = 1;

// To turn a bit of, we can use the cost of turning (on or of till i-1)
// to turn on, we can turn the current bit on  +  one of 
// 1. cost of turning on till prev k and intermediate off
// 2. all off till i-1;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    char c;
    int t, n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vi a(n);
        forn(i,n){
            cin>>c;
            a[i] = (c=='1');
        }
        vi pre(n);
        partial_sum(all(a), pre.begin());

        auto sum = [&](int l, int r){
            if(l>r) return 0;
            return pre[r] -  (l>0 ? pre[l-1] : 0);
        };

        vvi dp(n, vi(2,inf));
        dp[0][of] = (a[0]!=of);
        dp[0][on] = (a[0]!=on);

        fore(i,1,n){
            int prev_kth_on = (i-k>=0 ? dp[i-k][on] : 0) + sum(i-k+1,i-1);
            int prev_all_off = pre[i-1];
            min_self(dp[i][on], (a[i]!=on) + min(prev_all_off, prev_kth_on));
            min_self(dp[i][of], a[i] + min(dp[i-1][on], dp[i-1][of]));
        }

        // print_vv(dp);

        int ans = min(dp[n-1][on], dp[n-1][of]);
        cout<<ans<<endl;
    }
    return 0;
}