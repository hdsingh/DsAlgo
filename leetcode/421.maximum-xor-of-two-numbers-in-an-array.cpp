/*
 * @lc app=leetcode id=421 lang=cpp
 *
 * [421] Maximum XOR of Two Numbers in an Array
 *
 * https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/
 *
 * algorithms
 * Medium (52.59%)
 * Likes:    919
 * Dislikes: 164
 * Total Accepted:    45.2K
 * Total Submissions: 86K
 * Testcase Example:  '[3,10,5,25,2,8]'
 *
 * Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai <
 * 2^31.
 * 
 * Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
 * 
 * Could you do this in O(n) runtime?
 * 
 * Example:
 * 
 * 
 * Input: [3, 10, 5, 25, 2, 8]
 * 
 * Output: 28
 * 
 * Explanation: The maximum result is 5 ^ 25 = 28.
 * 
 * 
 * 
 * 
 */
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

// @lc code=start
// struct TrieNode{
//     bool eow; // end of word
//     TrieNode* children[26];
//     TrieNode(){
//         eow = false;
//         memset(children, NULL, sizeof(children));
//     }
// };


struct Trie{
    Trie* bit[2] = {nullptr};
};

class Solution {
    Trie* root;
public:
    int findMaximumXOR(vector<int>& nums) {
        if(nums.empty()) return 0;
        root = new Trie();
        int mx = INT_MIN;

        for(auto num: nums)
            insert(num);
        
        for(auto num: nums)
            mx = max(mx, maxxor(num));
        
        return mx;
    }

    void insert(int x){
        Trie* cur = root;
        for(int i=31; i>=0; --i){
            int b = (x>>i)&1;
            if(!cur->bit[b])
                cur->bit[b] = new Trie();
            cur = cur->bit[b];
        }
    }

    int maxxor(int x){
        Trie* cur = root;
        int ans = 0;
        for(int i=31; i>=0; --i){
            int b = (x>>i)&1;
            // !b since we need b to be diff for xor to be max
            if(cur->bit[!b]){
                ans|=(1LL<<i);
                cur = cur->bit[!b];
            }else
                cur = cur->bit[b];
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution sol; 
    vi a = {3, 10, 5, 25, 2, 8};
    int out = sol.findMaximumXOR(a); deb(out);
    return 0;
}
