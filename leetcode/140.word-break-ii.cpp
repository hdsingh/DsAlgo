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

class Solution1 {
    string s; set<string> dict;
    int n;
    map<int,set<string>> dp;
    int mn_len, mx_len;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        this->s = s; n = sz(s);
        mn_len = 1e4; mx_len = 0; 
        for(auto & w: wordDict){
            dict.insert(w);
            mn_len = min(mn_len, sz(w));
            mx_len = max(mx_len, sz(w));
        }      
        // deb(n, mn_len, mx_len);  
        if(!isbreakable()) return {};
        dfs(0);
        return vector<string>(all(dp[0]));
    }

    bool isbreakable(){
        vb dp1(n+1);
        dp1[0] = 1;

        for(int i=1; i<=n; ++i){
            for(int j=i-1; j>=0; --j){
                if(dp1[j] && dict.count(s.substr(j,i-j))){
                    dp1[i] = 1; 
                    break;
                }
            }
        }

        return dp1[n];
    }

    void dfs(int pos){
        if(sz(dp[pos])) return;
        
        string cur;
        for(int i=pos; i<min(n, pos+mx_len); ++i){
            cur+=s[i];
            if(pos + mn_len-1<=i && dict.count(cur)){
                dfs(i+1);
                for(auto sen: dp[i+1]){
                    sen = cur + " " + sen;
                    dp[pos].insert(sen);
                }
                if(i==n-1){
                    dp[pos].insert(cur);
                }
            }
        }
    }
};

class Solution {
    string s; set<string> dict;
    int n;
    map<int,set<string>> dp;
    int mn_len, mx_len;
    vb isBreakable;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        this->s = s; n = sz(s);
        isBreakable.assign(n,0);
        mn_len = 1e4; mx_len = 0; 
        for(auto & w: wordDict){
            dict.insert(w);
            mn_len = min(mn_len, sz(w));
            mx_len = max(mx_len, sz(w));
        }      
        // deb(n, mn_len, mx_len);  
        if(!checkbreakable()) return {};
        dfs(0);
        return vector<string>(all(dp[0]));
    }

    bool checkbreakable(){
        // if the word starting from index i is breakable

        isBreakable[n] = 1;
        for(int i=n-1; i>=0; --i){
            string cur;
            for(int j=i; j<n; ++j){
                cur+=s[j];
                if(dict.count(cur) && isBreakable[j+1]){
                    isBreakable[i] = 1;
                    break;
                }
            }
        }
        return isBreakable[0];
    }

    void dfs(int pos){
        if(sz(dp[pos])) return;
        
        string cur;
        for(int i=pos; i<min(n, pos+mx_len); ++i){
            cur+=s[i];
            if(pos + mn_len-1<=i && dict.count(cur)){
                if(!isBreakable[i+1]) continue;
                dfs(i+1);
                for(auto sen: dp[i+1]){
                    sen = cur + " " + sen;
                    dp[pos].insert(sen);
                }
                if(i==n-1){
                    dp[pos].insert(cur);
                }
            }
        }
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; string s; vs wordDict, out;
    s = "catsanddog", wordDict = { "cat", "cats", "and", "sand", "dog" };
    s = "pineapplepenapple", wordDict = { "apple", "pen", "applepen", "pine", "pineapple" };
    // s = "a", wordDict = {"a"};
    out = sol.wordBreak(s,wordDict);
    print(out);
    return 0;
}