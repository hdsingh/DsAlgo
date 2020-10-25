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

// For the same value unite rows with cols where it is present and
// take the max.
// Optimised by setting rank and maxRank, for limited values
class Solution {
    vector<int> par, rank, maxRank;
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> vals;  //a[i][j], i, j
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                vals.push_back({a[i][j], i, j});
            }
        }

        sort(vals.begin(), vals.end());
        par.assign(n+m,0); /// row's, col's max rank
        rank.assign(n+m,0);
        maxRank.assign(n+m,0);
        vector<vector<int>> out(n, vector<int>(m));

        for(int i=0; i<n*m; ){
            // init.
            int j = i;
            while(j<n*m && vals[j][0]==vals[i][0]){
                int x = vals[j][1], y = vals[j][2];
                par[x] = x, par[n + y] = n + y;
                maxRank[x] = rank[x], maxRank[n+y] = rank[n+y];
                ++j;
            }

            j = i;
            while(j<n*m && vals[j][0]==vals[i][0]){
                int x = vals[j][1], y = vals[j][2];
                unite(x,n+y);
                ++j;
            }

            j = i;
            while(j<n*m && vals[j][0]==vals[i][0]){
                int x = vals[j][1], y = vals[j][2]; 
                out[x][y] = rank[x] = rank[n+y] = maxRank[find_par(x)] + 1;
                ++j;
            }
 
            i = j;          
        }

        return out;
    }

    int find_par(int x){
        if(x==par[x]) return x;
        return par[x] = find_par(par[x]);
    }

    void unite(int a, int b){
        a = find_par(a);
        b = find_par(b);
        if(a==b) return;
        // rank[a]>rank[b];
        if(rank[a]<rank[b])
            swap(a,b);
        par[b] = a;
    }
};

class Solution0 {
    vector<int> par, rank;
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> vals;  //a[i][j], i, j
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                vals.push_back({a[i][j], i, j});
            }
        }

        sort(vals.begin(), vals.end());
        par.assign(n+m,0); /// row's, col's max rank
        rank.assign(n+m,0);
        vector<vector<int>> out(n, vector<int>(m));

        for(int i=0; i<n*m; ){
            vector<int> nrank = rank;
            iota(par.begin(), par.end(), 0);
            int j = i;
            while(j<n*m && vals[j][0]==vals[i][0]){
                int x = vals[j][1], y = vals[j][2];
                unite(x,n+y);
                ++j;
            }

            j = i;
            while(j<n*m && vals[j][0]==vals[i][0]){
                int x = vals[j][1], y = vals[j][2]; 
                out[x][y] = nrank[x] = nrank[n+y] = rank[find_par(x)] + 1;
                ++j;
            }

            rank = nrank;  
            i = j;          
        }

        return out;
    }

    int find_par(int x){
        if(x==par[x]) return x;
        return par[x] = find_par(par[x]);
    }

    void unite(int a, int b){
        a = find_par(a);
        b = find_par(b);
        if(a==b) return;
        // rank[a]>rank[b];
        if(rank[a]<rank[b])
            swap(a,b);
        par[b] = a;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; vvi mat; vvi out;
    mat = {{1,2},{3,4}};
    out = sol.matrixRankTransform(mat);  cout<<out;
    mat = {{7,7},{7,7}};
    out = sol.matrixRankTransform(mat); cout<<out;
    mat = {{20,-21,14},{-19,4,19},{22,-47,24},{-19,4,19}};
    out = sol.matrixRankTransform(mat); cout<<out;
    mat = {{7,3,6},{1,4,5},{9,8,2}};
    out = sol.matrixRankTransform(mat); cout<<out;
    mat = {{-37,-50,-3,44},{-37,46,13,-32},{47,-42,-3,-40},{-17,-22,-39,24}};
    out = sol.matrixRankTransform(mat); cout<<out;

    return 0;
}