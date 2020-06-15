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
    vi a;
    int m,k,n;
public:
    int minDays(vector<int>& bloomDay, int M, int K) {
        a = bloomDay; m = M, k=K;
        n = a.size();

        int l = -1, r = 1e9+10, ans = -1;
        while(1+l<r){
            int mid = l + (r-l)/2;
            if(can(mid))
                r = mid, ans = r;
            else 
                l = mid;
        }

        return ans;        

    }

    bool can(int mid){
        int grps = 0;
        int i = 0;
        while(i<n){
            int pi = i;
            int j = i;
            while(j-i+1<=k && j<n && a[j]<=mid){
                ++j;
            }
            if(j-i==k){
                ++grps;
            }
            i = j;
            if(i==pi) ++i;
        }

        return grps>=m;
    }
};

int main(){
    Solution sol;
    vi bloomDay; int n,m, k, out;
    
    bloomDay = {1,10,3,10,2}, m = 3, k = 1;
    out = sol.minDays(bloomDay, m,k); deb(out);
    bloomDay = {1,10,3,10,2}, m = 3, k = 2;
    out = sol.minDays(bloomDay, m,k); deb(out);
    bloomDay = {7,7,7,7,12,7,7}, m = 2, k = 3;
    out = sol.minDays(bloomDay, m,k); deb(out);
    bloomDay = {1000000000,1000000000}, m = 1, k = 1;
    out = sol.minDays(bloomDay, m,k); deb(out);
    bloomDay = {1,10,2,9,3,8,4,7,5,6}, m = 4, k = 2;
    out = sol.minDays(bloomDay, m,k); deb(out);
    return 0;
}