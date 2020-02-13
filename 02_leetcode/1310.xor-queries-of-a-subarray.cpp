/*
 * @lc app=leetcode id=1310 lang=cpp
 *
 * [1310] XOR Queries of a Subarray
 *
 * https://leetcode.com/problems/xor-queries-of-a-subarray/description/
 *
 * algorithms
 * Medium (66.15%)
 * Likes:    107
 * Dislikes: 5
 * Total Accepted:    7.9K
 * Total Submissions: 12K
 * Testcase Example:  '[1,3,4,8]\n[[0,1],[1,2],[0,3],[3,3]]'
 *
 * Given the array arr of positive integers and the array queries where
 * queries[i] = [Li, Ri], for each query i compute the XOR of elements from Li
 * to Ri (that is, arr[Li] xor arr[Li+1] xor ... xor arr[Ri] ). Return an array
 * containing the result for the given queries.
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
 * Output: [2,7,14,8] 
 * Explanation: 
 * The binary representation of the elements in the array are:
 * 1 = 0001 
 * 3 = 0011 
 * 4 = 0100 
 * 8 = 1000 
 * The XOR values for queries are:
 * [0,1] = 1 xor 3 = 2 
 * [1,2] = 3 xor 4 = 7 
 * [0,3] = 1 xor 3 xor 4 xor 8 = 14 
 * [3,3] = 8
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
 * Output: [8,0,4,4]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 3 * 10^4
 * 1 <= arr[i] <= 10^9
 * 1 <= queries.length <= 3 * 10^4
 * queries[i].length == 2
 * 0 <= queries[i][0] <= queries[i][1] < arr.length
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

class Solution {
public:
    vector<int> xorQueries(vector<int>& a, vector<vector<int>>& qs) {
        int n = a.size();
        vi pre(n);

        int x = 0;
        forn(i, n){
            x^=a[i];
            pre[i] = x;
        }

        // Scheme for every query repeat the outer area
        int qsz = qs.size();
        vi out(qsz);
        for(int i=0; i<qsz; i++){
            vi q = qs[i];
            int l = q[0] ? pre[q[0]-1] : 0;
            int r = pre[q[1]];
            out[i]  = l^r;      
        }

        return out;
    }
};
// @lc code=end


int main(){
    Solution sol; vi out, arr; vvi queries;
    arr = {1,3,4,8}, queries = {{0,1},{1,2},{0,3},{3,3}};
    arr = sol.xorQueries(arr, queries); print(arr); 

    arr = {4,8,2,10}, queries = {{2,3},{1,3},{0,0},{0,3}};
    arr = sol.xorQueries(arr, queries); print(arr); 

    return 0;
}
