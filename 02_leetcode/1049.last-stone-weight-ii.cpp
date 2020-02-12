/*
 * @lc app=leetcode id=1049 lang=cpp
 *
 * [1049] Last Stone Weight II
 *
 * https://leetcode.com/problems/last-stone-weight-ii/description/
 *
 * algorithms
 * Medium (42.66%)
 * Likes:    347
 * Dislikes: 17
 * Total Accepted:    10K
 * Total Submissions: 23.3K
 * Testcase Example:  '[2,7,4,1,8,1]'
 *
 * We have a collection of rocks, each rock has a positive integer weight.
 * 
 * Each turn, we choose any two rocks and smash them together.  Suppose the
 * stones have weights x and y with x <= y.  The result of this smash is:
 * 
 * 
 * If x == y, both stones are totally destroyed;
 * If x != y, the stone of weight x is totally destroyed, and the stone of
 * weight y has new weight y-x.
 * 
 * 
 * At the end, there is at most 1 stone left.  Return the smallest possible
 * weight of this stone (the weight is 0 if there are no stones left.)
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [2,7,4,1,8,1]
 * Output: 1
 * Explanation: 
 * We can combine 2 and 4 to get 2 so the array converts to [2,7,1,8,1] then,
 * we can combine 7 and 8 to get 1 so the array converts to [2,1,1,1] then,
 * we can combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
 * we can combine 1 and 1 to get 0 so the array converts to [1] then that's the
 * optimal value.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= stones.length <= 30
 * 1 <= stones[i] <= 100
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

// Place - or + in front of each stone and add to the previous set of possible sums
class Solution1 {
public:
    int lastStoneWeightII(vector<int>& a) {
        int n = a.size();
        set<int> sums;

        sums.insert(-a[0]);
        sums.insert(a[0]);
        for(int i=1; i<n; i++){
            set<int> new_sums;
            for(int s: sums){
                new_sums.insert(s+a[i]);
                new_sums.insert(s-a[i]);
            }
            sums = new_sums;
        }
        // find the minimum number >=0;
        int ans = 0;
        for(int s: sums){
            if(s>=0){
                ans = s;
                break;
            }
        }
        return ans;
    }   
};

class Solution {
public:
    int lastStoneWeightII(vector<int>& a) {
        int n = a.size();
        int sum = accumulate(a.begin(), a.end(), 0);

        vi dp(2*sum+1);
        // if possible to  have a weight i (sum+i)
        dp[sum+a[0]] = 1;
        dp[sum-a[0]] = 1;
        for(int i=1; i<n; i++){
            vi ndp(2*sum+1);
            for(int j=0; j<sum*2+1; j++){
                if(dp[j]==1){
                    ndp[j+a[i]] = 1;
                    ndp[j-a[i]] = 1;
                }
            }
            dp = ndp;
        }

        int minpos = 0;
        for(int i=sum; i<2*sum+1; i++){
            if(dp[i]==1){
                minpos = i-sum;
                break;
            }
        }

        // print(dp, 1);
        return minpos;
    }
};
// @lc code=end

int main(){
    Solution1 sol; int out;
    vi a;    
    a = {2,7,4,1,8,1};
    out = sol.lastStoneWeightII(a); deb(out);
    a = {2,0,5,9,4,3,4};
    out = sol.lastStoneWeightII(a); deb(out);
    a = {0,0,8,0,3,2,5,3,5,76,8,7,5,4,3,5,};
    out = sol.lastStoneWeightII(a); deb(out);

    return 0;
}

