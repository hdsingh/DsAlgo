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

class Solution{
public:
    bool isInterleave(string &a, string &b, string &c){
        int n = a.size(), m = b.size(), cs = c.size();
        if(n+m!=cs) return false;
        if(!n) return b==c;
        if(!m) return a==c;
        vector<int> dp(m+1);
        
        dp[0] = 1;
        for(int y=1; y<=m; ++y)
            dp[y] = (dp[y-1] && b[y-1]==c[y-1]);

        for(int x=1; x<=n; ++x){
            vector<int> ndp(m+1);
            ndp[0] = (dp[0] && a[x-1]==c[x-1]);
            
            for(int y=1; y<=m; ++y){
                ndp[y] = (a[x-1]==c[x+y-1] && dp[y]);
                if(!ndp[y]){
                    ndp[y] = (b[y-1]==c[x+y-1] && ndp[y-1]);
                }
            }
            
            dp = ndp;
        }
        
        return dp[m];
    }
    
    bool solve2d(string &a, string &b, string &c){
        int n = a.size(), m = b.size(), cs = c.size();
        if(n+m!=cs) return false;
        if(!n) return b==c;
        if(!m) return a==c;
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        
        dp[0][0] = 1;
        for(int x=1; x<=n; ++x)
            dp[x][0] = (dp[x-1][0] && a[x-1]==c[x-1]);
        
        for(int y=1; y<=m; ++y)
            dp[0][y] = (dp[0][y-1] && b[y-1]==c[y-1]);

        for(int x=1; x<=n; ++x){
            for(int y=1; y<=m; ++y){
                dp[x][y] = (a[x-1]==c[x+y-1] && dp[x-1][y]);
                if(!dp[x][y]){
                    dp[x][y] = (b[y-1]==c[x+y-1] && dp[x][y-1]);
                }
            }
        }
        
        return dp[n][m];
    }
    
    bool is_merged(int x, int y, string &a, string &b, string &c, vector<vector<int>> &dp){
        int &ans = dp[x][y];
        if(~ans) return ans;
        ans = false;
        if(x>=a.size() && y>=b.size()){
            return ans = true;
        }
        if(x>=a.size()){
            while(y<b.size() && b[y]==c[x+y])
                ++y;
            return ans = (y==b.size());
        }
        if(y>=b.size()){
            while(x<a.size() && a[x]==c[x+y]) 
                ++x;
            return ans = (x==a.size());
        }
        if(a[x]==c[x+y] && is_merged(x+1,y,a,b,c,dp))
            return ans = true;
        if(b[y]==c[x+y] && is_merged(x,y+1,a,b,c,dp))
            return ans = true;
        
        return false;
    }
};

class Solution0 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = sz(s1), l2 = sz(s2), l3 = sz(s3);
        if(l1+l2!=l3) return 0;
        vector<vb> dp(l1+1, vb(l2+1));

        for(int i=0; i<=l1; ++i){
            for(int j=0; j<=l2; ++j){
                if(i==0 && j==0) dp[i][j] = 1;
                else if(i==0)
                    dp[i][j] = (dp[i][j-1] && s2[j-1]==s3[i+j-1]);
                else if(j==0)
                    dp[i][j] = (dp[i-1][j] && s1[i-1]==s3[i+j-1]);
                else 
                    dp[i][j] = (dp[i-1][j] && s1[i-1]==s3[i+j-1]) || (dp[i][j-1] && s2[j-1]==s3[i+j-1]);
            }
        }
        return dp[l1][l2];
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; string s1, s2, s3; bool out;
    s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc";
    s1 = "q", s2 = "", s3 = "q";
    s1 = "a", s2 = "b", s3 = "ab";
    out = sol.isInterleave(s1,s2, s3); deb(out);
    // print_vv(sol.dp);
    return 0;
}