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

// TLE
class Solution0 {
    int n;
    vvi hats;
    vector<unordered_map<ll,int>> dp;
public:
    int numberWays(vector<vector<int>>& H) {
        hats = H;
        n = hats.size();
        dp.clear(); dp.resize(n);
    
        ll used = 0;
        return dfs(0,used);
    }

    int dfs(int pos, ll used){
        if(pos==n){
            return 1;
        }
        if(dp[pos].count(used)) return dp[pos][used];

        int ans =  0;
        for(auto h: hats[pos]){
            if( !((used>>h)&1) ){
                add_self(ans, dfs(pos+1, used|(1LL<<h)));
            }
        }

        return dp[pos][used] = ans;
    }
};
// Complexity: n*n*(2^40)


// instead of checking if a hat has been used, 
// check if a person has been assigned hat
class Solution1 {
    int n, full;
    vvi by; // hat h is preffered by {p1, p2, p3}
    int dp[41][1<<10];
public:
    int numberWays(vector<vector<int>>& hats) {
        memset(dp, -1, sizeof(dp));
        n = hats.size();
        full = (1<<n)-1;
        by.clear(); by.resize(41);
        for(int p=0; p<n; ++p){
            for(auto  h: hats[p]){
                by[h].push_back(p);
            }
        }

        return dfs(0, 0);
    }

    int dfs(int h, int has_hat){
        if(has_hat==full) return 1;
        if(h>40) return 0;
        if(~dp[h][has_hat]) return dp[h][has_hat];

        int ans = dfs(h+1,has_hat); // don't wear this hat 
        // since there are more hats and less, hence some will not be worn
        for(auto p: by[h]){
            if(!((has_hat>>p)&1)){
                add_self(ans, dfs(h+1, has_hat|(1<<p)));
            }
        }

        return dp[h][has_hat] = ans;
    }
};
// Complexity: h*h*2^10.


// Iterative
class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        vvi by(41); // hat h is preffered by person {p1,p2}

        for(int p=0; p<n; ++p)
            for(auto h: hats[p])
                by[h].push_back(p);

        vi dp(1<<n);
        dp[0] = 1;

        for(int hat=0; hat<41; ++hat){
            for(int mask=(1<<n)-1; mask>=0; --mask){ // person already wearing hat
                for(auto p: by[hat]){
                    if((mask>>p)&1) continue;
                    add_self(dp[mask|(1<<p)], dp[mask]);
                }
            }
        }

        return dp[(1<<n)-1];
    }
};


int main(){
    Solution sol;
    vector<vvi> hats = {
    {{3,4},{4,5},{5}},
    {{3,5,1},{3,5}},
    {{1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}},
    {{1,2,3},{2,3,5,6},{1,3,7,9},{1,8,9},{2,5,7}},
    {{1,2,4,6,7,8,9,11,12,13,14,15,16,18,19,20,23,24,25},{2,5,16},{1,4,5,6,7,8,9,12,15,16,17,19,21,22,24,25},{1,3,6,8,11,12,13,16,17,19,20,22,24,25},{11,12,14,16,18,24},{2,3,4,5,7,8,13,14,15,17,18,21,24},{1,2,6,7,10,11,13,14,16,18,19,21,23},{1,3,6,7,8,9,10,11,12,14,15,16,18,20,21,22,23,24,25},{2,3,4,6,7,10,12,14,15,16,17,21,22,23,24,25}},

    };

    for(auto h: hats){
        int ans = sol.numberWays(h); deb(ans);
    }

    return 0;
}