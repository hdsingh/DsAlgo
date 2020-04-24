/*
 * @lc app=leetcode id=472 lang=cpp
 *
 * [472] Concatenated Words
 *
 * https://leetcode.com/problems/concatenated-words/description/
 *
 * algorithms
 * Hard (41.25%)
 * Likes:    576
 * Dislikes: 90
 * Total Accepted:    49.1K
 * Total Submissions: 118.3K
 * Testcase Example:  '["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]'
 *
 * Given a list of words (without duplicates), please write a program that
 * returns all concatenated words in the given list of words.
 * A concatenated word is defined as a string that is comprised entirely of at
 * least two shorter words in the given array.
 * 
 * Example:
 * 
 * Input:
 * ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
 * 
 * Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
 * 
 * Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";
 * "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; "ratcatdogcat"
 * can be concatenated by "rat", "cat", "dog" and "cat".
 * 
 * 
 * 
 * Note:
 * 
 * The number of elements of the given array will not exceed 10,000 
 * The length sum of elements in the given array will not exceed 600,000. 
 * All the input string will only include lower case letters.
 * The returned elements order does not matter. 
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

struct trie{
    bool eow = false;
    trie *ch[26] = {};
};

class Solution {
    trie* root;
    vector<string> out;
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        root = new trie();
        for(auto &word: words)
            insert(word);
        out.clear();
        
        for(auto &word: words){
            if(dfs(0,0,word))
                out.push_back(word);
        }

        return out;        
    }

    void insert(string &word){
        trie* cur = root;
        for(auto x: word){
            if(!cur->ch[x-'a'])
                cur->ch[x-'a'] = new trie();
            cur = cur->ch[x-'a'];
        }
        cur->eow = true;
    }

    bool dfs(int pos, int cnt, string &s){
        if(cnt>=2 && pos==s.size()) return true;
        auto cur = root;
        for(int i=pos; i<s.size(); ++i){
            if(!cur->ch[s[i]-'a']) return false;
            cur = cur->ch[s[i]-'a'];
            
            if(cur->eow){
                // switch to next pos
                if(dfs(i+1,cnt+1,s)) return true;
            }
            // else keep searching here without using this eow
        }

        return false;
    }    
};
// @lc code=end

int main(){
    Solution sol;
    vs words = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
    vs out = sol.findAllConcatenatedWordsInADict(words); print(out);
    words = {"a","b","ab","abc"};
    out = sol.findAllConcatenatedWordsInADict(words); print(out);
    return 0;
}
