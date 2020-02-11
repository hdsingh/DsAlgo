/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 *
 * https://leetcode.com/problems/ones-and-zeroes/description/
 *
 * algorithms
 * Medium (40.50%)
 * Likes:    667
 * Dislikes: 160
 * Total Accepted:    36.3K
 * Total Submissions: 88.9K
 * Testcase Example:  '["10","0001","111001","1","0"]\n5\n3'
 *
 * In the computer world, use restricted resource you have to generate maximum
 * benefit is what we always want to pursue.
 * 
 * For now, suppose you are a dominator of m 0s and n 1s respectively. On the
 * other hand, there is an array with strings consisting of only 0s and 1s.
 * 
 * Now your task is to find the maximum number of strings that you can form
 * with given m 0s and n 1s. Each 0 and 1 can be used at most once.
 * 
 * Note:
 * 
 * 
 * The given numbers of 0s and 1s will both not exceed 100
 * The size of given string array won't exceed 600.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
 * Output: 4
 * 
 * Explanation: This are totally 4 strings can be formed by the using of 5 0s
 * and 3 1s, which are “10,”0001”,”1”,”0”
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: Array = {"10", "0", "1"}, m = 1, n = 1
 * Output: 2
 * 
 * Explanation: You could form "10", but then you'd have nothing left. Better
 * form "0" and "1".
 * 
 * 
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
    int findMaxForm(vector<string>& strs, int Z, int O) {
        int n = strs.size();

        vvi cnt;
        for(auto s: strs){
            int zs = count(all(s), '0');
            int os = s.size() - zs;
            cnt.pb({zs, os});           
        }
        
        // print_vv(cnt);
        vector<vvi> dp(n+1, vvi(Z+1, vi(O+1)));
        // max strings that can be obtained till ith pos, using upto z 0s and o 1s 
        fore(i, 1, n+1){
            fore(z, 0, Z+1){
                fore(o, 0, O+1){
                    int cur_z = cnt[i-1][0];
                    int cur_o = cnt[i-1][1];
                    dp[i][z][o] = dp[i-1][z][o];
                    if(z>=cur_z && o>=cur_o)
                        max_self(dp[i][z][o], 1 + dp[i-1][z-cur_z][o-cur_o]);
                }
            }
        }

        return dp[n][Z][O];
    }
};

class Solution {
public:
    int findMaxForm(vector<string>& strs, int Z, int O) {
        int n = strs.size();

        vvi cnt;
        for(auto s: strs){
            int zs = count(all(s), '0');
            int os = s.size() - zs;
            cnt.pb({zs, os});           
        }
        
        // print_vv(cnt);
        vvi dp(Z+1, vi(O+1));
        // max strings that can be obtained till ith pos, using upto z 0s and o 1s 
        fore(i, 1, n+1){
            for(int z=Z; z>=0; z--){
                for(int o=O; o>=0; o--){
                    int cur_z = cnt[i-1][0];
                    int cur_o = cnt[i-1][1];
                    if(z>=cur_z && o>=cur_o)
                        max_self(dp[z][o], 1 + dp[z-cur_z][o-cur_o]);
                }
            }
        }

        return dp[Z][O];
    }
};
// @lc code=end

int main(){
    Solution sol; int out;
    vs Array; int m, n;
    Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3;
    out = sol.findMaxForm(Array, m,n); deb(out);

    Array = {"0", "1", "10"}, m = 1, n = 1;
    out = sol.findMaxForm(Array, m,n); deb(out);
    return 0;
}
