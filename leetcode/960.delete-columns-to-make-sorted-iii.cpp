/*
 * @lc app=leetcode id=960 lang=cpp
 *
 * [960] Delete Columns to Make Sorted III
 *
 * https://leetcode.com/problems/delete-columns-to-make-sorted-iii/description/
 *
 * algorithms
 * Hard (53.58%)
 * Likes:    204
 * Dislikes: 7
 * Total Accepted:    5.5K
 * Total Submissions: 10.3K
 * Testcase Example:  '["babca","bbazb"]'
 *
 * We are given an array A of N lowercase letter strings, all of the same
 * length.
 * 
 * Now, we may choose any set of deletion indices, and for each string, we
 * delete all the characters in those indices.
 * 
 * For example, if we have an array A = ["babca","bbazb"] and deletion indices
 * {0, 1, 4}, then the final array after deletions is ["bc","az"].
 * 
 * Suppose we chose a set of deletion indices D such that after deletions, the
 * final array has every element (row) in lexicographic order.
 * 
 * For clarity, A[0] is in lexicographic order (ie. A[0][0] <= A[0][1] <= ...
 * <= A[0][A[0].length - 1]), A[1] is in lexicographic order (ie. A[1][0] <=
 * A[1][1] <= ... <= A[1][A[1].length - 1]), and so on.
 * 
 * Return the minimum possible value of D.length.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["babca","bbazb"]
 * Output: 3
 * Explanation: After deleting columns 0, 1, and 4, the final array is A =
 * ["bc", "az"].
 * Both these rows are individually in lexicographic order (ie. A[0][0] <=
 * A[0][1] and A[1][0] <= A[1][1]).
 * Note that A[0] > A[1] - the array A isn't necessarily in lexicographic
 * order.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["edcba"]
 * Output: 4
 * Explanation: If we delete less than 4 columns, the only row won't be
 * lexicographically sorted.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: ["ghi","def","abc"]
 * Output: 0
 * Explanation: All rows are already lexicographically sorted.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 100
 * 1 <= A[i].length <= 100
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
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

// A kind of LIS, just on multiple strings
class Solution {
    int n, m;
    vs a;
public:
    int minDeletionSize(vector<string>& a) {
        this->a = a;
        n = a.size();
        m = a[0].size();

        vi dp(m, 1);
        for(int i=0; i<m; ++i){
           for(int j=0; j<i; ++j){
                if(is_less_equal(j, i))
                    max_self(dp[i], dp[j]+1);
           }
        }

        // print(dp,1);
        int mxlen = *max_element(all(dp));
        return m - mxlen;
    }

    bool is_less_equal(int x, int y){
        for(auto &s: a)
            if(s[x]>s[y])
                return false;
        return true;
    }
};
// @lc code=end

int LIS(string s){
    int n = s.size();
    vi  dp(n,1);
    for(int i=0; i<n; ++i){
        for(int j=0; j<i; ++j){
            if(s[j]<s[i]){
                max_self(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(all(dp));
}

int main(){
    Solution sol; vs ss; int out;
    ss = { "babca","bbazb" };
    out = sol.minDeletionSize(ss); deb(out);
    ss = {"edcba"};
    out = sol.minDeletionSize(ss); deb(out);
    ss = {"ghi","def","abc"};
    out = sol.minDeletionSize(ss); deb(out);

    
    return 0;
}