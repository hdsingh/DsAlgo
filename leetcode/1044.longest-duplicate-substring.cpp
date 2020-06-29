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
    int ans;
    const int p = 31;
    const int m = 1e9 + 9;
    vector<ll> p_pow, h;
public:
    string longestDupSubstring(string s) {
        ans = -1;
        int n = s.size();
        p_pow.assign(n+1,0), h.assign(n+1,0);
        p_pow[0] = 1;
        for(int i=1; i<n; ++i)
            p_pow[i] = (p_pow[i-1] * p) % m;
        
        for(int i=0; i<n; ++i)
            h[i+1] = (h[i] + (s[i] - 'a' + 1)*p_pow[i])%m;
        
        int l = 0, r = n+1;
        while(1+l<r){
            int mid = l + (r-l)/2;
            if(has_rep_len(mid, s))
                l = mid;
            else
                r = mid;
        }

        if(ans==-1) return "";
        return s.substr(ans,l);
    }

    bool has_rep_len(int len, string &s){
        int n = s.size();
        // set<ll> seen;
        auto compare = [&](int p1, int p2){
            for(int i=0; i<len; ++i)
                if(s[p1+i]!=s[p2+i]) return false;
            return true;
        };
    
        unordered_map<ll, vector<int>> seen;
        // compare all strings of "len" 
        for(int i=0; i<=n-len; ++i){
            ll cur_h = (h[i+len] - h[i] + m)%m;
            cur_h = (cur_h * p_pow[n-1-i])%m; // raise all to same pow of p
            // deb(i,cur_h, s.substr(i,len));

            if(seen.count(cur_h)){
                for(auto pos: seen[cur_h]){
                    if(compare(i,pos)){
                        ans = i;
                        return true;
                    }
                }
            }else seen[cur_h].push_back(i);

        }
        
        return false;
    }
};

int main(){
    Solution sol; 
    vs ss = {
        "banana",
        "",
    };
    for(auto s: ss){
        string out = sol.longestDupSubstring(s);
        deb(out);
    }

    return 0;
}