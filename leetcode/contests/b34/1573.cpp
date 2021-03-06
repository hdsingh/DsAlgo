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
public:
    int numWays(string s) {
        ll n = s.size();
        if(n<3) return 0;
        ll ones = count(s.begin(), s.end(), '1');
        if(ones%3) return 0;
        if(ones==0){
            return ((n-1)*(n-2)/2)%mod;
        }
        ll cnt11 = 0, cnt10 = 0, cnt21 = 0, cnt20 = 0, cnt31 = 0;
        int i = 0;
        while(i<n){
            if(s[i]=='1') ++cnt11;
            if(cnt11==ones/3){
                int j = i+1;
                while(j<n && s[j]=='0') ++j;
                cnt10 = (j-i);
                break;
            }
            ++i;
        } 

        i = n-1;
        while(i<n){
            if(s[i]=='1') ++cnt31;
            if(cnt31==ones/3){
                int j = i-1;
                while(j>=0 && s[j]=='0') --j;
                cnt20 = (i-j);
                break;
            }
            --i;
        }
        // deb(cnt10, cnt20);
        ll ans = (cnt10*cnt20)%mod;
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; 
    vs ss = {
        "111", 
        "10101", 
"1001", 
"0000",
"100100010100110",
    };
    for(auto s: ss){
        int out = sol.numWays(s);
        deb(out);
    }
    return 0;
}