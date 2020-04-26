#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
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

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

// dp[i] = the max subset sum that can be obtained at pos i, 
// if a[i] is in the subset
// dp[i] = a[i] + max(0, dp[i-k], . ,   dp[i-1]);
// We can use queue to optimize the max finding process
class Solution0 {
public:
    int constrainedSubsetSum(vector<int>& a, int k) {
        int n = a.size();
        priority_queue<pair<int,int>> pq;

        int ans = INT_MIN;
        for(int i=0; i<n; ++i){
            while(pq.size() && i - pq.top().second > k)
                pq.pop();
            int prev_max = 0;
            if(pq.size()) 
                prev_max = max(0, pq.top().first);
            int cur = prev_max + a[i];
            // deb3(i,prev_max, cur);
            
            pq.push({cur,i});
            ans = max(ans, cur);
        }
        return ans;
    }
};

class Solution1 {
public:
    int constrainedSubsetSum(vector<int>& a, int k) {
        int n = a.size();
        deque<int> q;
        vector<int> dp(n);

        int ans = INT_MIN;
        for(int i=0; i<n; ++i){
            // remove stale elements
            while(!q.empty() && i - q.front()>k)
                q.pop_front();

            int prev_max = !q.empty() ? max(0, dp[q.front()]) : 0;

            dp[i] = prev_max + a[i];
            while(!q.empty() && dp[q.back()]<dp[i])
                q.pop_back();

            ans = max(dp[i],ans);
            q.push_back(i);
        }

        return ans;
        
    }
};

class Solution {
public:
    int constrainedSubsetSum(vector<int>& a, int k) {
        int n = a.size();
        deque<pair<int,int>> dq; // {index, val}

        int ans = INT_MIN;        
        for(int i=0; i<n; ++i){
            while(!dq.empty() && i - dq.front().first>k)
                dq.pop_front();
            
            int prev_max = !dq.empty() ? max(0, dq.front().second) : 0;
            int cur = a[i] + prev_max;

            while(!dq.empty() && dq.back().second<cur)
                dq.pop_back();
            
            dq.push_back({i,cur});
            ans = max(ans, cur);
        }

        return ans;
    }
};


int main(){
    Solution sol;
    int k,out; vi nums;
    nums = { 10,2,-10,5,20 }, k = 2; 
    out =  sol.constrainedSubsetSum(nums,k); deb(out);
    nums = { -1,-2,-3 }, k = 1;
    out =  sol.constrainedSubsetSum(nums,k); deb(out);
    nums = { 10,-2,-10,-5,20 }, k = 2;
    out =  sol.constrainedSubsetSum(nums,k); deb(out);
    return 0;
}