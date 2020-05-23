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

// The jump offset will always be (-250 to +250). {d-250, to d+250}, 
// since in each step we can jump at most len+1, or len-1
// and (1+ 2+ 3 ... 246)>=30,000.(by always making l+1, or l-1) jumps
// So instead of using prev jump length, which could be much more,
// using jump offset is better.

const int nax = 30001;
int n, d;
vi gems(nax);
int dp[nax][2*250];
int last = 0;

// +250 to counter -ve offset
int dfs(int x, int pjump){
    if(x>last) return 0;
    int offset = pjump - d + 250;
    if(~dp[x][offset]) return dp[x][offset];
    
    dp[x][offset] = 0;
    for(auto nx: {pjump-1, pjump, pjump+1}){
        if(nx>0){
            max_self(dp[x][offset], dfs(x+nx,nx));
        }
    }

    dp[x][offset]+=gems[x];
    return dp[x][offset];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin>>n>>d;
    int x;
    forn(i,n){
        cin>>x;
        gems[x]++;
        last = max(last, x);
    }

    cout<<dfs(d,d)<<endl;
    return 0;
}