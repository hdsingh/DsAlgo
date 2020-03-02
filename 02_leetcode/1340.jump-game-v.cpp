/*
 * @lc app=leetcode id=1340 lang=cpp
 *
 * [1340] Jump Game V
 *
 * https://leetcode.com/problems/jump-game-v/description/
 *
 * algorithms
 * Hard (55.62%)
 * Likes:    121
 * Dislikes: 5
 * Total Accepted:    5.3K
 * Total Submissions: 9.6K
 * Testcase Example:  '[6,4,14,6,8,13,9,7,10,6,12]\n2'
 *
 * Given an array of integers arr and an integer d. In one step you can jump
 * from index i to index:
 * 
 * 
 * i + x where: i + x < arr.length and  0 < x <= d.
 * i - x where: i - x >= 0 and  0 < x <= d.
 * 
 * 
 * In addition, you can only jump from index i to index j if arr[i] > arr[j]
 * and arr[i] > arr[k] for all indices k between i and j (More formally min(i,
 * j) < k < max(i, j)).
 * 
 * You can choose any index of the array and start jumping. Return the maximum
 * number of indices you can visit.
 * 
 * Notice that you can not jump outside of the array at any time.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [6,4,14,6,8,13,9,7,10,6,12], d = 2
 * Output: 4
 * Explanation: You can start at index 10. You can jump 10 --> 8 --> 6 --> 7 as
 * shown.
 * Note that if you start at index 6 you can only jump to index 7. You cannot
 * jump to index 5 because 13 > 9. You cannot jump to index 4 because index 5
 * is between index 4 and 6 and 13 > 9.
 * Similarly You cannot jump from index 3 to index 2 or index 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [3,3,3,3,3], d = 3
 * Output: 1
 * Explanation: You can start at any index. You always cannot jump to any
 * index.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [7,6,5,4,3,2,1], d = 1
 * Output: 7
 * Explanation: Start at index 0. You can visit all the indicies. 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: arr = [7,1,7,1,7,1], d = 2
 * Output: 2
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: arr = [66], d = 1
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 1000
 * 1 <= arr[i] <= 10^5
 * 1 <= d <= arr.length
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

class Solution {
    vi a;
    vi dp;
    int longestJump, d, n;
public:
    int maxJumps(vector<int>& arr, int D) {
        a = arr;
        longestJump = 0;
        d = D;
        n = a.size();
        dp.clear();
        dp.resize(n, -1);
    
        for(int i=0; i<n; ++i){
            longestJump = max(dfs(i), longestJump);
        }

        return longestJump;
    }

    int dfs(int x){
        if(dp[x]!=-1) return dp[x];
    
        int curMax = 0;
        for(int i=x+1; i<=x+d; ++i){
            if(i<n && a[x]>a[i])
                curMax = max(curMax, dfs(i));
            else break;
        }

        for(int i=x-1; i>=x-d; --i){
            if(i>=0 && a[x]>a[i])
                curMax = max(curMax, dfs(i));
            else break;
        }

        return dp[x] = curMax+1;
    }
};

// @lc code=end

int main(){
    vi a; Solution sol; int d,out;
    a = {6,4,14,6,8,13,9,7,10,6,12}; d=2;
    out = sol.maxJumps(a, d); deb(out);
    a = {3,3,3,3,3}; d =3;
    out = sol.maxJumps(a, d); deb(out);

    a = {7,6,5,4,3,2,1}; d = 1;
    out = sol.maxJumps(a, d); deb(out);

    a = {7,1,7,1,7,1}; d = 2;
    out = sol.maxJumps(a, d); deb(out);

    a = {66};
    out = sol.maxJumps(a, d); deb(out);

    return 0;
}
