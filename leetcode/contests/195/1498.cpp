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

ll powMod(ll n, ll p) {
    if(p==0) return 1;
    if(p<0){
        // deb("fkld");
        return 0;
    }
    ll res = 1;
    while (p) {
        if (p & 1) (res *= n) %= mod;
          (n *= n) %= mod;
        p >>= 1;
    }
    return res;
}

class Solution {
public:
    int numSubseq(vector<int>& a, int target) {
        int n = a.size();
        sort(a.begin(), a.end());

        // print(a,1);
        long long ans = 0;
        for(int i=0; i<n; ++i){
            if(2*a[i]>target) break;
            auto pos = upper_bound(a.begin()+i, a.end(), target - a[i]);
            --pos;
            int len = distance(a.begin()+i, pos);
            add_self(ans, powMod(2,len));
        }
        return ans;
    }
};

int main(){
    Solution sol; vi nums; int target, out;
    nums = {3,5,6,7}, target = 9;
    out = sol.numSubseq(nums, target); deb(out);
    nums = {3,3,6,8}, target = 10;
    out = sol.numSubseq(nums, target); deb(out);
    nums = {2,3,3,4,6,7}, target = 12;
    out = sol.numSubseq(nums, target); deb(out);
    nums = {5,2,4,1,7,6,8}, target = 16;
    out = sol.numSubseq(nums, target); deb(out);


    return 0;
}