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

// min len that can be obtined starting from ith pos,
class Solution {
    const int inf = 1e5;
    int n, K;
    string s;
    vvi dp;
public:
    int getLengthOfOptimalCompression(string s, int K) {
        this->s = s;
        this->K = K;
        dp.clear();
        dp.resize(200+2, vi(200,-1));
        n = s.size();
        return dfs(0,0);
    }

    int dfs(int pos, int k){
        int origK = k;
        if(k>K) return inf;
        if(pos==n) return 0;
        if(dp[pos][k]!=-1) return dp[pos][k];

        // delete this 
        int ans = inf;
        min_self(ans, dfs(pos+1, k+1));

        // start from here and take c conseq,
        // deleting the other elements not equal to s[pos] in between

        auto find_clen = [&](int cons){
            if(cons==1) return 1;
            if(cons<10) return 2;
            return 3;
        };

        int c = 0;
        for(int i=pos; i<n; ++i){
            if(s[i]==s[pos]) ++c;
            else ++k;
            int clen = find_clen(c);
            min_self(ans, clen + dfs(i+1, k));
        }

        return dp[pos][origK] = ans;
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; string s; int k, out;
    s = "aaabcccd", k = 2;
    out = sol.getLengthOfOptimalCompression(s,k); deb(out);
    s = "aabbaa", k = 2;
    out = sol.getLengthOfOptimalCompression(s,k); deb(out);
    s = "aaaaaaaaaaa", k = 0;
    out = sol.getLengthOfOptimalCompression(s,k); deb(out);

    return 0;
}