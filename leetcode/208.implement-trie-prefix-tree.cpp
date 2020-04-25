/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (44.73%)
 * Likes:    2555
 * Dislikes: 46
 * Total Accepted:    256.2K
 * Total Submissions: 571.2K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * Implement a trie with insert, search, and startsWith methods.
 * 
 * Example:
 * 
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");   
 * trie.search("app");     // returns true
 * 
 * 
 * Note:
 * 
 * 
 * You may assume that all inputs are consist of lowercase letters a-z.
 * All inputs are guaranteed to be non-empty strings.
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

// Implemetation 1
// struct TrieNode{
//     bool is_end_of_word = false;
//     unordered_map<int,TrieNode*>  children;

// };

// class Trie {
//     TrieNode* root;
// public:
//     /** Initialize your data structure here. */
//     Trie() { 
//         root = new TrieNode();
//     }

//     /** Inserts a word into the trie. */
//     void insert(string word) {
//         TrieNode* cur = root;

//         for(auto c: word){
//             // make a node if is not present
//             if(!cur->children.count(c-'a')) 
//                 cur->children[c-'a'] = new TrieNode();
//             cur = cur->children[c-'a'];
//         }
        
//         cur->is_end_of_word = true;
//     }
    
//     /** Returns if the word is in the trie. */
//     bool search(string word) {
//         TrieNode* cur = root;
//         for(auto c: word){
//             if(!cur->children.count(c-'a'))
//                 return false;
//             cur = cur->children[c-'a'];
//         }
//         return cur->is_end_of_word;
//     }
    
//     /** Returns if there is any word in the trie that starts with the given prefix. */
//     bool startsWith(string prefix) {
//         TrieNode* cur = root;
//         for(auto c: prefix){
//             if(!cur->children.count(c-'a'))
//                 return false;
//             cur = cur->children[c-'a'];
//         }

//         // if either it has children or some wor ends here i.e word is prefix of itself
//         return (cur->children.size() || cur->is_end_of_word);
//     }
// };

struct TrieNode{
    bool end;
    TrieNode* children[26];
    TrieNode(){
        end = false;
        memset(children, NULL, sizeof(children));
    }
};

class Trie{
    TrieNode* root;
public: 
    Trie(){
        root = new TrieNode();
    }
    
    ~Trie(){
        clear(root);
    }
    void clear(TrieNode* cur){
        for(int i=0; i<26; ++i)
            if(cur->children[i]) clear(cur->children[i]);
        delete cur;
    }

    void insert(string word){
        TrieNode* cur = root;
        for(auto c: word){
            if(!cur->children[c-'a'])
                cur->children[c-'a'] = new TrieNode();
            cur = cur->children[c-'a'];
        }
        cur->end = true;
    }

    bool search(string word){
        TrieNode* cur = root;
        for(auto c: word){
            if(!cur->children[c-'a'])
                return false;
            cur = cur->children[c-'a'];
        }
        return cur->end;
    }

    bool startsWith(string prefix){
        TrieNode* cur = root;
        for(auto c: prefix){
            if(!cur->children[c-'a'])
                return false;
            cur = cur->children[c-'a'];
        }
        return cur->children;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

int main(){
    Trie trie; bool out;
    trie.insert("apple");
    out = trie.search("apple"); deb(out); // returns true
    out = trie.search("app"); deb(out);   // returns false
    out = trie.startsWith("app");  deb(out);// returns true
    trie.insert("app");   
    out = trie.search("app"); deb(out);    // returns true
    return 0;
}
