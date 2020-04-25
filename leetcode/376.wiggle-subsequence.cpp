/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 *
 * https://leetcode.com/problems/wiggle-subsequence/description/
 *
 * algorithms
 * Medium (38.74%)
 * Likes:    737
 * Dislikes: 53
 * Total Accepted:    58.6K
 * Total Submissions: 151.2K
 * Testcase Example:  '[1,7,4,9,2,5]'
 *
 * A sequence of numbers is called a wiggle sequence if the differences between
 * successive numbers strictly alternate between positive and negative. The
 * first difference (if one exists) may be either positive or negative. A
 * sequence with fewer than two elements is trivially a wiggle sequence.
 * 
 * For example, [1,7,4,9,2,5] is a wiggle sequence because the differences
 * (6,-3,5,-7,3) are alternately positive and negative. In contrast,
 * [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its
 * first two differences are positive and the second because its last
 * difference is zero.
 * 
 * Given a sequence of integers, return the length of the longest subsequence
 * that is a wiggle sequence. A subsequence is obtained by deleting some number
 * of elements (eventually, also zero) from the original sequence, leaving the
 * remaining elements in their original order.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,7,4,9,2,5]
 * Output: 6
 * Explanation: The entire sequence is a wiggle sequence.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,17,5,10,13,15,10,5,16,8]
 * Output: 7
 * Explanation: There are several subsequences that achieve this length. One is
 * [1,17,10,13,10,16,8].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,2,3,4,5,6,7,8,9]
 * Output: 2
 * 
 * Follow up:
 * Can you do it in O(n) time?
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
    const int pos = 1;
    const int neg = 0;
public:
    int wiggleMaxLength(vector<int>& a) {
        int n = a.size();
        if(n<2) return n;
        vvi dp(n, vi(2));

        // 0: pos, 1: neg
        fore(i,1,n){
            int dif = a[i] - a[i-1];
            if(dif<0){
                dp[i][neg] = dp[i-1][pos] + 1;
                dp[i][pos] = dp[i-1][pos];
            }else if(dif>0){
                dp[i][pos] = dp[i-1][neg] + 1;
                dp[i][neg] = dp[i-1][neg];
            }else{
                dp[i][pos] = dp[i-1][pos];
                dp[i][neg] = dp[i-1][neg];
            }
        }
        
        // for(auto x: dp)
        //     print(x);

        return max(dp[n-1][0], dp[n-1][1]) + 1;
    }
};

class Solution {
public: 
    int wiggleMaxLength(vector<int>& a) {
        const int n = a.size();
        if(n<2) return n;

        int len_pos(0), len_neg(0);
        fore(i, 1, n){
            int dif = a[i]-a[i-1];
            if(dif<0){
                len_neg = len_pos + 1;
            }else if(dif>0){
                len_pos = len_neg + 1;
            }
            // else pos, neg will stay same
        }

        return max(len_pos, len_neg) + 1;
    } 
};
// @lc code=end

int main(){
    Solution sol; 
    vi a; int out;
    
    a = {1,7,4,9,2,5};
    out = sol.wiggleMaxLength(a);
    deb(out);

    a = {1,17,5,10,13,15,10,5,16,8};
    out = sol.wiggleMaxLength(a); 
    deb(out);

    a = {1,2,3,4,5,6,7,8,9};
    out = sol.wiggleMaxLength(a); 
    deb(out);
    return 0;
}