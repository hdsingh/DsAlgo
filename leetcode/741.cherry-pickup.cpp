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

const int nax = 50;
const int inf = 1e4;

// Move 2 person down
class Solution0 {
    int n;
    int dp[nax][nax][nax];
    vvi grid;
public:
    int cherryPickup(vector<vector<int>>& G) {
        memset(dp, -1, sizeof(dp));
        grid = G;
        n = grid.size();
        return max(0, dfs(0,0,0));
    }

    int dfs(int r1, int c1, int c2){
        int r2 = r1 + c1 - c2;
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1) return -inf;
        if(dp[r1][c1][c2]!=-1) return dp[r1][c1][c2];
        if(r1==n-1 && c1==n-1) return grid[r1][c1];

        int ans = dfs(r1, c1+1, c2); // L, D
        max_self(ans, dfs(r1, c1+1, c2+1)); // L, L
        max_self(ans, dfs(r1+1, c1, c2));   // D, D
        max_self(ans, dfs(r1+1, c1, c2+1)); // D, L 
        ans+=grid[r1][c1];
        if(r1!=r2) ans+=grid[r2][c2];

        return dp[r1][c1][c2] = ans;
    }
};

// By considering the fact that 2 person are moving
// 1 step at a time,
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vvi dp(n, vi(n, -inf)); 
        // max sum that can be obtained at r1, r2;

        dp[0][0] = grid[0][0];
        for(int step=1; step<=2*n-2; ++step){
            vvi dp2(n, vi(n, -inf));

            for(int r1=max(0, step-(n-1)); r1<=min(n-1, step); ++r1){
                for(int r2=max(0, step-(n-1)); r2<=min(n-1, step); ++r2){
                    int c1 = step - r1, c2 = step-r2;
                    if(grid[r1][c1]==-1 || grid[r2][c2]==-1) continue;
                    int val = grid[r1][c1];
                    if(r1!=r2) val+=grid[r2][c2];

                    if(r1 && r2) max_self(dp2[r1][r2], dp[r1-1][r2-1] + val);
                    if(r1) max_self(dp2[r1][r2], dp[r1-1][r2] + val);
                    if(r2) max_self(dp2[r1][r2], dp[r1][r2-1] + val);
                    max_self(dp2[r1][r2], dp[r1][r2] + val);
                }
            }

            dp = dp2;
        }
        return max(0, dp[n-1][n-1]);      
    }
};


int main(){
    Solution sol; vvi a;
    a ={{0, 1, -1},
        {1, 0, -1},
        {1, 1,  1}};
    a = {{1,1,1,1,1},{1,1,1,1,1},{1,1,-1,1,1},{0,-1,-1,1,1},{1,1,1,1,1}};
    // a = {{1,1,1,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,0,0,1},{1,0,0,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,1,1,1}};

    int out = sol.cherryPickup(a); deb(out);
    return 0;
}