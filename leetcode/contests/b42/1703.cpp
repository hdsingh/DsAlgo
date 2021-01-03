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
template <typename T> ostream& operator<<(ostream &os, const vector<T> &v){print(v); return os;};
template <typename T> ostream& operator<<(ostream &os, const vector<vector<T>> &vv){print_vv(vv); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const map<T,U>  &m){print_m(m); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const pair<T, U> &pr){debp(pr); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const vector<pair<T, U>> &vp){ print_vp(vp); return os;};

class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        if(k==1) return 0;
        int n = nums.size();
        ll ans = 1e18L;
        vl a;
        for(int i=0; i<n; ++i){
            if(nums[i]==1) a.push_back(i);
        }
        n=a.size();
        vl pre(n);
        partial_sum(a.begin(), a.end(), pre.begin());
        auto sum = [&](int lt, int rt){
            return pre[rt] - (lt-1>=0 ? pre[lt-1] : 0);  
        };
        auto cnt = [&](ll r){
            return r*(r+1)/2;  
        };
        

        for(int i=k/2; i<n; ++i){
            int mid = i;
            // odd
            int lt = i - k/2;
            int rt = lt + k - 1;
            if(rt<n){
                // mid in [0 1 2]  is 1.
                // mid in [0 1 2 3]  is 2.
                
                ll lsum = sum(lt,mid-1), rsum = sum(mid,rt);
                ll llen = mid-lt, rlen = rt-mid+1;
                ll cur = (a[mid]*llen - lsum) + (rsum - rlen*a[mid]) - cnt(llen) - cnt(rlen-1);
                ans = min(ans, cur);

                if(k%2==0){
                    // mid in [0 1 2 3]  is 1.
                    cur = (a[mid-1]*llen - lsum) + (rsum - rlen*a[mid-1]) - cnt(llen) - cnt(rlen-1);
                    ans = min(ans, cur);
                }
            }
        }
        return ans;
        
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol;
    vi num; int k; int out;
    num = {0,1,0,1,1,0,0,1,0,0,0,0,1,0,1,1,0,0,0,1,0,0,1,1,1,0,1,0}, k = 12;
    out = sol.minMoves(num, k); deb(out);
    num = {1,0,0,1,0,1}, k = 2;
    num = {1,0,0,0,0,0,1,1}, k = 3;
    out = sol.minMoves(num, k); deb(out);
    num = {1,1,0,1}, k = 2;
    out = sol.minMoves(num, k); deb(out);


    return 0;
}