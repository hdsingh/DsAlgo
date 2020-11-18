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
    bool canDistribute(vector<int>& nums, vector<int>& qs) {
        unordered_map<int,int> cnt;
        for(auto num: nums){
            cnt[num]++;
        }
        nums.clear();
        for(auto &[p,c]: cnt)
            nums.push_back(c);
        sort(nums.begin(), nums.end(), greater<int>());
        int m = qs.size();
        int n = min((int)nums.size(), m);
        vector<vector<int>> dp(n, vector<int>(1<<m,-1));

        return dfs(0,0,n,m,nums,qs,dp);
    }
    
    bool dfs(int pos, int vis, int &n, int &m, vector<int> &nums, vector<int> &qs, vector<vector<int>>  &dp){
        // deb(pos, vis);
        if(pos==n){
            return vis==((1<<m)-1);
        }
        // deb(pos, vis);
        int &ans = dp[pos][vis];
        if(~ans) return ans;
        ans = false;
        // try adding all possible subsets
        for(int mask=0; mask<(1<<m); ++mask){
            bool valid = true; int sum = 0;
            for(int i=0; i<m; ++i){
                if((mask>>i)&1){
                    if((vis>>i)&1){
                        valid = false;
                        break;
                    }
                    sum+=qs[i];
                }
            }

            if(!valid || sum>nums[pos]) continue;
            if(dfs(pos+1,(vis|mask),n,m,nums,qs,dp))
                return ans = true;  
        }

        return ans = false;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; int out;
    vi nums,quantity;
    nums = {1,2,3,4}, quantity = {2};
    out = sol.canDistribute(nums, quantity); deb(out);
    nums = {1,2,3,3}, quantity = {2};
    out = sol.canDistribute(nums, quantity); deb(out);
    nums = {1,1,2,2}, quantity = {2,2};
    out = sol.canDistribute(nums, quantity); deb(out);
    nums = {1,1,2,3}, quantity = {2,2};
    out = sol.canDistribute(nums, quantity); deb(out);
    nums = {1,1,1,1,1}, quantity = {2,3};
    out = sol.canDistribute(nums, quantity); deb(out);

    return 0;
}