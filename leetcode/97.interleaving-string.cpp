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

class Solution {
    string s1, s2, s3;
    int n, m;
    vector<vector<int>> dp;
public:
    bool isInterleave(string s1, string s2, string s3) {
        this->s1 = s1, this->s2 = s2, this->s3 =s3;
        n = s1.size(), m = s2.size();
        dp.assign(n+1, vi(m+1,-1));
        if(n+m!=s3.size()) return false;
        if(!n) return s2==s3;
        if(!m) return s1==s3;
        return can(0,0);
    }
    
    int can(int p1, int p2){
        int &ans = dp[p1][p2];
        if(~ans) return ans;
        ans = 0;
        if(p1==n && p2==m){
            return ans = 1;
        }else if(p1==n){
            return ans = s3.substr(n+p2)==s2.substr(p2);
        }else if(p2==m){
            return ans = s3.substr(m+p1)==s1.substr(p1);
        }
        
        if(s1[p1]==s3[p1+p2] && can(p1+1,p2))
            return ans = 1;
        
        if(s2[p2]==s3[p1+p2] && can(p1,p2+1))
            return ans = 1;

        return ans;
    }
};

class Solution {
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