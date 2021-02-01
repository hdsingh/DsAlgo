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
typedef pair<ll, ll> pll;
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


// 1.Mark the good nodes, i.e nodes which are already able to communicate with all the nbrs
// 2. Choose one specific lang and teach it to all the bad nodes who don't already know, keeping
// track of the count.
class Solution {
public:
    int minimumTeachings(int totLang, vector<vector<int>>& langs, vector<vector<int>>& frds) {
        int n = langs.size(); // number of users
        for(auto &lang: langs) for(auto &l: lang) --l;
        for(auto &frd: frds) --frd[0], --frd[1];

        vvi adj(n);
        for(auto frd: frds){
            int x = frd[0], y = frd[1];
            adj[x].pb(y); adj[y].pb(x);
        }
        vvi know(n, vi(totLang));
        forn(i,n){
            for(auto &l: langs[i])
                know[i][l] = 1;
        }

        vi vis(n);
        vi good(n); // if already can communicate with all nbrs

        // check good
        function<void(int)> dfs1 = [&](int node){
            vis[node] = 1;
            
            good[node] = 1;
            for(auto ad: adj[node]){
                bool found = 0;
                for(auto l: langs[node]){
                    if(know[ad][l]){
                        found = 1;
                        break;
                    }
                }
                if(!found){
                    good[node] = 0;
                    break;
                }
            }

            for(auto ad: adj[node]){
                if(!vis[ad])
                    dfs1(ad);
            }
        };

        forn(i,n){
            if(!vis[i]){
                dfs1(i);
            }
        }

        int curAns = 0, curLang = -1;
        
        function<void(int)> dfs = [&](int node){
            vis[node] = 1;
            if(!good[node]){
                if(!know[node][curLang]) 
                    ++curAns;
            }
            for(auto ad: adj[node]){
                if(!vis[ad])
                    dfs(ad);
            }
        };  

        int ans = n;
        forn(lang, totLang){
            curLang = lang;
            curAns = 0;
            vis.assign(n,0);
            forn(i,n){
                if(!vis[i]){
                    dfs(i);
                }
            }
            

            min_self(ans, curAns);
            if(ans==0) break;            
        }

        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; int n; vvi a, b; int out;
    n = 2, a = {{1},{2},{1,2}}, b = {{1,2},{1,3},{2,3}};
    out = sol.minimumTeachings(n,a,b); deb(out);
    n = 3, a = {{2},{1,3},{1,2},{3}}, b = {{1,4},{1,2},{3,4},{2,3}};
    out = sol.minimumTeachings(n,a,b); deb(out);
    n = 11,
    a = {{3,11,5,10,1,4,9,7,2,8,6},{5,10,6,4,8,7},{6,11,7,9},{11,10,4},{6,2,8,4,3},{9,2,8,4,6,1,5,7,3,10},{7,5,11,1,3,4},{3,4,11,10,6,2,1,7,5,8,9},{8,6,10,2,3,1,11,5},{5,11,6,4,2}},
    b = {{7,9},{3,7},{3,4},{2,9},{1,8},{5,9},{8,9},{6,9},{3,5},{4,5},{4,9},{3,6},{1,7},{1,3},{2,8},{2,6},{5,7},{4,6},{5,8},{5,6},{2,7},{4,8},{3,8},{6,8},{2,5},{1,4},{1,9},{1,6},{6,7}};
    out = sol.minimumTeachings(n,a,b); deb(out);
 
    return 0;
}