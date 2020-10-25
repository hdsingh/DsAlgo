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

class Solution {
    int n, m, mid;
    bool reached;
    vvi a;
    vector<vector<bool>> vis;
    vvi dirs = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    int minimumEffortPath(vector<vector<int>>& a) {
        n = a.size(), m = a[0].size();
        this->a = a;
        if(n==1 && m==1) return 0;

        int lt = INT_MAX, rt = INT_MIN;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(i+1<n){
                    int dif = abs(a[i][j] - a[i+1][j]);
                    lt = min(lt, dif); rt = max(rt, dif);
                }
                if(j+1<m){
                    int dif = abs(a[i][j] - a[i][j+1]);
                    lt = min(lt, dif); rt = max(rt, dif);
                }
            }
        }
        
        int ans = lt;
        lt--, rt++;
        while(1+lt<rt){
            mid = lt + (rt-lt)/2;
            if(can(mid)){
                ans = mid; rt = mid;
            }else{
                lt = mid;
            }
        }

        return ans;
    }

    bool can(int mid){
        vis.assign(n, vector<bool>(m, false));
        reached = 0;
        dfs(0,0);
        return reached;
    }

    void dfs(int x, int y){
        vis[x][y] = 1;
        if(x==n-1 && y==m-1){
            reached = true;
            return;
        }
        if(reached) return;

        if(x+1<n && !vis[x+1][y] && abs(a[x+1][y]-a[x][y])<=mid){
            dfs(x+1,y);
        }

        if(y+1<m && !vis[x][y+1] && abs(a[x][y+1]-a[x][y])<=mid){
            dfs(x,y+1);
        }

        if(x-1>=0 && !vis[x-1][y] && abs(a[x-1][y]-a[x][y])<=mid){
            dfs(x-1,y);
        }

        if(y-1>=0 && !vis[x][y-1] && abs(a[x][y-1]-a[x][y])<=mid){
            dfs(x,y-1);
        }
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; int out;
    vvi a; 
    a = {{1,2,2},{3,8,2},{5,3,5}};
    out = sol.minimumEffortPath(a); deb(out); 
    // a = {{1,2,3},{3,8,4},{5,3,5}};
    // out = sol.minimumEffortPath(a); deb(out); 
    // a = {{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}};
    // out = sol.minimumEffortPath(a); deb(out); 



    return 0;
}