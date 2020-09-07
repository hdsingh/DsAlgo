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
const int nax = 202;
int n, K;
int dp[nax][nax][nax];
// max subs that can be obtained till pos i, having j "a"s and doing k moves
string s, t;

// cntof a before pos, moves before pos
int dfs(int pos, int cnta, int moves){
    if(moves>K) return -inf;
    if(pos==n) return 0;
    int &ans = dp[pos][cnta][moves];
    if(~ans) return ans;
    ans = 0;
    // dont change
    if(s[pos]==t[1]){
        max_self(ans, cnta + dfs(pos+1, cnta, moves));
    }else{
        max_self(ans, dfs(pos+1, cnta + (s[pos]==t[0]), moves) );
    }

    // replace with a
    if(s[pos]!=t[0])
        max_self(ans, dfs(pos+1, cnta + 1, moves+1));    

    // replace with b
    if(s[pos]!=t[1]){
        max_self(ans, cnta + dfs(pos+1, cnta, moves+1));
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin>>n>>K;
    cin>>s>>t;

    if(t[0]==t[1]){
        int a = count(all(s), t[0]);
        int can = min(K, n-a);
        a+=can;
        int ans = a*(a-1)/2;
        ans = max(0, ans);
        cout<<ans<<"\n";
    }else{
        dfs(0,0,0);

        cout<<dp[0][0][0]<<"\n";
    }
    return 0;
}