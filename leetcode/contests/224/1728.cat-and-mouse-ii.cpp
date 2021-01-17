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

#define x first
#define y second

int dp[8][8][8][8][101];
vector<pii> moves1[8][8], moves2[8][8];
// mouse moves, cat moves

class Solution {
    const vector<pii> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    bool canMouseWin(vector<string>& grid, int cJump, int mJump) {
        int n = grid.size(), m = grid[0].size();
        pii mpos = {-1,-1}, cpos(mpos), fpos(mpos);
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]=='C'){
                    cpos = {i,j};
                }else if(grid[i][j]=='M'){
                    mpos = {i,j};
                }else if(grid[i][j]=='F'){
                    fpos = {i,j};
                }
            }
        }


        auto getAdj = [&](int x, int y, int jump){
            vector<pii> out;
            out.pb({x,y}); // stay at same
            for(auto [dx,dy]: dirs){
                for(int i=1; i<=jump; ++i){
                    int nx = x + dx*i, ny = y + dy*i;
                    if(0<=nx && nx<n && 0<=ny && ny<m && grid[nx][ny]!='#')
                        out.pb({nx,ny});
                    else break;
                }
            }
            return out; 
        };  

        for(int x=0; x<n; ++x){
            for(int y=0; y<m; ++y){
                moves1[x][y] = getAdj(x,y,mJump);
                moves2[x][y] = getAdj(x,y,cJump);
            }
        }

        memset(dp, -1, sizeof(dp));
        
        // can mouse win
        function<int(int,int,int,int,int)> dfs = [&](int mx, int my, int cx, int cy, int d){
            if(grid[mx][my]=='F') return 1;
            if(grid[cx][cy]=='F' || d==0 || (cx==mx && cy==my)) return 0;
            int &ans = dp[mx][my][cx][cy][d];
            if(~ans) return ans;

            bool mouseTurn = (d%2==0);
            if(mouseTurn){
                for(auto [nx, ny]: moves1[mx][my])
                    if(dfs(nx,ny,cx,cy,d-1))
                        return ans = 1;
                return ans = 0;
            }else{
                for(auto [nx, ny]: moves2[cx][cy])
                    if(dfs(mx,my,nx,ny,d-1)==0) // if mouse fails
                        return ans = 0; // return cat wins
                return ans = 1;
            }
            return ans; // redundant
        };

        return dfs(mpos.x, mpos.y, cpos.x, cpos.y, 70);
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; vs grid; int catJump, mouseJump; int out;
    grid = {"####F","#C...","M...."}, catJump = 1, mouseJump = 2;
    out = sol.canMouseWin(grid, catJump, mouseJump); deb(out);
    grid = {"M.C...F"}, catJump = 1, mouseJump = 4;
    out = sol.canMouseWin(grid, catJump, mouseJump); deb(out);

    grid = {"M.C...F"}, catJump = 1, mouseJump = 3;
    out = sol.canMouseWin(grid, catJump, mouseJump); deb(out);
    
    grid = {"C...#","...#F","....#","M...."}, catJump = 2, mouseJump = 5;
    out = sol.canMouseWin(grid, catJump, mouseJump); deb(out);
    grid = {".M...",
            "..#..",
            "#..#.",
            "C#.#.",
            "...#F"}, catJump = 3, mouseJump = 1;
    out = sol.canMouseWin(grid, catJump, mouseJump); deb(out);
    grid = {".....","...C.","...#.","...#M","F..#."}, catJump = 1, mouseJump = 3;
    out = sol.canMouseWin(grid, catJump, mouseJump); deb(out);

    return 0;
}