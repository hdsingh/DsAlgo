/*
 * @lc app=leetcode id=795 lang=cpp
 *
 * [795] Number of Subarrays with Bounded Maximum
 *
 * https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/description/
 *
 * algorithms
 * Medium (45.18%)
 * Likes:    450
 * Dislikes: 40
 * Total Accepted:    15.5K
 * Total Submissions: 34.3K
 * Testcase Example:  '[2,1,4,3]\n2\n3'
 *
 * We are given an array A of positive integers, and two positive integers L
 * and R (L <= R).
 * 
 * Return the number of (contiguous, non-empty) subarrays such that the value
 * of the maximum array element in that subarray is at least L and at most R.
 * 
 * 
 * Example :
 * Input: 
 * A = [2, 1, 4, 3]
 * L = 2
 * R = 3
 * Output: 3
 * Explanation: There are three subarrays that meet the requirements: [2], [2,
 * 1], [3].
 * 
 * 
 * Note:
 * 
 * 
 * L, R  and A[i] will be an integer in the range [0, 10^9].
 * The length of A will be in the range of [1, 50000].
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

// O(n^2) , Just for  reference 
class Solution1 {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int n = A.size();
        
        auto findmax = [&](int l, int r){
            int mx = INT_MIN;
            for(int i=l; i<=r; i++){
                mx = max(mx, A[i]);
            }
            return mx;
        };

        vvi r;
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j>=0; j--){
                int mx = findmax(j, i);
                if(L<=mx &&  mx<=R){
                    r.push_back({j,i});
                    ++count;
                }
            }
        }
        
        for(int i=0; i<r.size(); i++){
            cout<<r[i][0]<<" "<<r[i][1]<<" : ";
            for(int j=r[i][0]; j<=r[i][1]; j++)
                cout<<A[j]<<" ";
            cout<<endl;
        }

        return count;
    }
};

// keep track of the next of last position greater than R (l);
// if the number is in range, we will extend it till l, 
// and also save the increment(i-l+1);
// If number is less than L, we can't extend it, so it could only be
// appended to prev exixting sequences(res+=prev_count)
// else if A[i] > R, reset prev_count and l position
class Solution2 {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int n = A.size();
        int l = 0;
        int res = 0;
        
        int prev_count = 0;
        for(int i=0; i<n; i++){
            if(A[i]>=L && A[i]<=R){
                res+= i - l + 1;
                prev_count = i-l+1;
            }else if(A[i]<L){
                res+=prev_count;
            }
            else if(A[i]>R){
                l = i+1;
                prev_count = 0;
            }
        }
        return res;
    }
};

// Simplified implementation in terms of shifting left and right
// Whenever we get a<R, shift left and right, so count = r-l=i-i= 0
// if a>=L, shift R to i, so count = R - L
// else without shifhting R, we will consider prev count
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int n = A.size();
        int l = -1; int r = -1; int res = 0;

        for(int i=0; i<n; i++){
            if(A[i]>R) l=i;
            if(A[i]>=L) r = i;
            res+= r-l;
        }
        return res;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vi A; int out, L, R;
    L = 3, R = 6;
    A = { 9,3,1,1,4,5,3,8,5,6,9,6,4,3,2,4};
    out = sol.numSubarrayBoundedMax(A, L, R); deb(out);
    return 0;
};