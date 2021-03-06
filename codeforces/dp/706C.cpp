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

const ll inf = 1e15L;

int main(){
    int n;
    while(cin>>n){
        vi c(n); forn(i,n) cin>>c[i];
        vs ss(n), rs(n);
        forn(i,n){
            cin>>ss[i];
            rs[i] = ss[i];
            reverse(all(rs[i]));
        }

        vvl dp(n, vl(2,inf));
        // min cost till ith pos, if it is simple/reversed(0/1)
        string mn = "";
        dp[0][0] = 0;
        dp[0][1] = c[0];

        fore(i,1,n){
            // prev simple
            if(ss[i-1]<=ss[i])
                min_self(dp[i][0], dp[i-1][0]);
            
            if(ss[i-1]<=rs[i])
                min_self(dp[i][1], dp[i-1][0] + c[i]);

            // prev rev
            if(rs[i-1]<=ss[i])
                min_self(dp[i][0], dp[i-1][1]);

            if(rs[i-1]<=rs[i])
                min_self(dp[i][1], dp[i-1][1] + c[i]);
        }

        ll min_cost = min(dp[n-1][0], dp[n-1][1]);
        if(min_cost>=inf){
            cout<<-1<<endl;
            continue;
        }
        cout<<min_cost<<endl;
        
    }
    return 0;
}