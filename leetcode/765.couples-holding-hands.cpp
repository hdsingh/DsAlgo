/*
 * @lc app=leetcode id=765 lang=cpp
 *
 * [765] Couples Holding Hands
 *
 * https://leetcode.com/problems/couples-holding-hands/description/
 *
 * algorithms
 * Hard (53.58%)
 * Likes:    527
 * Dislikes: 56
 * Total Accepted:    21.3K
 * Total Submissions: 39.7K
 * Testcase Example:  '[0,2,1,3]'
 *
 * 
 * N couples sit in 2N seats arranged in a row and want to hold hands.  We want
 * to know the minimum number of swaps so that every couple is sitting side by
 * side.  A swap consists of choosing any two people, then they stand up and
 * switch seats. 
 * 
 * The people and seats are represented by an integer from 0 to 2N-1, the
 * couples are numbered in order, the first couple being (0, 1), the second
 * couple being (2, 3), and so on with the last couple being (2N-2, 2N-1).
 * 
 * The couples' initial seating is given by row[i] being the value of the
 * person who is initially sitting in the i-th seat.
 * 
 * Example 1:
 * Input: row = [0, 2, 1, 3]
 * Output: 1
 * Explanation: We only need to swap the second (row[1]) and third (row[2])
 * person.
 * 
 * 
 * Example 2:
 * Input: row = [3, 2, 0, 1]
 * Output: 0
 * Explanation: All couples are already seated side by side.
 * 
 * 
 * 
 * Note:
 * ⁠
 * ⁠len(row) is even and in the range of [4, 60].
 * ⁠row is guaranteed to be a permutation of 0...len(row)-1.
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

// Greedy approach:
// Start from 0th pos, and check the next char,
// if not valid then swap
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> pos(n);
        for(int i=0; i<n; ++i)
            pos[row[i]] = i;
        
        int cnt = 0;
        for(int i=0; i<n; i+=2){
            int cur = row[i];
            int nxt = row[i+1];
            int req = cur&1 ? cur-1 : cur + 1;
            if(req!=nxt){
                swap(row[i+1], row[pos[req]]);
                swap(pos[req], pos[nxt]);
            ++cnt;
            }
        }
        return cnt;
    }
};
// @lc code=end

int main(){
    Solution sol; vvi rows; int cnt;
    rows = {
        {0, 2, 1, 3},
        {3, 2, 0, 1},
        {3,4,5,0,1,2},
    };
    for(auto &row: rows){
        cnt = sol.minSwapsCouples(row); deb(cnt);
    }
    return 0;
}
