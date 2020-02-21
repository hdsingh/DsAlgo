/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 *
 * https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
 *
 * algorithms
 * Medium (54.31%)
 * Likes:    418
 * Dislikes: 12
 * Total Accepted:    15.9K
 * Total Submissions: 29.2K
 * Testcase Example:  '[1,2,3,4,5,6,7,8,9,10]\n5'
 *
 * A conveyor belt has packages that must be shipped from one port to another
 * within D days.
 * 
 * The i-th package on the conveyor belt has a weight of weights[i].  Each day,
 * we load the ship with packages on the conveyor belt (in the order given by
 * weights). We may not load more weight than the maximum weight capacity of
 * the ship.
 * 
 * Return the least weight capacity of the ship that will result in all the
 * packages on the conveyor belt being shipped within D days.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: weights = [1,2,3,4,5,6,7,8,9,10], D = 5
 * Output: 15
 * Explanation: 
 * A ship capacity of 15 is the minimum to ship all the packages in 5 days like
 * this:
 * 1st day: 1, 2, 3, 4, 5
 * 2nd day: 6, 7
 * 3rd day: 8
 * 4th day: 9
 * 5th day: 10
 * 
 * Note that the cargo must be shipped in the order given, so using a ship of
 * capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6,
 * 7), (8), (9), (10) is not allowed. 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: weights = [3,2,2,4,1,4], D = 3
 * Output: 6
 * Explanation: 
 * A ship capacity of 6 is the minimum to ship all the packages in 3 days like
 * this:
 * 1st day: 3, 2
 * 2nd day: 2, 4
 * 3rd day: 1, 4
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: weights = [1,2,3,1,1], D = 4
 * Output: 3
 * Explanation: 
 * 1st day: 1
 * 2nd day: 2
 * 3rd day: 3
 * 4th day: 1, 1
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= D <= weights.length <= 50000
 * 1 <= weights[i] <= 500
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define all(x) x.begin(), x.end()
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
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

// DP : TLE
class Solution1 {
    const int inf = 1e9;
public:
    int shipWithinDays(vector<int>& a, int D) {
        int n = a.size();
        vvi dp(D+1, vi(n+1, inf));
        // min capacity of the ship to get till ith package till day d
        // the min capacity equals the max of capacity till prev day till pack j, or transfering
        // package j+1 to i on next day
        vi pre(n+1);
        for(int i=1; i<=n; i++)
            pre[i] = pre[i-1] + a[i-1];
    
        dp[0][0] = 0;
        for(int d=1; d<=D; d++){
            for(int i=1; i<=n; i++){
                for(int j=0; j<i; j++){
                    min_self(dp[d][i], max(dp[d-1][j], pre[i] - pre[j] ));
                }
            }
        }

        // print_vv(dp);
        return dp[D][n];
    }
};

// Space optimized DP: TLE
class Solution2 {
    const int inf = 1e9;
public:
    int shipWithinDays(vector<int>& a, int D) {
        int n = a.size();
        vi dp(n+1);
        // min capacity of the ship to get till ith package till day d
        // the min capacity equals the max of capacity till prev day till pack j, or transfering
        // package j+1 to i on next day
        vi pre(n+1);
        for(int i=1; i<=n; i++)
            pre[i] = pre[i-1] + a[i-1];
    
        dp= pre;
        for(int d=2; d<=D; d++){
            for(int i=n; i>=1; i--){
                for(int j=0; j<i; j++){
                    min_self(dp[i], max(dp[j], pre[i] - pre[j] ));
                }
            }
        }

        // print(dp);
        return dp[n];
    }
};

// Binary Search
class Solution {
public:
    int shipWithinDays(vector<int>& a, int D) {
        int l = 0; 
        int r = accumulate(all(a), 0)+1;
        int mid;
        while(l<r){
            mid = l + (r-l)/2;
            if(is_possible(mid, D, a)){
                r = mid;
            }else 
                l = mid + 1;
        }
        // will terminate when l==r
        return l;
    }

    bool is_possible(const int cap, const int D, vi &a){
        int n = a.size();
        int cnt = 1; int sum = 0;

        for(int i=0; i<n; i++){
            if(sum+a[i]<=cap){
                sum+=a[i];
            }else{
                sum = a[i];
                ++cnt;
            }
            if(sum>cap || cnt>D) return false;
        }
        
        return true;
    }
};
// @lc code=end

int main(){
    Solution sol; vi weights; int D, out;
    weights = { 1,2,3,4,5,6,7,8,9,10 }, D = 5;
    out = sol.shipWithinDays(weights, D); deb(out);
    weights = { 10,50,100,100,50,100,100,100 }; D = 5;
    out = sol.shipWithinDays(weights, D); deb(out);

    weights = { 3,2,2,4,1,4 }, D = 3;
    out = sol.shipWithinDays(weights, D); deb(out);

    weights = { 1,2,3,1,1 }, D = 4;
    out = sol.shipWithinDays(weights, D); deb(out);

    weights = { 147,73,265,305,191,152,192,293,309,292,182,157,381,287,73,162,313,366,346,47 }, D = 10;
    out = sol.shipWithinDays(weights, D); deb(out);

    // out = sol.is_possible(14, D, weights); deb(out);
    return 0;
}


