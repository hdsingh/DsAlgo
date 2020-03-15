/*
 * @lc app=leetcode id=854 lang=cpp
 *
 * [854] K-Similar Strings
 *
 * https://leetcode.com/problems/k-similar-strings/description/
 *
 * algorithms
 * Hard (37.49%)
 * Likes:    299
 * Dislikes: 30
 * Total Accepted:    13.8K
 * Total Submissions: 36.7K
 * Testcase Example:  '"ab"\n"ba"'
 *
 * Strings A and B are K-similar (for some non-negative integer K) if we can
 * swap the positions of two letters in A exactly K times so that the resulting
 * string equals B.
 * 
 * Given two anagrams A and B, return the smallest K for which A and B are
 * K-similar.
 * 
 * Example 1:
 * 
 * 
 * Input: A = "ab", B = "ba"
 * Output: 1
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = "abc", B = "bca"
 * Output: 2
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: A = "abac", B = "baca"
 * Output: 2
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: A = "aabc", B = "abca"
 * Output: 2
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length == B.length <= 20
 * A and B contain only lowercase letters from the set {'a', 'b', 'c', 'd',
 * 'e', 'f'}
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

// B stays fixed, all the changes will be made in a
// starting from pos 0, if chars match the move forward,
// else if chars dont match
// ie. a[i]!=b[i], then find a pos j, i<j, such that, a[j]==b[i]
// swap these and move forward, but ther could be more positions where the
// above conditon is satisfied, so we will check all those using dfs
// Basically trying out all swaps by backtracking + memo
class Solution {
    int n;
    string b;
    unordered_map<string, int> cnt_swaps_memo;
public:
    int kSimilarity(string a, string _b) {
        n = a.size();
        b = _b;
        cnt_swaps_memo.clear();
        return dfs(0, a);     
    }

    // if the string till before pos "start" is matching,
    // then min number of swaps required to convert a to b
    int dfs(int start, string a){ 
        if(start==n) return 0;
        if(cnt_swaps_memo.count(a)) return cnt_swaps_memo[a];

        // move to pos where a, b dont match
        int i = start;
        while(i<n && a[i]==b[i]) ++i;
        if(i==n) return 0;


        int min_swaps = 1e4;
        // since b is constant, find a pos in a where a[j]==b[i]
        // find the char a[j] which is equal to b[i], and also a[j]!=b[j]
        // if a[j]==b[j] then tere is no need to swap it since it is already in correct place
        for(int j=i+1; j<n; ++j){
            if(a[j]==b[i] && a[j]!=b[j]){
                swap(a[i], a[j]);
                min_swaps = min(min_swaps, dfs(i+1,a));
                swap(a[i], a[j]);
            }
        }

        return cnt_swaps_memo[a] = 1 + min_swaps;
    }
};
// @lc code=end

int main(){
    Solution sol;  string A, B; int out;
    A = "ab", B = "ba";
    out = sol.kSimilarity(A,B); deb(out);

    A = "abc", B = "bca";
    out = sol.kSimilarity(A,B); deb(out);

    A = "abccaacceecdeea", B = "bcaacceeccdeaae";
    out = sol.kSimilarity(A,B); deb(out);

    return 0;
}
