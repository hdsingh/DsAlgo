/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (47.68%)
 * Likes:    2156
 * Dislikes: 84
 * Total Accepted:    228.4K
 * Total Submissions: 473K
 * Testcase Example:  '3'
 *
 * Given n, how many structurally unique BST's (binary search trees) that store
 * values 1 ... n?
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: 5
 * Explanation:
 * Given n = 3, there are a total of 5 unique BST's:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
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

// Observation: 
//  (n:trees) (0:1, 1:1, 2:2, 3:5,)
// for 4,
// if it begins with 1 ->       {}... 1... {2,3,4}  (1*5)
// if it begins with 2 ->      {1}....2....{3,4}    (1*2)
// if it begins with 3 ->      {1,2}..3...{4}       (2*1)
// if  it egins with 4 ->      {1,2,3}...4...{}     (5*1)
// total = 14
// 1,1,2,5,14...catalan numbers
class Solution {
    int nmax = 19;
    bool calcuated = false;
    vi catalan;
public:
    int numTrees(int n) {
        if(!calcuated) precalc();
    
        return catalan[n];
    }

    // C(n) = summation_k=0_to_n-1( C(k)*C(n-1-k))
    void precalc(){
        catalan.resize(nmax+1);
        catalan[0] = 1; 
        catalan[1] = 1;
        for(int i=2; i<=nmax; ++i){
            for(int j=0; j<i; ++j){
                catalan[i]+= catalan[j]*catalan[i-j-1];
            }
        }
        calcuated = true;
    }
};
// @lc code=end

int main(){
    Solution sol; 
    vi a = {1,5,8};
    for(auto x: a){
        int out = sol.numTrees(x); deb(out);
    }
    return 0;
}
