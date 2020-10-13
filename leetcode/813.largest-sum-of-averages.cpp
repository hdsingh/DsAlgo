/*
 * @lc app=leetcode id=813 lang=cpp
 *
 * [813] Largest Sum of Averages
 *
 * https://leetcode.com/problems/largest-sum-of-averages/description/
 *
 * algorithms
 * Medium (48.14%)
 * Likes:    703
 * Dislikes: 27
 * Total Accepted:    19K
 * Total Submissions: 39.5K
 * Testcase Example:  '[9,1,2,3,9]\n3'
 *
 * We partition a row of numbers A into at most K adjacent (non-empty) groups,
 * then our score is the sum of the average of each group. What is the largest
 * score we can achieve?
 * 
 * Note that our partition must use every number in A, and that scores are not
 * necessarily integers.
 * 
 * 
 * Example:
 * Input: 
 * A = [9,1,2,3,9]
 * K = 3
 * Output: 20
 * Explanation: 
 * The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9
 * + (1 + 2 + 3) / 3 + 9 = 20.
 * We could have also partitioned A into [9, 1], [2], [3, 9], for example.
 * That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
 * 
 * 
 * 
 * 
 * Note: 
 * 
 * 
 * 1 <= A.length <= 100.
 * 1 <= A[i] <= 10000.
 * 1 <= K <= A.length.
 * Answers within 10^-6 of the correct answer will be accepted as correct.
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

class Solution {
public:
    double largestSumOfAverages(vector<int>& a, int K) {
        int n = a.size();
        vi pre(n);
        pre[0] = a[0];
        for(int i=1; i<n; i++)
            pre[i] = pre[i-1]+a[i];
        
        auto avg = [&](int l, int r){
            double sum =  pre[r] - (l ? pre[l-1] : 0);
            return sum/(r-l+1);
        };

        vector<vector<double>> dp(n, vector<double>(K+1));
        forn(i, n)
            dp[i][1] = avg(0, i);

        for(int i=0; i<n; i++){
            for(int add=1; add+i<n; add++){
                for(int k=2; k<=K; k++){
                    max_self(dp[i+add][k], dp[i][k-1] + avg(i+1, i+add));
                }
            }
        }
        // print_vv(dp);

        return dp[n-1][K];
    }
};
// @lc code=end

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        vector<vector<double>> dp(n+1, vector<double>(K+1));
        double sum = 0;
        for(int i=1; i<=n; ++i){
            sum+=A[i-1]; 
            dp[i][1] = sum/i;
        }

        for(int i=1; i<=n; ++i){
            double sum = 0;
            for(int j=i; j<=n; ++j){
                sum+=A[j-1];
                for(int k=2; k<=K; ++k){
                    max_self(dp[j][k], dp[i-1][k-1] + sum/(j-i+1));
                }
            }
        }

        return dp[n][K];
    }
};


int main(){
    Solution sol;
    vi A; int K; double out;
    A = {9,1,2,3,9 };
    K = 3;
    out = sol.largestSumOfAverages(A, K); deb(out); 
    
    A = {1,2,3,4,5,6,7};
    K = 4;
    out = sol.largestSumOfAverages(A, K); deb(out); 
    return 0;
}