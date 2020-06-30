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

class Hashs{
    int n;
    const int p = 31;
    const int m = 1e9 + 9;
    vl h, p_pow;
public:
    Hashs(string &s){
        n = s.size();
        p_pow.assign(n+1,0); h.assign(n+1,0);
        p_pow[0] = 1;
        for(int i=1; i<n; ++i)
            p_pow[i] = (p_pow[i-1]*p)%m;
        
        for(int i=0; i<n; ++i)  
            h[i+1] = (h[i] + (s[i]-'a'+1)*p_pow[i])%m;
    }

    ll find(int l, int r){
        ll cur = (h[r+1] - h[l] + m)%m;
        return (cur*p_pow[n-1-l])%m;
    }
};

// 2 eq strings have eq hash, however if 2 hases are eq, 
// strings may or  may not equate.
class Solution {
public:
    int distinctEchoSubstrings(string s) {
        int n = s.size();
        Hashs H(s);
        set<ll> seen;


        for(int l=0; l<n; ++l){
            for(int len=2; l+len<=n; len+=2){
                int r = l + len-1;
                int mid = (l+r)/2;
                ll h1 = H.find(l,mid);
                ll h2 = H.find(mid+1, l+len-1);
                // deb(l,mid,l+len-1);
                if(h1==h2) seen.insert({h1});
            }
        }
        
        return seen.size();
    }
};

int main(){
    Solution sol;
    vs ss = {
        "abcabcabc",
        "leetcodeleetcode",
    };
    for(auto s: ss){
        int out = sol.distinctEchoSubstrings(s); deb(out);
    }
    return 0;
}