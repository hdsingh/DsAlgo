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

// after each cut the remaining piece of pizza always 
// has the lower right coordinate at (rows-1,cols-1).
class Solution {
    int n,m,k;
    vvi pre;
    int dp[51][51][11];
public:
    int ways(vector<string>& pizza, int K) {
        n = pizza.size(), m = pizza[0].size();
        k = K;
        pre.assign(n+1, vi(m+1,0));
        // pre : tot apples in pizza[r: ][c: ]

        for(int i=n-1; i>=0; --i){
            for(int j=m-1; j>=0; --j){
                pre[i][j] = pre[i+1][j] + pre[i][j+1] - pre[i+1][j+1] + (pizza[i][j]=='A');
            }
        }
        memset(dp, -1, sizeof(dp));
        return dfs(0,0,0);        
    }

    int dfs(int r, int c, int cuts){
        if(pre[r][c]==0) return 0; // if this part has no apple (invalid)
        if(cuts==k-1) return 1;
        if(~dp[r][c][cuts]) return dp[r][c][cuts];

        int ans = 0;
        // horizontal cuts
        for(int nr = r+1; nr<n; ++nr){
            if(pre[r][c] - pre[nr][c]>0){
                add_self(ans, dfs(nr, c, cuts+1));
            }
        }

        // vertical cuts
        for(int nc = c+1; nc<m; ++nc){
            if(pre[r][c] - pre[r][nc]>0)
                add_self(ans, dfs(r, nc, cuts+1));
        }
    
        return dp[r][c][cuts] = ans;
    }
};

int main(){
    Solution sol; vs pizza; int k, out;
    pizza = { "A..","AAA","..." }, k = 3;
    out = sol.ways(pizza,k); deb(out);
    pizza = { "A..","AA.","..." }, k = 3;
    out = sol.ways(pizza,k); deb(out);
    pizza = { "A..","A..","..." }, k = 1;
    out = sol.ways(pizza,k); deb(out);
    pizza = { ".A..A","A.A..","A.AA.","AAAA.","A.AA." }, k = 5;
    out = sol.ways(pizza,k); deb(out);

    return 0;
}