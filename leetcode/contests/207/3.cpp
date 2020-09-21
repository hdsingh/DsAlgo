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

const ll inf = 1e18;
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vvl neg(n, vl(m, inf)), pos(n, vl(m, -inf));
        // min neg and max pos
        min_self(neg[0][0], grid[0][0]);
        max_self(pos[0][0], grid[0][0]);
        for(int j=1; j<m; ++j){
            min_self(neg[0][j], neg[0][j-1]*grid[0][j]);
            min_self(neg[0][j], pos[0][j-1]*grid[0][j]);
            max_self(pos[0][j], neg[0][j-1]*grid[0][j]);
            max_self(pos[0][j], pos[0][j-1]*grid[0][j]);
        }

        for(int i=1; i<n; ++i){
            min_self(neg[i][0], neg[i-1][0]*grid[i][0]);
            min_self(neg[i][0], pos[i-1][0]*grid[i][0]);
            max_self(pos[i][0], neg[i-1][0]*grid[i][0]);
            max_self(pos[i][0], pos[i-1][0]*grid[i][0]);
        }

        for(int i=1; i<n; ++i){
            for(int j=1; j<m; ++j){
                min_self(neg[i][j], neg[i-1][j]*grid[i][j]);
                min_self(neg[i][j], neg[i][j-1]*grid[i][j]);
                min_self(neg[i][j], pos[i-1][j]*grid[i][j]);
                min_self(neg[i][j], pos[i][j-1]*grid[i][j]);

                max_self(pos[i][j], neg[i-1][j]*grid[i][j]);
                max_self(pos[i][j], neg[i][j-1]*grid[i][j]);
                max_self(pos[i][j], pos[i-1][j]*grid[i][j]);
                max_self(pos[i][j], pos[i][j-1]*grid[i][j]);
            }
        }

        // print_vv(grid);
        // print_vv(pos);
        // print_vv(neg);
        if(pos[n-1][m-1]<0) return -1;
        return pos[n-1][m-1]%mod;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; vvi grid; int out;

    grid = {{-1,-2,-3},
        {-2,-3,-3},
        {-3,-3,-2}};
    out = sol.maxProductPath(grid); deb(out);

    grid = {{1,-2,1},
        {1,-2,1},
        {3,-4,1}};
    out = sol.maxProductPath(grid); deb(out);


    grid = {{1, 3},
        {0,-4}};
    out = sol.maxProductPath(grid); deb(out);

    grid = {{ 1, 4,4,0},
        {-2, 0,0,1},
        { 1,-1,1,1}};

    out = sol.maxProductPath(grid); deb(out);

    return 0;
}