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

class Solution0 {
    int n,m;
    vvi grid;
    int dp[71][71][71];
public:
    int cherryPickup(vector<vector<int>>& G) {
        memset(dp, -1, sizeof(dp));
        grid = G;
        n = grid.size(), m = grid[0].size();
        return dfs(0,0,m-1);
    }

    int dfs(int r, int c1, int c2){
        if(c1<0 || c2<0 || c1>=m || c2>=m || r>=n) return 0;
        if(~dp[r][c1][c2]) return dp[r][c1][c2];
        int ans = 0;

        for(int nc1=c1-1; nc1<=c1+1; ++nc1){
            for(int nc2=c2-1; nc2<=c2+1; ++nc2){
                max_self(ans, dfs(r+1, nc1, nc2));
            }
        }

        ans+=grid[r][c1]; 
        if(c1!=c2) ans+=grid[r][c2];
        return dp[r][c1][c2] = ans;
    }
};

const int inf = 1e5;
class Solution1 {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vvi dp(m, vi(m,-inf));
        // gain in rth row, when rob 1 is in C1, and rob 2 is in C2

        dp[0][m-1] = grid[0][0] + grid[0][m-1];
        
        for(int r=0; r<n-1; ++r){
            vvi ndp(m, vi(m,-inf));
            for(int c1=0; c1<m; ++c1){
                for(int c2=0; c2<m; ++c2){
                    for(int nc1=c1-1; nc1<=c1+1; ++nc1){
                        for(int nc2=c2-1; nc2<=c2+1; ++nc2){
                            if(nc1<0 || nc2<0 || nc1>=m || nc2>=m) continue;
                            int val = grid[r+1][nc1];
                            if(nc1!=nc2) val+=grid[r+1][nc2];
                            max_self(ndp[nc1][nc2], dp[c1][c2] + val);
                        }
                    }
                }
            }
            dp = ndp;
        }

        int ans = 0;
        forn(c1,m){
            forn(c2,m){
                max_self(ans,dp[c1][c2]);
            }
        }
        return ans; 
    }
};


class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dp[2][m][m];
        memset(dp, -1, sizeof(dp));
        // gain in rth row, when rob 1 is in C1, and rob 2 is in C2

        dp[0][0][m-1] = grid[0][0] + grid[0][m-1];
        
        for(int r=0; r<n-1; ++r){
            int now = (r&1); int nxt = !now;
            memset(dp[nxt], -1, sizeof(dp[nxt]));

            for(int c1=0; c1<m; ++c1){
                for(int c2=0; c2<m; ++c2){
                    if(dp[now][c1][c2]==-1) continue;

                    for(int nc1=c1-1; nc1<=c1+1; ++nc1){
                        for(int nc2=c2-1; nc2<=c2+1; ++nc2){
                            if(nc1<0 || nc2<0 || nc1>=m || nc2>=m) continue;
                            int val = grid[r+1][nc1];
                            if(nc1!=nc2) val+=grid[r+1][nc2];
                            max_self(dp[nxt][nc1][nc2], dp[now][c1][c2] + val);
                        }
                    }
                }
            }
        }

        int now = (n-1)&1;
        int ans = 0;
        forn(c1,m){
            forn(c2,m){
                max_self(ans,dp[now][c1][c2]);
            }
        }
        return ans; 
    }
};

int main(){
    Solution sol;
    vector<vvi> grids = {
        {{3,1,1},{2,5,1},{1,5,5},{2,1,1}},

        {{1,0,0,0,0,0,1},{2,0,0,0,0,3,0},{2,0,9,0,0,0,0},{0,3,0,5,4,0,0},{1,0,2,3,0,0,6}},

        {{1,0,0,3},{0,0,0,3},{0,0,3,3},{9,0,3,3}},

        {{1,1},{1,1}},

        {{0,8,7,10,9,10,0,9,6},{8,7,10,8,7,4,9,6,10},{8,1,1,5,1,5,5,1,2},{9,4,10,8,8,1,9,5,0},{4,3,6,10,9,2,4,8,10},{7,3,2,8,3,3,5,9,8},{1,2,6,5,6,2,0,10,0}},

    };

    for(auto grid: grids){
        int out = sol.cherryPickup(grid); deb(out);
    }
    return 0;
}