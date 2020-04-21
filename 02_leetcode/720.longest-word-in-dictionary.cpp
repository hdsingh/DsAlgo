/*
 * @lc app=leetcode id=720 lang=cpp
 *
 * [720] Longest Word in Dictionary
 *
 * https://leetcode.com/problems/longest-word-in-dictionary/description/
 *
 * algorithms
 * Easy (47.42%)
 * Likes:    529
 * Dislikes: 654
 * Total Accepted:    55K
 * Total Submissions: 115.9K
 * Testcase Example:  '["w","wo","wor","worl","world"]'
 *
 * Given a list of strings words representing an English Dictionary, find the
 * longest word in words that can be built one character at a time by other
 * words in words.  If there is more than one possible answer, return the
 * longest word with the smallest lexicographical order.  If there is no
 * answer, return the empty string.
 * 
 * Example 1:
 * 
 * Input: 
 * words = ["w","wo","wor","worl", "world"]
 * Output: "world"
 * Explanation: 
 * The word "world" can be built one character at a time by "w", "wo", "wor",
 * and "worl".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
 * Output: "apple"
 * Explanation: 
 * Both "apply" and "apple" can be built from other words in the dictionary.
 * However, "apple" is lexicographically smaller than "apply".
 * 
 * 
 * 
 * Note:
 * All the strings in the input will only contain lowercase letters.
 * The length of words will be in the range [1, 1000].
 * The length of words[i] will be in the range [1, 30].
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
    string longestWord(vector<string>& words) {
        set<string> s;
        for(auto w: words)
            s.insert(w);

        string ans; int len = 0 ;
        for(auto w: words){
            if(w.size()<len) continue;
            if(w.size()==len && w>ans) continue;
            string t = w;
            t.pop_back();

            bool found = true;
            while(!t.empty()){
                if(!s.count(t)){
                    found = false;
                    break;
                }
                t.pop_back();
            }
            if(found){
                ans = w;
                len = ans.size();
            }
        }
        return ans;
    }
};

struct TrieNode{
    bool eow; // end of word
    TrieNode* children[26];
    TrieNode(){
        eow = false;
        memset(children, NULL, sizeof(children));
    }
};

class Trie {
    int mx_len = 0;
    string lw; //longest word
    TrieNode* root;    
public:
    Trie(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode* cur = root;
        for(auto x: word){
            if(!cur->children[x-'a'])
                cur->children[x-'a'] = new TrieNode();
            cur = cur->children[x-'a'];
        }
        cur->eow = true;
    }

    bool search(string word){
        TrieNode* cur = root;
        for(auto x: word){
            if(!cur->children[x-'a']) return false;
            cur = cur->children[x-'a'];
        }
        return cur->eow;
    }

    string find_max(){
        mx_len = 0; lw.clear();
        string w;
        dfs(root, 0, w);
        return lw;
    }

    void dfs(TrieNode* cur, int len, string w){
        if(len>mx_len){
            lw = w;
            mx_len = len;
        }

        if(len==mx_len){
            lw = min(lw,w);
        }

        for(int i=0; i<26; ++i){
            if(cur->children[i] && cur->children[i]->eow){
                dfs(cur->children[i], len+1, w + char('a' + i));
            }
        }
    }

    ~Trie(){
        clear(root);
    }
    
    void clear(TrieNode* cur){
        for(int i=0; i<26; ++i){
            if(cur->children[i]) clear(cur->children[i]);
        }
        delete cur;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for(auto w: words)
            trie.insert(w);

        return trie.find_max();
    }
};


// @lc code=end

int main(){
    Solution sol;    
    vs words; string ans;
    words = { "w","wo","wor","worl", "world" };
    ans = sol.longestWord(words); deb(ans);
    words = { "a", "banana", "app", "appl", "ap", "apply", "apple" };
    ans = sol.longestWord(words); deb(ans);
    words = { "t","ti","tig","tige","tiger","e","en","eng","engl","engli","englis","english","h","hi","his","hist","histo","histor","history" };
    ans = sol.longestWord(words); deb(ans);

    return 0;
}
