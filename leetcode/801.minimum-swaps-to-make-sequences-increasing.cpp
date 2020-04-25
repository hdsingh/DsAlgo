/*
 * @lc app=leetcode id=801 lang=cpp
 *
 * [801] Minimum Swaps To Make Sequences Increasing
 *
 * https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/
 *
 * algorithms
 * Medium (37.81%)
 * Likes:    784
 * Dislikes: 56
 * Total Accepted:    24.1K
 * Total Submissions: 63.6K
 * Testcase Example:  '[1,3,5,4]\n[1,2,3,7]'
 *
 * We have two integer sequences A and B of the same non-zero length.
 * 
 * We are allowed to swap elements A[i] and B[i].  Note that both elements are
 * in the same index position in their respective sequences.
 * 
 * At the end of some number of swaps, A and B are both strictly increasing.
 * (A sequence is strictly increasing if and only if A[0] < A[1] < A[2] < ... <
 * A[A.length - 1].)
 * 
 * Given A and B, return the minimum number of swaps to make both sequences
 * strictly increasing.  It is guaranteed that the given input always makes it
 * possible.
 * 
 * 
 * Example:
 * Input: A = [1,3,5,4], B = [1,2,3,7]
 * Output: 1
 * Explanation: 
 * Swap A[3] and B[3].  Then the sequences are:
 * A = [1, 3, 5, 7] and B = [1, 2, 3, 4]
 * which are both strictly increasing.
 * 
 * 
 * Note:
 * 
 * 
 * A, B are arrays with the same length, and that length will be in the range
 * [1, 1000].
 * A[i], B[i] are integer values in the range [0, 2000].
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

// Refer: https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/solution/
// n1: not swap i-1, s1: swap i-1, n2: not swap i
// A[i-1] = a1, A[i-2] = a2, B[i-1] = b1, B[i-2] =  b2
// a1 < a2
// b1 < b2
// Case 1: a1<a2 and b1<b2
// we can swap either both or none of these,
// i.e. none:   n2 = min(n2,n1)
//      both:   s2 = min(s2, s1+1)
// case 2 : swap only one
// b1 < a2
// a1 < b2
//   or
// a1 < b2
// b1 < a2
// (both equivalent)
// swap one of these
// n2 = min(n2, s1)  (cant swap n2, i-1 have been swapped for cost s1)
// s2 = min(s2, n1+1) (swap 2 or ns1 + 1(cost))
class Solution {
public:
    int minSwap(vector<int>& a, vector<int>& b) {
        int n = a.size();

        int n1, n2, s1, s2;
        n1 = 0; s1 = 1;
        for(int i=1; i<n; i++){
            n2=1e6; s2 = 1e6;
            //  none or both
            if(a[i-1]<a[i] && b[i-1]<b[i]){
                // n2 = min(n2, n1);
                // s2 = min(s2, s1+1);
                n2 = n1;   // no swap
                s2 = s1+1; // both
            }

            // only one
            if(a[i-1]<b[i] && b[i-1]<a[i]){
                n2 = min(n2, s1);
                s2 = min(s2, n1+1);
            }

            s1 = s2;
            n1 = n2;
        }
        return min(s1, n1);    
    }
};
// @lc code=end


int main(){
    Solution sol; int out; vi A, B;
    A = { 1,3,5,4 }, B = { 1,2,3,7 };
    out = sol.minSwap(A, B); deb(out);
    return 0;
}