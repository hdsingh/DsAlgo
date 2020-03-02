/*
 * @lc app=leetcode id=982 lang=cpp
 *
 * [982] Triples with Bitwise AND Equal To Zero
 *
 * https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/description/
 *
 * algorithms
 * Hard (55.48%)
 * Likes:    84
 * Dislikes: 106
 * Total Accepted:    6.7K
 * Total Submissions: 12K
 * Testcase Example:  '[2,1,3]'
 *
 * Given an array of integers A, find the number of triples of indices (i, j,
 * k) such that:
 * 
 * 
 * 0 <= i < A.length
 * 0 <= j < A.length
 * 0 <= k < A.length
 * A[i] & A[j] & A[k] == 0, where & represents the bitwise-AND operator.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [2,1,3]
 * Output: 12
 * Explanation: We could choose the following i, j, k triples:
 * (i=0, j=0, k=1) : 2 & 2 & 1
 * (i=0, j=1, k=0) : 2 & 1 & 2
 * (i=0, j=1, k=1) : 2 & 1 & 1
 * (i=0, j=1, k=2) : 2 & 1 & 3
 * (i=0, j=2, k=1) : 2 & 3 & 1
 * (i=1, j=0, k=0) : 1 & 2 & 2
 * (i=1, j=0, k=1) : 1 & 2 & 1
 * (i=1, j=0, k=2) : 1 & 2 & 3
 * (i=1, j=1, k=0) : 1 & 1 & 2
 * (i=1, j=2, k=0) : 1 & 3 & 2
 * (i=2, j=0, k=1) : 3 & 2 & 1
 * (i=2, j=1, k=0) : 3 & 1 & 2
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 1000
 * 0 <= A[i] < 2^16
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
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

class Solution0 {
public:
    int countTriplets(vector<int>& a) {
        int n = a.size();
        int cnt = 0;

        forn(i, n){
            forn(j,n){
                forn(k, n){
                    if(!(a[i]&a[j]&a[k])){
                        // deb3(a[i],a[j],a[k]);
                        ++cnt;
                    }
                }
            }
        }
        return cnt;
    }
};

// Ref: https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/discuss/226721/Java-DP-O(3-*-216-*-n)-time-O(216)-space
class Solution1 {
public:
    int countTriplets(vector<int>& a) {
        int n = a.size();
        int M = 3;
        int N = 1<<16;
        vvi dp(M+1, vi(N));
        dp[0][N-1] =  1;
        // for the case in dp[1][mask &x] = dp[0][mask]
        // when all 1 (N-1) ,   [11..1&x] = 1
        // Otherwise if everything in dp[0] is 0, then dp[1] would not be initailised

        for(int m=0; m<M; ++m){
            for(int mask=0; mask<N; ++mask){
                for(auto x: a){
                    dp[m+1][mask & x] += dp[m][mask];
                }
            }
        }

        return dp[M][0];
    }
};

// Compute a&b first, then & it with c
class Solution2 {
public:
    int countTriplets(vector<int>& a) {
        int n = a.size();
        
        unordered_map<int,int> cnt;
        for(auto &x: a){
            for(auto &y: a){
                cnt[x&y]++;
            }
        }
        int out = 0;
        for(auto p: cnt){
            for(auto &x: a){
                if((p.first&x)==0)
                    out+=p.second;
            }
        }
        return out;
    }
};

// Same with vector
class Solution {
public:
    int countTriplets(vector<int>& a) {
        int n = a.size();
        int out = 0;
        int masks[1<<16] = {};

        for(auto &x: a){
            for(auto &y: a){
                masks[x&y]++;
            }
        }

        for(auto &x: a){
            for(int mask=0; mask<(1<<16); mask++){
                if((x&mask)==0)
                    out+=masks[mask];
            }
        }
        
        return out;
    }
};

// @lc code=end

int main(){
    Solution sol; vi a; int out;
    a = {1,2,3,4,5,5,0,8,6,4,3,5,6,6};
    out = sol.countTriplets(a); deb(out);
    return 0;
}