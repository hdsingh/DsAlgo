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
#define x first
#define y second

const int inf = 1e9;
typedef tuple<int,int,int> ti; // x,y,moves
vvi dirs = {{0,1},{0,-1},{1,0},{-1,0}};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    while(cin>>n>>m){
        pii st, ed;
        cin>>st.x>>st.y>>ed.x>>ed.y;
        vvi grid(n+2, vi(m+2));
        fore(i,1,n+1) fore(j,1,m+1){
            char c; cin>>c;
            grid[i][j] = (c=='.');
        }
        vvi vis(n+1, vi(m+1, inf));
        vis[st.x][st.y] = 0;
        deque<ti> q;
        q.push_front({st.x, st.y, 0});

        while(!q.empty()){
            auto [x,y,moves] = q.front(); q.pop_front();
            if(moves>vis[x][y]) continue;

            bool found = 0;
            for(auto dir : dirs){
                int nx = x + dir[0], ny = y + dir[1];
                if(0<nx && nx<=n && 0<ny && ny<=m && grid[nx][ny]){
                    found = 1;
                    if(moves<vis[nx][ny]){
                        vis[nx][ny] = moves;
                        q.push_front({nx,ny,moves});
                    }                    
                }
            }

            fore(nx, x-2, x+2+1){
                fore(ny, y-2, y+2+1){
                    if(nx==x && ny==y) continue;
                    if(0<nx && nx<=n && 0<ny && ny<=m && grid[nx][ny]){
                        if(moves+1<vis[nx][ny]){
                            vis[nx][ny] = moves+1;
                            q.push_back({nx,ny,moves+1});
                        }
                    }
                }
            }
        }

        int ans = vis[ed.x][ed.y];
        if(ans>=inf) ans = -1;
        cout<<ans<<"\n";

    }
    return 0;
}