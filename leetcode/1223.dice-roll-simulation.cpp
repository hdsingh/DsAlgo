/*
 * @lc app=leetcode id=1223 lang=cpp
 *
 * [1223] Dice Roll Simulation
 *
 * https://leetcode.com/problems/dice-roll-simulation/description/
 *
 * algorithms
 * Medium (43.50%)
 * Likes:    163
 * Dislikes: 61
 * Total Accepted:    6.2K
 * Total Submissions: 14.3K
 * Testcase Example:  '2\n[1,1,2,2,2,3]'
 *
 * A die simulator generates a random number from 1 to 6 for each roll. You
 * introduced a constraint to the generator such that it cannot roll the number
 * i more than rollMax[i] (1-indexed) consecutive times. 
 * 
 * Given an array of integers rollMax and an integer n, return the number of
 * distinct sequences that can be obtained with exact n rolls.
 * 
 * Two sequences are considered different if at least one element differs from
 * each other. Since the answer may be too large, return it modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 2, rollMax = [1,1,2,2,2,3]
 * Output: 34
 * Explanation: There will be 2 rolls of die, if there are no constraints on
 * the die, there are 6 * 6 = 36 possible combinations. In this case, looking
 * at rollMax array, the numbers 1 and 2 appear at most once consecutively,
 * therefore sequences (1,1) and (2,2) cannot occur, so the final answer is
 * 36-2 = 34.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 2, rollMax = [1,1,1,1,1,1]
 * Output: 30
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 3, rollMax = [1,1,1,2,2,3]
 * Output: 181
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 5000
 * rollMax.length == 6
 * 1 <= rollMax[i] <= 15
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

class Solution1 {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vvi> dp(n, vvi(6, vi(16)));
        // dp[times][last number appeared][consec times]

        forn(i, 6)
            dp[0][i][1] = 1;
        
        fore(roll, 1, n){
            forn(f, 6){
                forn(nf, 6){
                    if(f!=nf)
                        fore(times, 1, rollMax[nf]+1)
                            add_self(dp[roll][f][1], dp[roll-1][nf][times]);
                }

                fore(times, 2, rollMax[f]+ 1){
                    add_self(dp[roll][f][times], dp[roll-1][f][times-1]);
                }
            }
        }

        int ans = 0;
        forn(i, 6){
            forn(times, 16)
                add_self(ans, dp[n-1][i][times]);
        }

        return ans;
    }
};

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax){
        vvi dp(n+1, vi(6));
        vi sum(n+1);
        // At ith round we get a face j

        sum[0] = 1;
        fore(rnd,1,n+1){
            forn(face, 6){
                fore(prev, 1, rollMax[face]+1)
                    if(rnd-prev>=0)
                        add_self(dp[rnd][face], sum[rnd-prev]-dp[rnd-prev][face]);
            }

            forn(face, 6)
                add_self(sum[rnd], dp[rnd][face]);
        }

        return sum[n];
    } 
};

// @lc code=end

int main(){
    Solution sol;
    vi rollMax; int out,n;
    n = 2, rollMax = { 1,1,2,2,2,3 };
    out = sol.dieSimulator(n,rollMax);deb(out);

    n = 2, rollMax = { 1,1,1,1,1,1 };
    out = sol.dieSimulator(n,rollMax);deb(out);

    n = 3; rollMax = {1,1,1,2,2,3};
    out = sol.dieSimulator(n,rollMax);deb(out);
    return 0;
}
