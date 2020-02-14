/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 *
 * https://leetcode.com/problems/maximum-product-of-word-lengths/description/
 *
 * algorithms
 * Medium (50.01%)
 * Likes:    679
 * Dislikes: 61
 * Total Accepted:    90.3K
 * Total Submissions: 180.3K
 * Testcase Example:  '["abcw","baz","foo","bar","xtfn","abcdef"]'
 *
 * Given a string array words, find the maximum value of length(word[i]) *
 * length(word[j]) where the two words do not share common letters. You may
 * assume that each word will contain only lower case letters. If no such two
 * words exist, return 0.
 * 
 * Example 1:
 * 
 * 
 * Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
 * Output: 16 
 * Explanation: The two words can be "abcw", "xtfn".
 * 
 * Example 2:
 * 
 * 
 * Input: ["a","ab","abc","d","cd","bcd","abcd"]
 * Output: 4 
 * Explanation: The two words can be "ab", "cd".
 * 
 * Example 3:
 * 
 * 
 * Input: ["a","aa","aaa","aaaa"]
 * Output: 0 
 * Explanation: No such pair of words.
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

// Using bitmasks
class Solution1 {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<bitset<26>> wds(n);

        for(int i=0; i<n; i++){
            for(auto c: words[i]){
                wds[i][c-'a'] = 1;
            }
        }

        int mp = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if( (wds[i] & wds[j]) ==0){ // no intersection
                    mp = max(mp, (int)(words[i].size() * words[j].size()));
                }
            }
        }

        return mp;
    }
};

// Using int
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        unordered_map<int, int> mxlen;

        for(auto w: words){
            int mask = 0;
            for(auto c: w)
                mask|= 1<<(c-'a');
            
            mxlen[mask] = max(mxlen[mask], (int) w.size());
            // a, aa, aaa all have mask 1 but max len poibel for such mask
            // is max number of (a)s. 
        }

        int mxp = 0;
        for(auto a: mxlen){
            for(auto b: mxlen){
                if(!(a.first & b.first)){ // intersection 0: nothing common
                    mxp = max(mxp, a.second*b.second);
                }
            }
        }

        return mxp;
    }
};
// @lc code=end


int main(){
    Solution sol; vs words; int out;
    words = {"abcw","baz","foo","bar","xtfn","abcdef"};
    out = sol.maxProduct(words); deb(out);

    words = {"a","ab","abc","d","cd","bcd","abcd"};
    out = sol.maxProduct(words); deb(out);

    words = {"a","aa","aaa","aaaa"};
    out = sol.maxProduct(words); deb(out);

    return 0;
}