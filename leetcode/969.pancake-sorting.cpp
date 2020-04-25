/*
 * @lc app=leetcode id=969 lang=cpp
 *
 * [969] Pancake Sorting
 *
 * https://leetcode.com/problems/pancake-sorting/description/
 *
 * algorithms
 * Medium (64.65%)
 * Likes:    280
 * Dislikes: 351
 * Total Accepted:    21.6K
 * Total Submissions: 33.3K
 * Testcase Example:  '[3,2,4,1]'
 *
 * Given an array A, we can perform a pancake flip: We choose some positive
 * integer k <= A.length, then reverse the order of the first k elements of A.
 * We want to perform zero or more pancake flips (doing them one after another
 * in succession) to sort the array A.
 * 
 * Return the k-values corresponding to a sequence of pancake flips that sort
 * A.  Any valid answer that sorts the array within 10 * A.length flips will be
 * judged as correct.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,4,1]
 * Output: [4,2,4,3]
 * Explanation: 
 * We perform 4 pancake flips, with k values 4, 2, 4, and 3.
 * Starting state: A = [3, 2, 4, 1]
 * After 1st flip (k=4): A = [1, 4, 2, 3]
 * After 2nd flip (k=2): A = [4, 1, 2, 3]
 * After 3rd flip (k=4): A = [3, 2, 1, 4]
 * After 4th flip (k=3): A = [1, 2, 3, 4], which is sorted. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3]
 * Output: []
 * Explanation: The input is already sorted, so there is no need to flip
 * anything.
 * Note that other answers, such as [3, 3], would also be accepted.
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 100
 * A[i] is a permutation of [1, 2, ..., A.length]
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
    vector<int> pancakeSort(vector<int>& a) {
        int n = a.size();
        int l = n-1;

        vi out;
        while(!is_sorted(all(a))){
            // Pick the max element
            int mloc = max_element(a.begin(), a.begin()+l+1) - a.begin();
    
            // bring it to front if not already
            if(mloc){
                out.pb(mloc+1);
                reverse(a.begin(), a.begin()+mloc+1);
            }
            // put this element to it respective pos
            reverse(a.begin(), a.begin()+l+1);
            out.pb(l+1);
            --l;
        }

        return out;

    }
};
// @lc code=end

int main(){
    Solution sol; vi A; vi out;
    A =  {1,2,4,3};
    out = sol.pancakeSort(A); print(out);
    return 0;
}
