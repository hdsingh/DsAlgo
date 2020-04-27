/*
 * @lc app=leetcode id=862 lang=cpp
 *
 * [862] Shortest Subarray with Sum at Least K
 *
 * https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/
 *
 * algorithms
 * Hard (23.58%)
 * Likes:    901
 * Dislikes: 26
 * Total Accepted:    26K
 * Total Submissions: 109.8K
 * Testcase Example:  '[1]\n1'
 *
 * Return the length of the shortest, non-empty, contiguous subarray of A with
 * sum at least K.
 * 
 * If there is no non-empty subarray with sum at least K, return -1.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = [1], K = 1
 * Output: 1
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = [1,2], K = 4
 * Output: -1
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: A = [2,-1,2], K = 3
 * Output: 3
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 50000
 * -10 ^ 5 <= A[i] <= 10 ^ 5
 * 1 <= K <= 10 ^ 9
 * 
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
#define sz(a) int((a).size())
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
public:
    int shortestSubarray(vector<int>& a, int k) {
        int n = a.size();
        int min_len = INT_MAX;
        vector<int> b(n+1); // represents sum with first i elements
        for(int i=1; i<=n; ++i)
            b[i] = b[i-1] + a[i-1];
        deque<int> q;

        for(int i=0; i<=n; ++i){
            
            // if a prev pos has satisfied the condition for cur i, 
            // there is no more need for it, because for upcoming i, the lenght will 
            // only increase and we need shortest
            while(!q.empty() && b[i] - b[q.front()]>=k)
                min_len = min(min_len, i - q.front()), q.pop_front();
            
            // the b[i], with less value and much shorter len can satisfy the condition
            // then there is no need of larger and far away pos
            while(!q.empty() && b[q.back()]>=b[i])
                q.pop_back();

            q.push_back(i);
        }

        return min_len==INT_MAX ? -1 : min_len;
    }
};
// @lc code=end

int main(){
    Solution sol;   
    vi A; int K; int out;
    A = { 1 }, K = 1;
    out = sol.shortestSubarray(A, K); deb(out);
    A = { 1,2 }, K = 4;
    out = sol.shortestSubarray(A, K); deb(out);
    A = { 2,-1,2 }, K = 3;
    out = sol.shortestSubarray(A, K); deb(out);
    A = { 77,19,35,10,-14 }; K = 19;
    out = sol.shortestSubarray(A, K); deb(out);
    A = { 17,85,93,-45,-21 }, K = 150;
    out = sol.shortestSubarray(A, K); deb(out);
    A = {-28,81,-20,28,-29}, K = 89;
    out = sol.shortestSubarray(A, K); deb(out);
    A = { 44,-25,75,-50,-38,-42,-32,-6,-40,-47}, K = 19;
    out = sol.shortestSubarray(A, K); deb(out); // 1

    return 0;
}
