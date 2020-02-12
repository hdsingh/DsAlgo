/*
 * @lc app=leetcode id=1262 lang=cpp
 *
 * [1262] Greatest Sum Divisible by Three
 *
 * https://leetcode.com/problems/greatest-sum-divisible-by-three/description/
 *
 * algorithms
 * Medium (42.52%)
 * Likes:    242
 * Dislikes: 6
 * Total Accepted:    7.9K
 * Total Submissions: 18.4K
 * Testcase Example:  '[3,6,5,1,8]'
 *
 * Given an array nums of integers, we need to find the maximum possible sum of
 * elements of the array such that it is divisible by three.
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,6,5,1,8]
 * Output: 18
 * Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum
 * divisible by 3).
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4]
 * Output: 0
 * Explanation: Since 4 is not divisible by 3, do not pick any number.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,3,4,4]
 * Output: 12
 * Explanation: Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum
 * divisible by 3).
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 4 * 10^4
 * 1 <= nums[i] <= 10^4
 * 
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

// TLE using simple 1d dp
class Solution1 {
public:
    int maxSumDivThree(vector<int>& a) {
        int n = a.size();
        int sum = accumulate(all(a), 0);

        vi dp(sum+1); // is_possible
        // possible to have sum s till ith pos
        // for each prev existing sum, in order to move forward, 
        // we will add the new num and miss the new num
        dp[0] = 1; // miss the first num
        dp[0+a[0]] = 1;
        for(int i=1; i<n; i++){
            vi ndp(sum+1);
            for(int j=0; j<sum+1; j++){
                if(dp[j]){ // if prev sum exists
                    ndp[j+a[i]] = 1; // add it 
                    ndp[j] = 1; // miss it
                }
            }
            dp = ndp;
        }
        
        int ans = 0;
        for(int i=sum; i>=0; i--){
            if(dp[i] && i%3==0){
                ans = i;
                break;
            }
        }

        return ans;
    }
};

// TLE using set
class Solution2 {
public:
    int maxSumDivThree(vector<int>& a) {
        int n = a.size();
        set<int> sums; //possible sums

        sums.insert(0);
        sums.insert(a[0]);

        for(int i=1;i<n; i++){
            set<int> nsums;
            for(int x: sums){
                nsums.insert(x);
                nsums.insert(x+a[i]);
            }
            sums = nsums;
        }
        
        int ans = 0;
        for(auto i = sums.rbegin(); i!=sums.rend(); i++){
            if(*i && (*i)%3==0){
                ans = *i;
                break;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxSumDivThree(vector<int>& a) {
        int n = a.size();
        vi dp(3); // maximum sum giving mod i

        for(int x : a){
            vi ndp = dp;
            for(int i=0; i<3; i++){
               max_self(ndp[ (dp[i]+x)%3 ], dp[i]+x);
            }
            dp = ndp;
        }

        return dp[0];
    }
};

// @lc code=end


int main(){
    Solution sol; vi nums; int out;
    nums = {3,6,5,1,8};
    out = sol.maxSumDivThree(nums); deb(out);

    nums = {4};
    out = sol.maxSumDivThree(nums); deb(out);

    nums = {1,2,3,4,4};
    out = sol.maxSumDivThree(nums); deb(out);
    // int x;
    // vi a;
    // while(cin>>x){
    //     a.pb(x);
    // }
    // out = sol.maxSumDivThree(a); deb(out);


    return 0;
}


