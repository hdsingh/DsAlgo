/*
 * @lc app=leetcode id=1155 lang=cpp
 *
 * [1155] Number of Dice Rolls With Target Sum
 *
 * https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/
 *
 * algorithms
 * Medium (49.70%)
 * Likes:    342
 * Dislikes: 23
 * Total Accepted:    20.8K
 * Total Submissions: 41.9K
 * Testcase Example:  '1\n6\n3'
 *
 * You have d dice, and each die has f faces numbered 1, 2, ..., f.
 * 
 * Return the number of possible ways (out of f^d total ways) modulo 10^9 + 7
 * to roll the dice so the sum of the face up numbers equals target.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: d = 1, f = 6, target = 3
 * Output: 1
 * Explanation: 
 * You throw one die with 6 faces.  There is only one way to get a sum of 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: d = 2, f = 6, target = 7
 * Output: 6
 * Explanation: 
 * You throw two dice, each with 6 faces.  There are 6 ways to get a sum of 7:
 * 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: d = 2, f = 5, target = 10
 * Output: 1
 * Explanation: 
 * You throw two dice, each with 5 faces.  There is only one way to get a sum
 * of 10: 5+5.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: d = 1, f = 2, target = 3
 * Output: 0
 * Explanation: 
 * You throw one die with 2 faces.  There is no way to get a sum of 3.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: d = 30, f = 30, target = 500
 * Output: 222616187
 * Explanation: 
 * The answer must be returned modulo 10^9 + 7.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= d, f <= 30
 * 1 <= target <= 1000
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

class Solution1 {
public:
    int numRollsToTarget(int d, int F, int T) {

        vvi dp(d+1, vi(max(F, T)+1));
        // th: throw
        for(int i=1; i<=F; i++){
            dp[1][i] = 1;
        }
        
        for(int th = 2; th<=d; th++){
            for(int f=1; f<=F;   f++){
                for(int val=1; val<=T; val++){
                    if(f+val<=T){
                        add_self(dp[th][val+f], dp[th-1][val]);
                    }else break;
                }
            }
        } 
        // print_vv(dp);
        return dp[d][T];
    }
};

// Reduce dims
class Solution2 {
public:
    int numRollsToTarget(int D, int F, int T) {
        
        vi dp(max(F, T) + 1);
        dp[0] = 1;
        for(int d=0; d<D; d++){
            vi new_dp(dp.size());
            for(int val=0; val<=T; val++){
                for(int f=1; f<=F; f++){
                    if(val+f<=T)
                        add_self(new_dp[val+f], dp[val]);
                    else break;
                }
            }
            dp = new_dp;
        }
        
        // print(dp);

        return dp[T];
    }
};

// Use prefix sums
class Solution {
public:
    int numRollsToTarget(int D, int F, int T) {
        
        vi dp(max(F, T) + 1);
        dp[0] = 1;
        for(int d=0; d<D; d++){
            for(int i=1; i<=T; i++){
                add_self(dp[i], dp[i-1]);
            }
            vi new_dp(dp.size());
            for(int val = 1; val<=T; val++){
                new_dp[val] = dp[val-1] - (val-F-1>=0 ? dp[val - F - 1] : 0);
                if(new_dp[val]<0){
                    new_dp[val]+=mod;
                }
            } 

            dp = new_dp;
        }
        
        // print(dp);

        return dp[T];
    }
};

// @lc code=end


int main(){
    Solution sol;
    int d,f,target, out;
    d = 1, f = 6, target = 3;
    out = sol.numRollsToTarget(d,f,target);
    deb(out);

    d = 2, f = 6, target = 7;
    out = sol.numRollsToTarget(d,f,target);
    deb(out);

    d = 2, f = 5, target = 10;
    out = sol.numRollsToTarget(d,f,target);
    deb(out);

    d = 1, f = 2, target = 3;
    out = sol.numRollsToTarget(d,f,target);
    deb(out);

    d = 30, f = 30, target = 500;
    out = sol.numRollsToTarget(d,f,target);
    deb(out);
    
    return 0;
}